//LC-1155

// You have n dice, and each die has k faces numbered from 1 to k.

// Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.

class Solution {
    //Time complexity -> O(k^n) exponential
    //Space complexity -> O(n+1) = O(n)
public:
    long long int MOD = 1000000007;

    int numRollsToTarget(int n, int k , int target) {
        //base cases
        if(target < 0) return 0;
        if(n == 0 && target == 0) return 1;
        if(n == 0 && target != 0) return 0;
        if(n !=0 && target == 0) return 0;

        int ans = 0;
        for(int i=1; i<=k; i++) {
            ans += numRollsToTarget(n-1, k , target-i);
        }
        return ans;
    }
};