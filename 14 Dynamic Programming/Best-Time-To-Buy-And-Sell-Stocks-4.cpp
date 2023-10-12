class Solution {
public:

    int solveRE(vector<int>& prices, int i, int buy, int limit){
        if(i >= prices.size() || limit == 0) return 0;
        
        int profit = 0;
        if(buy){
            int buyItProfit = -prices[i] + solveRE(prices, i+1, 0, limit);
            int skipProfit = solveRE(prices, i+1, 1, limit);
            profit = max(buyItProfit, skipProfit);
        }
        else{
            int sellItProfit = prices[i] + solveRE(prices, i+1, 1, limit - 1);
            int skipProfit = solveRE(prices, i+1, 0, limit);
            profit = max(sellItProfit, skipProfit);
        }

        return profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        return solveRE(prices, 0, 1, k);
    }
};






class Solution {
public:

    int solveTD(vector<int>& prices, int i, int buy, int limit, vector<vector<vector<int>>>& dp){
        if(i >= prices.size() || limit == 0) return 0;
        if(dp[i][buy][limit] != -1) return dp[i][buy][limit];

        int profit = 0;
        if(buy){
            int buyItProfit = -prices[i] + solveTD(prices, i+1, 0, limit, dp);
            int skipProfit = solveTD(prices, i+1, 1, limit, dp);
            profit = max(buyItProfit, skipProfit);
        }
        else{
            int sellItProfit = prices[i] + solveTD(prices, i+1, 1, limit - 1, dp);
            int skipProfit = solveTD(prices, i+1, 0, limit, dp);
            profit = max(sellItProfit, skipProfit);
        }

        dp[i][buy][limit] = profit;
        return dp[i][buy][limit];
    }

    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solveTD(prices, 0, 1, k, dp);
    }
};







class Solution {
public:

    int solveBU(vector<int>& prices, int i, int buy, int k, vector<vector<vector<int>>>& dp){
        for(int i=prices.size() - 1; i>=0 ; i--){
            for(int buy = 0 ; buy < 2 ; buy++){
                for(int limit = 1 ; limit < k+1; limit++){
                    int profit = 0;
                    if(buy){
                        int buyItProfit = -prices[i] + dp[i+1][0][limit];
                        int skipProfit = dp[i+1][1][limit];
                        profit = max(buyItProfit, skipProfit);
                    }
                    else{
                        int sellItProfit = prices[i] + dp[i+1][1][limit-1];
                        int skipProfit = dp[i+1][0][limit];
                        profit = max(sellItProfit, skipProfit);
                    }

                    dp[i][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][k];        
    }

    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        return solveBU(prices, 0, 1, k, dp);
    }
};






class Solution {
public:

    int solveSO(vector<int>& prices, int i, int buy, int k, vector<vector<vector<int>>>& dp){
        for(int i=prices.size() - 1; i>=0 ; i--){
            for(int buy = 0 ; buy < 2 ; buy++){
                for(int limit = 1 ; limit < k+1; limit++){
                    int profit = 0;
                    if(buy){
                        int buyItProfit = -prices[i] + dp[1][0][limit];
                        int skipProfit = dp[1][1][limit];
                        profit = max(buyItProfit, skipProfit);
                    }
                    else{
                        int sellItProfit = prices[i] + dp[1][1][limit-1];
                        int skipProfit = dp[1][0][limit];
                        profit = max(sellItProfit, skipProfit);
                    }

                    dp[0][buy][limit] = profit;
                }
            }
            dp[1] = dp[0];
        }
        return dp[0][1][k];        
    }

    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(2, vector<int>(k+1, 0)));
        return solveSO(prices, 0, 1, k, dp);
    }
};