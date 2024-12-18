#include "pch.h"
#include <gtest/gtest.h>
#include "../MotorController/MotorController.h"


TEST(MotorControllerTest, RunMotorController) {
    Motor motor(5, 6);
    motor.speed = 100;  // Example value for motor speed

    MotorController motorController;
    motorController.motors.push_back(motor);
    
    // Call the Run method with a timestamp (example)
    motorController.Run(1000);

    // Add assertions to check if the motor's speed was updated or other expected behaviors
    EXPECT_EQ(motor.speed, 100);  // Example assertion, modify based on actual expected behavior
}