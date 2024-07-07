#include <iostream>
#include <vector>
using namespace std;
void printPermutation(const vector<int>& perm)
{
    for (int i = 0; i < perm.size(); ++i)
    {
        cout << perm[i] << " ";
    }
    cout << endl;
}
void johnsonTrotter(int n)
{
    vector<int> perm(n);
    vector<int> dir(n, -1);
    for (int i = 0; i < n; ++i)
    {
        perm[i] = i + 1;
    }
    printPermutation(perm);
    int mobile;
    bool foundMobile;
    while (true)
    {
        mobile = 0;
        foundMobile = false;
        for (int i = 0; i < n; ++i)
        {
            int nextPos = i + dir[i];
            if (nextPos >= 0 && nextPos < n && perm[i] > perm[nextPos])
            {
                if (!foundMobile || perm[i] > perm[mobile])
                {
                    mobile = i;
                    foundMobile = true;
                }
            }
        }
        if (!foundMobile)
        {
            break;
        }
        int nextPos = mobile + dir[mobile];
        swap(perm[mobile], perm[nextPos]);
        swap(dir[mobile], dir[nextPos]);
        for (int i = 0; i < n; ++i)
        {
            if (perm[i] > perm[mobile])
            {
                dir[i] = -dir[i];
            }
        }
        printPermutation(perm);
    }
}

int main() {
    int n = 4;
    cout << "Permutations generated using Johnson-Trotter algorithm:" << endl;
    johnsonTrotter(n);

    return 0;
}
