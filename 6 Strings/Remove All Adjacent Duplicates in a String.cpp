// LC-1047

// You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.
// We repeatedly make duplicate removals on s until we no longer can.
// Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.


class Solution {
    int hasDupAt(string s){
        int index = -1;
        for(int i=0 ; i<s.length() ; i++){
            if(s[i]==s[i+1]){
                index = i;
                break;
            }
        }
        return index;
    }
public:
    string removeDuplicates(string s) {
        while(hasDupAt(s) >= 0){
            s.erase(hasDupAt(s), 2);
        }
        return s;
    }
};

// OR

class solution{
    public:
    string removeDuplicates(string& s){
        string ans = "";
        for(int i=0; i<s.length(); i++){
            if(ans.length() > 0 && s[i] == ans[ans.length() - 1]){
                ans.pop_back();
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};