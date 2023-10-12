// LC-345

// Given a string s, reverse only all the vowels in the string and return it.
// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.


class Solution {
public:
    
    bool isVowel(char ch){
        ch = tolower(ch);
        return ch=='a'|| ch=='e'|| ch=='i'|| ch=='o'|| ch=='u' ;
    }
    
    string reverseVowels(string s) {
        int l=0;
        int h=s.size()-1;
        
        while(l<h){
            if(isVowel(s[l]) && isVowel(s[h])){
                swap(s[l],s[h]);
                l++;
                h--;
            }
            else if(!isVowel(s[l]))
                l++;
            else
                h--;
        }
        
        return s;
    }
};