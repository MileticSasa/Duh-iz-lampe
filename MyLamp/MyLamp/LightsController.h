#pragma once

#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <thread>
#include <iostream>

#include "GPIOController.h"


class LightsController
{
public:
	bool flashing;
	std::vector<int> gpio_pins;
	GPIOController gpio_controller;

	LightsController(std::vector<int> pins);
	virtual ~LightsController();

	void flashing_light(int pin);
	void stop_flashing_light();
};

