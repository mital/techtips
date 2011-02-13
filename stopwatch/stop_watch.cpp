/************************************************
* @author: Mital Vora <mital.d.vora@gmail.com> *
************************************************/

#include "stop_watch.h"

#ifdef WIN32
#include <time.h>

// define gettimeofday for windows
#include <Winsock2.h>

#if defined(_MSC_VER) || defined(_MSC_EXTENSIONS)
#define DELTA_EPOCH_IN_MICROSECS  11644473600000000Ui64
#else
#define DELTA_EPOCH_IN_MICROSECS  11644473600000000ULL
#endif
struct timezone
{
	int  tz_minuteswest; /* minutes W of Greenwich */
	int  tz_dsttime;     /* type of dst correction */
};

int gettimeofday(struct timeval *tv, struct timezone *tz)
{
	// Define a structure to receive the current Windows filetime
	FILETIME ft;

	// Initialize the present time to 0 and the timezone to UTC
	unsigned __int64 tmpres = 0;
	static int tzflag = 0;

	if (NULL != tv)
	{
		GetSystemTimeAsFileTime(&ft);

		// The GetSystemTimeAsFileTime returns the number of 100 nanosecond 
		// intervals since Jan 1, 1601 in a structure. Copy the high bits to 
		// the 64 bit tmpres, shift it left by 32 then or in the low 32 bits.
		tmpres |= ft.dwHighDateTime;
		tmpres <<= 32;
		tmpres |= ft.dwLowDateTime;

		// Convert to microseconds by dividing by 10
		tmpres /= 10;

		// The Unix epoch starts on Jan 1 1970.  Need to subtract the difference 
		// in seconds from Jan 1 1601.
		tmpres -= DELTA_EPOCH_IN_MICROSECS;

		// Finally change microseconds to seconds and place in the seconds value. 
		// The modulus picks up the microseconds.
		tv->tv_sec = (long)(tmpres / 1000000UL);
		tv->tv_usec = (long)(tmpres % 1000000UL);
	}

	if (NULL != tz)
	{
		if (!tzflag)
		{
			_tzset();
			tzflag++;
		}

		// Adjust for the timezone west of Greenwich
		tz->tz_minuteswest = _timezone / 60;
		tz->tz_dsttime = _daylight;
	}

	return 0;
}
#else
#include <sys/time.h>
#endif


namespace techtips
{
	double TimeUtils::getCurrentTimeInMiliSeconds()
	{
		struct timeval curtime;
		gettimeofday(&curtime, 0);
		return (curtime.tv_sec * 1000) + curtime.tv_usec;

	}
	double TimeUtils::getCurrentTimeInSeconds()
	{
		return (double)time(NULL);
	}

	StopWatch::StopWatch(bool start)
		: start_time(0),
		end_time(0)
	{
		if (start)
		{
			this->start();
		}
	}

	StopWatch::~StopWatch()
	{
	}

	void StopWatch::start()
	{
		start_time = TimeUtils::getCurrentTimeInMiliSeconds();
		end_time = 0;
	}

	void StopWatch::stop()
	{
		if (start_time != 0)
		{
			end_time = TimeUtils::getCurrentTimeInMiliSeconds();
		}
	}

	double StopWatch::elapsed() const
	{
		if (start_time && end_time)
		{
			return end_time - start_time;
		}
		return 0;
	}
}
