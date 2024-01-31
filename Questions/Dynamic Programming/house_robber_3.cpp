#include <iostream>
#include <unordered_map>
#include <algorithm> // for std::max

/**
 * Definition for a binary tree node.
 */
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
    int solveUsingRecursion(TreeNode* root){
        //Base Case :
        if(!root) return 0; //No root then no robbery
        int include = 0, exclude = 0;
        //rob this house :
        include += root->val;
        //rob left of left and right house :
        if(root->left){
            include += solveUsingRecursion(root->left->left) + solveUsingRecursion(root->left->right) ;
        }
        //rob right of left and right house :
        if(root->right){
            include += solveUsingRecursion(root->right->left) + solveUsingRecursion(root->right->right) ;
        }
        //else dont rob this house :
        exclude += solveUsingRecursion(root->left) + solveUsingRecursion(root->right) ;
        //Return Max of Include and Exclude :
        return std::max(include,exclude);
    }

    //Using Memoization :

    int solveUsingRecursionTD(TreeNode* root, std::unordered_map<TreeNode*,int>& dp){
        //Base Case :
        if(!root) return 0; //No root then no robbery
        if(dp.find(root) != dp.end()) return dp[root] ;
        int include = 0, exclude = 0;
        //rob this house :
        include += root->val;
        //rob left of left and right house :
        if(root->left){
            include += solveUsingRecursionTD(root->left->left, dp) + solveUsingRecursionTD(root->left->right, dp) ;
        }
        //rob right of left and right house :
        if(root->right){
            include += solveUsingRecursionTD(root->right->left, dp) + solveUsingRecursionTD(root->right->right, dp) ;
        }
        //else dont rob this house :
        exclude += solveUsingRecursionTD(root->left, dp) + solveUsingRecursionTD(root->right, dp) ;
        //Return Max of Include and Exclude :
        return dp[root] = std::max(include, exclude);
    }

    int rob(TreeNode* root) {
        //return solveUsingRecursion(root);
        //creating dp map :
        std::unordered_map<TreeNode*, int> dp;
        return solveUsingRecursionTD(root, dp) ;
    }
};

// Main function
int main() {
    Solution solution;

    // Example 1
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->right = new TreeNode(3);
    root1->right->right = new TreeNode(1);

    std::cout << "Example 1: " << solution.rob(root1) << std::endl;

    // Example 2
    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(4);
    root2->right = new TreeNode(5);
    root2->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(3);
    root2->right->right = new TreeNode(1);

    std::cout << "Example 2: " << solution.rob(root2) << std::endl;

    // Clean up allocated memory
    delete root1;
    delete root2;

    return 0;
}
