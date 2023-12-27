/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool BalancedTree = true;
    int height(TreeNode* root){
        if(!root) return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        //checking balance or not :
        if(BalancedTree && abs(leftHeight - rightHeight) > 1){
            BalancedTree = false;
        }
        return max(leftHeight,rightHeight) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        height(root);
        return BalancedTree;
    }
};