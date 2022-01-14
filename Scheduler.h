#pragma once

#include <functional>

namespace PGG
{
	class Scheduler;
}

// performs a given task with the given delay
class PGG::Scheduler
{
	private:

		std::function<void()> _task;
		int _counter;
		int _delay;

	public:

		Scheduler()
		{
			_task = []() {};
			_counter = 0;
			_delay = 0;
		}

		Scheduler(int delay, std::function<void()> task)
		{
			_task = task;
			_counter = 0;
			_delay = delay;
		}

		void operator++(int)
		{
			if (on() && ++_counter == _delay)
			{
				_task();
			}
		}

		// getters / setters
		bool on() { return _counter < _delay; }
};