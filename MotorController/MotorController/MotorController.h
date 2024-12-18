#pragma once

#include <list>
#include "Motor.h"
#include "PositionCalculator.h"

class MotorController {
public:
    // Constructor to initialize the motor controller with a list of motors
    MotorController();

    //updates all motors
    void Run(unsigned long time);

    void AddMotor(const Motor& motor);

    std::vector<Motor> motors;
};
