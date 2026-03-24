#include <iostream>
#include "Car.hpp"

int main() {
	std::cout << "=== TEST SUBSYSTEMS ===" << std::endl;

	Engine engine;
	engine.start();
	engine.stop();

	Gearbox gearbox;
	gearbox.shift_gears_up();
	gearbox.shift_gears_down();
	gearbox.reverse();

	SteeringSystem steering;
	steering.turn_wheel(25.0f);
	steering.straighten_wheels();

	BrakeSystem brakes;
	brakes.apply_force_on_brakes(120.0f);
	brakes.apply_emergency_brakes();

	SpeedController speed;
	speed.accelerate(60.0f);

	std::cout << "\n=== TEST CAR (ORCHESTRATION) ===" << std::endl;

	Car car;
	car.start();
	car.accelerate(30.0f);
	car.shiftGearUp();
	car.turnWheel(15.0f);
	car.straightenWheels();
	car.applyBrakes(40.0f);
	car.shiftGearDown();
	car.reverse();
	car.emergencyBrakes();
	car.stop();

	return 0;
}
