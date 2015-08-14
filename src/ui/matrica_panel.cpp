#include "ui/matrica_panel.h"

#include <ds/app/engine/engine_cfg.h>
#include <ds/app/environment.h>
#include <ds/app/event_notifier.h>
#include <ds/debug/debug_defines.h>
#include <ds/ui/sprite/image.h>
#include <ds/ui/sprite/sprite_engine.h>
#include <ds/ui/tween/tweenline.h>
#include "app/app_defs.h"
#include "app/globals.h"

#pragma warning(disable: 4355)

namespace matrica {
	/**
	* Matrica::MatricaPanel
	*/
	MatricaPanel::MatricaPanel(Globals& g)
		: inherited(g.mEngine)
		, mGlobals(g)
		, mEventClient(g.mEngine.getNotifier(), [this](const ds::Event *m){ if (m) this->onAppEvent(*m); }){

		setColor(ci::Color(1.0f,0.0f, 0.6f));
//		setColor(ci::Color(0.0f, 1.0f, 0.69f));

		ci::Vec2f pos = mGlobals.mEngine.getSettings(SETTINGS_LAYOUT).getSize("matrica:panel:position");
		ci::Vec2f size = mGlobals.mEngine.getSettings(SETTINGS_LAYOUT).getSize("matrica:panel:size");
		float cornerRad = mGlobals.mEngine.getSettings(SETTINGS_LAYOUT).getFloat("matrica:panel:corner_radius");

		setPosition(pos.x,pos.y);
		setSize(size);
		setCornerRadius(cornerRad);
		setTransparent(false);
		enable(true);

	}

	void MatricaPanel::onAppEvent(const ds::Event& in_e) {

	
	}

} // namespace jci