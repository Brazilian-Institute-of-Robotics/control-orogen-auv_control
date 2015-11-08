/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include "CommandMultiplex.hpp"

using namespace auv_control;

CommandMultiplex::CommandMultiplex(std::string const& name)
    : CommandMultiplexBase(name)
{
}

CommandMultiplex::CommandMultiplex(std::string const& name, RTT::ExecutionEngine* engine)
    : CommandMultiplexBase(name, engine)
{
}

CommandMultiplex::~CommandMultiplex()
{
}

bool CommandMultiplex::configureHook()
{
    if (! CommandMultiplexBase::configureHook())
        return false;


    names = _names.get();

    if (names.size() == 0){
        return false;
    }

    if (!setupCommandInputPorts()){
        return false;
    }

    return true;
}

void CommandMultiplex::updateHook()
{
    CommandMultiplexBase::updateHook();
}

void CommandMultiplex::cleanupHook()
{
    releaseCommandInputPorts();
    CommandMultiplexBase::cleanupHook();
}

bool CommandMultiplex::setupCommandInputPorts()
{
    for (size_t i =0; i < names.size(); i++) {
        if (!addCommandInputPort(names[i])) {
            return false;
        }
    }

    return true;
}

bool CommandMultiplex::addCommandInputPort(std::string name)
{
    if (provides()->hasService("cmd_in_" + name))
        return false;

    RTT::InputPort<base::samples::Joints> *port = new RTT::InputPort<base::samples::Joints>("cmd_in_" + name);
    provides()->addPort(*port);
    input_ports.insert(std::make_pair("cmd_in_" + name, port));

    return true;
}

void CommandMultiplex::releaseCommandInputPorts()
{
    for (std::map<std::string, RTT::InputPort<base::samples::Joints>* >::iterator it = input_ports.begin() ;
            it != input_ports.end(); it++) {
        RTT::InputPort<base::samples::Joints> *port = it->second;
        provides()->removePort(port->getName());
        delete port;
    }

    input_ports.clear();
}
