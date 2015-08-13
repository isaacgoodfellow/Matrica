#ifndef _MATRICA_APP_H_
#define _MATRICA_APP_H_

#include <cinder/app/AppBasic.h>
#include <ds/app/app.h>

#include "app/globals.h"
#include "query/query_handler.h"

namespace matrica {
class AllData;

class Matrica : public ds::App {
public:
	Matrica();

	virtual void		keyDown(ci::app::KeyEvent event);
	void				setupServer();
	void				update();
private:
	typedef ds::App		inherited;

	// Data
	AllData				mAllData;

	// Data acquisition
	Globals				mGlobals;
	QueryHandler		mQueryHandler;

	//Idle state of the app to detect state change
	bool				mIdling;


	void				moveCamera(const ci::Vec3f& deltaMove);
};

} // !namespace matrica

#endif // !_MATRICA_APP_H_