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

int main() {
IsBinaryTree_MaxHeap bt;

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

if (bt.isHeap(root) == true)
	std::cout << "Given binary tree is a Heap" << std::endl;
else
	std::cout << "Given binary tree is not a Heap" << std::endl;

return 0;
}

// This code is contributed by vikramshirsath177.
