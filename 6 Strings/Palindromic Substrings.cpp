//LC-647
(very important)
// Given a string s, return the number of palindromic substrings in it.
// A string is a palindrome when it reads the same backward as forward.
// A substring is a contiguous sequence of characters within the string.

//BRUTE FORCE -> TC=O(n3)
//find all the substrings using two nested loops (n2)
//then check if the substring is palindrome or not (n)

// INTUITION:- expand aroud the 'centre' index everytime
// Time complexity -> O(n2)
// look at the movement of left and right carefully
// for detecting odd length palindromic substrings, left and right start from the same position and left goes 1 step backward everytime and right goes 1 step forward everytime... in each step , the length of the substring made is ODD
// for detecting even length palindromic substrings, left ans right start from 1 unit distance appart and then left goes backward by 1 step and right goes forward by 1 step everytime... in each step , the length of the substring made is EVEN
//total palindromic substrings found = total palindromic substrings found of odd length + total palindromic substrings found of even length


class Solution {
public:
    int expandAroundIndex(string s, int left, int right) {
        int count = 0;
        //jab tak match karega, tab tak count increment kardo and i piche and j aaage kardo
        while(left >= 0 && right <s.length() && s[left] == s[right] ) {
            count++;
            left--;
            right++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int totalCount = 0;
        int n = s.length();

        for(int center=0; center<n; center++) {
            //odd
            int oddKaAns = expandAroundIndex(s, center, center);
            totalCount = totalCount + oddKaAns;
            //even
            int evenKaAns = expandAroundIndex(s,center,center+1);
            totalCount = totalCount + evenKaAns;
        }

        return totalCount;
    }
};




