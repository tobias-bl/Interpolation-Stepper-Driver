#include "WayPoint.h"

WayPoint::WayPoint() {
    time = 0;
    endPosition = 0;
    endSpeed = 0;
}

WayPoint::WayPoint(long position, double speed, long ti) {
    endPosition = position;
    endSpeed = speed;
    time = ti;
}
