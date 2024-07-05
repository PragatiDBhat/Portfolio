#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN = 500;
int n;
int womenPref[MAXN][MAXN], menPref[MAXN][MAXN];
int womenPartner[MAXN], menPartner[MAXN];
bool menFree[MAXN];
int womenRank[MAXN][MAXN];
void stableMarriage()
{
    queue<int> freeMen;
    memset(menFree, true, sizeof(menFree));
    memset(womenPartner, -1, sizeof(womenPartner));
    for (int i = 0; i < n; ++i)
    {
        freeMen.push(i);
    }
    while (!freeMen.empty())
    {
        int man = freeMen.front();
        freeMen.pop();

        for (int i = 0; i < n && menFree[man]; ++i)
        {
            int woman = menPref[man][i];

            if (womenPartner[woman] == -1)
            {
                womenPartner[woman] = man;
                menPartner[man] = woman;
                menFree[man] = false;
            }
            else
            {
                int currentPartner = womenPartner[woman];
                if (womenRank[woman][man] < womenRank[woman][currentPartner])
                {
                    womenPartner[woman] = man;
                    menPartner[man] = woman;
                    menFree[man] = false;
                    menFree[currentPartner] = true;
                    freeMen.push(currentPartner);
                }
            }
        }
    }
}
int main() {
    cout << "Enter number of men/women: ";
    cin >> n;

    cout << "Enter men's preferences (one line per man, space separated):\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> menPref[i][j];
            menPref[i][j]--;
        }
    }
    cout << "Enter women's preferences (one line per woman, space separated):\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> womenPref[i][j];
            womenPref[i][j]--;
            womenRank[i][womenPref[i][j]] = j;
        }
    }
    stableMarriage();
    cout << "Stable matching results:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "Woman " << i + 1 << " is paired with Man " << womenPartner[i] + 1 << "\n";
    }
    return 0;
}

