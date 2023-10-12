#include <bits/stdc++.h>
#include <vector>
using namespace std;

char maxFreqChar(string &str)
{
    int freq[26] = {0};

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            // uppercase letter
            int index = str[i] - 'A';
            freq[index]++;
        }
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            // lowercase letter
            int index = str[i] - 'a';
            freq[index]++;
        }
    }

    int maxi = -1;
    int ans = -1;
    for(int i = 0; i < 26 ; i++){
        if(maxi < freq[i]){
            ans = i;
            maxi = freq[i];
        }
    }

    return ans+'a';

}

int main()
{
    string str = "committee";

    char ch = maxFreqChar(str);

    cout<<"Character with maximum frequency is : " << ch <<endl;

    // cout << "Character with maximum frequency is : " << ans.second << " with a frequency of : "<< ans.first << endl;
}