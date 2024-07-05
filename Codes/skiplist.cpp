#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;
const int MAX_LEVEL = 6;
struct Node
{
    int value;
    Node** forward;
};
Node* createNode(int level, int value)
{
    Node* newNode = new Node;
    newNode->value = value;
    newNode->forward = new Node*[level + 1];
    memset(newNode->forward, 0, sizeof(Node*) * (level + 1));
    return newNode;
}
int randomLevel()
{
    int level = 0;
    while (rand() % 2 == 0 && level < MAX_LEVEL)
    {
        level++;
    }
    return level;
}
Node* initializeSkipList()
{
    Node* header = createNode(MAX_LEVEL, INT_MIN);
    return header;
}
void insertElement(Node* header, int value)
{
    Node* update[MAX_LEVEL + 1];
    Node* current = header;

    for (int i = header->forward[0] ? MAX_LEVEL : 0; i >= 0; i--)
    {
        while (current->forward[i] != nullptr && current->forward[i]->value < value)
        {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];

    if (current == nullptr || current->value != value)
    {
        int level = randomLevel();

        if (level > MAX_LEVEL)
        {
            level = MAX_LEVEL;
        }

        Node* newNode = createNode(level, value);

        for (int i = 0; i <= level; i++)
        {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }
}
bool searchElement(Node* header, int value)
{
    Node* current = header;
    for (int i = MAX_LEVEL; i >= 0; i--)
    {
        while (current->forward[i] != nullptr && current->forward[i]->value < value)
        {
            current = current->forward[i];
        }
    }
    current = current->forward[0];
    return (current != nullptr && current->value == value);
}
void deleteElement(Node* header, int value)
{
    Node* update[MAX_LEVEL + 1];
    Node* current = header;

    for (int i = header->forward[0] ? MAX_LEVEL : 0; i >= 0; i--)
    {
        while (current->forward[i] != nullptr && current->forward[i]->value < value)
        {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];

    if (current != nullptr && current->value == value)
    {
        for (int i = 0; i <= MAX_LEVEL; i++)
        {
            if (update[i]->forward[i] != current)
            {
                break;
            }
            update[i]->forward[i] = current->forward[i];
        }
        delete current;
    }
}
void displaySkipList(Node* header)
{
    cout << "Skip List:" << endl;
    for (int i = 0; i <= MAX_LEVEL; i++)
    {
        Node* node = header->forward[i];
        cout << "Level " << i << ": ";
        while (node != nullptr)
        {
            cout << node->value << " ";
            node = node->forward[i];
        }
        cout << endl;
    }
}
void displayMenu()
{
    cout << "Menu:" << endl;
    cout << "1. Insert Element" << endl;
    cout << "2. Search Element" << endl;
    cout << "3. Delete Element" << endl;
    cout << "4. Display Skip List" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}
int main()
{
    Node* header = initializeSkipList();

    int choice, value;
    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            insertElement(header, value);
            cout << "Element inserted successfully." << endl;
            break;
        case 2:
            cout << "Enter value to search: ";
            cin >> value;
            cout << (searchElement(header, value) ? "Element found." : "Element not found.") << endl;
            break;
        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            deleteElement(header, value);
            cout << "Element deleted successfully." << endl;
            break;
        case 4:
            displaySkipList(header);
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
