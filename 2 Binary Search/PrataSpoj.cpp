// IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting. The subcommittee members are asked to go to food connection and get P (P<=1000) pratas packed for the function. The stall has L cooks (L<=50) and each cook has a rank R (1<=R<=8). A cook with a rank R can cook 1 prata in the first R minutes 1 more prata in the next 2R minutes, 1 more prata in 3R minutes and so on (he can only cook a complete prata) (For example if a cook is ranked 2, he will cook one prata in 2 minutes one more prata in the next 4 mins an one more in the next 6 minutes hence in total 12 minutes he cooks 3 pratas in 13 minutes also he can cook only 3 pratas as he does not have enough time for the 4th prata). The webmaster wants to know the minimum time to get the order done. Please write a program to help him out.

#include <bits/stdc++.h>
#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

bool isPossibleSolution(vector<int> cooksRanks, int P, int mid)
{
   int prataMade = 0;
   for(int i=0; i<cooksRanks.size() ;i++){
        int rank = cooksRanks[i];
        int j=1;
        int timeTaken = 0;

        while(true){
            if(timeTaken + j*rank <= mid){
                prataMade++;
                timeTaken += j*rank;
                j++;
            }
            else{
                break;
            }
        }
   }
   if(prataMade < P)
        return false;
   else
        return true;
}

int minTimeToCompleteOrder(vector<int> cooksRanks, int P)
{
    int start = 0;
    int ans = -1;
    int highestRank = *max_element(cooksRanks.begin(), cooksRanks.end());
    int maxTime = highestRank * ((P * (P - 1)) / 2);
    int end = maxTime;

    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (isPossibleSolution(cooksRanks, P, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }

    return ans;
}

int main()
{
    vector<int> cooksRanks = {1,2,3,4};
    int P = 10;
    int ans = minTimeToCompleteOrder(cooksRanks, P);
    cout<<"Min time in which order can be completed is : "<<ans<<endl;
    return 0;
}