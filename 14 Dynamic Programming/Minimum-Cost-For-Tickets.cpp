class Solution {
public:
    //MEMOIZATION
    int minCostHelper(vector<int>& days, vector<int>& costs, int i, vector<int>& dp){
        //base case
        if(i >= days.size()) return 0;
        if(dp[i] != -1) return dp[i];

        //solve 1 case
        //1 day pass taken
        int cost1 = costs[0] + minCostHelper(days, costs, i+1, dp);

        //7 day pass taken
        int passEndDay = days[i] + 7 - 1;
        int j=i;

        while(j < days.size() && days[j] <= passEndDay){
            j++;
        }

        int cost7 = costs[1] + minCostHelper(days, costs, j, dp);

        //30 day pass taken
        passEndDay = days[i] + 30 - 1;
        j=i;

        while(j < days.size() && days[j] <= passEndDay){
            j++;
        }

        int cost30 = costs[2] + minCostHelper(days, costs, j, dp);

        // return min(cost1, min(cost7, cost30));
        dp[i] = min(cost1, min(cost7, cost30));
        return dp[i];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);
        return minCostHelper(days, costs, 0, dp);
    }
};


//TABULATION
class Solution {
public:

    int minCostHelper(vector<int>& days, vector<int>& costs, int i, vector<int>& dp){
        //base case
        dp[days.size()] = 0;

        //solve 1 case
        for(int i=days.size() - 1; i>=0 ; i--){
            //1 day pass taken
            int cost1 = costs[0] + dp[i+1] ;

            //7 day pass taken
            int passEndDay = days[i] + 7 - 1;
            int j=i;

            while(j < days.size() && days[j] <= passEndDay){
                j++;
            }

            int cost7 = costs[1] + dp[j];

            //30 day pass taken
            passEndDay = days[i] + 30 - 1;
            j=i;

            while(j < days.size() && days[j] <= passEndDay){
                j++;
            }

            int cost30 = costs[2] + dp[j];
        

            dp[i] = min(cost1, min(cost7, cost30));
            
        }
        return dp[0];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size() + 1, -1);
        return minCostHelper(days, costs, 0, dp);
    }
};