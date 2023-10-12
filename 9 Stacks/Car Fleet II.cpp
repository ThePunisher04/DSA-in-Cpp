//LC-1776
// There are n cars traveling at different speeds in the same direction along a one-lane road. You are given an array cars of length n, where cars[i] = [positioni, speedi] represents:

// positioni is the distance between the ith car and the beginning of the road in meters. It is guaranteed that positioni < positioni+1.
// speedi is the initial speed of the ith car in meters per second.
// For simplicity, cars can be considered as points moving along the number line. Two cars collide when they occupy the same position. Once a car collides with another car, they unite and form a single car fleet. The cars in the formed fleet will have the same position and the same speed, which is the initial speed of the slowest car in the fleet.

// Return an array answer, where answer[i] is the time, in seconds, at which the ith car collides with the next car, or -1 if the car does not collide with the next car. Answers within 10-5 of the actual answers are accepted.

 

// Example 1:

// Input: cars = [[1,2],[2,1],[4,3],[7,2]]
// Output: [1.00000,-1.00000,3.00000,-1.00000]
// Explanation: After exactly one second, the first car will collide with the second car, and form a car fleet with speed 1 m/s. After exactly 3 seconds, the third car will collide with the fourth car, and form a car fleet with speed 2 m/s.


class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
    std::vector<double> collisionTimes(n, -1.0);
    std::stack<int> carStack;

    for (int i = n - 1; i >= 0; i--) {
        int position = cars[i][0];
        int speed = cars[i][1];

        while (!carStack.empty()) {
            int j = carStack.top();
            int nextPosition = cars[j][0];
            int nextSpeed = cars[j][1];

            // Check if the current car will catch up with the next car
            if (speed > nextSpeed) {
                double collisionTime = (nextPosition - position) / (double)(speed - nextSpeed);
                if (collisionTimes[j] == -1.0 || collisionTime <= collisionTimes[j]) {
                    collisionTimes[i] = collisionTime;
                    break;
                }
            }

            // If the current car cannot catch up with the next car, pop the next car from the stack
            carStack.pop();
        }

        // Push the current car onto the stack
        carStack.push(i);
    }

    return collisionTimes;
    }
};