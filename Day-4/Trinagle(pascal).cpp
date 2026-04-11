#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;

    vector<int> prev = {1};

    for(int i = 1; i <= n; i++){
        vector<int> curr(i + 1, 1);

        for(int j = 1; j < i; j++){
            curr[j] = prev[j-1] + prev[j];
        }

        prev = curr;
    }

    for(int x : prev){
        cout << x << " ";
    }

    return 0;
}