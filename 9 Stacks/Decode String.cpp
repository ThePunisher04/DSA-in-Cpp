//LC-394

// Given an encoded string, return its decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

// You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

// The test cases are generated so that the length of the output will never exceed 105.

 

// Example 1:
// Input: s = "3[a]2[bc]"
// Output: "aaabcbc"

// Example 2:
// Input: s = "3[a2[c]]"
// Output: "accaccacc"

// Example 3:
// Input: s = "2[abc]3[cd]ef"
// Output: "abcabccdcdcdef"


class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(auto ch : s){
            if(ch == ']'){
                string stringToRepeat = "";
                //creating the string that we want to repeat
                while(!st.empty() && st.top() != "["){
                    string top = st.top();
                    stringToRepeat += top;
                    st.pop();
                }
                st.pop(); //popping the opening bracket [
                string numericTimes = "";
                while(!st.empty() && isDigit(st.top()[0])){
                    numericTimes += st.top();
                    st.pop();
                }
                reverse(numericTimes.begin(), numericTimes.end());
                int n = stoi(numericTimes);

                //final decoding 
                string currentDecode = "";
                while(n--){
                    currentDecode+= stringToRepeat;
                }
                st.push(currentDecode);
            }
            else{
                //not a closing bracket ]
                string temp (1, ch); // converting char data type to string data type
                st.push(temp);
            }
        }
        //forming our answer
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};