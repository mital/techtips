/************************************************
 * @author: Mital Vora <mital.d.vora@gmail.com> *
 ************************************************/

#ifndef _WIN32_TIMER_H_
#define _WIN32_TIMER_H_

#include "Timer.h"

namespace techtips
{
	class Win32Timer : public Timer
	{
	private:
		unsigned loadTimeTimerID;

	public:
		Win32Timer(long _duration, bool _recursive);
		virtual ~Win32Timer();

		virtual void start();
		virtual bool stop();
	};

	class Win32CallerTimer
		: public Win32Timer
	{
	public:
		Win32CallerTimer(long _duration, bool _recursive);
		virtual ~Win32CallerTimer();
		virtual void callback();
	};
}
#endif // _WIN32_TIMER_H_