#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node
{
    int data;
    Color color;
    Node *left, *right, *parent;
};

Node* root = nullptr;

Node* createNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->color = RED;
    newNode->left = newNode->right = newNode->parent = nullptr;
    return newNode;
}

void rotateLeft(Node *&x)
{
    Node *y = x->right;
    x->right = y->left;
    if (y->left != nullptr)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == nullptr)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void rotateRight(Node *&x)
{
    Node *y = x->left;
    x->left = y->right;
    if (y->right != nullptr)
        y->right->parent = x;
    y->parent = x->parent;
    if (x->parent == nullptr)
        root = y;
    else if (x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;
    y->right = x;
    x->parent = y;
}

void fixViolation(Node *&x)
{
    while (x != root && x->color != BLACK && x->parent->color == RED)
    {
        Node *parent = x->parent;
        Node *grandparent = parent->parent;
        if (parent == grandparent->left)
        {
            Node *uncle = grandparent->right;
            if (uncle != nullptr && uncle->color == RED)
            {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                x = grandparent;
            }
            else
            {
                if (x == parent->right)
                {
                    rotateLeft(parent);
                    x = parent;
                    parent = x->parent;
                }
                rotateRight(grandparent);
                swap(parent->color, grandparent->color);
                x = parent;
            }
        }
        else
        {
            Node *uncle = grandparent->left;
            if (uncle != nullptr && uncle->color == RED)
            {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                x = grandparent;
            }
            else
            {
                if (x == parent->left)
                {
                    rotateRight(parent);
                    x = parent;
                    parent = x->parent;
                }
                rotateLeft(grandparent);
                swap(parent->color, grandparent->color);
                x = parent;
            }
        }
    }
    root->color = BLACK;
}

void insert(const int &data)
{
    Node *newNode = createNode(data);

    if (root == nullptr)
    {
        root = newNode;
    }
    else
    {
        Node *current = root;
        Node *parent = nullptr;
        while (current != nullptr)
        {
            parent = current;
            if (newNode->data < current->data)
                current = current->left;
            else
                current = current->right;
        }

        newNode->parent = parent;
        if (parent == nullptr)
            root = newNode;
        else if (newNode->data < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;

        fixViolation(newNode);
    }
}

Node* minValueNode(Node* node)
{
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

void fixDoubleBlack(Node *node, Node *parent)
{
    Node* sibling;
    while (node != root && (node == nullptr || node->color == BLACK))
    {
        if (node == parent->left)
        {
            sibling = parent->right;
            if (sibling != nullptr && sibling->color == RED)
            {
                sibling->color = BLACK;
                parent->color = RED;
                rotateLeft(parent);
                sibling = parent->right;
            }
            if ((sibling->left == nullptr || sibling->left->color == BLACK) && (sibling->right == nullptr || sibling->right->color == BLACK))
            {
                sibling->color = RED;
                node = parent;
                parent = node->parent;
            }
            else
            {
                if (sibling->right == nullptr || sibling->right->color == BLACK)
                {
                    if (sibling->left != nullptr)
                        sibling->left->color = BLACK;
                    sibling->color = RED;
                    rotateRight(sibling);
                    sibling = parent->right;
                }
                sibling->color = parent->color;
                parent->color = BLACK;
                if (sibling->right != nullptr)
                    sibling->right->color = BLACK;
                rotateLeft(parent);
                node = root;
                break;
            }
        }
        else
        {
            sibling = parent->left;
            if (sibling != nullptr && sibling->color == RED)
            {
                sibling->color = BLACK;
                parent->color = RED;
                rotateRight(parent);
                sibling = parent->left;
            }
            if ((sibling->right == nullptr || sibling->right->color == BLACK) && (sibling->left == nullptr || sibling->left->color == BLACK))
            {
                sibling->color = RED;
                node = parent;
                parent = node->parent;
            }
            else
            {
                if (sibling->left == nullptr || sibling->left->color == BLACK)
                {
                    if (sibling->right != nullptr)
                        sibling->right->color = BLACK;
                    sibling->color = RED;
                    rotateLeft(sibling);
                    sibling = parent->left;
                }
                sibling->color = parent->color;
                parent->color = BLACK;
                if (sibling->left != nullptr)
                    sibling->left->color = BLACK;
                rotateRight(parent);
                node = root;
                break;
            }
        }
    }
    if (node != nullptr)
        node->color = BLACK;
}

void deleteNode(int key)
{
    Node *current = root;
    while (current != nullptr)
    {
        if (current->data == key)
        {
            break;
        }
        current = (current->data < key) ? current->right : current->left;
    }
    if (current == nullptr)
    {
        cout << "Node with key " << key << " not found." << endl;
        return;
    }

    Node *toDelete = current;
    Color originalColor = toDelete->color;
    Node *child = (toDelete->left == nullptr) ? toDelete->right : toDelete->left;

    if (toDelete->left == nullptr && toDelete->right == nullptr)
    {
        if (toDelete == root)
        {
            root = nullptr;
        }
        else
        {
            if (toDelete == toDelete->parent->left)
                toDelete->parent->left = nullptr;
            else
                toDelete->parent->right = nullptr;
        }
        delete toDelete;
    }
    else if (toDelete->left != nullptr && toDelete->right != nullptr)
    {
        Node *successor = toDelete->right;
        while (successor->left != nullptr)
            successor = successor->left;
        toDelete->data = successor->data;
        toDelete = successor;
        originalColor = toDelete->color;
        child = toDelete->right;
        if (toDelete->parent->left == toDelete)
            toDelete->parent->left = child;
        else
            toDelete->parent->right = child;
        if (child != nullptr)
            child->parent = toDelete->parent;
        fixDoubleBlack(child, toDelete->parent);
        delete toDelete;
    }
    else
    {
        if (toDelete == root)
        {
            root = child;
            root->parent = nullptr;
        }
        else
        {
            if (toDelete->parent->left == toDelete)
                toDelete->parent->left = child;
            else
                toDelete->parent->right = child;
            child->parent = toDelete->parent;
        }
        if (originalColor == BLACK)
            fixDoubleBlack(child, child->parent);
        delete toDelete;
    }
}


void inorderHelper(Node *root)
{
    if (root == nullptr) return;
    inorderHelper(root->left);
    cout << root->data << " (" << (root->color == RED ? "RED" : "BLACK") << ") ";
    inorderHelper(root->right);
}

void preorderHelper(Node *root)
{
    if (root == nullptr) return;
    cout << root->data << " (" << (root->color == RED ? "RED" : "BLACK") << ") ";
    preorderHelper(root->left);
    preorderHelper(root->right);
}

void postorderHelper(Node *root)
{
    if (root == nullptr) return;
    postorderHelper(root->left);
    postorderHelper(root->right);
    cout << root->data << " (" << (root->color == RED ? "RED" : "BLACK") << ") ";
}

void displayInorder()
{
    inorderHelper(root);
    cout << endl;
}

void displayPreorder()
{
    preorderHelper(root);
    cout << endl;
}

void displayPostorder()
{
    postorderHelper(root);
    cout << endl;
}

Node* searchHelper(Node* root, int key)
{
    if (root == nullptr || root->data == key)
        return root;
    if (root->data < key)
        return searchHelper(root->right, key);
    return searchHelper(root->left, key);
}

void search(const int &key)
{
    Node* result = searchHelper(root, key);
    if (result != nullptr)
        cout << key << " found in the tree." << endl;
    else
        cout << key << " not found in the tree." << endl;
}

void displayMenu()
{
    cout << "1. Insert element\n";
    cout << "2. Delete element\n";
    cout << "3. Display tree in Inorder\n";
    cout << "4. Display tree in Preorder\n";
    cout << "5. Display tree in Postorder\n";
    cout << "6. Search for an element\n";
    cout << "7. Exit\n";
}

int main()
{
    int choice, element;

    do
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element to insert: ";
            cin >> element;
            insert(element);
            break;
        case 2:
            cout << "Enter element to delete: ";
            cin >> element;
            deleteNode(element);
            break;
        case 3:
            cout << "Inorder traversal: ";
            displayInorder();
            break;
        case 4:
            cout << "Preorder traversal: ";
            displayPreorder();
            break;
        case 5:
            cout << "Postorder traversal: ";
            displayPostorder();
            break;
        case 6:
            cout << "Enter element to search: ";
            cin >> element;
            search(element);
            break;
        case 7:
            cout << "Exiting...";
            break;
        default:
            cout << "Invalid choice!\n";
        }
        cout << endl;
    }
    while (choice != 7);

    return 0;
}
