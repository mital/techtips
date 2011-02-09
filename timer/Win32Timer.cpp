/************************************************
 * @author: Mital Vora <mital.d.vora@gmail.com> *
 ************************************************/

#include <windows.h>
#include "Win32Timer.h"

namespace techtips
{
	std::map<unsigned, Timer *> timers;

	Win32Timer::Win32Timer(long _duration, bool _recursive)
		: Timer(_duration, _recursive),
		loadTimeTimerID(0)
	{
	}

	Win32Timer::~Win32Timer()
	{
		if (this->loadTimeTimerID != 0)
		{
			std::map<unsigned, Timer *>::iterator oIter = timers.find(this->loadTimeTimerID);
			if(oIter != timers.end())
			{
				timers.erase(oIter);
			}
		}
	}

	VOID CALLBACK TimerProc(HWND hwnd,
		UINT uMsg,	UINT_PTR idEvent, DWORD dwTime)
	{
			std::map<unsigned, Timer *>::iterator oIter = timers.find(idEvent);
			if(oIter != timers.end())
			{
				Timer * timer = oIter->second;
				timer->callback();
			}
	}


	void Win32Timer::start()
	{
		this->loadTimeTimerID = SetTimer(NULL, this->id, this->duration, &TimerProc);
		timers[this->loadTimeTimerID] = this;
	}

	bool Win32Timer::stop()
	{
		if (this->loadTimeTimerID)
		{
			KillTimer(0 , this->loadTimeTimerID);
			std::map<unsigned, Timer *>::iterator oIter = timers.find(this->loadTimeTimerID);
			if(oIter != timers.end())
			{
				timers.erase(oIter);
				return true;
			}
		}
		return false;
	}

	Win32CallerTimer::Win32CallerTimer(long _duration,
		bool _recursive)
		: Win32Timer(_duration, _recursive)
	{
	}

	Win32CallerTimer::~Win32CallerTimer()
	{
	}

	void Win32CallerTimer::callback()
	{
		if (! this->recursive)
		{
			this->stop();
		}
		// This method would be called in the thread by which the timer is created.
		// TODO: Implement your functionality here
		::MessageBox(0, L"This is callback function called by timer. Implement your functionality here", L"techtips timer example", MB_OK);
	}
}
