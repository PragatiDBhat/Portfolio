#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform topological sorting
vector<int> topologicalSort(int V, vector<vector<int>>& adj) {
    // Array to store in-degree of vertices
    vector<int> inDegree(V, 0);
    for (int u = 0; u < V; ++u) {
        for (int v : adj[u]) {
            inDegree[v]++;
        }
    }

    // Queue to store vertices with in-degree 0
    queue<int> q;
    for (int u = 0; u < V; ++u) {
        if (inDegree[u] == 0) {
            q.push(u);
        }
    }

    // Result vector to store the topological order
    vector<int> topoOrder;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);

        // Decrease in-degree of adjacent vertices
        for (int v : adj[u]) {
            if (--inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // If topoOrder size is less than V, graph has a cycle
    if (topoOrder.size() != V) {
        cout << "Graph has a cycle!" << endl;
        return {};
    }

    return topoOrder;
}

int main() {
    int V = 6; // Number of vertices
    vector<vector<int>> adj(V);

    // Adding edges for the example graph
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    // Perform topological sorting
    vector<int> topoOrder = topologicalSort(V, adj);

    // Print the topological order
    if (!topoOrder.empty()) {
        cout << "Topological order:";
        for (int v : topoOrder) {
            cout << " " << v;
        }
        cout << endl;
    }

    return 0;
}
