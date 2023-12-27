#include <iostream>
#include<queue>
using namespace std;

class TreeNode{
  public:
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
	  this->data = val;
	  this->left = NULL;
	  this->right = NULL;
	}


};

//it returns root node of the created tree
TreeNode* createTree() {
  cout << "enter the value for Node: " << endl;
  int data;
  cin >> data;

  if(data == -1) {
	return NULL;
  }
  //Step1: create Node
  TreeNode* root = new TreeNode(data);
  //Step2: Create left subtree
  //cout << "left of Node: " << root->data << endl;
  root->left = createTree();
  //Step3: Craete right subtree
  //cout << "right of Node: " << root->data << endl;
  root->right = createTree();
  return root;

}
void levelOrderTraversal(TreeNode* root) {
	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);

	//asli traversal start krete h 

	while(!q.empty()) {
		TreeNode* front = q.front();
		q.pop();

		if(front == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			//valid node wala case
			cout << front->data << " ";

			if(front->left != NULL) {
				q.push(front->left);
			}
			if(front->right != NULL) {
				q.push(front->right);
			}
		}
	}
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL )
        return NULL;
        if(root->data == p->data) {
             return p;
        }
        if(root->data == q->data) {
            return q;
        }
        
        TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);

        if(leftAns == NULL && rightAns == NULL)
            return NULL;
        else if(leftAns != NULL && rightAns == NULL)
            return leftAns;
        else if(leftAns == NULL && rightAns != NULL)
            return rightAns;
        else 
        return root;




    }
};
int main() {

    TreeNode* root = createTree();
    TreeNode* LCA = lowestCommonAncestor(root,)
	cout << "Level Order : ";
	levelOrderTraversal(root);
	cout << endl;

  return 0;
}