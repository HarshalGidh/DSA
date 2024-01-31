#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> allPossibleBSTs(int start, int end) {
        // Base Case:
        if (start > end) return {0}; // return NULL
        if (start == end) return {new TreeNode(start)}; // creating an end node and returning it

        // traversing each node once and considering them as root:
        vector<TreeNode*> ans;
        for (int i = start; i <= end; i++) {
            // get all left nodes:
            vector<TreeNode*> left = allPossibleBSTs(start, i - 1);
            // get all right nodes:
            vector<TreeNode*> right = allPossibleBSTs(i + 1, end);
            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j]; // to get multiple possible combinations of left
                    root->right = right[k]; // to get multiple possible combinations of right
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }

    // create a dp map:
    map<pair<int, int>, vector<TreeNode*>> dp;
    vector<TreeNode*> allPossibleBSTsTD(int start, int end) {
        // Base Case:
        if (start > end) return {0}; // return NULL
        if (start == end) return {new TreeNode(start)}; // creating an end node and returning it
        if (dp.find({start, end}) != dp.end()) return dp[{start, end}];
        // traversing each node once and considering them as root:
        vector<TreeNode*> ans;
        for (int i = start; i <= end; i++) {
            // get all left nodes:
            vector<TreeNode*> left = allPossibleBSTsTD(start, i - 1);
            // get all right nodes:
            vector<TreeNode*> right = allPossibleBSTsTD(i + 1, end);
            for (int j = 0; j < left.size(); j++) {
                for (int k = 0; k < right.size(); k++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j]; // to get multiple possible combinations of left
                    root->right = right[k]; // to get multiple possible combinations of right
                    ans.push_back(root);
                }
            }
        }
        return dp[{start, end}] = ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        // return allPossibleBSTs(1, n);
        return allPossibleBSTsTD(1, n);
    }
};

int main() {
    Solution solution;

    // Example 1:
    int n1 = 3;
    vector<TreeNode*> result1 = solution.generateTrees(n1);
    cout << "Example 1: " << endl;
    for (auto root : result1) {
        // You can write a helper function to print the tree structure
        // Here, let's just print the root values
        cout << root->val << ", ";
    }
    cout << endl;

    // Example 2:
    int n2 = 1;
    vector<TreeNode*> result2 = solution.generateTrees(n2);
    cout << "Example 2: " << endl;
    for (auto root : result2) {
        cout << root->val << ", ";
    }
    cout << endl;

    return 0;
}
