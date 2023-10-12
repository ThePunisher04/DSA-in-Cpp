#include <iostream>
using namespace std;

string reverse(string &s, int start, int end){
    if(start >= end){
        return s;
    }

    swap(s[start], s[end]);
    reverse(s, start+1, end-1);
}

int main(){
    string s = "vatsalya";
    string rev = s;
    int len=s.length();
    reverse(rev, 0, len-1);
    cout<<"("<<s<<") when reversed, becomes -> ("<<rev<<")"<<endl;
}