#pragma once
#ifndef EVENTS_INSTRUMENT_EVENTS_H_
#define EVENTS_INSTRUMENT_EVENTS_H_

#include <cinder/Vector.h>
#include <ds/app/event.h>

namespace matrica {

	class MatricaModel;

	/**
	* \class matrica::NoteFiredEvent
	* \brief A note was played
	*/
	class NoteFiredEvent : public ds::Event {
	public:
		static int			WHAT();
		//todo: Change this from a reference to something faster, like index or something
		NoteFiredEvent( const MatricaModel& model, int note);
		const MatricaModel& mModel;
		const int mNote;
	};

} // namespace matrica

#endif
