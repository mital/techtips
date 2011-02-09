/************************************************
 * @author: Mital Vora <mital.d.vora@gmail.com> *
 ************************************************/
#include <windows.h>

#include <iostream>

#include "Win32Timer.h"

using namespace techtips;


int main()
{
	const int duration = 5000; // Timeout duration in miliseconds.
	const bool recursive = true;
	Timer * timer = new Win32CallerTimer(duration, recursive);
	timer->start();
	MSG Msg;
	while (GetMessage(&Msg, NULL, 0, 0))
	{
		DispatchMessage(&Msg);
	}
	timer->stop();

	return 0;
}