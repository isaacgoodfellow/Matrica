#include "events/instrument_events.h"

namespace matrica {

	/**
	* \class matrica::TriangleFired
	*/
	static ds::EventRegistry    NOTE_FIRED("NoteFired");

	int NoteFiredEvent::WHAT() {
		return NOTE_FIRED.mWhat;
	}

	NoteFiredEvent::NoteFiredEvent(const std::string& channel, int note)
		: ds::Event(NOTE_FIRED.mWhat)
		, mNote(note)
		, mChannel(channel)
	{
	}

} // namespace matrica
