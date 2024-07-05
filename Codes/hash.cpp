#include <iostream>
#include <vector>
#include <list>
using namespace std;
struct HashNode
{
    int key;
    int value;
    HashNode(int key, int value) : key(key), value(value) {}
};
struct HashTable
{
    int capacity;
    vector<list<HashNode>> table;
    HashTable(int capacity) : capacity(capacity)
    {
        table.resize(capacity);
    }
    int hash(int key)
    {
        return key % capacity;
    }
    void insert(int key, int value)
    {
        int index = hash(key);
        for (auto& node : table[index])
        {
            if (node.key == key)
            {
                node.value = value;
                return;
            }
        }
        table[index].push_back(HashNode(key, value));
    }
    void remove(int key)
    {
        int index = hash(key);
        auto& bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it)
        {
            if (it->key == key)
            {
                bucket.erase(it);
                return;
            }
        }
    }
    int get(int key)
    {
        int index = hash(key);
        for (auto& node : table[index])
        {
            if (node.key == key)
            {
                return node.value;
            }
        }
        return -1;
    }
};
int main() {
    HashTable ht(10);
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);
    ht.insert(4, 40);
    ht.insert(5, 50);
    cout << "Value for key 3: " << ht.get(3) << endl;
    cout << "Value for key 6: " << ht.get(6) << endl;
    ht.remove(2);
    cout << "Value for key 2 after deletion: " << ht.get(2) << endl;
    return 0;
}
