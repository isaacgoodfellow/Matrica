#include "metronome.h"
#include "app/globals.h"
#include "events/app_events.h"
#include "events/time_events.h"

#include "cinder/Rand.h"

#include "osc_sender.h"


namespace matrica{

	OSCSender::OSCSender( Globals& g, const std::string& host, const int & port)
		: mGlobals(g)
		, mEventClient(g.mEngine.getNotifier(), [this](const ds::Event *m){ if (m) this->onAppEvent(*m); })
		, mHost(host)
		, mPort(port)
	{
	}

	void OSCSender::onAppEvent(const ds::Event& in_e) {
		ci::osc::Message message;
		message.setAddress("/test");
		message.addIntArg(2);//note_no);
		sender.sendMessage(message);
	}

}