#include "StateHandler.h"

StateHandler::StateHandler()
	: m_state(Running)
{

}

StateHandler::State StateHandler::state() const
{
	return m_state;
}

void StateHandler::changeState(StateHandler::State state)
{
	m_state = state;
}
