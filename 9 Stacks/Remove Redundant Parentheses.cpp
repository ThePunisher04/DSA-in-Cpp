class Solution{
    public:

    bool findRedundantBrackets(string& s){
        stack<char> st;
        for(int i = 0 ; i < s.length() ; i++){
            char ch = s[i];
            //if ch is opening bracket or an opertor, then push it in stack
            if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
                st.push(ch);
            }
            else if(ch == ')'){
                //closing bracket
                bool isRedundant = true;
                while(st.top() != '('){
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/'){
                        //essential bracket
                        isRedundant = false;
                    }
                    st.pop();    
                }
                if(isRedundant == true)
                    return true;
                else
                    st.pop();
            }
        }
        return false; //no redundant bracket found
    }
};