#ifndef _DRIVER_ESC_BASE_HPP_
#define _DRIVER_ESC_BASE_HPP_

#include "tim.h"

#include "Driver/Base.hpp"
#include "Driver/TTY.hpp"

namespace Driver
{
	namespace ESC
	{
		class Base : public Driver::Base
		{
			protected: // CONSTRUCTORS
				Base(void) = default;
			public: // DESTRUCTOR
				virtual ~Base(void) = default;

			public: // GETTERS
			public: // SETTERS
				virtual void set_pulse_width(uint16_t pulse_width) = 0;

			public: // METHODS
				virtual bool initialize(void) = 0;
		};
	}
}

#endif
