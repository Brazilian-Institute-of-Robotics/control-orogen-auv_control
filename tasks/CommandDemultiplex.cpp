#include "CommandDemultiplex.hpp"

using namespace auv_control;

CommandDemultiplex::CommandDemultiplex(std::string const& name)
    : CommandDemultiplexBase(name)
{
}

CommandDemultiplex::CommandDemultiplex(std::string const& name, RTT::ExecutionEngine* engine)
    : CommandDemultiplexBase(name, engine)
{
}

CommandDemultiplex::~CommandDemultiplex()
{
}

bool CommandDemultiplex::configureHook()
{
    if (! CommandDemultiplexBase::configureHook())
        return false;


    names = _names.get();

    if (names.size() == 0){
        return false;
    }

    if (!setupCommandOutputPorts()){
        return false;
    }

    return true;
}

void CommandDemultiplex::updateHook()
{
    CommandDemultiplexBase::updateHook();

    base::samples::Joints input;

    if (_cmd_in.read(input) == RTT::NewData){

        for (size_t i = 0; i < input.names.size(); i++){
            if (!writeOutputPortByName("cmd_out_" + input.names[i], input.names[i], input.elements[i])){
                //TODO: go to exception state
                return;
            }
        }
    }

}

void CommandDemultiplex::cleanupHook()
{
    releaseCommandOutputPorts();
    CommandDemultiplexBase::cleanupHook();
}

bool CommandDemultiplex::setupCommandOutputPorts()
{

    for (size_t i =0; i < names.size(); i++) {
        if (!addCommandOutputPort(names[i])) {
            return false;
        }
    }

    return true;
}

bool CommandDemultiplex::addCommandOutputPort(std::string name)
{
    if (provides()->hasService("cmd_out_" + name))
        return false;

    RTT::OutputPort<base::samples::Joints> *port = new RTT::OutputPort<base::samples::Joints>("cmd_out_" + name);
    provides()->addPort(*port);
    output_ports.insert(std::make_pair("cmd_out_" + name, port));

    return true;
}

void CommandDemultiplex::releaseCommandOutputPorts()
{
    for (std::map<std::string, RTT::OutputPort<base::samples::Joints>* >::iterator it = output_ports.begin() ;
            it != output_ports.end(); it++) {
        RTT::OutputPort<base::samples::Joints> *port = it->second;
        provides()->removePort(port->getName());
        delete port;
    }

    output_ports.clear();
}

bool CommandDemultiplex::writeOutputPortByName(const std::string& port_name, const std::string& name, const base::JointState& elem) {

    std::map<std::string, RTT::OutputPort<base::samples::Joints>* >::iterator it  = output_ports.find(port_name);

    if (it == output_ports.end()) {
        return false;
    }

    base::samples::Joints joints;
    joints.time = base::Time::now();
    joints.names.push_back(name);
    joints.elements.push_back(elem);

    output_ports[port_name]->write(joints);
    return true;
}
