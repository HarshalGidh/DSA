// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Node of the binary tree
struct node {
	int data;
	node* left;
	node* right;
	node(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

// Function to print flattened
// binary Tree
void print(node* parent)
{
	node* curr = parent;
	while (curr != NULL)
		cout << curr->data << " ", curr = curr->right;
}

// Function to perform in-order traversal
// recursively
void inorder(vector<int>& traversal, node* parent)
{
	// Base Case
	if (parent == NULL)
		return;

	inorder(traversal, parent->left);
	// Storing the values in the vector
	traversal.push_back(parent->data);

	inorder(traversal, parent->right);
}

void form(int pos, vector<int> traversal, node*& prev)
{
	// Base Case
	if (pos == traversal.size())
		return;

	prev->right = new node(traversal[pos]);
	prev->left = NULL;

	prev = prev->right;

	// calling for the next element of the vector
	form(pos + 1, traversal, prev);
}
// Function to flatten binary tree using
// level order traversal
node* flatten(node* parent)
{

	// Dummy node
	node* dummy = new node(-1);

	// Pointer to previous element
	node* prev = dummy;

	// vector to store the inorder traversal of the binary
	// tree
	vector<int> traversal;
	inorder(traversal, parent);

	// forming the sorted list from the vector obtained
	form(0, traversal, prev);

	prev->left = NULL;
	prev->right = NULL;
	node* ret = dummy->right;

	// Delete dummy node
	delete dummy;
	return ret;
}

int main()
{

	node* root = new node(5);
	root->left = new node(3);
	root->right = new node(7);
	root->left->left = new node(2);
	root->left->right = new node(4);
	root->right->left = new node(6);
	root->right->right = new node(8);

	// Calling required function
	print(flatten(root));

	return 0;
}
