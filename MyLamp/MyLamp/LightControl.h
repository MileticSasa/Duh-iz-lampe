#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <thread>

#include "GPIOController.h"


void flash_the_light(int pin)
{
	srand(time(NULL));

	GPIOController gpio_controller;

	while (1)
	{
		int delay_between_flashes = rand() % 5000000 + 3000000;
		int lightning_interval = rand() % 10000 + 3000;

		std::cout << "flashes delay: " << delay_between_flashes << "\n";
		std::cout << "lightning lasts: " << lightning_interval << "\n";

		std::this_thread::sleep_for(std::chrono::microseconds(delay_between_flashes));

		gpio_controller.write_GPIO_pin(pin, 1);
		std::this_thread::sleep_for(std::chrono::microseconds(50));
		gpio_controller.write_GPIO_pin(pin, 0);
		std::this_thread::sleep_for(std::chrono::microseconds(50));
		gpio_controller.write_GPIO_pin(pin, 1);
		std::this_thread::sleep_for(std::chrono::microseconds(50));
		gpio_controller.write_GPIO_pin(pin, 0);
		std::this_thread::sleep_for(std::chrono::microseconds(50));
		gpio_controller.write_GPIO_pin(pin, 1);
		std::this_thread::sleep_for(std::chrono::microseconds(lightning_interval));
		gpio_controller.write_GPIO_pin(pin, 0);
	}
}
