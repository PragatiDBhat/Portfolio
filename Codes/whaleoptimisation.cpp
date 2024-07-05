#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;
const int N = 30;
const int Imax = 500;
const int Dim = 2;
const double b = 1.5;
struct Whale
{
    vector<double> position;
    double fitness;
};
double fitnessFunction(const vector<double> &position)
{
    double fitness = 0.0;
    for (double x : position)
    {
        fitness += x * x;
    }
    return fitness;
}
vector<Whale> initializePopulation(int n, int dim)
{
    vector<Whale> population(n);
    for (int i = 0; i < n; ++i) {
        population[i].position.resize(dim);
        for (int d = 0; d < dim; ++d)
        {
            population[i].position[d] = ((double) rand() / RAND_MAX) * 10 - 5;
        }
        population[i].fitness = fitnessFunction(population[i].position);
    }
    return population;
}
int main()
{
    srand(time(0));
    vector<Whale> whales = initializePopulation(N, Dim);
    Whale bestWhale = *min_element(whales.begin(), whales.end(), [](const Whale &a, const Whale &b)
    {
        return a.fitness < b.fitness;
    });
    int t = 1;
    while (t <= Imax)
    {
        for (int i = 0; i < N; ++i)
        {
            double a = 2.0 - (2.0 * t / Imax);
            double r = ((double) rand() / RAND_MAX);
            double A = 2.0 * a * r - a;
            double C = 2.0 * ((double) rand() / RAND_MAX);
            double p = ((double) rand() / RAND_MAX);
            double l = ((double) rand() / RAND_MAX) * 2 - 1;
            double D[Dim];
            if (p < 0.5)
            {
                if (fabs(A) < 1)
                {
                    for (int d = 0; d < Dim; ++d)
                    {
                        D[d] = fabs(C * bestWhale.position[d] - whales[i].position[d]);
                        whales[i].position[d] = bestWhale.position[d] - A * D[d];
                    }
                }
                else
                {
                    int randIndex = rand() % N;
                    Whale randWhale = whales[randIndex];
                    for (int d = 0; d < Dim; ++d)
                    {
                        D[d] = fabs(C * randWhale.position[d] - whales[i].position[d]);
                        whales[i].position[d] = randWhale.position[d] - A * D[d];
                    }
                }
            }
            else
            {
                for (int d = 0; d < Dim; ++d)
                {
                    D[d] = fabs(bestWhale.position[d] - whales[i].position[d]);
                    whales[i].position[d] = D[d] * exp(b * l) * cos(2 * M_PI * l) + bestWhale.position[d];
                }
            }
            whales[i].fitness = fitnessFunction(whales[i].position);
        }
        Whale currentBestWhale = *min_element(whales.begin(), whales.end(), [](const Whale &a, const Whale &b)
        {
            return a.fitness < b.fitness;
        });
        if (currentBestWhale.fitness < bestWhale.fitness)
        {
            bestWhale = currentBestWhale;
        }
        ++t;
    }
    cout << "Best fitness: " << bestWhale.fitness << endl;
    cout << "Best position: ";
    for (double x : bestWhale.position)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
