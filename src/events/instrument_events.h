#pragma once
#ifndef EVENTS_INSTRUMENT_EVENTS_H_
#define EVENTS_INSTRUMENT_EVENTS_H_

#include <cinder/Vector.h>
#include <ds/app/event.h>

namespace matrica {

	/**
	* \class matrica::TriangleFiredEvent
	* \brief trianglewaveform instrument fired
	*/
	class TriangleFiredEvent : public ds::Event {
	public:
		static int			WHAT();
		TriangleFiredEvent(int note);
		int mNote;
	};

} // namespace matrica

#endif
