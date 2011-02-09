/************************************************
 * @author: Mital Vora <mital.d.vora@gmail.com> *
 ************************************************/

#include "Timer.h"

namespace techtips
{
	unsigned Timer::timerid = 0;

	Timer::Timer(long _duration, bool _recursive)
		: id(++Timer::timerid),
		duration(_duration),
		recursive(_recursive)
	{
	}
}
