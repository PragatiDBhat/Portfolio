#include <iostream>
#include <vector>
using namespace std;
int maxSumSubarray(vector<int>& arr, int k)
{
    int n = arr.size();
    if (n < k)
    {
        cout << "Invalid input: Array size should be at least k." << endl;
        return -1;
    }
    int windowSum = 0;
    for (int i = 0; i < k; ++i)
    {
        windowSum += arr[i];
    }
    int maxSum = windowSum;
    for (int i = k; i < n; ++i)
    {
        windowSum += arr[i] - arr[i - k];
        maxSum = max(maxSum, windowSum);
    }
    return maxSum;
}
int main()
{
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    int maxSum = maxSumSubarray(arr, k);
    cout << "Maximum sum of a subarray of size " << k << " is: " << maxSum << endl;
    return 0;
}

