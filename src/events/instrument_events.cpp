#include "events/instrument_events.h"
#include "model/MatricaModel.h"

namespace matrica {

	/**
	* \class matrica::TriangleFired
	*/
	static ds::EventRegistry    NOTE_FIRED("NoteFired");

	int NoteFiredEvent::WHAT() {
		return NOTE_FIRED.mWhat;
	}

	NoteFiredEvent::NoteFiredEvent(const MatricaModel& model, int note)
		: ds::Event(NOTE_FIRED.mWhat)
		, mNote(note)
		, mModel(model)
	{
	}

} // namespace matrica
