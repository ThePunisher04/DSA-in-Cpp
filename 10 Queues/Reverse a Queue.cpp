#include <iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseQueue(queue<int> &q) {
        stack<int> s;

        //step 1: put all elements of q into s
        while(!q.empty() ) {
                int element = q.front();
                q.pop();

                s.push(element);
        }

        //step2: put all element from stackinto q
        while(!s.empty()) {
                int element = s.top();
                s.pop();

                q.push(element);
        }
}

void reverseQueueRecursion(queue<int> & q) {
        //Base case
        if(q.empty()) 
                return;

        //step A
        int temp = q.front();
        q.pop();

        //step B
        reverseQueueRecursion(q);

        //step C;
        q.push(temp);
}

// TC = O(n)
// SC = O(n)