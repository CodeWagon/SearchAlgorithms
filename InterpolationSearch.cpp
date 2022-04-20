/******************************************************************************
// C++ Interpolation Search
// To execute this snippet you can use https://www.onlinegdb.com/ and select C++
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
 
// Search key - x
// Array length - n
// It returns index of 'x' in given array 'arr' if present,
// otherwise -1
int interpolationSearch(int arr[], int l, int r, int x)
{
    // condition to make sure key is in the subarray of 
    // selected by the formula
    while (l <= r && x >= arr[l] && x <= arr[r]) {
        
        // This formula returns an index which is close to 
        int estimate = l +  (x-arr[l])*(r-l) / (arr[r]-arr[l]);
 
        // Check if x is present at mid
        if (arr[estimate] == x)
            return estimate;
 
        // If x greater, pick right half
        if (arr[estimate] < x)
            l = estimate + 1;
 
        // If x is smaller, pick left half
        else
            r = estimate - 1;
    }
 
    // If search key 'x' is not found in 'arr' then 
    return -1;
}
 
int main(void)
{
    // interpolation search works best on uniformly distributed and the array should be sorted
    int arr[] = { 10, 13, 15, 26, 28, 50, 56, 88, 94, 127, 159, 356, 480, 567, 689, 699, 780, 850, 956, 995 };

    // Search key is x
    int x = 159;
  
    // In this arr has 5 elements so size of array will be
    // size of entire array divided by size of a single element 
    // in the array
    int n = sizeof(arr) / sizeof(arr[0]);
  
    int result = interpolationSearch(arr, 0, n - 1, x);
    
    // Printing the result
    if(result == -1) {
      cout << "Search key is not present in array";
    } else {
      cout << "Search key is present at position " << result+1;
    }
  
    return 0;
}
