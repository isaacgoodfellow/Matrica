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
		, mBackgroundImage(ds::ui::Sprite::makeAlloc<ds::ui::Image>([&g]()->ds::ui::Image*{return new ds::ui::Image(g.mEngine, ds::ui::Image::IMG_CACHE_F); }, this))
	{

		hide();
		setTransparent(true);
		setSize(x, y);
		addChild(mBackgroundImage);
 		mBackgroundImage.setImageFile(ds::Environment::getAppFolder("data/images/", "hi_res_forest.jpg"));
 		mBackgroundImage.setTransparent(false);
 		mBackgroundImage.setOpacity(0.01f);
		mBackgroundImage.setCenter(0.0f, 1.0f);
		mBackgroundImage.setPosition(0.0f, mGlobals.mEngine.getWorldHeight());
 		mBackgroundImage.show();

		//Scale up the image to fit
		float w = mBackgroundImage.getWidth();
		float h = mBackgroundImage.getHeight();
		float dw = mGlobals.mEngine.getWorldWidth() / mBackgroundImage.getWidth();
		float dh = mGlobals.mEngine.getWorldWidth() / mBackgroundImage.getHeight();
		float s = (dw > dh) ? dw : dh;
		mBackgroundImage.setScale(s);
		mBackgroundImage.tweenOpacity(1.0f, 1.0f, 0.0f, ci::EaseInAtan());

	}

} // namespace matrica