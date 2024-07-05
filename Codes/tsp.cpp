#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const int INF = 1e9;
double calcDistance(pair<int, int> city1, pair<int, int> city2)
{
    int dx = city1.first - city2.first;
    int dy = city1.second - city2.second;
    return sqrt(dx * dx + dy * dy);
}

double totalDistance(vector<int>& route, vector<pair<int, int>>& cities)
{
    double dist = 0.0;
    for (int i = 0; i < route.size() - 1; ++i)
    {
        dist += calcDistance(cities[route[i]], cities[route[i + 1]]);
    }
    dist += calcDistance(cities[route.back()], cities[route[0]]);
    return dist;
}
pair<vector<int>, double> tspBruteForce(vector<pair<int, int>>& cities)
{
    int n = cities.size();
    vector<int> route(n);
    for (int i = 0; i < n; ++i)
    {
        route[i] = i;
    }
    double minDist = INF;
    vector<int> bestRoute;
    do {
        double currentDist = totalDistance(route, cities);
        if (currentDist < minDist)
        {
            minDist = currentDist;
            bestRoute = route;
        }
    } while (next_permutation(route.begin() + 1, route.end()));

    return make_pair(bestRoute, minDist);
}
int main() {
    vector<pair<int, int>> cities = {{0, 0}, {1, 1}, {2, 3}, {5, 2}, {7, 0}};
    pair<vector<int>, double> result = tspBruteForce(cities);
    cout << "Shortest path order: ";
    for (int city : result.first)
    {
        cout << city << " ";
    }
    cout << endl;
    cout << "Shortest path distance: " << result.second << endl;

    return 0;
}
