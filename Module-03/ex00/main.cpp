#include <iostream>
#include "Car.hpp"

int main() {
	std::cout << "=== TEST SUBSYSTEMS ===" << std::endl;


	std::cout << "--- Engine ---" << std::endl;
	Engine engine;
	engine.start();
	engine.stop();

	std::cout << std::endl << "--- Gearbox ---" << std::endl;
	Gearbox gearbox;
	gearbox.shift_gears_up();
	gearbox.shift_gears_down();
	gearbox.reverse();

	std::cout << std::endl << "--- SteeringSystem ---" << std::endl;
	SteeringSystem steering;
	steering.turn_wheel(25.5f);
	steering.straighten_wheels();

	std::cout << std::endl << "--- BrakeSystem ---" << std::endl;
	BrakeSystem brakes;
	brakes.apply_force_on_brakes(120.0f);
	brakes.apply_emergency_brakes();

	std::cout << std::endl << "--- SpeedController ---" << std::endl;
	SpeedController speed;
	speed.accelerate(60.0f);


	std::cout << std::endl << "\n=== TEST CAR (ORCHESTRATION) ===" << std::endl;

	Car car;
	car.start();
	car.accelerate(30.0f);
	car.shift_gears_up();
	car.turn_wheel(15.0f);
	car.straighten_wheels();
	car.apply_force_on_brakes(40.0f);
	car.shift_gears_down();
	car.reverse();
	car.apply_emergency_brakes();
	car.stop();

	return 0;
}
