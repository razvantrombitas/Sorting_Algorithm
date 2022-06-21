// Iterative Merge Sort 
#include <iostream>
#include <chrono>
using namespace std;
// define the number of unsorted elements
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
    int curr_size; // curr_size varies from 1 to n/2
    int left_start; // starting index of left subarray to be merged

    // Merge subarrays in bottom up manner.  First merge subarrays of
    // size 1 to create sorted subarrays of size 2, then merge subarrays
    // of size 2 to create sorted subarrays of size 4, and so on.

    for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size)
    {
        // Pick starting point of different subarrays of current size
        #pragma omp parallel for
        for (left_start=0; left_start<n-1; left_start += 2*curr_size)
        {
            // Find ending point of left subarray. mid+1 is starting point of right
            int mid = min(left_start + curr_size - 1, n-1);
            int right_end = min(left_start + 2*curr_size - 1, n-1);

            // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
            merge(arr, left_start, mid, right_end);
        }
    }
}

template <class T> void printArray(T A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout <<" "<< A[i];
    cout <<"\n";
}

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
