class Solution {
public:

    int numSquaresHelper(int n){
        if(n == 0) return 0;
        if(n < 0) return 0;

        int i = 1;
        int ans = INT_MAX;
        int end = sqrt(n);
        
        while(i <= end){
            int perfectSquare = i*i;
            int numberOfSquares = 1 + numSquaresHelper(n-perfectSquare);
            if(numberOfSquares < ans){
                ans = numberOfSquares;
            }
            i++;
        }
        
        return ans;
    }
    int numSquares(int n) {
        return numSquaresHelper(n);
    }
};

//MEMOIZATION
class Solution {
public:

    int numSquaresHelper(int n, vector<int>& dp){
        if(n == 0) return 0;
        if(n < 0) return 0;

        if(dp[n] != -1){
            return dp[n];
        }

        int i = 1;
        int ans = INT_MAX;
        int end = sqrt(n);
        
        while(i <= end){
            int perfectSquare = i*i;
            int numberOfSquares = 1 + numSquaresHelper(n-perfectSquare, dp);
            if(numberOfSquares < ans){
                ans = numberOfSquares;
            }
            i++;
        }
        
        // return ans;
        dp[n] = ans;
        return dp[n];
    }
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return numSquaresHelper(n, dp);
    }
};


//TABULATION
class Solution {
public:

    int numSquaresHelper(int n){
        vector<int> dp(n+1, -1);
        dp[0] = 1;

        for(int i=1 ; i<=n ; i++){
            int start = 1;
            int ans = INT_MAX;
            int end = sqrt(i);
            
            while(start <= end){
                int perfectSquare = start * start;
                int numberOfSquares = 1 + dp[i - perfectSquare];
                if(numberOfSquares < ans){
                    ans = numberOfSquares;
                }
                start++;
            }
            dp[i] = ans;
        }
        
        return dp[n];
        
    }
    int numSquares(int n) {
        return numSquaresHelper(n) - 1;
    }
};