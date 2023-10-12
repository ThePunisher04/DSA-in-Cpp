#include <iostream>
#include<stack>
using namespace std;

void print(stack<int> s){
        while(!s.empty()){
                cout<<s.top()<<" ";
                s.pop();
        }
        cout<<endl;
}

void insertAtBottom(stack<int> &s, int target) {
        
        //base case
        if(s.empty()) {
                s.push(target);
                return;
        }

        int topElement = s.top();
        s.pop();
        //rec cal
        insertAtBottom(s, target);
        //BT
        s.push(topElement);
        
}

int main() {
        stack<int> s;

        s.push(11);
        s.push(23);
        s.push(35);
        s.push(41);
        s.push(58);
        s.push(62);
        s.push(70);

        print(s);
        insertAtBottom(s, 69);
        print(s);

        return 0;
}