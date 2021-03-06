#ifndef _MATRICA_APP_APPEVENTS_H_
#define _MATRICA_APP_APPEVENTS_H_

#include <ds/app/event.h>

namespace matrica {

class IdleStartedEvent : public ds::RegisteredEvent < IdleStartedEvent > {
public:
	IdleStartedEvent(){};
};

class IdleEndedEvent : public ds::RegisteredEvent < IdleEndedEvent > {
public:
	IdleEndedEvent(){};

};

class MatricaClosedEvent : public ds::RegisteredEvent < MatricaClosedEvent > {
public:
	MatricaClosedEvent(){};

};


class RequestAppExitEvent : public ds::RegisteredEvent<RequestAppExitEvent>{
public:
	RequestAppExitEvent(){};
};

} // !namespace matrica

#endif // !_MATRICA_APP_APPEVENTS_H_