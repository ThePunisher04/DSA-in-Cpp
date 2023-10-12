class Solution {
public:

    int solveRE(vector<int>& prices, int i, int buy){
        if(i >= prices.size()) return 0;

        int profit = 0;
        if(buy){
            int buyItProfit = -prices[i] + solveTD(prices, i+1, 0);
            int skipProfit = solveTD(prices, i+1, 1);
            profit = max(buyItProfit, skipProfit);
        }
        else{
            int sellItProfit = prices[i] + solveTD(prices, i+1, 1);
            int skipProfit = solveTD(prices, i+1, 0);
            profit = max(sellItProfit, skipProfit);
        }

        return profit;
    }

    int maxProfit(vector<int>& prices) {
        return solveRE(prices, 0, true);
    }
};







class Solution {
public:

    int solveTD(vector<int>& prices, int i, int buy, vector<vector<int>>& dp){
        if(i >= prices.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;
        if(buy){
            int buyItProfit = -prices[i] + solveTD(prices, i+1, 0, dp);
            int skipProfit = solveTD(prices, i+1, 1, dp);
            profit = max(buyItProfit, skipProfit);
        }
        else{
            int sellItProfit = prices[i] + solveTD(prices, i+1, 1, dp);
            int skipProfit = solveTD(prices, i+1, 0, dp);
            profit = max(sellItProfit, skipProfit);
        }

        dp[i][buy] = profit;
        return dp[i][buy];
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solveTD(prices, 0, true, dp);
    }
};







class Solution {
public:

    int solveBU(vector<int>& prices, vector<vector<int>>& dp){

        for(int i=prices.size() - 1 ; i>=0 ; i--){
            for(int buy=0 ; buy<2 ; buy++){
                int profit = 0;
                if(buy){
                    int buyItProfit = -prices[i] + dp[i+1][0]);
                    int skipProfit = dp[i+1][1];
                    profit = max(buyItProfit, skipProfit);
                }
                else{
                    int sellItProfit = prices[i] + dp[i+1][1];
                    int skipProfit = dp[i+1][0];
                    profit = max(sellItProfit, skipProfit);
                }
                dp[i][buy] = profit;
            }
        }
        
        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
        return solveBU(prices, dp);
    }
};








class Solution {
public:

    int solveSO(vector<int>& prices, vector<vector<int>>& dp){

        for(int i=prices.size() - 1 ; i>=0 ; i--){
            for(int buy=0 ; buy<2 ; buy++){
                int profit = 0;
                if(buy){
                    int buyItProfit = -prices[i] + dp[1][0]);
                    int skipProfit = dp[1][1];
                    profit = max(buyItProfit, skipProfit);
                }
                else{
                    int sellItProfit = prices[i] + dp[1][1];
                    int skipProfit = dp[1][0];
                    profit = max(sellItProfit, skipProfit);
                }
                dp[0][buy] = profit;
            }
            dp[1] = dp[0];
        }
        
        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(2, 0));
        return solveSO(prices, dp);
    }
};