// LC-14

// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".

// Input: strs = ["flower","flow","flight"]
// Output: "fl"

//Approach-1 : BRUTE FORCE
//vector mei jo first string diya hai uske first char ko main baaki ke strings ke first char se compare karta chalunga
//agar sab match kar gaye to curr char ko ans string mein include kar lunga
//agar match nahi kiya to loop se hi bahar aa jaunga

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int i=0;
        while(true){
            char curr_ch = 0;
            
            for(auto word : strs){
                if(i >= word.size()){
                    curr_ch = 0;
                    break;
                }
                
                else if(curr_ch == 0){
                    curr_ch = word[i];
                }
                
                else if(word[i] != curr_ch){
                    curr_ch = 0;
                    break;
                }
            }
            if(curr_ch == 0){
                break;
            }
            
            ans.push_back(curr_ch);
            i++;
            
        }
        return ans;
    }
};

//Approach-2 : SORTING
//sort the array then the words who have a common prefix will get grouped and come together
//all the words who dont have a common prefix will be separated from the group
//now just compare the first and last word in your array

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        //to take care of the testcases
        if(strs.size() == 0 || (strs.size() == 1) && strs[0]==""){
            return res;
        }
        //sort to group all the common prefixes
        sort(strs.begin(), strs.end());

        //now get the first and last string
        string first = strs[0];
        string last = strs[strs.size() - 1];

        int i = 0;
        while(first[i] == last[i] && i<first.length() && i <last.length()){
            res += first[i];
            i++;
        }

        return res;
    }
};