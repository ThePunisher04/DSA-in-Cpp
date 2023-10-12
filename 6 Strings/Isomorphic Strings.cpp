//LC-205

// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int hash[256] = {0}; //mapping of each char of language 's' to language 't'
        bool istCharsMapped[256] = {0}; //stores if t[i] char is already mapped with s[i]
        //agar t ka ek char already s ke kisi char se map kar chuka hai, to hum dobara usse map nahi karenge
        
        for(int i=0 ; i<s.size() ; i++){
            if(hash[s[i]] == 0 && istCharsMapped[t[i]] == 0){
                hash[s[i]] = t[i];
                istCharsMapped[t[i]] = true;
            }
        }
        
        for(int i=0 ; i<s.size() ; i++){
            if(char(hash[s[i]]) != t[i]){
                return false;
            }
        }
        
        return true;
    }
};