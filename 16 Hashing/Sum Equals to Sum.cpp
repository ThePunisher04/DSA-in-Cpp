// Given an array A of N integers. The task is to find if there are two pairs (a, b) and (c, d) such that a+b = c+d.

// Example 1:

// Input:N=7 A[] = {3, 4, 7, 1, 2, 9, 8} Output: 1Explanation:(3, 7) and (9, 1) are the pairs whosesum are equal.  

class Solution
{
  public:
    int findPairs(long long a[], long long n)
    {
        //code here.
        unordered_map<int, bool> map;
        //generate pairs
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sum = a[i] + a[j];
                if(map.find(sum) != map.end())
                    return true;
                else
                    map[sum] = true;
            }
        }
        return false;
    }
};
