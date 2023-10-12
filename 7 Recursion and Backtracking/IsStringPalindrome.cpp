#include <iostream>
using namespace std;

bool isPalindrome(string &s, int i, int j)
{
    if (i > j)
    {
        return true;
    }

    if (s[i] != s[j])
    {
        return false;
    }
    isPalindrome(s, i + 1, j - 1);
    
}

int main()
{
    string s = "noon";
    int len = s.length();
    bool ans = isPalindrome(s, 0, len - 1);
    if (ans)
        cout << "(" << s << ") is a palindrome" << endl;
    else
        cout << "(" << s << ") is not a palindrome" << endl;
}