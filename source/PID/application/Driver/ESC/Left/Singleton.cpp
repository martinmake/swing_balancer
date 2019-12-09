#include "Driver/ESC/Left/Singleton.hpp"

namespace Driver
{
	namespace ESC
	{
		Left::Singleton left;

		namespace Left
		{
			// METHODS
			bool Singleton::initialize(void)
			{
				HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);

				INITIALIZATION_OK("LEFT ESC");
			}
		}
	}
}
