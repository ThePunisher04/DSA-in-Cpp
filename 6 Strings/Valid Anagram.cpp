//LC-242

// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Approach-1 : Sorting
// Time complexity -> O(n*logn)
// after sorting, compare the 2 strings
// if they are equal , they are anagrams
// if they are not equal , they are not anagrams

// Approach-2 : Hashmap
// Time complexity -> O(n+m) where n is size of s string and m is size of t string = O(n)
// for string s, make a frequency hashmap to store all the number of occurences of a char
// for string t, make a frequency hashmap to store all the number of occurences of a char
// compare both the hashmaps
// if they are equal , they are anagrams
// if they are not equal , they are not anagrams


class Solution {
public:
    bool isAnagram(string s, string t) {
        int freqTable[256] = {0};
        
        for(int i=0 ; i<s.size() ; i++){
            freqTable[s[i]]++;             //internal typecasting
            //freqTable[(int)s[i]]++;      //external typecasting
        }
        
        for(int i=0 ; i<t.size() ; i++){
            freqTable[t[i]]--;
        }
        
        for(int i=0 ; i<256 ; i++){
            if(freqTable[i] != 0){
                return false;
                
            }
        }
        
        return true;
    }
};