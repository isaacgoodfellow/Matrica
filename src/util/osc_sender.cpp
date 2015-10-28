#include "osc_sender.h"

#include "app/globals.h"
#include "events/app_events.h"
#include "events/instrument_events.h"
#include "model/MatricaModel.h"
#include "util/metronome.h"


namespace matrica{

	OSCSender::OSCSender( Globals& g, const std::string& host, const int & port)
		: mGlobals(g)
		, mEventClient(g.mEngine.getNotifier(), [this](const ds::Event *m){ if (m) this->onAppEvent(*m); })
		, mHost(host)
		, mPort(port)
	{
		mSender.setup(mHost, mPort);
	}

	void OSCSender::onAppEvent(const ds::Event& in_e) {
		if (in_e.mWhat == NoteFiredEvent::WHAT()){
			const NoteFiredEvent&	e((NoteFiredEvent&)in_e);
			ci::osc::Message message;
			message.setAddress(e.mModel.getChannel());
			message.addIntArg(e.mNote);
			mSender.sendMessage(message);
		}
	}

}