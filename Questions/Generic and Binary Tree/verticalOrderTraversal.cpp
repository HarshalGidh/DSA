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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int,int>>> q;//Node ,(row,col)
        map<int,map<int,multiset<int>>>mp; //col->map->row->vector containing value of Node
        q.push({root,{0,0}}) ;//root is at {0,0}
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            TreeNode* &node = front.first;
            auto coordinate = front.second;
            int &row = coordinate.first;
            int &col = coordinate.second;
            mp[col][row].insert(node->val);
            if(node->left){ //go left
                q.push({node->left,{row + 1, col - 1}});
            }
            if(node->right){ //go right
                q.push({node->right,{row + 1,col + 1}});
            }
        }
        //store vertical order in ans 
        for(auto it : mp){
            auto &colMap = it.second; //to get the col->row->multiset map
            vector<int>verticalLine;
            for(auto colMapIt :colMap){
                auto &mset = colMapIt.second;
                verticalLine.insert(verticalLine.end(),mset.begin(),mset.end());
            }
            ans.push_back(verticalLine);
        }
        return ans;
    }
};