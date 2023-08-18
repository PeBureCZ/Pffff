#pragma once

using namespace System;
using namespace System::Threading::Tasks;

public ref class CustomTimer
{
private:

public:
	void TimerTick()
	{
	Task::Delay(TimeSpan::FromMilliseconds(100))->Wait();
	}

	void startTimer()
	{
		while (true)
		{
			Task^ timerTask = Task::Run(gcnew Action(this, &CustomTimer::TimerTick));

		}
			
	}
};