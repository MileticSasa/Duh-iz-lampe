#include "GPIOController.h"


GPIOController::GPIOController()
{

}


GPIOController::~GPIOController()
{

}


void GPIOController::set_direction_GPIO_pin(std::string direction, int pin)
{
	std::string set_direction_str = std::string("sudo echo " + direction + " > /sys/class/gpio/gpio" + std::to_string(pin) + "/direction");
	std::system(set_direction_str.c_str());
}


void GPIOController::export_GPIO_pin(int pin)
{
	std::string export_str = std::string("sudo echo " + std::to_string(pin) + " > /sys/class/gpio/export");
	std::system(export_str.c_str());
}


void GPIOController::write_GPIO_pin(int pin, int value)
{
	std::string write_cmd = std::string("sudo echo " + std::to_string(value) + " > /sys/class/gpio/gpio" + std::to_string(pin) + "/value");
	std::system(write_cmd.c_str());
}


void GPIOController::enable(int pin, GPIO_OPERATION_TYPE op_type)
{
	export_GPIO_pin(pin);

	std::string operation;

	if (op_type == GPIO_OPERATION_TYPE::READ)
		operation = "in";
	else
		operation = "out";

	set_direction_GPIO_pin(operation, pin);

}
