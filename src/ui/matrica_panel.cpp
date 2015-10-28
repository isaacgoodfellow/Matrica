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
#include "events/app_events.h"
#include "ui/matrica_button.h"
#include "ui/matrica_touch_grabber.h"
#include<ds/ui/touch/multi_touch_constraints.h>

#pragma warning(disable: 4355)

namespace matrica {
	
	/**
	* Matrica::MatricaPanel
	*/

	MatricaPanel::MatricaPanel(Globals& g, MatricaModel& model)
		: inherited(g.mEngine)
		, mGlobals(g)
		, mModel(model)
		, mEventClient(g.mEngine.getNotifier(), [this](const ds::Event *m){ if (m) this->onAppEvent(*m); }){

		enableMultiTouch(ds::ui::MULTITOUCH_CAN_POSITION | ds::ui::MULTITOUCH_CAN_SCALE);
		enable(true);

		setColor(model.getMainColor());

		ci::Vec2f pos = mGlobals.mEngine.getSettings(SETTINGS_LAYOUT).getSize("matrica:panel:position");
		
		ci::Vec2f button_size = mGlobals.mEngine.getSettings(SETTINGS_LAYOUT).getSize("matrica:panel:button:size");
		float button_gutter = mGlobals.mEngine.getSettings(SETTINGS_LAYOUT).getFloat("matrica:panel:button:gutter");
		float cornerRad = mGlobals.mEngine.getSettings(SETTINGS_LAYOUT).getFloat("matrica:panel:corner:radius");
		float button_pad = mGlobals.mEngine.getSettings(SETTINGS_LAYOUT).getFloat("matrica:panel:button:pad");

		x_res = model.getXRes();
		y_res = model.getYRes();

		float width = x_res * button_size.x + x_res * (button_pad - 1) + button_gutter * 2.0f;
		float height = y_res * button_size.y + y_res * (button_pad - 1) + button_gutter * 2.0f;

		ci::Vec2f size = ci::Vec2f(width, height);
		setPosition(pos.x, pos.y);
		setSize(size);
		setCornerRadius(cornerRad);
		setTransparent(false);
		enable(true);

		float xp = button_gutter;
		float yp = button_gutter;


		mButtons.resize(x_res);
		for( auto it = mButtons.begin(); it != mButtons.end(); ++it){
			(*it).resize(y_res);
		}

		for (int x = 0; x < x_res; x++){
			for (int y = 0; y < y_res; y++){
				MatricaButton *p = new MatricaButton(mGlobals);
				p->x = x;
				p->y = y;
				addChildPtr(p);
				p->setSize(button_size.x, button_size.y);
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

		setCenter(0.5f, 0.5f);
		setScale(0.0f);
		setOpacity(0.0f);

	}

	void MatricaPanel::animateOn(){
		float dur = 1.0f;
		tweenOpacity(1.0f, dur, 0.0f, cinder::EaseInOutCirc());
		tweenScale(ci::Vec3f(1.0f, 1.0f, 1.0f), dur, 0.0f, cinder::EaseInOutCirc());
	}


	void MatricaPanel::onAppEvent(const ds::Event& in_e) {
		if (in_e.mWhat == IdleEndedEvent::WHAT()){
			animateOn();
		}

	}

} // namespace jci