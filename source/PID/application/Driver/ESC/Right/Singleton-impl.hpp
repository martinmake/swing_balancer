inline void Singleton::set_pulse_width(uint16_t pulse_width)
{
	htim4.Instance->CCR2 = pulse_width;
}
