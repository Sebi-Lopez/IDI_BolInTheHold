// ----------------------------------------------------
// Timer.cpp
// Body for CPU Tick Timer class
// ----------------------------------------------------

#include "Timer.h"

// ---------------------------------------------
Timer::Timer()
{
	Start();
}

// ---------------------------------------------
void Timer::Start()
{
	running = true;
	started_at = SDL_GetTicks();
}

// ---------------------------------------------
void Timer::Stop()
{
	if (running == true)
	{
		running = false;
		stopped_at = SDL_GetTicks();
	}

}

void Timer::Resume()
{
	if (running == false)
	{		
		running = true; 
		started_at += SDL_GetTicks() - stopped_at;
	}
}

// ---------------------------------------------
Uint32 Timer::Read()
{
	if(running == true)
	{
		return SDL_GetTicks() - started_at;
	}
	else
	{
		return stopped_at - started_at;
	}
}

float Timer::ReadSec()
{
	if (running == true)
	{
		return (SDL_GetTicks() - started_at) / 1000.f;
	}
	else
	{
		return (stopped_at - started_at) / 1000.f;
	}
}

bool Timer::isRunning()
{
	return running;
}


