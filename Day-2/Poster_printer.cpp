// Problem Statement
// A printing press in DiceCity uses a special machine to print colors on blank sheets of paper. The machine operates on pairs of neighboring sheets and can print in one of two color combinations:

// "BR": Changes two neighboring blank sheets to blue (B) and red (R).
// "RB": Changes two neighboring blank sheets to red (R) and blue (B).
// Each operation of the machine modifies the colors of the two adjacent sheets beneath it.

// Input Format
// The first line of the input contains a single integer T denoting the number of test cases.

// The first line of each test case contains an integer N denoting the length of the sequence that is to be printed.

// The second line of each test case contains a string s denoting the sequence of colors that is to be printed on the sheets. It is guaranteed that the length of s is N and that s only consists of the characters W, R, and B.

// Output Format
// For each test case, output a single line containing "YES" if the target sequence can be printed, or "NO" if it cannot be.

// Constraints
// 1 ≤ T ≤ 10^4

// 1 ≤ N ≤ 10^5

// Sample Testcase 0
// Testcase Input
// 2
// 3
// RBR
// 1
// B
// Testcase Output
// YES
// NO
// Explanation
// Testcase 1: The sequence "RBB" can be achieved as follows:
// Print "RB" on sheets 1 and 2 → Result: RBW
// Print "BR" on sheets 2 and 3 → Result: RBR

// Testcase 2: It is impossible to achieve a single "B" starting from all white sheets using the machine as it requires at least one "R" for the machine to print "B".

// Sample Testcase 1
// Testcase Input
// 2
// 5
// BRBBW
// 3
// BRB
// Testcase Output
// YES
// YES
// Explanation
// Testcase 1: Starting with all sheets as 'W', the sequence "BRBBW" can be achieved by printing the machine in the following steps:


// Print "BR" on sheets 1 and 2 → Result: BRWWW
// Print "RB" on sheets 3 and 4 → Result: BRRBW
// Print "RB" on sheets 2 and 3 → Result: BRBBW

// Testcase 2: The sequence "BRB" can be achieved by printing the machine as follows:


// Print "BR" on sheets 1 and 2 → Result: BRW
// Print "RB" on sheets 2 and 3 → Result: BRB

#include <iostream>
using namespace std;

bool canPrint(string s) {
    int n = s.size();

    for (int i = 0; i < n; ) {

        if (s[i] == 'W') {
            i++;
            continue;
        }

        int j = i;
        bool hasR = false, hasB = false;

        // process segment
        while (j < n && s[j] != 'W') {
            if (s[j] == 'R') hasR = true;
            if (s[j] == 'B') hasB = true;
            j++;
        }

        // check condition
        if (!(hasR && hasB)) return false;

        i = j;
    }

    return true;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        string s;
        cin >> s;

        cout << (canPrint(s) ? "YES" : "NO") << endl;
    }
}