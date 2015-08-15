#include "ui/background/background_view.h"

#include "app/app_defs.h"
#include <ds/app/engine/engine_cfg.h>
#include <ds/app/environment.h>
#include <ds/ui/sprite/image.h>
#include <ds/ui/sprite/sprite_engine.h>

#include "app/globals.h"

#pragma warning(disable: 4355)

namespace matrica {

	/**
	* Matrica::MatricaPanel
	*/

	BackgroundView::BackgroundView(Globals& g, float x, float y)
		: inherited(g.mEngine)
		, mGlobals(g)
		, mShadeImg(ds::ui::Sprite::makeAlloc<ds::ui::Image>([&g]()->ds::ui::Image*{return new ds::ui::Image(g.mEngine, ds::ui::Image::IMG_CACHE_F); }, this))
	{

		setTransparent(false);
		setSize(x, y);
		addChild(mShadeImg);
		mShadeImg.setImageFile(ds::Environment::getAppFolder("data/images/", "hi_res_forest1.jpg"));
		mShadeImg.setTransparent(false);
		mShadeImg.setOpacity(1.0f);
		mShadeImg.show();

		//Scale up the image to fit
		float w = mShadeImg.getWidth();
		float h = mShadeImg.getHeight();
		float dw = getWidth() / mShadeImg.getWidth();
		float dh = getHeight() / mShadeImg.getHeight();
		float s = (dw > dh) ? dw : dh;
		mShadeImg.setScale(s);

	}

} // namespace jci