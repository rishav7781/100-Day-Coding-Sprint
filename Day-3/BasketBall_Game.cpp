// Problem Statement
// In a peculiar basketball game, where World Cup is happening, Aniket is tasked with keeping the scores of the match. The game unfolds in rounds, and with each rounds there is a system like the matches played previously will be highlighted in future scores too i.e where the scores of previous rounds can influence those in the future.

// Aniket starts each game with an null record.

// He is provided with a list of operations, represented by strings, denoted as 'ops'.

// Each operation, 'ops[i]', can be one of the following:

// An integer 'x', indicating the recording of a new score 'x'.
// A '+', which means recording a score that is the sum of the previous two scores (it is ensured that there are always at least two previous scores available).
// A 'D', signifying recording a score that is double the previous score (it is ensured that there is always a previous score available).
// A 'C', indicating the invalidation of the previous score, removing it from the record (it is ensured that there is always a previous score to remove).
// Aniket's task is to process these operations and calculate the sum of all the scores and keep record of it for the final judgement.

// Input Format
// The first line contains a single integer n representing number of operations.

// From the Second line take input a vector of a string(the operations to perform) of size n.

// Output Format
// Print  the sum of all the scores remaining in the record after processing all operations

// Constraints
// 1 <= ops.length <= 10^3

// ops[i] is "C", "D", "+", or a string representing an integer in the range

// [-3 * 10^4, 3 * 10^4].

// For operation "+", there will always be at least two previous scores on the record.

// For operations "C" and "D", there will always be at least one previous score on the record.

// Sample Testcase 0
// Testcase Input
// 8
// 1 2 + C D 8 D +
// Testcase Output
// 55
// Explanation
// - Aniket records 1: [1] - Aniket records 2: [1, 2] - Aniket records the sum of the last two scores (1 + 2): [1, 2, 3] - Aniket invalidates the previous score: [1, 2] - Aniket records double the previous score (2 * 2): [1, 2, 4] - Aniket records 8: [1, 2, 4, 8] - Aniket records double the previous score (8 * 2): [1, 2, 4, 8, 16] - Aniket records the sum of the last two scores (8 + 16): [1, 2, 4, 8, 16, 24] Total score: 1 + 2 + 4 + 8 + 16 + 24 = 55

// Sample Testcase 1
// Testcase Input
// 7
// 3 4 + D C D +
// Testcase Output
// 49
// Explanation
// - Aniket records 3: [3] - Aniket records 4: [3, 4] - Aniket records the sum of the last two scores (3 + 4): [3, 4, 7] - Aniket records double the previous score (7 * 2): [3, 4, 7, 14] - Aniket invalidates the previous score: [3, 4, 7] - Aniket records double the previous score (7 * 2): [3, 4, 7, 14] - Aniket records the sum of the last two scores (7 + 14): [3, 4, 7, 14, 21] Total score: 3 + 4 + 7 + 14 + 21 = 49

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

// Placeholder for user logic function
int user_logic(vector<string>& ops) {
    /*
    Write your logic here.
    Parameters:
        ops (vector<string>&): Vector of operations as strings
    Returns:
        int: Computed result based on the problem statement

    */
    stack <int> st;

    for(string op : ops){
        if(op=="+"){
            int x= st.top();
            st.pop();
            int y= st.top();
            int sum= x+y;
            st.push(x);
            st.push(sum);
        }
            else if(op=="D"){
                st.push(2 * st.top());
            }
            else if(op=="C"){
                st.pop();
            }
            else {
                st.push(stoi(op));
            }
        }
        int total=0;

        while(!st.empty()){
            total+=st.top();
            st.pop();
        }

        return total;

    }

int main() {
    int n;
    cin >> n; // Input for number of operations
    vector<string> ops(n);
    
    // Input vector of operations
    for (int i = 0; i < n; ++i) {
        cin >> ops[i];
    }
    
    // Call user logic function and print the output
    int result = user_logic(ops);
    cout << result << endl;
    
    return 0;
}