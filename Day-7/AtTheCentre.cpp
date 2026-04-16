// Problem Statement
// Alice is playing a game where she is at the origin point (0,0) on a 2D plane and wants to distribute K books to the people closest to her (one to each). There are N other people on the plane, each located at specific coordinates.

// Your task is to identify and output the coordinates of the K people who are nearest to Alice.

// Input Format
// The first line contains an integer N, the number of people on the plane.

// The next N lines each contain two integers representing the x and y coordinates of each person.

// The final line contains an integer K, the number of books Alice wants to distribute.

// Output Format
// Print the coordinates of the K people who are closest to Alice.

// Constraints
// 0 <= K <= N <= 10^2

// -10^4 <= x, y <= 10^4

// Sample Testcase 0
// Testcase Input
// 2
// 1 3
// -1 1
// 1
// Testcase Output
// -1 1
// Explanation
// The closest point is -1, 1.
// Sample Testcase 1
// Testcase Input
// 3
// 1 1
// 2 2
// 3 3
// 1
// Testcase Output
// 1 1
// Explanation
// The distance between (1, 1) and the origin is sqrt (2).
// The distance between (2, 2) and the origin is sqrt (8).
// The distance between (3, 3) and the origin is sqrt (18).
// Since sqrt (2) is closer to the origin.
// We only want the closest k = 1 points from the origin, so the answer is just [[1,1]]

#include <bits/stdc++.h>
using namespace std;

// function to calculate distance from origin
int getDist(int x, int y) {
    return x*x + y*y;  // no sqrt needed
}

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> points(n);

    for(int i = 0; i < n; i++){
        cin >> points[i].first >> points[i].second;
    }

    int k;
    cin >> k;

    // sort based on distance
    sort(points.begin(), points.end(), [](pair<int,int> a, pair<int,int> b){
        return (a.first*a.first + a.second*a.second) <
               (b.first*b.first + b.second*b.second);
    });

    // print first k points
    for(int i = 0; i < k; i++){
        cout << points[i].first << " " << points[i].second << endl;
    }

    return 0;
}