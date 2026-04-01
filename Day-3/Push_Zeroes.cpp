// Problem Statement
// You are given an array, containing numbers and zeroes, you need to push all the zeroes to the end of the array. Notice that while pushing the zeroes the relative ordering between the non-zero elements should not change.

// Given an array, push the zeroes and print the array.

// Input Format
// The first line of the input contains ‘n’ the number of elements in the array.

// The following line contains n numbers, arr[i], the elements of the array.

// Output Format
// Print the array after pushing the zeroes.

// Constraints
// 1<=n<=105

// -100<=arr[i]<=100

// Sample Testcase 0
// Testcase Input
// 4
// 0 0 0 1
// Testcase Output
// 1 0 0 0 
// Explanation
// Keeping the order of non zero elements the same and appending the zeroes in the end the resultant array is 1 0 0 0
// Sample Testcase 1
// Testcase Input
// 5
// 1 0 2 0 3
// Testcase Output
// 1 2 3 0 0
// Explanation
// After appending the zeroes in the end the result array becomes 1 2 3 0 0

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int j = 0;

    // Step 1: move non-zero elements forward
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[j++] = arr[i];
        }
    }

    // Step 2: fill remaining with zero
    while (j < n) {
        arr[j++] = 0;
    }

    // print result
    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}