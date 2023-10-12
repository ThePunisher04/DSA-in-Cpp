// LC-539
// Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.


// Example 1:
// Input: timePoints = ["23:59","00:00"]
// Output: 1

// Example 2:
// Input: timePoints = ["00:00","23:59","00:00"]
// Output: 0

// Example 3:
// Input: timePoints = ["12:10","10:15","13:15","17:20","18:00","19:47","23:59"]
          //minutes[] = {730,    615,    795,    1040,   1080,   1187,   1439}
          //sort them
          //minutes[] = {615,    730,    795,    1040,   1080,   1187,   1439}
// Output: 40


// INTUITION:-
//Time is circular in nature. 
//00:00 in HH:MM format when converted to minutes by standard maths comes out to be o minutes, but in reality it is 1440 minutes... both are the same... therefore we have to somehow map this 0 minutes to 1440 minutes
// convert the given time points array in HH:MM format to just minutes (use a separate vector)
        //use stoi function to convert string to integer
        //multiply HH by 60 then add MM to it
        //push this number in minutes vector
// now sort this vector for simplicity [TC = O(n*logn)]
        // if we dont sort the vector, then TC would be O(n2) for n2 comparisons, plus it would be tedious and untidy
// calculate time diff between adjacent elements... notice as time is circular, you would miss out comparing the first element to the last element by this approach
// calculate time diff between the first and the last element
// return the min time diff


class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        //step-1: convert hours into minutes
        vector<int> minutes;
        
        for(int i=0; i<timePoints.size() ; i++){
            string curr = timePoints[i];
            int hours = stoi(curr.substr(0,2));
            int mins = stoi(curr.substr(3,2));
            int totalMinutes = hours*60 + mins;
            minutes.push_back(totalMinutes);
        }
        
        //step-2: sort
        sort(minutes.begin(),minutes.end());
        
        //step03: calc. diff. and min. diff.
        int mini = INT_MAX;
        int n = minutes.size();
        
        for(int i=0 ; i<n-1 ; i++){
            int diff = minutes[i+1] - minutes[i];
            mini = min(mini,diff);
        }
        
        //THIS IS THE GAME
        //minutes[0] mei hi 1440 isiliye add kar rahe kyuki vector sorted hai
        int lastDiff1 = (minutes[0]+1440) - minutes[n-1];
        int lastDiff2 = minutes[n-1] - minutes[0];
        int lastDiff = min(lastDiff1,lastDiff2);
        mini = min(mini,lastDiff);
        
        return mini;
    }
};