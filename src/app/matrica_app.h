#ifndef _MATRICA_APP_H_
#define _MATRICA_APP_H_

#include <cinder/app/AppBasic.h>
#include <ds/app/app.h>
#include <ds/app/event_client.h>
#include <ds/touch/touch_debug.h>

#include "app/globals.h"
#include "query/query_handler.h"

#include "util/metronome.h"


namespace matrica {
class AllData;

class Matrica : public ds::App {
public:
	Matrica();

	virtual void		mouseDown(ci::app::MouseEvent e);
	virtual void		mouseDrag(ci::app::MouseEvent e);
	virtual void		mouseUp(ci::app::MouseEvent e);
	virtual void		keyDown(ci::app::KeyEvent event);
	void				setupServer();
	void				update();

	virtual void		fileDrop(ci::app::FileDropEvent event);

private:

	void				createBeat(ci::Vec3f pos);
	void				createJuno(ci::Vec3f pos);
	void				createChime(ci::Vec3f pos);

	void				forceStartIdleMode();
	void				onAppEvent(const ds::Event&);

	// Data
	AllData				mAllData;

	// Data acquisition
	Globals				mGlobals;
	QueryHandler		mQueryHandler;

	//Idle state of the app to detect state change
	bool				mIdling;

	// Handle mouse events and simulate touch events
	ds::TouchDebug		mTouchDebug;
	Metronome			mMetronome;
	// App events can be handled here
	ds::EventClient		mEventClient;
};

} // !namespace matrica

#endif // !_MATRICA_APP_H_