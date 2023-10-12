#include <bits/stdc++.h> 
using namespace std; 

// Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order without using any extra space. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

// Example 1:

// Input: 
// n = 4, arr1[] = [1 3 5 7] 
// m = 5, arr2[] = [0 2 6 8 9]
// Output: 
// arr1[] = [0 1 2 3]
// arr2[] = [5 6 7 8 9]
// Explanation:
// After merging the two 
// non-decreasing arrays, we get, 
// 0 1 2 3 5 6 7 8 9.


class Solution {
    //LC--912
    // Approach2 : GAP METHOD 
    //Time complexity -> O(n*logn)
    //Space complexity -> O(1)
public:
    void mergeInPlace(vector<int>&v, int start, int mid, int end){
        int total_len = end-start+1;
        int gap = (total_len / 2) + (total_len % 2);
        while(gap > 0){
            int i = start;
            int j = start + gap;
            while(j <= end){
                if(v[i] > v[j]){
                    swap(v[i],v[j]);
                }
                ++i;
                ++j;
            }
            gap = gap <=1 ? 0 : (gap / 2) + (gap % 2);
        }
    }
    
    void mergeSort(vector<int>&v , int start, int end){
        if(start >= end){
            return ;
        }
        int mid = (start + end) / 2;
        mergeSort(v,start,mid);
        mergeSort(v,mid+1,end);
        mergeInPlace(v,start,mid,end);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};