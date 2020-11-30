#include <iostream>
#include <time.h>
#include <chrono>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    using namespace chrono;
    int size = 0;
    cout << "how big do you want the array?" << endl;
    cin >> size;

    auto started = chrono::high_resolution_clock::now();

    int* toSort = new int[size];

    srand((unsigned)time(0));

    for (int i = 0; i < size; i++) {
        toSort[i] = (rand() % 100) + 1;
    }

    quickSort(toSort, 0, sizeof(*toSort));

    auto done = std::chrono::high_resolution_clock::now();

    duration<double> time_span = duration_cast<duration<double>>(done - started);

    cout << (time_span.count()) << "seconds";
}
