// Problem Statement
// You are given a series of queries of the form (A, B), where:

// A represents the count of the number B. For example, the query (3, 5) means the number 5 appears 3 times.
// Your task is to compute the absolute difference between the numbers which have the highest and lowest frequencies (appearing at least once).

// If there are multiple numbers with the same frequency, choose the smallest number for the lowest frequency and the largest number for the highest frequency.
// Input Format
// The first line contains a single integer denoting the number of queries.

// The second line onwards contains two space separated integers denoting the queries

// Output Format
// Output the maximum possible absolute difference between the numbers with the highest and lowest frequencies. If there are only two numbers with the same occurrence, the output should be 0.

// Constraints
// 1 <= Q <= 10^5.

// 1 <= A, B <= 10^5.

// Sample Testcase 0
// Testcase Input
// 1
// 2 1
// Testcase Output
// 0
// Explanation
// As there is only one pair availabe so the difference will be 0.

// Sample Testcase 1
// Testcase Input
// 4
// 1 2
// 1 3
// 2 5
// 4 4
// Testcase Output
// 2
// Explanation
// As per the question:


// 2 occurs 1 time
// 3 occurs 1 time
// 5 occurs 2 times
// 4 occurs 4 times


// Therefore the we need to get the difference between the number occuring most number of times (4) and the number ocuring least number of times(2, 3). 


// As we want maximum difference the answer is: 4-2 = 2.

#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

int main() {
    int q;
    cin >> q;

    unordered_map<int, long long> freq;

    for(int i = 0; i < q; i++) {
        long long A, B;
        cin >> A >> B;
        freq[B] += A;   // accumulate counts
    }

    if(freq.size() <= 1) {
        cout << 0;
        return 0;
    }

    long long minFreq = LLONG_MAX;
    long long maxFreq = LLONG_MIN;

    for(auto &p : freq) {
        minFreq = min(minFreq, p.second);
        maxFreq = max(maxFreq, p.second);
    }

    int minNum = INT_MAX;
    int maxNum = INT_MIN;

    for(auto &p : freq) {
        if(p.second == minFreq)
            minNum = min(minNum, p.first);

        if(p.second == maxFreq)
            maxNum = max(maxNum, p.first);
    }

    cout << abs(maxNum - minNum);

    return 0;
}