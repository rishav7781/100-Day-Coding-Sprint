// Problem Statement
// Given an array of intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

// Input Format
// First line contains an integers denoting the no. of rows, N.

// Second line contains an integer M, which will always be 2.

// Next N lines contains two space-seprated integers denoted start and end.

// Output Format
// Display the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

// Constraints
// 1 <= intervals.length<= 105
// intervals[i].length == 2
// -5 * 104<= starti <endi <= 5 * 104
// Sample Testcase 0
// Testcase Input
// 3
// 2
// 1 2
// 1 2
// 1 2
// Testcase Output
// 2
// Explanation
// You need to remove two [1,2] to make the rest of the intervals non-overlapping.
// Sample Testcase 1
// Testcase Input
// 1 
// 2
// 2 3
// Testcase Output
// 0
// Explanation
// You don't need to remove any of the intervals since they're already non-overlapping.

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

// Placeholder for user logic function
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    // User will implement this function
    int cnt=0;
    sort(intervals.begin(),intervals.end(),[](auto &a, auto&b){
        return a[1] <b[1];
    });
    int prev_end=intervals[0][1];
    for(int i=1;i<intervals.size();i++){
        if(intervals[i][0] < prev_end){
            cnt++;
        }else{
            prev_end=intervals[i][1];
        }
    }
    return cnt;;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> intervals(N, vector<int>(M));

    for (int i = 0; i < N; ++i) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    // Call user logic function and print the output
    int result = eraseOverlapIntervals(intervals);
    cout << result << endl;

    return 0;
}