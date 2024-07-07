#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int jumpSearch(const vector<int>& arr, int target) {
    int n = arr.size();
    int step = sqrt(n);
    int prev = 0;
    while (arr[min(step, n) - 1] < target)
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }
    while (arr[prev] < target)
    {
        prev++;
        if (prev == min(step, n))
            return -1;
    }
    if (arr[prev] == target)
        return prev;

    return -1;
}
void printResult(int result, int target)
{
    if (result == -1)
        cout << "Element " << target << " not found in the array." << endl;
    else
        cout << "Element " << target << " found at index " << result << "." << endl;
}
int main()
{
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target1 = 11;
    int target2 = 8;
    int result1 = jumpSearch(arr, target1);
    int result2 = jumpSearch(arr, target2);
    printResult(result1, target1);
    printResult(result2, target2);
    return 0;
}
