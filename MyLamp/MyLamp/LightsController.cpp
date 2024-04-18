#include "LightsController.h"


LightsController::LightsController(std::vector<int> pins)
{
	flashing = true;
	this->gpio_pins = pins;
	gpio_controller = GPIOController();

	for (int i = 0; i < gpio_pins.size(); i++)
	{
		gpio_controller.enable(gpio_pins[i], GPIO_OPERATION_TYPE::WRITE);
	}
}


LightsController::~LightsController()
{
	
}


void LightsController::flashing_light(int pin)
{
	srand(time(NULL));

	while (1)
	{
		int delay_between_flashes = rand() % 2000000 + 1000000;
		int lightning_interval = rand() % 300000 + 50000;

		std::cout << "flashes delay: " << delay_between_flashes << "\n";
		std::cout << "lightning lasts: " << lightning_interval << "\n";

		std::this_thread::sleep_for(std::chrono::microseconds(delay_between_flashes));

		gpio_controller.write_GPIO_pin(pin, 1);
		std::this_thread::sleep_for(std::chrono::microseconds(lightning_interval));
	}
}


void LightsController::stop_flashing_light()
{
	flashing = false;
}
