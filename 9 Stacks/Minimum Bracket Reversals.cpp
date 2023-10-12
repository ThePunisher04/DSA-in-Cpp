// Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression.
// A reversal means changing '{' to '}' or vice-versa.

// Example 1:
// Input:
// S = "}{{}}{{{"
// Output: 3
// Explanation: One way to balance is:
// "{{{}}{}}". There is no balanced sequence
// that can be formed in lesser reversals.

// Example 2:
// Input: 
// S = "{{}{{{}{{}}{{"
// Output: -1
// Explanation: There's no way we can balance
// this sequence of braces.



int countRev (string s)
{
    // if the length og the string is odd, then it is impossible to make pairs
    if(s.size() & 1){
        return -1;
    }
    
    stack<char> st;
    int count = 0;
    
    for(auto ch : s){
        if(ch == '{'){
            st.push(ch);
        }
        else{
            //closing brackets
            if(!st.empty() && st.top() == '{'){
                //match -- pair up
                st.pop();
            }
            else{
                //no match 
                st.push(ch);
            }
        }
    }
    
    //if stack is empty then it was already balanced
    //if stack is non-empty, then we have to balance it
    
    while(!st.empty()){
        char a = st.top();
        st.pop();
        char b = st.top();
        st.pop();
        
        if(a == b){
            count += 1;
        }
        else{
            count += 2;
        }
    }
    
    return count;
}