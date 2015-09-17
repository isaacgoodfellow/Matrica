#include "events/instrument_events.h"

namespace matrica {

	/**
	* \class matrica::TriangleFired
	*/
	static ds::EventRegistry    TRI_FIRED("TriangleFired");

	int TriangleFiredEvent::WHAT() {
		return TRI_FIRED.mWhat;
	}

	TriangleFiredEvent::TriangleFiredEvent(int in)
		: ds::Event(TRI_FIRED.mWhat)
		, mNote(in)
	{
	}

} // namespace matrica
