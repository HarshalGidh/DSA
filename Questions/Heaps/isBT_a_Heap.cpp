#include <iostream>

class Node {
public:
int data;
Node* left;
Node* right;
Node(int data) {
	this->data = data;
	left = NULL;
	right = NULL;
}
};

class IsBinaryTree_MaxHeap {
public:
bool isHeap(Node* tree) {
	bool result = true;

	// check if child is greater than parent
	if (tree != NULL && (tree->left != NULL && tree->left->data > tree->data) ||
		(tree->right != NULL && tree->right->data > tree->data)) {
	return false;
	}

	// check if left subtree has children but right is null
	if (tree->left != NULL) {
	if ((tree->left->left != NULL || tree->left->right != NULL) && tree->right == NULL) {
		return false;
	}
	}

	// check if right subtree has children and left is null
	if (tree->right != NULL) {
	if ((tree->right->left != NULL || tree->right->right != NULL) && tree->left == NULL) {
		return false;
	}
	}

	// check if right subtre has children but not left subtree
	if (tree->left != NULL) {
	if (tree->left->left == NULL && tree->left->right == NULL) {
		if (tree->right != NULL) {
		if (tree->right->left != NULL || tree->right->right != NULL) {
			return false;
		}
		}
	}
	}

	// recursively call for left and right subtree
	if (tree != NULL && tree->left != NULL) {
	bool l = isHeap(tree->left);
	result = result & l;
	}
	if (tree != NULL && tree->right != NULL) {
	bool r = isHeap(tree->right);
	result = result & r;
	}

	return result;
}
};
class Solution {
  public:
    int countNodes(Node* root){
      if(!root) return 0;
      int leftAns = countNodes(root->left);
      int rightAns = countNodes(root->right);
      return 1 + leftAns + rightAns ;
    }
    bool isCBT(Node* root,int i,int &n){
        if(!root) return true;
        if(i > n) return false; //index cant be greater than no. of Nodes
        return isCBT(root->left,2*i,n) && isCBT(root->right,2*i + 1, n);
    }
    bool isMaxHeap(Node* root){
        if(!root) return true;
        bool l = isMaxHeap(root->left);
        bool r = isMaxHeap(root->right);
        bool ans = true;
        if(!root->left && !root->right) ans =  true;
        if(root->left && !root->right) ans = root->data >root->left->data;
        else if(root->left && root->right){
            bool leftAns = root->data > root->left->data ;
            bool rightAns = root->data > root->right->data;
            ans = leftAns && rightAns;
        }
        return ans && l && r ;
    }
    bool isHeap(struct Node* tree) {
        int n = countNodes(tree);
        if(n == 0) return true;
        int i = 1; //heap is 1 indexed
        bool CBT = isCBT(tree,i,n);
        bool validHeap = isMaxHeap(tree);
        return CBT && validHeap ;
    }
};

int main() {
	//IsBinaryTree_MaxHeap bt;
	Solution sol;
	Node* root = new Node(10);
	root->left = new Node(9);
	root->right = new Node(8);
	root->left->left = new Node(7);
	root->left->right = new Node(6);
	root->right->left = new Node(5);
	root->right->right = new Node(4);
	root->left->left->left = new Node(3);
	root->left->left->right = new Node(2);
	root->left->right->left = new Node(1);

	if (sol.isHeap(root) == true)
		std::cout << "Given binary tree is a Heap" << std::endl;
	else
		std::cout << "Given binary tree is not a Heap" << std::endl;

	return 0;
}

// This code is contributed by vikramshirsath177.
