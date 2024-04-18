#include <iostream>
#include <thread>
#include <vector>

#include "LightControl.h"
#include "LightsController.h"

#define FIRST_PIN   4
#define SECOND_PIN  17
#define THIRD_PIN   26

using namespace std;


int main()
{
    cout << "Hello wordl!!!" << endl;

    vector<int> pins = vector<int>();
    pins.push_back(FIRST_PIN);
    pins.push_back(SECOND_PIN);
    pins.push_back(THIRD_PIN);

    LightsController controller = LightsController(pins);

    vector<thread> light_control_threads = vector<thread>();

    for (unsigned int i = 0; i < pins.size(); i++)
    {
        thread t(flash_the_light, pins[i]);
        light_control_threads.push_back(move(t));
    }

    for (unsigned int i = 0; i < pins.size(); i++)
    {
        light_control_threads[i].join();
    }
    
    return 0;
}