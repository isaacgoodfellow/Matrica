#pragma once
#ifndef EVENTS_INSTRUMENT_EVENTS_H_
#define EVENTS_INSTRUMENT_EVENTS_H_

#include <cinder/Vector.h>
#include <ds/app/event.h>

namespace matrica {

	/**
	* \class matrica::NoteFiredEvent
	* \brief A note was played
	*/
	class NoteFiredEvent : public ds::Event {
	public:
		static int			WHAT();
		NoteFiredEvent( const std::string& channel, int note);
		const std::string& mChannel;
		const int mNote;
	};

} // namespace matrica

#endif
