#include "Time.h"
#include <iostream>
long Time::lastFrameTime;
float Time::deltaTime;
bool Time::firstFrameProcessed = false;
void Time::Update()
{
	if (!firstFrameProcessed) {
		lastFrameTime = GetCurrentTime();
		firstFrameProcessed = 1;
	}
	long currentTime = GetCurrentTime();
	deltaTime = (currentTime - lastFrameTime)/1000.0;
	lastFrameTime = currentTime;
}

long Time::GetCurrentTime()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
}
