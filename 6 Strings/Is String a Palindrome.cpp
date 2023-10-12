#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str){
    int s=0;
    int e=str.length()-1;

    while(s<=e){
        if(str[s] != str[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;
}

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    int len = str.length();

    if(isPalindrome(str)){
        cout<<"Palindrome"<<endl;
    }
    else{
        cout<<"Not a Palindrome"<<endl;
    }

    return 0;
}