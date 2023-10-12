//LC-134

// There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

// Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique

 

// Example 1:

// Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
// Output: 3
// Explanation:
// Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
// Travel to station 4. Your tank = 4 - 1 + 5 = 8
// Travel to station 0. Your tank = 8 - 2 + 1 = 7
// Travel to station 1. Your tank = 7 - 3 + 2 = 6
// Travel to station 2. Your tank = 6 - 4 + 3 = 5
// Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
// Therefore, return 3 as the starting index.


//INTUITION
// aim ye hai ki agar mai kisi bhi ek station se apni journey shuru karu to vapas pura circle ghum ke vahi aa jau
// 1 litre se 1km hi ja paoge
// agar kisi i petrol pump se j petrol pump tak nahi pahunch pa rahe hai, iska matlab i+1 and j ke beech mei jitne bhi petrol pumps hai (excluding j) hum vaha se j petrol pump tak nahi pahunch payenge... jab extra petrol leke bhi nahi pahunch pa rahe to without extra petrol pump to vaise bhi nahi pahunch paoge... commonsense


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        //kitna petrol kam padgya
        int deficit = 0;
        //kitna petrol bacha hua h 
        int balance = 0;
        //circuit kaha se start krre ho
        int start = 0;

        for(int i=0; i<gas.size(); i++){
            balance += gas[i] - cost[i];
            if(balance < 0 ) {
                //yahi pr galti hogi
                deficit += abs(balance);
                // or
                // deficit += balance
                start = i+1;
                balance = 0;
            }
        }

        if(balance >= deficit ) {
            //or
            // balance + deficit >= 0
            return start;
        }
        else {
            return -1;
        }



    }
};