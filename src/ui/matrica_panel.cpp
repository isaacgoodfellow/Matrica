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
#include "ui/matrica_button.h"
#include "ui/matrica_touch_grabber.h"

#pragma warning(disable: 4355)

namespace matrica {
	
	/**
	* Matrica::MatricaPanel
	*/

	MatricaPanel::MatricaPanel(Globals& g)
		: inherited(g.mEngine)
		, mGlobals(g)
		, mEventClient(g.mEngine.getNotifier(), [this](const ds::Event *m){ if (m) this->onAppEvent(*m); }){


		mTouchGrabber = new MatricaTouchGrabber(mGlobals, this);
		addChildPtr(mTouchGrabber);
//		mTouchGrabber->enable(true);
//		mTouchGrabber->sendToFront();

		setColor(ci::Color(0.8f,0.8f,0.8f));
//		setColor(ci::Color(1.0f,0.0f, 0.6f));
//		setColor(ci::Color(0.0f, 1.0f, 0.69f));

		ci::Vec2f pos = mGlobals.mEngine.getSettings(SETTINGS_LAYOUT).getSize("matrica:panel:position");
		ci::Vec2f size = mGlobals.mEngine.getSettings(SETTINGS_LAYOUT).getSize("matrica:panel:size");
		ci::Vec2f button_size = mGlobals.mEngine.getSettings(SETTINGS_LAYOUT).getSize("matrica:panel:button:size");
		float button_gutter = mGlobals.mEngine.getSettings(SETTINGS_LAYOUT).getFloat("matrica:panel:button:gutter");
		float cornerRad = mGlobals.mEngine.getSettings(SETTINGS_LAYOUT).getFloat("matrica:panel:corner:radius");

		setPosition(pos.x,pos.y);
		setSize(size);
		setCornerRadius(cornerRad);
		setTransparent(false);
		enable(true);

		x_res = 16;

		float xp = button_gutter;
		float yp = button_gutter;

		float button_pad = 3;

		mButtons.resize(x_res);
		for( auto it = mButtons.begin(); it != mButtons.end(); ++it){
			(*it).resize(x_res);
		}

		for (int x = 0; x < x_res; x++){
			for (int y = 0; y < x_res; y++){
				MatricaButton *p = new MatricaButton(mGlobals);
				p->x = x;
				p->y = y;
				addChildPtr(p);
				p->setSize(button_size.x, button_size.y);
				p->setCornerRadius(button_size.x * 0.1f);
				p->setPosition(xp, yp);
				p->layout();
				yp += button_size.y;
				yp += button_pad;
				mButtons[x][y] = p;
			}
			yp = button_gutter;
			xp += button_size.x;
			xp += button_pad;
		}

//		mTouchGrabber->sendToFront();
//		mTouchGrabber->setSize(button_area.x, button_area.y);
//		mTouchGrabber->setPosition(button_gutter_x, button_gutter_y);

	}

	void MatricaPanel::onAppEvent(const ds::Event& in_e) {

	
	}

} // namespace jci