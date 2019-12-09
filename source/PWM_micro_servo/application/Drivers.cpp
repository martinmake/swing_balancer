#include "Drivers.hpp"

using namespace Driver;

Drivers drivers;

bool Drivers::initialize(void)
{
	bool has_failed = false;

	if (!tty        .initialize()) has_failed = true;
	if (!status_leds.initialize()) has_failed = true;
	if (!micro_servo.initialize()) has_failed = true;

	#ifdef DEBUG
		tty.putchar('\n');
	#endif

	if (has_failed) return ERROR;

	return OK;
}
