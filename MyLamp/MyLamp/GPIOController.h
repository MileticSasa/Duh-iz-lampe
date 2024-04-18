#pragma once

#include <string>
#include "Definitions.h"


class GPIOController
{
public:
	GPIOController();
	virtual ~GPIOController();

	void set_direction_GPIO_pin(std::string direction, int pin);
	void export_GPIO_pin(int pin);

	void write_GPIO_pin(int pin, int value);

	void enable(int pin, GPIO_OPERATION_TYPE op_type);
};

