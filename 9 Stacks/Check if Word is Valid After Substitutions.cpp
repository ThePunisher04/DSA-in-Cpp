// Given a string s, determine if it is valid.

// A string s is valid if, starting with an empty string t = "", you can transform t into s after performing the following operation any number of times:

// Insert string "abc" into any position in t. More formally, t becomes tleft + "abc" + tright, where t == tleft + tright. Note that tleft and tright may be empty.
// Return true if s is a valid string, otherwise, return false.

 

// Example 1:
// Input: s = "aabcbc"
// Output: true
// Explanation:
// "" -> "abc" -> "aabcbc"
// Thus, "aabcbc" is valid.

// Example 2:
// Input: s = "abcabcababcc"
// Output: true
// Explanation:
// "" -> "abc" -> "abcabc" -> "abcabcabc" -> "abcabcababcc"
// Thus, "abcabcababcc" is valid.

// Example 3:
// Input: s = "abccba"
// Output: false
// Explanation: It is impossible to get "abccba" using the operation.


class Solution {
    //Time Complexity = O(N)
    //Space Complexity = O(N)
public:
    bool isValid(string s) {
        if(s[0] != 'a'){
            return false;
        }
        //we are making pairs of "abc"
        stack<char> st;
        for(char ch : s){
            if(ch == 'a'){
                //a ko sidha push kardo
                st.push(ch);
            }
            else{
                if(ch == 'b'){
                    if(!st.empty() && st.top() == 'a'){
                        //top pe 'a' pada hua hai
                        st.push(ch);
                    }
                    else{
                        // top pe 'a' nahi tha
                        return false;
                    }
                }
                else{
                    // 'c' aaya hai
                    if(!st.empty() && st.top() == 'b'){
                        //top pe 'b' pada hua hai
                        st.pop();
                        if(!st.empty() && st.top() == 'a'){
                            //top pe 'a' pada hua hai
                            //pair mil gaya
                            st.pop();
                        }
                        else{
                            return false;
                        }
                    }
                    else{
                        //top pe 'b' nahi pada hua
                        return false;
                    }
                }
            }
        }
        return st.empty();
    }
};




class Solution {
    //Time Complexity = O(N2)
public:
    bool isValid(string s) {
        if(s.size() == 0){
            return true;
        }

        int fnd = s.find("abc");
        if(fnd != string::npos){
            string tleft = s.substr(0, fnd);
            string tright = s.substr(fnd+3, s.size());
            return isValid(tleft + tright);
        }

        return false;
    }
};