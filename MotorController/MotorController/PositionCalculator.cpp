#include "PositionCalculator.h"


// Calculate position based on provided parameters
double PositionCalculator::CalculatePosition(
    long startPosition, long time, long endPos,
    long m1, long m2, long x) {
    // Ensure time is not zero to avoid division by zero
    if (time == 0 || x == 0) {
        return startPosition;
    }
    else if (x == time) {
        return endPos;
    }

    // Convert time and x to double for precision
    double timeInSeconds = static_cast<double>(time);
    double currentTimeInSeconds = static_cast<double> (x);

    // Calculate fractional time position
    double t = currentTimeInSeconds / timeInSeconds;  // Fraction of the total time in seconds
    double t2 = t * t;                                // Square of the fractional time
    double t3 = t2 * t;                               // Cube of the fractional time

    // Use a cubic interpolation formula
    double a0 = startPosition;
    double a1 = m1;                                             // Initial velocity (m1)
    double a2 = -3 * startPosition + 3 * endPos - 2 * m1 - m2;  // Based on initial & final position + velocities
    double a3 = 2 * startPosition - 2 * endPos + m1 + m2;       // Based on initial & final position + velocities

    // Calculate position using the cubic polynomial
    double position = a0 + a1 * t + a2 * t2 + a3 * t3;

    // Return the calculated position rounded to the nearest integer (no commas needed)
    return position;
}

