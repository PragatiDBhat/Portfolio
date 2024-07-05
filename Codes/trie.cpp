#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
struct TrieNode
{
    unordered_map<char, TrieNode*> children;
    bool isEndOfPath;
    TrieNode() : isEndOfPath(false) {}
};
void insert(TrieNode* root, const string& filePath)
{
    TrieNode* current = root;
    for (char c : filePath)
    {
        if (current->children.find(c) == current->children.end())
        {
            current->children[c] = new TrieNode();
        }
        current = current->children[c];
    }
    current->isEndOfPath = true;
}
bool search(TrieNode* root, const string& filePath)
{
    TrieNode* current = root;
    for (char c : filePath)
    {
        if (current->children.find(c) == current->children.end())
        {
            return false; // Path does not exist
        }
        current = current->children[c];
    }
    return current != nullptr && current->isEndOfPath;
}
void remove(TrieNode* root, const string& filePath)
{
    TrieNode* current = root;
    vector<TrieNode*> nodes;
    for (char c : filePath)
    {
        if (current->children.find(c) == current->children.end())
        {
            return;
        }
        nodes.push_back(current);
        current = current->children[c];
    }
    if (current != nullptr && current->isEndOfPath)
    {
        current->isEndOfPath = false;
    }
    for (int i = nodes.size() - 1; i >= 0; --i)
    {
        if (nodes[i]->children.empty() && !nodes[i]->isEndOfPath)
        {
            delete nodes[i];
            nodes[i] = nullptr;
        }
        else
        {
            break;
        }
    }
}
void destroy(TrieNode* node)
{
    if (node == nullptr)
    {
        return;
    }
    for (auto& pair : node->children)
    {
        destroy(pair.second);
    }
    delete node;
}
int main()
{
    TrieNode* root = new TrieNode();
    insert(root, "/usr/local/bin");
    insert(root, "/home/user/documents");
    insert(root, "/usr/local/include");
    cout << "/usr/local/bin exists? " << (search(root, "/usr/local/bin") ? "Yes" : "No") << endl;
    cout << "/usr/local/include exists? " << (search(root, "/usr/local/include") ? "Yes" : "No") << endl;
    cout << "/home/user/documents exists? " << (search(root, "/home/user/documents") ? "Yes" : "No") << endl;
    cout << "/usr/local/lib exists? " << (search(root, "/usr/local/lib") ? "Yes" : "No") << endl;
    remove(root, "/usr/local/bin");
    remove(root, "/usr/local/include");
    cout << "/usr/local/bin exists after removal? " << (search(root, "/usr/local/bin") ? "Yes" : "No") << endl;
    cout << "/usr/local/include exists after removal? " << (search(root, "/usr/local/include") ? "Yes" : "No") << endl;
    destroy(root);
    return 0;
}
