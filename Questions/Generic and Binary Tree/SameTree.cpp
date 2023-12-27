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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //Base Case
        if(!p && !q) return true ; //both are null so same in structure so far
        if(p && q){
            return (p->val == q->val) 
                    && isSameTree(p->left,q->left)
                    && isSameTree(p->right,q->right);
        //returning true or false if value are same and calling recursion to check other nodes
        }
        return false; //not identical
    }
};
//T.C. = O(n) worst case is when we traverse the whole tree