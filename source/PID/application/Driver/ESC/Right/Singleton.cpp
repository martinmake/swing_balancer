#include "Driver/ESC/Right/Singleton.hpp"

namespace Driver
{
	namespace ESC
	{
		Right::Singleton right;

		namespace Right
		{
			// METHODS
			bool Singleton::initialize(void)
			{
				HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);

				INITIALIZATION_OK("RIGHT ESC");
			}
		}
	}
}
