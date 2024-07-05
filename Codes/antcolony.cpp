#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <limits>
using namespace std;
const int N = 5;
const int M = 10;
const int Imax = 100;
const double alpha = 1.0;
const double beta = 2.0;
const double evaporation = 0.5;
const double Q = 100;
double distances[N][N] =
{
    {0, 2, 2, 5, 7},
    {2, 0, 4, 8, 2},
    {2, 4, 0, 1, 3},
    {5, 8, 1, 0, 2},
    {7, 2, 3, 2, 0}
};
double pheromones[N][N];
void initializePheromones()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            pheromones[i][j] = 1.0;
        }
    }
}
double heuristic(int i, int j)
{
    return 1.0 / (distances[i][j] + 1e-6);
}
class Ant
{
public:
    vector<int> tour;
    double tour_length;
    Ant() : tour_length(0) {}
    void visitCity(int city)
    {
        tour.push_back(city);
    }
    bool isVisited(int city)
    {
        return find(tour.begin(), tour.end(), city) != tour.end();
    }
    void clear()
    {
        tour.clear();
        tour_length = 0;
    }
    void calculateTourLength()
    {
        tour_length = 0;
        for (size_t i = 1; i < tour.size(); ++i) {
            tour_length += distances[tour[i - 1]][tour[i]];
        }
        tour_length += distances[tour.back()][tour[0]];
    }
};
int selectNextCity(Ant &ant, int currentCity)
{
    vector<double> probabilities(N, 0.0);
    double sum = 0.0;
    for (int i = 0; i < N; ++i)
    {
        if (!ant.isVisited(i))
        {
            probabilities[i] = pow(pheromones[currentCity][i], alpha) * pow(heuristic(currentCity, i), beta);
            sum += probabilities[i];
        }
    }
    for (int i = 0; i < N; ++i)
    {
        probabilities[i] /= sum;
    }
    double r = ((double) rand() / RAND_MAX);
    double cumulativeProbability = 0.0;
    for (int i = 0; i < N; ++i)
    {
        cumulativeProbability += probabilities[i];
        if (r <= cumulativeProbability)
        {
            return i;
        }
    }
    for (int i = 0; i < N; ++i)
    {
        if (!ant.isVisited(i))
        {
            return i;
        }
    }

    return -1;
}
void updatePheromones(vector<Ant> &ants)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            pheromones[i][j] *= (1 - evaporation);
        }
    }
    for (const Ant &ant : ants)
    {
        for (size_t i = 1; i < ant.tour.size(); ++i)
        {
            int from = ant.tour[i - 1];
            int to = ant.tour[i];
            pheromones[from][to] += Q / ant.tour_length;
            pheromones[to][from] += Q / ant.tour_length;
        }
        int from = ant.tour.back();
        int to = ant.tour[0];
        pheromones[from][to] += Q / ant.tour_length;
        pheromones[to][from] += Q / ant.tour_length;
    }
}
int main()
{
    srand(time(0));
    initializePheromones();
    vector<Ant> ants(M);
    Ant bestAnt;
    bestAnt.tour_length = numeric_limits<double>::infinity();
    for (int t = 0; t < Imax; ++t)
    {
        for (Ant &ant : ants)
        {
            ant.clear();
            int startCity = rand() % N;
            ant.visitCity(startCity);

            for (int step = 1; step < N; ++step)
            {
                int currentCity = ant.tour.back();
                int nextCity = selectNextCity(ant, currentCity);
                ant.visitCity(nextCity);
            }
            ant.calculateTourLength();
            if (ant.tour_length < bestAnt.tour_length)
            {
                bestAnt = ant;
            }
        }
        updatePheromones(ants);
        cout << "Iteration " << t + 1 << ": Best tour length = " << bestAnt.tour_length << endl;
    }
    cout << "Best tour length: " << bestAnt.tour_length << endl;
    cout << "Best tour: ";
    for (int city : bestAnt.tour)
    {
        cout << city << " ";
    }
    cout << endl;
    return 0;
}

