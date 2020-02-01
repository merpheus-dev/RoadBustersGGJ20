#pragma once
#include <chrono>
struct Time {
public:
	static float deltaTime;
	static void Update();
	static long GetCurrentTime();
private:
	static long lastFrameTime;
	static bool firstFrameProcessed;
};