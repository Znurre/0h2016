#ifndef STATEHANDLER_H
#define STATEHANDLER_H


class StateHandler
{
	public:
		enum State
		{
			Running,
			GameOver
		};

		StateHandler();

		State state() const;
		void changeState(State state);

	private:
		State m_state;
};

#endif // STATEHANDLER_H
