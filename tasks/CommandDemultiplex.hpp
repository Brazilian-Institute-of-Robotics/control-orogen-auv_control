#ifndef AUV_CONTROL_COMMANDDEMULTIPLEX_TASK_HPP
#define AUV_CONTROL_COMMANDDEMULTIPLEX_TASK_HPP

#include <string>
#include <map>
#include "auv_control/CommandDemultiplexBase.hpp"

namespace auv_control {

/*! \class CommandDemultiplex
 * \brief The task context provides and requires services. It uses an ExecutionEngine to perform its functions.
 * Essential interfaces are operations, data flow ports and properties. These interfaces have been defined using the oroGen specification.
 * In order to modify the interfaces you should (re)use oroGen and rely on the associated workflow.
 *
 * \details
 * The name of a TaskContext is primarily defined via:
 \verbatim
 deployment 'deployment_name'
 task('custom_task_name','auv_control::CommandDemultiplex')
 end
 \endverbatim
 *  It can be dynamically adapted when the deployment is called with a prefix argument.
 */
class CommandDemultiplex: public CommandDemultiplexBase {
    friend class CommandDemultiplexBase;
protected:

    std::vector<std::string> names;

    std::map<std::string, RTT::OutputPort<base::samples::Joints>* > output_ports;

    bool setupCommandOutputPorts();

    bool addCommandOutputPort(std::string name);

    void releaseCommandOutputPorts();

    bool writeOutputPortByName(const std::string& port_name, const std::string& name, const base::JointState& elem);

public:

    /** TaskContext constructor for CommandDemultiplex
     * \param name Name of the task. This name needs to be unique to make it identifiable via nameservices.
     * \param initial_state The initial TaskState of the TaskContext. Default is Stopped state.
     */
    CommandDemultiplex(std::string const& name = "auv_control::CommandDemultiplex");

    /** TaskContext constructor for CommandDemultiplex
     * \param name Name of the task. This name needs to be unique to make it identifiable for nameservices.
     * \param engine The RTT Execution engine to be used for this task, which serialises the execution of all commands, programs, state machines and incoming events for a task.
     */
    CommandDemultiplex(std::string const& name, RTT::ExecutionEngine* engine);

    /** Default deconstructor of CommandDemultiplex
     */
    ~CommandDemultiplex();

    bool configureHook();

    void updateHook();

    void cleanupHook();
};
}

#endif

