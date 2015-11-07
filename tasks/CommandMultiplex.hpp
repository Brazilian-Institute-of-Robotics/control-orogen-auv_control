/* Generated from orogen/lib/orogen/templates/tasks/Task.hpp */

#ifndef AUV_CONTROL_COMMANDMULTIPLEX_TASK_HPP
#define AUV_CONTROL_COMMANDMULTIPLEX_TASK_HPP

#include "auv_control/CommandMultiplexBase.hpp"

namespace auv_control {

/*! \class CommandMultiplex
 * \brief The task context provides and requires services. It uses an ExecutionEngine to perform its functions.
 * Essential interfaces are operations, data flow ports and properties. These interfaces have been defined using the oroGen specification.
 * In order to modify the interfaces you should (re)use oroGen and rely on the associated workflow.
 *
 * \details
 * The name of a TaskContext is primarily defined via:
 \verbatim
 deployment 'deployment_name'
 task('custom_task_name','auv_control::CommandMultiplex')
 end
 \endverbatim
 *  It can be dynamically adapted when the deployment is called with a prefix argument.
 */
class CommandMultiplex: public CommandMultiplexBase {
    friend class CommandMultiplexBase;
protected:

public:
    /** TaskContext constructor for CommandMultiplex
     * \param name Name of the task. This name needs to be unique to make it identifiable via nameservices.
     * \param initial_state The initial TaskState of the TaskContext. Default is Stopped state.
     */
    CommandMultiplex(std::string const& name = "auv_control::CommandMultiplex");

    /** TaskContext constructor for CommandMultiplex
     * \param name Name of the task. This name needs to be unique to make it identifiable for nameservices.
     * \param engine The RTT Execution engine to be used for this task, which serialises the execution of all commands, programs, state machines and incoming events for a task.
     */
    CommandMultiplex(std::string const& name, RTT::ExecutionEngine* engine);

    /** Default deconstructor of CommandMultiplex
     */
    ~CommandMultiplex();
    bool configureHook();

    bool startHook();

    void updateHook();

    void errorHook();

    void stopHook();

    void cleanupHook();
};
}

#endif

