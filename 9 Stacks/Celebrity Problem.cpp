// A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
// A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
// Note: Follow 0 based indexing.
// Follow Up: Can you optimize it to O(N)
 

// Example 1:

// Input:
// N = 3
// M[][] = {{0 1 0},
//          {0 0 0}, 
//          {0 1 0}}
// Output: 1
// Explanation: 0th and 2nd person both
// know 1. Therefore, 1 is the celebrity. 



class Solution 
{
    //Time Complexity = O(N)
    //Space Complexity = O(N)
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;

        //Step-1 : Push allthe persons into the stack
        for(int i=0; i<n; i++){
            st.push(i);
        } 

        //Step-2 : 
        while(st.size() != 1){
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();

            if(M[a][b] == 1){
                // 'a' knows 'b' -> a is not a celebrity -> b might be a celebrity -> push b
                st.push(b);
            }
            else{
                // 'a' does not knows 'b' -> a might not a celebrity -> b is not a celebrity coz a doesn't knows b -> push a
                st.push(a);
            }
        }

        //stack only has 1 person -> check if he is the celebrity
        int mightBeCelebrity = st.top(); st.pop();

        //check if mightBeCelebrity person doesnt know anyone
        for(int i=0; i<n; i++){
            //row check
            if(M[mightBeCelebrity][i] == 1){
                return -1;
            }
        }

        //check if everyone knows mightBeCelebrity person
        for(int i=0; i<n ; i++){
            //column check
            if(M[i][mightBeCelebrity] == 0 && i != mightBeCelebrity){
                return -1;
            }
        }

        //mightBeCelebrity person is actually the celebrity
        return mightBeCelebrity;
    }
};




class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& matrix, int N) 
    {
        // code here 
        int n = matrix.size();

    // Start with assuming the first person as the celebrity candidate
    int celebrity = 0;

    // Check if the celebrity candidate knows anyone or someone knows the candidate
    for (int i = 1; i < n; i++) {
        if (matrix[celebrity][i] == 1) {
            celebrity = i;
        }
    }

    // Check if the celebrity candidate is actually a celebrity
    for (int i = 0; i < n; i++) {
        // Skip if the person is the celebrity candidate
        if (i == celebrity) {
            continue;
        }

        // If the celebrity candidate knows anyone or someone doesn't know the candidate,
        // the candidate is not a celebrity
        if (matrix[celebrity][i] == 1 || matrix[i][celebrity] == 0) {
            return -1;
        }
    }

    return celebrity;
    }
};



