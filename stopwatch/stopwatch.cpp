// stopwatch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "stop_watch.h"
#include "scoped_stop_watch.h"

void some_method()
{
	std::cout << "execute_some_method: started" << std::endl;
	std::cout << "I am printing 10 lines of logs." << std::endl;
	for(int i=0;i<10;i++)
	{
		std::cout << "This is my log " << i << std::endl;
	}
	std::cout << "execute_some_method: returned" << std::endl;
}

void some_method_scoped_stop_watch_example()
{
	techtips::ScopedStopWatch scopedStopWatch("some_method_scoped_stop_watch_example", std::cout);
	std::cout << "I am printing 10 lines of logs." << std::endl;
	for(int i=0;i<10;i++)
	{
		std::cout << "This is my log " << i << std::endl;
	}
}

int main()
{
	bool start = false;
	std::cout << "StopWatch Example" << std::endl;
	techtips::StopWatch sw(start);
	sw.start();
	some_method();
	sw.stop();
	std::cout << "execute_some_method: took " << sw.elapsed() << " milisecods time to execute" << std::endl;

	std::cout << "--------------------------------------------------------------------------------" << std::endl;
	std::cout << "ScopedStopWatch Example" << std::endl;
	some_method_scoped_stop_watch_example();
	return 0;
}

