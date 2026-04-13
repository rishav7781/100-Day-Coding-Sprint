// Problem Statement
// You have a budget of X coins each day to buy beer, and your goal is to buy as many bottles of beer as possible before the price of beer in all shops exceeds your daily budget.
// There are N shops, and each shop sells one bottle of beer per day. The price of beer in each shop increases by 1 coin per day after each purchase.
// You can visit multiple shops in a single day, but you can buy only one bottle per shop per day.

// Your task is to determine the total number of beer bottles you can buy before the prices at all shops exceed your daily budget.

// Input Format
// The first line contains two space-seperated integers N, X. The number of shops and everyday budget.

// The second line contains N space-seperated integers, representing the cost of one bottle in each shop.

// Output Format
// Print one integer representing the total number of beer bottles you can buy before prices exceed your daily budget.

// Constraints
// 1 ≤  N ≤ 2*10^5

// 1 ≤  X ≤10^9

// 1≤ A[i]  ≤10^9

// Sample Testcase 0
// Testcase Input
// 5 9
// 10 20 30 40 50
// Testcase Output
// 0
// Explanation
// The prices on the first day are [10, 20, 30, 40, 50].
// Since all prices exceed your budget of 9 coins on the very first day, you can't buy any beer.

// Sample Testcase 1
// Testcase Input
// 3 7
// 2 1 2
// Testcase Output
// 11
// Explanation
// Day 1: Prices are [2, 1, 2]. The total cost is 2 + 1 + 2 = 5, which is within the budget of 7 coins, so you buy 3 bottles.
// Day 2: Prices are [3, 2, 3]. The total cost is 3 + 2 + 3 = 8, which exceeds the budget, so you can only buy 2 bottles (3 + 2 = 5).
// Day 3: Prices are [4, 3, 4]. The total cost is 4 + 3 + 4 = 11, which exceeds the budget, so you can buy only 2 bottles (4 + 3 = 7).
// Day 4: Prices are [5, 4, 5]. The total cost is 5 + 4 + 5 = 14, so you can only buy 1 bottle (5).
// Day 5: Prices are [6, 5, 6]. You can buy 1 bottle (6).
// Day 6: Prices are [7, 6, 7]. You can buy 1 bottle (7).
// Day 7: Prices are [8, 7, 8]. The total cost is 8 + 7 + 8 = 23, which exceeds the budget, so you can only buy 1 bottle (7).


// Total bottles bought: 3 (Day 1) + 2 (Day 2) + 2 (Day 3) + 1 (Day 4) + 1 (Day 5) + 1 (Day 6) + 1 (Day 7) = 11 bottles in total.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long long X;
    cin >> n >> X;

    vector<long long> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    long long total = 0;
    long long days = 0;

    while(true) {
        long long sum = 0;
        long long count = 0;

        for(int i = 0; i < n; i++) {
            if(arr[i] + days <= X) {
                sum += arr[i] + days;
                if(sum <= X) count++;
            }
        }

        if(count == 0) break;

        total += count;
        days++;
    }

    cout << total;
    return 0;
}