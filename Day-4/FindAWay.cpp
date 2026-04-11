// Problem Statement
// Robert wants to organize a marathon across your city.

// The city has landmarks numbered from to that can act as starting or finishing points. The landmarks are connected by roads. Each road has a length of n. The city map resembles a binary tree in which each landmark represents a vertex of the tree, and each road represents an edge. The tree is rooted at vertex 1.

// As the first step in planning, he wants to find the longest simple path between any two landmarks in the city.

// Help Robert to find the maximum length of the marathon he can organize.

// Input Format
// The first line contains an integer  - the number of landmarks in the city.

// The next n lines describe the binary tree structure of the city. The ith line contains two integers li and ri – the indices of the left and right children of the ith vertex, respectively. If some child doesn't exist, then the number “-1” is set instead.

// It is guaranteed that the given graph is a binary tree rooted at vertex 1.

// Output Format
// The output should consist of a single integer in a new line, the maximum length of the marathon that Robert can organize.

// Constraints
//  1 ≤ n ≤ 4*10^4

// 1 ≤ l, r  ≤ n or l, r = -1

// Sample Testcase 0
// Testcase Input
// 5
// 2 3
// -1 -1
// 4 5
// -1 -1
// -1 -1
// Testcase Output
// 3
// Explanation
// From the given tree, we can observe that length of one of the longest paths highlighted in the figure is 4. One of the ways to organize the marathon is to start at landmark 2 and end at landmark 4.
// Sample Testcase 1
// Testcase Input
// 7
// 5 3
// -1 -1
// -1 -1
// -1 -1
// 7 2
// -1 4
// 6 -1
// Testcase Output
// 5
// Explanation
// From the given tree, we can see that the highlighted path is the longest, and its length is 5. The marathon can be started at landmark 3 and ended at landmark 4

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int diameter = 0;

// function to calculate height and update diameter
int height(TreeNode* root) {
    if (root == NULL) return 0;

    int left = height(root->left);
    int right = height(root->right);

    // update diameter
    diameter = max(diameter, left + right);

    // return height
    return 1 + max(left, right);
}

// main logic
int user_logic(TreeNode* root) {
    diameter = 0;
    height(root);
    return diameter;
}

// FIXED tree construction
TreeNode* construct_tree(int i, const vector<pair<int, int>>& nodes) {
    if (i < 0 || i >= nodes.size()) {
        return nullptr;
    }

    TreeNode* node = new TreeNode(i + 1);

    if (nodes[i].first != -1) {
        node->left = construct_tree(nodes[i].first - 1, nodes);
    }

    if (nodes[i].second != -1) {
        node->right = construct_tree(nodes[i].second - 1, nodes);
    }

    return node;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> nodes(n);
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i].first >> nodes[i].second;
    }

    TreeNode* root = construct_tree(0, nodes);

    int result = user_logic(root);
    cout << result << endl;

    return 0;
}