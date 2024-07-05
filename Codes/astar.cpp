#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <limits>
#include <algorithm>
using namespace std;
struct Node
{
    int id;
    vector<pair<Node*, int>> neighbors;
    Node(int id) : id(id) {}
};
vector<Node*> aStarSearch(Node* start, Node* goal)
{
    map<Node*, int> heuristic;
    map<Node*, int> gScore;
    map<Node*, int> fScore;
    map<Node*, Node*> cameFrom;
    set<Node*> closedSet;
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> openSet;
    auto calculateHeuristic = [&](Node* u, Node* v)
    {
        return abs(u->id - v->id);
    };
    heuristic[start] = calculateHeuristic(start, goal);
    gScore[start] = 0;
    fScore[start] = gScore[start] + heuristic[start];
    openSet.push(make_pair(fScore[start], start));
    while (!openSet.empty())
    {
        Node* current = openSet.top().second;
        openSet.pop();
        if (current == goal)
        {
            vector<Node*> path;
            Node* reconstructNode = goal;
            while (reconstructNode != nullptr) {
                path.push_back(reconstructNode);
                reconstructNode = cameFrom[reconstructNode];
            }
            reverse(path.begin(), path.end());
            return path;
        }
        closedSet.insert(current);
        for (auto& neighbor : current->neighbors) {
            Node* neighborNode = neighbor.first;
            int tentative_gScore = gScore[current] + neighbor.second;

            if (closedSet.find(neighborNode) != closedSet.end())
            {
                continue;
            }
            if (tentative_gScore < gScore[neighborNode] || closedSet.find(neighborNode) == closedSet.end())
            {
                cameFrom[neighborNode] = current;
                gScore[neighborNode] = tentative_gScore;
                fScore[neighborNode] = gScore[neighborNode] + heuristic[neighborNode];
                openSet.push(make_pair(fScore[neighborNode], neighborNode));
            }
        }
    }
    return vector<Node*>();
}

int main() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    node1->neighbors.push_back(make_pair(node2, 1));
    node1->neighbors.push_back(make_pair(node3, 3));
    node2->neighbors.push_back(make_pair(node4, 4));
    node3->neighbors.push_back(make_pair(node4, 1));
    Node* startNode = node1;
    Node* goalNode = node4;
    vector<Node*> path = aStarSearch(startNode, goalNode);
    cout << "Path from node " << startNode->id << " to node " << goalNode->id << ":" << endl;
    if (!path.empty())
    {
        for (Node* node : path)
        {
            cout << node->id << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "No path found!" << endl;
    }
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    return 0;
}
