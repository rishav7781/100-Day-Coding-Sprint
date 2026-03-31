// Problem Statement
// You are given an array A of size N.

// Your task is to count the number of unique pairs of non-overlapping subarrays such that both subarrays have the same sum.

// Each subarray is defined by a pair of indices [L, R] (1-based indexing), where 1 ≤ L ≤ R ≤ N.

// Two subarrays must not overlap, meaning they should not share any common index.

// Also, the pair ([L1, R1], [L2, R2]) is considered the same as ([L2, R2], [L1, R1]), so count each valid pair only once.

// Input Format
// The first line of input contains an integer N, representing the array size.

// The second line of input contain N space-separated integers,representing the elements of array A.

// Output Format
// Display a single integer representing the required number of pairs.

// Constraints
// 1 ≤ N ≤ 10^6

// -10^6 ≤ A[i] ≤ 10^6

// Sample Testcase 0
// Testcase Input
// 4
// 1 -1 2 -2
// Testcase Output
// 2
// Explanation
// The array is [1, -1, 2, -2].
// There are two pairs of subarrays with equal sums that do not overlap:
// Subarray from index 1 to 2: [1, -1] with sum 1 - 1 = 0
// Subarray from index 3 to 4: [2, -2] with sum 2 - 2 = 0
// Subarray from index 1 to 1: [1] with sum 1
// Subarray from index 2 to 3: [-1, 2] with sum -1 + 2 = 1
// Therefore, the output is 2.

// Sample Testcase 1
// Testcase Input
// 3
// 1 2 3
// Testcase Output
// 1
// Explanation
// The array is [1, 2, 3].
// There is only one pair of subarrays with equal sums that do not overlap:
// Subarray from index 1 to 2: [1, 2] with sum 1 + 2 = 3
// Subarray from index 3 to 3: [3] with sum 3
// Therefore, the output is 1.

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countValidPairs(int N, vector<int>& A) {
    vector<int> prefixSum(N + 1, 0);
    unordered_map<int, vector<pair<int, int>>> sumMap;
    
    // Compute prefix sum
    for (int i = 1; i <= N; ++i) {
        prefixSum[i] = prefixSum[i - 1] + A[i - 1];
    }
    
    // Store subarrays in a hashmap
    for (int L = 1; L <= N; ++L) {
        for (int R = L; R <= N; ++R) {
            int sum = prefixSum[R] - prefixSum[L - 1];
            sumMap[sum].push_back({L, R});
        }
    }

    int count = 0;
    
    // Find valid non-overlapping pairs
    for (auto& entry : sumMap) {
        vector<pair<int, int>>& subarrays = entry.second;
        int sz = subarrays.size();

        for (int i = 0; i < sz; ++i) {
            for (int j = i + 1; j < sz; ++j) {
                if (subarrays[i].second < subarrays[j].first || subarrays[j].second < subarrays[i].first) {
                    count++;
                }
            }
        }
    }
    
    return count;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    cout << countValidPairs(N, A) << endl;
    return 0;
}