#include <iostream>
#include <vector>
using namespace std;
struct BPlusTreeNode
{
    bool isLeaf;
    vector<int> keys;
    vector<BPlusTreeNode*> children;
    BPlusTreeNode* next;
};

BPlusTreeNode* createNode(bool isLeaf)
{
    BPlusTreeNode* newNode = new BPlusTreeNode;
    newNode->isLeaf = isLeaf;
    newNode->next = nullptr;
    return newNode;
}
bool search(BPlusTreeNode* root, int key)
{
    if (root == nullptr)
    {
        return false;
    }
    int i = 0;
    while (i < root->keys.size() && key > root->keys[i])
    {
        i++;
    }
    if (i < root->keys.size() && key == root->keys[i])
    {
        return true;
    }
    if (root->isLeaf)
    {
        return false;
    }
    return search(root->children[i], key);
}
void insert(BPlusTreeNode*& root, int key)
{
    if (root == nullptr)
    {
        root = createNode(true);
        root->keys.push_back(key);
    }
    else if (root->isLeaf)
    {
        root->keys.push_back(key);
        sort(root->keys.begin(), root->keys.end());
    }
    else
    {
        int i = 0;
        while (i < root->keys.size() && key > root->keys[i])
        {
            i++;
        }
        insert(root->children[i], key);
    }
}
void remove(BPlusTreeNode*& root, int key)
{
    if (root == nullptr)
    {
        return;
    }
    int i = 0;
    while (i < root->keys.size() && key > root->keys[i])
    {
        i++;
    }
    if (i < root->keys.size() && key == root->keys[i])
    {
        if (root->isLeaf)
        {
            root->keys.erase(root->keys.begin() + i);
        }
        else
        {
            if (root->children[i]->keys.size() >= 2)
            {
                int predecessorKey = root->children[i]->keys.back();
                remove(root->children[i], predecessorKey);
                root->keys[i] = predecessorKey;
            }
            else if (root->children[i + 1]->keys.size() >= 2)
            {
                int successorKey = root->children[i + 1]->keys.front();
                remove(root->children[i + 1], successorKey);
                root->keys[i] = successorKey;
            }
            else
            {
                root->children[i]->keys.push_back(root->keys[i]);
                root->children[i]->keys.insert(root->children[i]->keys.end(), root->children[i + 1]->keys.begin(), root->children[i + 1]->keys.end());
                root->children[i]->children.insert(root->children[i]->children.end(), root->children[i + 1]->children.begin(), root->children[i + 1]->children.end());
                root->keys.erase(root->keys.begin() + i);
                root->children.erase(root->children.begin() + i + 1);
                delete root->children[i + 1];
            }
        }
    }
    else
    {
        remove(root->children[i], key);
    }
}
void display(BPlusTreeNode* root)
{
    if (root == nullptr)
    {
        return;
    }
    for (int i = 0; i < root->keys.size(); i++)
    {
        cout << root->keys[i] << " ";
    }
    cout << endl;
    if (!root->isLeaf)
    {
        for (int i = 0; i < root->children.size(); i++)
        {
            display(root->children[i]);
        }
    }
}
int main()
{
    BPlusTreeNode* root = nullptr;
    int choice, key;

    do
    {
        cout << "Menu:" << endl;
        cout << "1. Insert Key" << endl;
        cout << "2. Search Key" << endl;
        cout << "3. Remove Key" << endl;
        cout << "4. Display Tree" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            insert(root, key);
            break;
        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            if (search(root, key))
            {
                cout << "Key " << key << " found in the B+ tree." << endl;
            }
            else
            {
                cout << "Key " << key << " not found in the B+ tree." << endl;
            }
            break;
        case 3:
            cout << "Enter key to remove: ";
            cin >> key;
            remove(root, key);
            break;
        case 4:
            cout << "B+ Tree Structure:" << endl;
            display(root);
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    while (choice != 5);

    return 0;
}
