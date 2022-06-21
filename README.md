# Sorting Algorithm - Merge Sort
Merge Sort is a Divide and Conquer algorithm. It divides the input array into two halves, calls itself for the two halves, and then it merges the two sorted halves. The merge() function is used for merging two halves. The merge(arr, l, m, r) is a key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one. 

In order to implement this algorithm, the following steps should be considered: 

*    Declare left variable to 0 and right variable to n-1 
*    Find mid by medium formula. mid = (left+right)/2
*    Call merge sort on (left,mid)
*    Call merge sort on (mid+1,rear)
*    Continue till left is less than right
*    Then call merge function to perform merge sort.

![Merge Sort](https://www.101computing.net/wp/wp-content/uploads/Merge-Sort-Algorithm.png)


## Usage

Use the Makefile in order to run both recursive and iterative, optimized and unoptimized versions of the Merge Sort algorithm.

```bash
make
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.


