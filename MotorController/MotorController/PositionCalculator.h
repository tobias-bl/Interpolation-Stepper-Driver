#pragma once

class PositionCalculator {
public:
    /**
     * Calculate the position based on cubic interpolation.
     *
     * @param startPosition Initial position.
     * @param time Total time of the motion.
     * @param endPos Final position.
     * @param m1 Initial velocity.
     * @param m2 Final velocity.
     * @param x Current time elapsed.
     * @return The calculated position as a long integer.
     */
    static double CalculatePosition(
        long startPosition, long time, long endPos,
        long m1, long m2, long x);
};