#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    TrieNode* fail;
    vector<int> output;
};
TrieNode* createNode()
{
    TrieNode* newNode = new TrieNode;
    newNode->fail = nullptr;
    return newNode;
}
void insertPattern(TrieNode* root, const string& pattern, int index)
{
    TrieNode* current = root;
    for (char c : pattern)
    {
        if (current->children.find(c) == current->children.end())
        {
            current->children[c] = createNode();
        }
        current = current->children[c];
    }
    current->output.push_back(index);
}
void buildFailureLinks(TrieNode* root)
{
    queue<TrieNode*> q;
    root->fail = root;
    for (auto& kv : root->children)
    {
        kv.second->fail = root;
        q.push(kv.second);
    }
    while (!q.empty())
    {
        TrieNode* current = q.front();
        q.pop();
        for (auto& kv : current->children)
        {
            char c = kv.first;
            TrieNode* child = kv.second;
            q.push(child);
            TrieNode* failNode = current->fail;
            while (failNode != root && failNode->children.find(c) == failNode->children.end())
            {
                failNode = failNode->fail;
            }
            if (failNode->children.find(c) != failNode->children.end())
            {
                child->fail = failNode->children[c];
            }
            else
            {
                child->fail = root;
            }
            child->output.insert(child->output.end(), child->fail->output.begin(), child->fail->output.end());
        }
    }
}
vector<pair<int, int>> search(TrieNode* root, const string& text, const vector<string>& patterns)
{
    TrieNode* current = root;
    vector<pair<int, int>> matches;
    for (int i = 0; i < text.size(); ++i)
    {
        char c = text[i];
        while (current != root && current->children.find(c) == current->children.end())
        {
            current = current->fail;
        }
        if (current->children.find(c) != current->children.end())
        {
            current = current->children[c];
        }
        else
        {
            current = root;
        }
        for (int index : current->output)
        {
            int patternStartIndex = i - patterns[index].size() + 1;
            matches.push_back({patternStartIndex, index});
        }
    }
    return matches;
}

int main()
{
    vector<string> patterns = {"he", "she", "his", "hers"};
    string text = "ushershe";
    TrieNode* root = createNode();
    for (int i = 0; i < patterns.size(); ++i)
    {
        insertPattern(root, patterns[i], i);
    }
    buildFailureLinks(root);
    vector<pair<int, int>> matches = search(root, text, patterns);
    cout << "Pattern matches in text:" << endl;
    for (auto match : matches)
    {
        int patternIndex = match.second;
        int startIndex = match.first;
        cout << "Pattern '" << patterns[patternIndex] << "' found at index " << startIndex << endl;
    }
    return 0;
}
