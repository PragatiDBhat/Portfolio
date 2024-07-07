#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int rodCutting(int price[], int n)
{
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        int maxProfit = INT_MIN;
        for (int j = 1; j <= i; ++j)
        {
            maxProfit = max(maxProfit, price[j - 1] + dp[i - j]);
        }
        dp[i] = maxProfit;
    }
    return dp[n];
}
int main()
{
    int length[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(price) / sizeof(price[0]);
    cout << "Maximum profit for rod of length " << n << " is: " << rodCutting(price, n) << endl;
    return 0;
}
