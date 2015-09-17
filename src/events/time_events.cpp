#include "events/time_events.h"

namespace matrica {

	/**
	* \class matrica::MetroTickEvent
	*/
	static ds::EventRegistry    METRO_TICK("MetroTickEvent");

	int MetroTickEvent::WHAT() {
		return METRO_TICK.mWhat;
	}

	MetroTickEvent::MetroTickEvent()
		: ds::Event(METRO_TICK.mWhat)
	{
	}

} // namespace matrica
