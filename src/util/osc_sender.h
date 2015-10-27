#pragma once
#ifndef UI_MATRICA_UTIL_OSC_SENDER_H_
#define UI_MATRICA_UTIL_OSC_SENDER_H_

#include "util/time_seconds.h"
#include <ds/app/event_client.h>
#include <ds/ui/sprite/image.h>
#include "OscSender.h"

namespace matrica {

	class Globals;

	/*
	* \class matrica::OSCSender
	* \class that sends the OSC messages produced by matrica
	*/

	class OSCSender {
	public:

		OSCSender(Globals&, const std::string& host, const int & port);

	private:

		void onAppEvent(const ds::Event&);

		Globals&					mGlobals;
		ds::EventClient				mEventClient;

		ci::osc::Sender sender;
		const std::string			mHost;
		const int 					mPort;

	};

}

#endif