// Recursive Merge Sort
#include <iostream>
#include <chrono>
using namespace std;
// define the number of unsorted elements
#define N 500000
uint32_t arr[N];

// Merge two subarrays L and M into arr
template <class T> void merge(T arr[], int p, int q, int r) {

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];

    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Divide the array into two subarrays, sort them and merge them
template <class T> void mergeSort(T arr[], int l, int r) {
    if (l < r) {
        
        int m = l + (r - l) / 2;
        mergeSort<T>(arr, l, m);
        mergeSort<T>(arr, m + 1, r);

        // Merge the sorted subarrays
        // optimization: the array is already sorted; by adding this if O(n) time complexity could be obtained in best case
        if (arr[m] > arr[m + 1]) 
        	merge<T>(arr, l, m, r);
    }
}
template <class T> void printArray(T arr[], int size) {

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {

    for (int i = 0; i < N; i++)
        arr[i] = (uint32_t) rand() ;

    auto start = std::chrono::high_resolution_clock::now();
    mergeSort<uint32_t>( arr, 0, N - 1);
    auto stop = std::chrono::high_resolution_clock::now();
    cout << "Done in " << std::chrono::duration_cast<std::chrono::milliseconds>(stop-start).count() << " ms" << std::endl;

//    cout << "Sorted array: \n";
//    printArray<uint32_t>(arr, N);
    return 0;
}