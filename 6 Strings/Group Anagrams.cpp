// LC-49

// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

#include <unordered_map>
#include <vector>
#include <string>
class Solution
{
//Time complexity -> O(N*K) = O(n2)
//Space Complexity -> O(N*K) = O(n2)
public:
    std::array<int, 256> hash(string s)
    {

        std::array<int, 256> hash = {0};
        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i]]++;
        }

        return hash;
    }
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        map<std::array<int, 256>, vector<string>> mp;

        for (auto str : strs)
        {
            mp[hash(str)].push_back(str);
        }

        vector<vector<string>> ans;

        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            ans.push_back(it->second);
        }

        return ans;
    }
};

//OR
//Time complexity -> O(N*KlogK) = O(n2*logn)
//Space Complexity -> O(N*K) = O(n2)
// n = strs.size()
//k = length of longest anagram
vector<vector<string>> groupAnagrams(vector<string> &strs)
{

    map<string, vector<string>> mp;

    for (auto originalAnagram : strs)
    {
        string sortedAnagram = originalAnagram;
        sort(s.begin(), s.end());
        mp[sortedAnagram].push_back(originalAnagram);
    }

    vector<vector<string>> ans;

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        ans.push_back(it->second);
    }

    return ans;
}