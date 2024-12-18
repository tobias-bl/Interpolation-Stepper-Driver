#include <list>
#include "Motor.h"
#include "PositionCalculator.h"
#include "MotorController.h"

MotorController::MotorController() {
	// Optionally, initialize motors here or leave empty
}

void MotorController::AddMotor(const Motor& motor) {
	motors.push_back(motor);
}

void MotorController::Run(unsigned long time) {
    // Iterate over motors and perform operations
    for (Motor& motor : motors) {
        motor.UpdateWantedPosition(time);
    }
}
