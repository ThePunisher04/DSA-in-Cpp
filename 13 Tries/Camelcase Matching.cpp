class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> result;
    for (const string& query : queries) {
        int i = 0, j = 0;
        while (i < query.length() && j < pattern.length()) {
            if (query[i] == pattern[j]) {
                i++;
                j++;
            } else if (isupper(query[i])) {
                break;
            } else {
                i++;
            }
        }
        while (i < query.length() && islower(query[i])) {
            i++;
        }
        result.push_back(j == pattern.length() && i == query.length());
    }
    return result;
    }
};