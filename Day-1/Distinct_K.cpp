// Problem Statement
// You wish to help Ashish, who possesses a collection of N strings, some of which may be duplicated, and has been assigned the task of finding the kth unique string.

// If the number of unique strings is less than k, he needs to display -1. Considering you are Ashish's best friend can you assist him with this challenge?

// Input Format
// The first line contains an integer N denoting the number of strings.

// The next N lines contain strings.

// The next line contains an integer k.

// Output Format
// The output contains the kth distinct string. If there are less than k unique string display -1.

// Constraints
// 1 <= N <= 10^3

// 1 <= String.length() <= 10^3

// Sample Testcase 0
// Testcase Input
// 6
// d
// b
// c
// b
// c
// a
// 2
// Testcase Output
// a
// Explanation
// The only strings in arr that are distinct are "d" and "a." The letter "d" comes first, making it the first separate string.

// Because "a" appears second, it is the second distinct string. "a" is returned since k == 2.

// Sample Testcase 1
// Testcase Input
// 3
// dac
// ba
// a
// 1 
// Testcase Output
// dac
// Explanation
// As all the strings are unique we have the strings in the order: 
// dac, ba, a

// Now, as we can see the value of k=1 therefore, the string returned is the 1st unique string = dac.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
      int n;
      cin >>n;
      vector<string> arr(n);
      unordered_map<string , int> freq;

      for(int i=0;i<n;i++){
        cin >>arr[i];
        freq[arr[i]]++;
      }
      int k;
      cin >>k;

      int cnt=0;

      for(int i=0;i<n;i++){
        if(freq[arr[i]]==1){
            cnt++;
        }
        if(cnt==k) {
            cout<<arr[i];
            return 0;
        }
    
      }
    cout << -1;

    return 0;
}