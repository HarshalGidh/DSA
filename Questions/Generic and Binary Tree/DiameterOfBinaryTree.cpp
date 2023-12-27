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
    int Diameter = 0;
    int height(TreeNode* root){
        if(!root) return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int CurrDiameter = leftHeight + rightHeight;
        Diameter = max(Diameter,CurrDiameter);
        return max(leftHeight,rightHeight) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        height(root);
        return Diameter;
    }
};