#include <FOSL/Math/PID.hpp>

#include "Drivers.hpp"

#define THROTTLE_MAXIMUM (1100)
#define THROTTLE_MINIMUM (1050)
#define THROTTLE_DIFFERENCE (THROTTLE_MAXIMUM - THROTTLE_MINIMUM)
#define THROTTLE_MEDIUM (THROTTLE_MINIMUM + THROTTLE_DIFFERENCE / 2)

// #define KP ((float) 3.0)
// #define KI ((float) 2.0)
// #define KD ((float) 7.0)
// #define INTEGRATOR_LIMIT (10.0)

#define KP ((float)  5.0)
#define KI ((float)  3.0)
#define KD ((float) 10.0)
#define INTEGRATOR_LIMIT (20.0)

using namespace FOSL::TTY;
using namespace Driver;

extern "C" int application(void)
{
	drivers.initialize();

	ESC::left .set_pulse_width(1000);
	ESC::right.set_pulse_width(1000);

	tty.puts("BEGIN COUNTDOWN!");
	HAL_Delay(1000);
	tty.puts("THREE!");
	HAL_Delay(1000);
	tty.puts("TWO!");
	HAL_Delay(1000);
	tty.puts("ONE!");
	HAL_Delay(1000);

	uint16_t pulse_width = THROTTLE_MINIMUM;
	while (pulse_width <= THROTTLE_MEDIUM)
	{
		ESC::left .set_pulse_width(pulse_width);
		ESC::right.set_pulse_width(pulse_width);
		tty.printf("%u\n", pulse_width);
		HAL_Delay(50);
		pulse_width++;
	}

	PID::Float pid(KP, KI, KD, INTEGRATOR_LIMIT);
	HAL_TIM_Base_Start(&htim1);
	while (true)
	{
		// static int32_t angle_offset = 0;

		// float error = 0.0;
		// uint16_t delta_time = 0;
		// uint16_t start_time = htim1.Instance->CNT;

		imu.read_angular_rate();
		// angle_offset += imu.angular_rate.x;// delta_time;

		// float controll_signal = pid(angle_offset);
		float controll_signal = pid(imu.angular_rate.x);

		controll_signal = map_to(controll_signal, -100, 100, -1, 1);

		uint16_t  left_pulse_width = THROTTLE_MEDIUM + (THROTTLE_DIFFERENCE / 2) * (-controll_signal);
		uint16_t right_pulse_width = THROTTLE_MEDIUM + (THROTTLE_DIFFERENCE / 2) * (+controll_signal);

		 left_pulse_width += 10;
		right_pulse_width -= 10;

		 left_pulse_width = clamp( left_pulse_width, THROTTLE_MINIMUM, THROTTLE_MAXIMUM);
		right_pulse_width = clamp(right_pulse_width, THROTTLE_MINIMUM, THROTTLE_MAXIMUM);

		ESC::left .set_pulse_width( left_pulse_width);
		ESC::right.set_pulse_width(right_pulse_width);
	}
}

extern "C" void key1_handler(void)
{
		ESC::left .set_pulse_width(1000);
		ESC::right.set_pulse_width(1000);
		while (true) {}
}
