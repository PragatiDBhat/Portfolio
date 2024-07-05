#include <iostream>
#include <vector>
using namespace std;
void maxHeapify(vector<int>& arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}
void buildMaxHeap(vector<int>& arr)
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}
void insertMaxHeap(vector<int>& arr, int key)
{
    arr.push_back(key);
    int i = arr.size() - 1;
    while (i > 0 && arr[(i - 1) / 2] < arr[i])
    {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
int extractMax(vector<int>& arr)
{
    if (arr.empty())
    {
        cout << "Heap underflow!" << endl;
        return -1;
    }
    int root = arr[0];
    arr[0] = arr.back();
    arr.pop_back();
    maxHeapify(arr, arr.size(), 0);
    return root;
}
void printHeap(vector<int>& arr)
{
    cout << "Heap: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> heap;
    insertMaxHeap(heap, 10);
    insertMaxHeap(heap, 20);
    insertMaxHeap(heap, 15);
    insertMaxHeap(heap, 40);
    insertMaxHeap(heap, 50);
    insertMaxHeap(heap, 100);
    printHeap(heap);
    int maxElement = extractMax(heap);
    if (maxElement != -1)
    {
        cout << "Extracted max element: " << maxElement << endl;
        printHeap(heap);
    }
    return 0;
}

