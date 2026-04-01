// Problem Statement
// You are given two binary strings a and b, where the length of string a is less than or equal to the length of string b. Your task is to find the total number of differing bits when string a is compared with every possible substring of b that is of the same length as a. A bit is considered different if the corresponding bits in the same positions of a and the substring of b are not equal.

// Input Format
// The first line of input consists of string a.

// The second line of input consists of string b.

// Output Format
// Print a single line of output consisting of the total sum after comparing the bits.

// Constraints
// 1<= a.length <= b.length<= 2 * 105

// Sample Testcase 0
// Testcase Input
// 01
// 00111
// Testcase Output
// 3
// Explanation
// The substrings of b of length 2 (length of a) are: '00', '01', '11', '11'

// Comparing a = 01 with each substring:
// 01 vs 00 has 1 differing bits.
// 01 vs 01 has 0 differing bit.
// 01 vs 11 has 1 differing bit.
// 01 vs 11 has 1 differing bit.
// Total differing bits = 1 + 0 + 1 + 1 = 3

// Sample Testcase 1
// Testcase Input
// 101
// 11001
// Testcase Output
// 4
// Explanation
// The substrings of b of length 3 (length of a) are: 110, 100, and 001.
// Comparing a = 101 with each substring:
// 101 vs 110 has 2 differing bits.
// 101 vs 100 has 1 differing bit.
// 101 vs 001 has 1 differing bit.
// Total differing bits = 2 + 1 + 1 = 4.

#include <bits/stdc++.h>
using namespace std;

#define MAX 200002

long long int compareBits(string a, string b) {
    // User logic goes here
    int n = a.size();
    int m = b.size();

    long long cnt=0;
    for(int i=0;i<=m-n;i++){
        string x= b.substr(i,n);
        for (int j = 0; j < n; j++) {
            if (a[j] != x[j]) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << compareBits(a, b);
    return 0;
}