#include "Motor.h"
#include "PositionCalculator.h"

Motor::Motor(int Pin, int DirPin)
    : pin(Pin), dirPin(DirPin), timeWayPointPoped(0), currentSpeed(0), wantedPosition(0), timeWantedPositionSet(0) {

}

void Motor::AddWaypoint(const WayPoint& waypoint) {
    wayPoints.push(waypoint);
}

void Motor::UpdateWantedPosition(unsigned long time) {


    if (!wayPoints.empty()) {
        WayPoint currentWaypoint = wayPoints.front();
        if (time >= timeWayPointPoped + currentWaypoint.time) {
            previousWaypoint = currentWaypoint;
            wayPoints.pop();
            timeWayPointPoped = time;
        }
        else {
            if (!wayPoints.empty()) {
                    unsigned long timeDiv = time - timeWayPointPoped; 

                    double pos = PositionCalculator::CalculatePosition(
                        previousWaypoint.endPosition,  
                        currentWaypoint.time,
                        currentWaypoint.endPosition,
                        previousWaypoint.endPosition, 
                        currentWaypoint.endSpeed,
                        timeDiv
                    );
                    long newPosition = static_cast<long>(pos);
                    if (pos != wantedPosition) {            
                        if (timeDiv > 0) {
                            currentSpeed = (pos - wantedPosition) / timeDiv;
                        }
                        else {
                            currentSpeed = 0;
                        }
                        wantedPosition = newPosition;
                        timeWantedPositionSet = time;
                    }
                }
        }
    }
}
