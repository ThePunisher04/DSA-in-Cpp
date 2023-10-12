// Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
// Since the result may be very large, so you need to return a string instead of an integer.


// Example 1:
// Input: nums = [10,2]
// Output: "210"

// Example 2:
// Input: nums = [3,30,34,5,9]
// Output: "9534330"


class Solution {
public:

    static bool myComp(string a, string b){
        string t1 = a + b;
        string t2 = b + a;
        return t1 > t2;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> snums;
        for(int i=0 ; i<nums.size() ; i++){
            snums.push_back(to_string(nums[i]));
        }

        //custom sort
        sort(snums.begin() , snums.end() , myComp);

        //edge case
        if(snums[0] == "0") return "0";

        string result = "";
        for(auto str : snums){
            result += str;
        }

        return result;
    }
};