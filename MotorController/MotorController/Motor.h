#pragma once

#include <queue>
#include "WayPoint.h"

class Motor {
public:
    int pin;
    int dirPin;
    std::queue<WayPoint> wayPoints;
    WayPoint previousWaypoint;

    unsigned long timeWayPointPoped = 0;
    double currentSpeed = 0;                    //current speed
    long wantedPosition = 0;                    //calculated position
    unsigned long timeWantedPositionSet = 0;    

    Motor(int Pin, int DirPin);

    void AddWaypoint(const WayPoint& waypoint);
    void UpdateWantedPosition(unsigned long time);
};
