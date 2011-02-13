/************************************************
 * @author: Mital Vora <mital.d.vora@gmail.com> *
 ************************************************/

#ifndef _SCOPED_STOP_WATCH_H_
#define _SCOPED_STOP_WATCH_H_

#include <string>
#include <iostream>

#include "stop_watch.h"

namespace techtips
{
	class ScopedStopWatch : public StopWatch
	{
		const std::string method_name;
		std::ostream & ostr;
	public:
		ScopedStopWatch(const std::string & method_name, std::ostream & os = std::cout);
		~ScopedStopWatch();
	};
}
#endif // _STOP_WATCH_H_