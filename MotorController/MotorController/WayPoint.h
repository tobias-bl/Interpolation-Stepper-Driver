#pragma once

class WayPoint {
public:
    unsigned long time;
    double endSpeed;
    long endPosition;

    WayPoint(); 
    WayPoint(long position, double speed, long ti); 
};