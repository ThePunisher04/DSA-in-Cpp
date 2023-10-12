//LC-22

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Example 1:
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]



class Solution {
public:
    void solve(vector<string> &ans, int n, int rem_open, int rem_close, string output) {
        //base case 
        if(rem_open == 0 && rem_close == 0) {
            ans.push_back(output);
            return;
        }

        //include open bracket
        if(rem_open > 0 ){
            output.push_back('(');
            solve(ans, n, rem_open-1, rem_close, output);
            //backtrack
            output.pop_back();
        }

        //include close bracket
        if(rem_close > rem_open) {
            output.push_back(')');
            solve(ans, n , rem_open, rem_close-1 ,output);
            //backtrack
            output.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        // int used_open = 0;
        // int used_close = 0;
        int rem_open = n;
        int rem_close = n;
        string output = "";
        solve(ans, n, rem_open,rem_close, output);
        return ans;
    }
};