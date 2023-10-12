// Given an array of strings words and an integer k, return the k most frequent strings.

// Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

 

// Example 1:

// Input: words = ["i","love","leetcode","i","love","coding"], k = 2
// Output: ["i","love"]
// Explanation: "i" and "love" are the two most frequent words.
// Note that "i" comes before "love" due to a lower alphabetical order.


//Approach - 1 : TRIES AS A HASH 
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    int frequency;

    TrieNode() : isEndOfWord(false), frequency(0) {}
};

// Insert a word into the Trie
void insertWord(TrieNode* root, const string& word) {
    TrieNode* curr = root;
    for (char c : word) {
        if (curr->children.find(c) == curr->children.end()) {
            curr->children[c] = new TrieNode();
        }
        curr = curr->children[c];
    }
    curr->isEndOfWord = true;
    curr->frequency++;
}

// Custom comparator for the priority queue
struct CompareWords {
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
        // If the frequencies are equal, sort lexicographically
        if (a.second == b.second) {
            return a.first < b.first;
        }
        // Otherwise, sort by frequency in descending order
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // Trie to store words and their frequencies
    TrieNode* root = new TrieNode();

    // Insert each word into the Trie
    for (const string& word : words) {
        insertWord(root, word);
    }

    // Priority queue to keep track of the k most frequent words
    priority_queue<pair<string, int>, vector<pair<string, int>>, CompareWords> pq;

    // Helper function to perform DFS and collect the k most frequent words
    function<void(TrieNode*, string)> dfs = [&](TrieNode* node, string currWord) {
        if (node->isEndOfWord) {
            pq.push({currWord, node->frequency});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        for (auto& it : node->children) {
            char c = it.first;
            TrieNode* child = it.second;
            dfs(child, currWord + c);
        }
    };

    // Perform DFS to collect the k most frequent words
    dfs(root, "");

    // Retrieve the k most frequent words from the priority queue
    vector<string> result;
    while (!pq.empty()) {
        result.push_back(pq.top().first);
        pq.pop();
    }

    // Reverse the result vector to get the words in descending order of frequency
    reverse(result.begin(), result.end());

    return result;
    }
};



//Approach - 2 : HASING WITH THE HELP OF HEAPS (better method)

class Solution {
public:
    struct CompareWords {
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
        // If the frequencies are equal, sort lexicographically
        if (a.second == b.second) {
            return a.first < b.first;
        }
        // Otherwise, sort by frequency in descending order
        return a.second > b.second;
    }
};

    vector<string> topKFrequent(vector<string>& words, int k) {
        // Hash map to store word frequency
    unordered_map<string, int> wordFreq;

    // Count the frequency of each word
    for (const string& word : words) {
        wordFreq[word]++;
    }

    // Priority queue to keep track of the k most frequent words
    priority_queue<pair<string, int>, vector<pair<string, int>>, CompareWords> pq;

    // Add words and their frequencies to the priority queue
    for (const auto& entry : wordFreq) {
        pq.push(entry);
        // Keep the queue size limited to k
        if (pq.size() > k) {
            pq.pop();
        }
    }

    // Retrieve the k most frequent words from the priority queue
    vector<string> result;
    while (!pq.empty()) {
        result.push_back(pq.top().first);
        pq.pop();
    }

    // Reverse the result vector to get the words in descending order of frequency
    reverse(result.begin(), result.end());

    return result;
    }
};