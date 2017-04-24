#pragma once
#ifndef EVENTS_TIME_EVENTS_H_
#define EVENTS_TIME_EVENTS_H_

#include <cinder/Vector.h>
#include <ds/app/event.h>

namespace matrica {

	/**
	* \class matrica::MetroTickEvent
	* \brief time moves ever onwards
	*/
	class MetroTickEvent : public ds::Event {
	public:
		static int			WHAT();
		MetroTickEvent(int time);
		int mTick;
	};

} // namespace matrica

#endif
