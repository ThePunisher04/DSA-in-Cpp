#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getLength(char ch[])
{
    int count = 0;
    for (int i = 0; ch[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

void reverse(char ch[], int n){
    int s=0;
    int e=n-1;

    while(s<=e){
        swap(ch[s],ch[e]);
        s++;
        e--;
    }
}

int main()
{
    char ch[200];
    cout << "Enter a string: ";
    cin >> ch;

    int len = getLength(ch);
    reverse(ch,len);

    cout << "Reverse string is : " << ch << endl;

    return 0;
}