#pragma once
#ifndef JCI_UTIL_TIMESECONDS_H__
#define JCI_UTIL_TIMESECONDS_H__

#include <Poco/Timestamp.h>

namespace ds {
	namespace time {

		/**
		* \class ds::time::Seconds
		* \brief Basic timer. I discovered at home that boost::timer is
		* completely non-portable across OSs (in terms of timing seconds;
		* it seems to be timing an abstract notion of CPU time), so use this.
		*/
		class Seconds {
		public:
			Seconds();

			void						restart();
			// Restart with the supplied offset. If this value is positive,
			// you will get negative elapsed values.
			void						restart(const double offset);
			double						elapsed();

		private:
			Poco::Timestamp::TimeVal	mStart;
		};

	} // namespace time
} // namespace ds

#endif // JCI_UTIL_TIMESECONDS_H__