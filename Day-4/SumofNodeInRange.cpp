// Problem Statement
// You are given the root of the Binary Search Tree. You are also provided integers start and end.

// You have to return the sum of all the nodes that lie in the inclusive range of start and end.

// All the values in the tree are unique

// Input Format
// First line No of Nodes of Binary Search Tree.
// Second line contains the Nodes of Binary Search Tree
// Third line contains two integers start and end respectively
// Output Format
// Single integer that represents the sum of Node’s value in the inclusive range of start and end.

// Constraints
// 1<=No. Of Nodes <=1000
// 1<=Node’s value <=100000
// 1<=start < end<=100000
// Sample Testcase 0
// Testcase Input
// 3
// 0 5 6 
// 1 2
// Testcase Output
// 0
// Explanation
// There is no Node whose value lies in the range 1 and 2 inclusive.
// Sample Testcase 1
// Testcase Input
// 6
// 5 8 10 9 6 0 
// 3 9
// Testcase Output
// 28
// Explanation
// 5 8 9 6 are the Node’s value which lies in  the range 3 to 9 inclusive .
// 5+8+9+6=28
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insert_into_bst(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val <= root->val) root->left = insert_into_bst(root->left, val);
    else root->right = insert_into_bst(root->right, val);
    return root;
}

int dfs(TreeNode* root, int start, int end){
    if(root==NULL) return 0;
    int sum=0;
    if(root->val >= start && root->val <= end){
        sum+=root->val;
    }
    if(root->left!=NULL){
       sum+= dfs(root->left,start, end);
    }
    if(root->right!=NULL){
        sum+=dfs(root->right,start,end);
    }
    return sum;

}
int sum_of_values_in_range(TreeNode* root, int start, int end) {
    // Your logic here.
    int res=dfs(root, start,end);
    return res;
}

int main() {
    int n, start, end;
    cin >> n;
    int values[n];
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    cin >> start >> end;
    TreeNode* root = NULL;
    for (int i = 0; i < n; ++i) {
        root = insert_into_bst(root, values[i]);
    }
    int result = sum_of_values_in_range(root, start, end);
    cout << result << endl;
    return 0;
}