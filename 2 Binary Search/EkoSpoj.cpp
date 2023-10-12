// Lumberjack Mirko needs to chop down M metres of wood. It is an easy job for him since he has a nifty new woodcutting machine that can take down forests like wildfire. However, Mirko is only allowed to cut a single row of trees.

// Mirko‟s machine works as follows: Mirko sets a height parameter H (in metres), and the machine raises a giant sawblade to that height and cuts off all tree parts higher than H (of course, trees not higher than H meters remain intact). Mirko then takes the parts that were cut off. For example, if the tree row contains trees with heights of 20, 15, 10, and 17 metres, and Mirko raises his sawblade to 15 metres, the remaining tree heights after cutting will be 15, 15, 10, and 15 metres, respectively, while Mirko will take 5 metres off the first tree and 2 metres off the fourth tree (7 metres of wood in total).

// Mirko is ecologically minded, so he doesn‟t want to cut off more wood than necessary. That‟s why he wants to set his sawblade as high as possible. Help Mirko find the maximum integer height of the sawblade that still allows him to cut off at least M metres of wood.

#include <bits/stdc++.h>
#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

bool isPossibleSolution(vector<long long int> trees, long long int M, long long int mid)
{
    int woodCollected = 0;
    for (int i = 0; i < trees.size(); i++)
    {
        if (trees[i] - mid > 0)
        {
            woodCollected += trees[i] - mid;
        }
    }
    
    return woodCollected >= M ? true : false;
}

long long int maxSawBladeHeight(vector<long long int> trees, long long int M)
{

    long long int start = 0;
    long long int ans = -1;
    long long int maxHeight = INT_MIN;

    for (auto treeHeight : trees)
    {
        maxHeight = max(maxHeight, treeHeight);
    }

    long long int end = maxHeight;

    long long int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (isPossibleSolution(trees, M, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + ((end - start) / 2);
    }

    return ans;
}

int main()
{
    vector<long long int> trees = {20, 15, 10, 17};
    int M = 7;
    int bladeHeight = maxSawBladeHeight(trees, M);
    cout << "Maximum sawblade height: " << bladeHeight << endl;
}