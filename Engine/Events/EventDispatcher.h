#pragma once
#include <map>
#include <functional>
#include "Event.h"
class EventDispatcher {
public:
	static void Subscribe(const char* _key, Event* _event);
	static void Dispatch(const char* _key);
private:
	static std::map<const char*, Event*> eventCache;
};