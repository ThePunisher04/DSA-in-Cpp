//LC-28

// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 
// Example 1:
// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.

// Example 2:
// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.


// Approach : SLIDING WINDOW
//Time complexity -> O((n-m+1)*m) = O(n*m) = O(n2)
//needle vali string ke first char ko haystack string ke har index ke compare karate jao
//agar equal nahi hui to haystack mei aage badho
//agar equal mil gayi to next char compare karo
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        
        for(int i=0 ; i<=n-m ; i++){
            //(n-m) isiliye le rahe kyuki agar needle out of bound ho gaya to compare karane ka koi fayda nahi h
            for(int j=0 ; j<m ; j++){
                if(needle[j] != haystack[i+j]){
                    break;
                }
                if(j == m-1){
                    //j needle ke last index pe pahunch gaya, iska matlab maine needle ko pura search kar liya hai
                    return i;
                }
            }
        }
        
        return -1;
    }
};