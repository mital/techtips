/************************************************
 * @author: Mital Vora <mital.d.vora@gmail.com> *
 ************************************************/
#ifndef _TIMER_H_
#define _TIMER_H_

#include <map>

namespace techtips
{
	class Timer
	{
		static unsigned timerid;

	protected:
		const unsigned id;
		const long duration;
		const bool recursive;

	public:
		Timer(long _duration, bool _recursive);
		virtual ~Timer() {}

		virtual void start()=0;
		virtual bool stop()=0;
		virtual void callback() = 0;

		unsigned getID() const { return id; }
	};
}
#endif // _TIMER_H_