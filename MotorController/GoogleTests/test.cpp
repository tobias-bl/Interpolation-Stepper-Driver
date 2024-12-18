#include "pch.h"
#include "../MotorController/Motorcontroller.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(test1, test1) {
	MotorController motorController;
	Motor motor1 = Motor(2, 3);
	//pos, speed, time
	WayPoint w1;
	WayPoint w2 = WayPoint(6400, 0, 50);
	WayPoint w3 = WayPoint(0, 0, 50);
	
	motor1.AddWaypoint(w1);
	motor1.AddWaypoint(w2);
	motor1.AddWaypoint(w3);

	motorController.AddMotor(motor1);

	int time = 0;

	while (true) {
		motorController.Run(time);
		time += 2;
	}
}