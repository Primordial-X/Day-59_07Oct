#include <stdio.h>
#include <string.h>

//Q109: Write a program to take an integer array arr and an integer k as inputs. 
//Print the maximum sum of all the subarrays of size k.

/*
Sample Test Cases:
Input 1:
arr[100, 200, 300, 400] = , k = 2
Output 1:
700

Input 2:
arr[1, 4, 2, 10, 23, 3, 1, 0, 20] = , k = 4
Output 2:
39

Input 3:
arr[100, 200, 300, 400] = , k = 1
Output 3:
400

*/

int maxSumSubarray(int arr[], int n, int k) {
    if (n < k) {
        return -1; // Not enough elements for a subarray of size k
    }

    int max_sum = 0;
    int current_sum = 0;

    // Calculate the sum of the first window of size k
    for (int i = 0; i < k; i++) {
        current_sum += arr[i];
    }
    max_sum = current_sum;

    // Slide the window from start to end of the array
    for (int i = k; i < n; i++) {
        current_sum += arr[i] - arr[i - k]; // Add next element and remove the first element of the previous window
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    return max_sum;
}