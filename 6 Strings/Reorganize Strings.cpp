//LC-767

// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
// Return any possible rearrangement of s or return "" if not possible.


// Approach-1 : USE PRIORITY QUEUE
// Time complexity -> O(n*logn)

//Approach-2 : Greedy
// Time complexity -> O(n)
//find out the most occuring character and fill it non-adjacently, kyuki vahi sabse badi problem create kar raha h
//fill the remaining characters
//when i am placing the most occuring char , it should be placed in 1 go (ghum ke vapas nahi rakhna)
        //count hash
        //place most occuring char in 1 go
            //if(not possible) return ""
        //place others with 1 index gap

class Solution {
public:
    string reorganizeString(string s) {
        int hash[256]={0};
        
        for(int i=0; i<s.size() ; i++){
            hash[s[i]-'a']++;
        }
        
        char max_freq_char;
        int max_freq = INT_MIN;
        
        for(int i=0 ; i<26 ; i++){
            if(hash[i] > max_freq){
                max_freq = hash[i];
                max_freq_char = i + 'a';
            }
        }
        
        int index=0;
        while(max_freq > 0 && index<s.size()){
            s[index] = max_freq_char;
            max_freq--;
            index += 2;
        }
        
        if(max_freq != 0){
            return "";
        }
        
        hash[max_freq_char - 'a'] = 0;
        
        for(int i=0 ; i<26 ; i++){
            while(hash[i] > 0){
                //agar index out of bound ho gaya hai after placing ther most freq char to index vo 1 pe le aao
                index = index >= s.size() ? 1 : index;
                s[index] = i + 'a';
                hash[i]--;
                index += 2;
            }
        }
        
        return s;
    }
};