// Problem Statement
// Given an array of size N. Suppose that at any index ‘i’, the array element is ‘X’. If X is negative, you have to remove the minimum elements present just before X such that the sum of those element is greater than or equal to absolute value of X. If the sum of those elements is less than abs(X), remove all elements before X.

// After removing those elements, convert X to its absolute value and go to the next index and perform the same operation. 

// Return the sum of all elements present in the array after performing the above operation.  

// Note 

// You must operate only if ‘X’ is negative.
// For each new index, consider the modified array for operation.
// Input Format
// The first line contains an integer N.
// The second line contains N elements - the array elements.

// Output Format
// The output should return the final sum after performing the mentioned operation.

// Constraints
// 1 <= N <= 10^5. 

// -10^4<=A[i]<=10^4 for all (0<=i<N)

// Sample Testcase 0
// Testcase Input
// 5	   
// 4 2 2 3 -6 
// Testcase Output
// 10
// Explanation
// Given array is 4,2,2,3,-6 
// First, we push ‘a’ to stack.
// Here, indices 0,1,2 and 3 are positive, so there is no need to operate.
// Now at index 4, -6 is there. So x=-6.
// We delete elements until the sum is less than abs(x), i.e., 6.
// The minimum elements whose sum will be greater than or equal to abs(x) are 3(index=3), 2(index =2), and 2(index=1). So delete these three elements and convert x to its absolute value. 
// Now the array will be {4,6}.
// Hence the final answer will be 4+6=10.
//  So, the result is 10.
// Sample Testcase 1
// Testcase Input
// 7
// 2 -1 3 4 -4 2 3
// Testcase Output
// 13
// Explanation
// (abs(-1) + 3 + abs(-4) + 2 + 3)  =13

#include <iostream>
#include <vector>
#include <stack>

int good_sum(int N, std::vector<int> &A) {
    // Write your logic here
   std:: stack<int> st;
    for(int i=0;i<N;i++){
        if(A[i] >0 ){
            st.push(A[i]);
        }else{
            int tar= abs(A[i]);
            int sum=0;
                while(!st.empty() && sum < tar){
                    sum +=st.top();
                    st.pop();
                }
                st.push(tar);
            }
    }
    long long result=0;
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }
    return result;
    return 0;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }
    
    // Call user logic function and print the output
    int result = good_sum(N, A);
    std::cout << result << std::endl;
    return 0;
}