#ifndef _DRIVER_ESC_RIGHT_SINGLETON_HPP_
#define _DRIVER_ESC_RIGHT_SINGLETON_HPP_

#include "Driver/ESC/Base.hpp"

namespace Driver
{
	namespace ESC
	{
		namespace Right
		{
			class Singleton : public Driver::ESC::Base
			{
				public: // CONSTRUCTORS
					Singleton(void) = default;
				public: // DESTRUCTOR
					~Singleton(void) = default;

				public: // GETTERS
				public: // SETTERS
					void set_pulse_width(uint16_t pulse_width) override;

				public: // METHODS
					bool initialize(void) override;
			};

			#include "Driver/ESC/Right/Singleton-impl.hpp"
		}

		extern Right::Singleton right;
	}
}

#endif
