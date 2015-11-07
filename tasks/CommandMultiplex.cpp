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



/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See CommandMultiplex.hpp for more detailed
// documentation about them.

bool CommandMultiplex::configureHook()
{
    if (! CommandMultiplexBase::configureHook())
        return false;
    return true;
}
bool CommandMultiplex::startHook()
{
    if (! CommandMultiplexBase::startHook())
        return false;
    return true;
}
void CommandMultiplex::updateHook()
{
    CommandMultiplexBase::updateHook();
}
void CommandMultiplex::errorHook()
{
    CommandMultiplexBase::errorHook();
}
void CommandMultiplex::stopHook()
{
    CommandMultiplexBase::stopHook();
}
void CommandMultiplex::cleanupHook()
{
    CommandMultiplexBase::cleanupHook();
}
