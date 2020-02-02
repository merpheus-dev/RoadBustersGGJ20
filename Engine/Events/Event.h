#pragma once
#include <functional>
class Event {
public:
	Event(std::function<void()> callback)
	{
		m_callback = callback;
	}
	void Dispatch() {
		m_callback();
	}
private:
	std::function<void()> m_callback;
};