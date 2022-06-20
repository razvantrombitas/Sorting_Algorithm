// Merge sort
//#include <iostream>
//#include <chrono>
//using namespace std;
//#define N 100000
//uint32_t arr[N];
//// Merge two subarrays L and M into arr
//template <class T> void merge(T arr[], uint32_t p, uint32_t q, uint32_t r) {
//
//    // Create L ← A[p..q] and M ← A[q+1..r]
//    uint32_t n1 = q - p + 1;
//    uint32_t n2 = r - q;
//
//    uint32_t L[n1], M[n2];
//
//    for (uint32_t i = 0; i < n1; i++)
//        L[i] = arr[p + i];
//
//    for (uint32_t j = 0; j < n2; j++)
//        M[j] = arr[q + 1 + j];
//
//    // Maintain current index of sub-arrays and main array
//    uint32_t i, j, k;
//    i = 0;
//    j = 0;
//    k = p;
//
//    // Until we reach either end of either L or M, pick larger among
//    // elements L and M and place them in the correct position at A[p..r]
//    while (i < n1 && j < n2) {
//        if (L[i] <= M[j]) {
//            arr[k] = L[i];
//            i++;
//        } else {
//            arr[k] = M[j];
//            j++;
//        }
//        k++;
//    }
//
//    // When we run out of elements in either L or M,
//    // pick up the remaining elements and put in A[p..r]
//    while (i < n1) {
//        arr[k] = L[i];
//        i++;
//        k++;
//    }
//
//    while (j < n2) {
//        arr[k] = M[j];
//        j++;
//        k++;
//    }
//}
//
//// Divide the array into two subarrays, sort them and merge them
//template <class T> void mergeSort(T arr[], uint32_t l, uint32_t r) {
//    if (l < r) {
//        // m is the point where the array is divided into two subarrays
//        uint32_t m = l + (r - l) / 2;
//
//        mergeSort<T>(arr, l, m);
//        mergeSort<T>(arr, m + 1, r);
//        // Merge the sorted subarrays
//        if (arr[m] > arr[m + 1]) //optimization: the array is already sorted
//                                 //by adding this if O(n) time complexity could be obtained in best case
//        merge<T>(arr, l, m, r);
//    }
//}
//template <class T> void printArray(T arr[], uint32_t size) {
//
//    for (uint32_t i = 0; i < size; i++)
//        cout << arr[i] << " ";
//    cout << endl;
//}
//
//// Driver program
//int main() {
//
//    for (int i = 0; i < N; i++)
//        arr[i] = (uint32_t) rand() ;
//
//    auto start = std::chrono::high_resolution_clock::now();
//    mergeSort<uint32_t>( arr, 0, N - 1);
//    auto stop = std::chrono::high_resolution_clock::now();
//    cout << "Done in " << duration_cast<std::chrono::milliseconds>(stop-start).count() << " ms" << std::endl;
//
////    cout << "Sorted array: \n";
////    printArray<uint32_t>(arr, N);
//    return 0;
//}


// Iterative merge sort */
#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
#define N 500000
uint32_t arr[N];

int min(int x, int y) { return (x<y)? x :y; }

/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
template <class T> void merge(T arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


template <class T> void mergeSort(T arr[], int n)
{
    int curr_size;  // For current size of subarrays to be merged
    // curr_size varies from 1 to n/2
    int left_start; // For picking starting index of left subarray
    // to be merged

    // Merge subarrays in bottom up manner.  First merge subarrays of
    // size 1 to create sorted subarrays of size 2, then merge subarrays
    // of size 2 to create sorted subarrays of size 4, and so on.

    for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size)
    {
        // Pick starting point of different subarrays of current size
        #pragma omp parallel for
        for (left_start=0; left_start<n-1; left_start += 2*curr_size)
        {
            // Find ending point of left subarray. mid+1 is starting
            // point of right
            int mid = min(left_start + curr_size - 1, n-1);

            int right_end = min(left_start + 2*curr_size - 1, n-1);

            // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
            merge(arr, left_start, mid, right_end);
        }
    }
}

/* Function to print an array */
template <class T> void printArray(T A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout <<" "<< A[i];
    cout <<"\n";
}

/* Driver program to test above functions */
int main() {

    for (int i = 0; i < N; i++)
        arr[i] = (uint32_t) rand() * rand() ;

    auto start = std::chrono::high_resolution_clock::now();
    mergeSort<uint32_t>(arr, N);
    auto stop = std::chrono::high_resolution_clock::now();
    cout << "Done in " << std::chrono::duration_cast<std::chrono::milliseconds>(stop-start).count() << " ms" << std::endl;

//    cout << "Sorted array: \n";
//    printArray<uint32_t>(arr, N);

    return 0;
}
