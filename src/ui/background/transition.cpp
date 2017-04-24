#include "ui/background/transition.h"

#include "app/app_defs.h"
#include <ds/app/engine/engine_cfg.h>
#include <ds/app/environment.h>
#include <ds/ui/sprite/sprite_engine.h>

#include "app/globals.h"

#pragma warning(disable: 4355)

namespace matrica {

	/**
	* Matrica::TransitionView
	*/

	TransitionView::TransitionView(Globals& g)
		: inherited(g.mEngine)
		, mGlobals(g)
	{

		setSize(mGlobals.mEngine.getWorldWidth(), mGlobals.mEngine.getWorldHeight());
		show();
		enable(false);
		
		setTransparent(false);
		setBlendMode(ds::ui::BlendMode::MULTIPLY);
		setOpacity(1.0f);

		setColor(ci::Color(0.0f, 0.0f, 0.0f));
		tweenOpacity(0.0f, 3.0f, 3.0f, ci::EaseOutInQuad(), [this]{ release(); });

		sendToFront();

	}

} // namespace matrica