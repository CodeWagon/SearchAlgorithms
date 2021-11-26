/******************************************************************************
C++ code for jump search
To execute this code you can use online gdb - an online compiler for quick execution of snippets
or any tool you prefer!
*******************************************************************************/

#include <iostream>
#include <math.h>
using namespace std;
 
int jumpSearch(int arr[], int n, int key)
{
    int i;
    // a good step size is square root of the number
    int step = sqrt(n);
  
    // keep track of the previous step
    int prev = 0;
    while(arr[step] < key){
        prev = step;
        step = step + sqrt(n);
        if(step >= n ) break;
    }
    
    // linear search till we find the key
    // between prev and step
    while(prev <= step){
        if(arr[prev] == key){
            return prev;
        }
        prev = prev + 1;
    }
    return -1;
}
 
// Driver code
int main(void)
{
    // arr - array of element
    int arr[] = { 8, 23, 45, 56, 67, 89, 90, 100, 103, 107, 135, 167, 189, 190, 200, 210, 345} ;
  
    // x - search key
    int key = 167;
  
    // n - size of array (found by dividing size of 
    // entire array by size of single element from the array
    int n = sizeof(arr) / sizeof(arr[0]);
   
    // Function call for jump search
    int result = jumpSearch(arr, n, key);
    if(result == -1){
        cout << "Element is not in the array :-(";
    } else {
        cout << "Element found at position : " << result;
    }
    return 0;
}
