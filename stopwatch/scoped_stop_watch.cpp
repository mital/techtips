/************************************************
* @author: Mital Vora <mital.d.vora@gmail.com> *
************************************************/

#include "scoped_stop_watch.h"


namespace techtips
{
	ScopedStopWatch::ScopedStopWatch(const std::string & method_name, std::ostream & os)
		: StopWatch(true),
		method_name(method_name),
		ostr(os)
	{
		ostr << "method:" << method_name << " called" << std::endl;
	}

	ScopedStopWatch::~ScopedStopWatch()
	{
		this->stop();
		ostr << "method:" << method_name << " returned" << std::endl;
		ostr << "method:" << method_name << " took " << this->elapsed() << " milisecods time to execute" << std::endl;
	}
}
