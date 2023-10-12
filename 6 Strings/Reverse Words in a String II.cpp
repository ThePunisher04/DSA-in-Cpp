#include <bits/stdc++.h>
#include <vector>
using namespace std;

void display(vector<string> &s)
{

    cout << "Your string is :-" << endl;

    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
}

string reverseWord(string s)
{
    int start = 0;
    int end = s.length() - 1;

    while (start <= end)
    {
        swap(s[start++], s[end--]);
    }

    return s;
}

int main()
{
    string s = "my name is khan";
    vector<string> word;
    string str = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            string temp = reverseWord(str);
            word.push_back(temp);
            str = "";
        }
        else
        {
            str = str + s[i];
        }
    }
    
    //for the last word in the input string
    string temp = reverseWord(str);
    word.push_back(temp);
    display(word);

    
}