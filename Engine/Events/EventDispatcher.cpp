#include "EventDispatcher.h"
std::map<const char*, Event*> EventDispatcher::eventCache;
void EventDispatcher::Subscribe(const char* _key, Event* _event)
{
	eventCache.insert(std::pair<const char*, Event*>(_key, _event));
}

void EventDispatcher::Dispatch(const char* _key)
{
	if (eventCache.find(_key) == eventCache.end())
		return;
	auto val = eventCache.at(_key);
	val->Dispatch();
}
