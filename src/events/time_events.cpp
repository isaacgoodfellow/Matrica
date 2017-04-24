#include "events/time_events.h"

namespace matrica {

	/**
	* \class matrica::MetroTickEvent
	*/
	static ds::EventRegistry    METRO_TICK("MetroTickEvent");

	int MetroTickEvent::WHAT() {
		return METRO_TICK.mWhat;
	}

	MetroTickEvent::MetroTickEvent(int tick)
		: ds::Event(METRO_TICK.mWhat)
		, mTick(tick)
	{
	}

} // namespace matrica
