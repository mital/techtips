// stopwatch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "stop_watch.h"

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

int main()
{
	bool start = false;
	techtips::StopWatch sw(start);
	sw.start();
	some_method();
	sw.stop();
	std::cout << "execute_some_method: took " << sw.elapsed() << " milisecods time to execute" << std::endl;
	return 0;
}

