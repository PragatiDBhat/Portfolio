#include <iostream>
#include <vector>
using namespace std;
vector<int> parent;
vector<int> ranks;
void initialize(int n)
{
    parent.resize(n);
    ranks.resize(n, 0);
    for (int i = 0; i < n; ++i)
    {
        parent[i] = i;
    }
}
int find(int x)
{
    if (parent[x] != x)
    {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}
void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY)
    {
        if (ranks[rootX] > ranks[rootY])
        {
            parent[rootY] = rootX;
        }
        else if (ranks[rootX] < ranks[rootY])
        {
            parent[rootX] = rootY;
        }
        else
        {
            parent[rootY] = rootX;
            ranks[rootX]++;
        }
    }
}
bool connected(int x, int y)
{
    return find(x) == find(y);
}
int main()
{
    int n, q;
    cout << "Enter number of elements and number of queries: ";
    cin >> n >> q;
    initialize(n);
    cout << "Enter queries (union/find):" << endl;
    for (int i = 0; i < q; ++i) {
        string type;
        int x, y;
        cin >> type >> x >> y;
        if (type == "union")
        {
            unionSets(x, y);
        }
        else if (type == "find")
        {
            if (connected(x, y))
            {
                cout << x << " and " << y << " are in the same set." << endl;
            }
            else
            {
                cout << x << " and " << y << " are not in the same set." << endl;
            }
        }
    }
    return 0;
}
