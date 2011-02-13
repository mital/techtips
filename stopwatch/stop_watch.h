/************************************************
 * @author: Mital Vora <mital.d.vora@gmail.com> *
 ************************************************/

#ifndef _STOP_WATCH_H_
#define _STOP_WATCH_H_


namespace techtips
{
	namespace TimeUtils
	{
		double getCurrentTimeInMiliSeconds();
		double getCurrentTimeInSeconds();
	}

	class StopWatch
	{
		double start_time;
		double end_time;
	public:
		StopWatch(bool start = false);
		~StopWatch();
		void start();
		void stop();
		double elapsed() const;
	};
}
#endif // _STOP_WATCH_H_