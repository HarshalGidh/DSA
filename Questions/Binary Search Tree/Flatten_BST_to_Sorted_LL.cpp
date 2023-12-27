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
void levelOrderTraversal(node* root){
  queue<node*> q;
  q.push(root);
  q.push(NULL);
  while(!q.empty()){
    node*front = q.front();q.pop();
    if(!front){
      cout<<endl;
      if(!q.empty()) q.push(NULL);
    }
    else{
      cout<<front->data<<" ";
      if(front->left)
        q.push(front->left);
      if(front->right)
        q.push(front->right);
    }
  }
}

// Function to print flattened
// binary Tree
void print(node* parent)
{
	node* curr = parent;
	while (curr != NULL)
		cout << curr->data << "->", curr = curr->right;
}

// Function to perform in-order traversal
// recursively
void in(node* root,node* &prev)
{
	if(!root) return ;
  in(root->left,prev); //left
  prev->left = NULL;
  prev->right = root;
  prev = root;
  in(root->right,prev);
}
node* flatten(node* root)
{
	// Dummy node
	node* dummy = new node(-1);
	// Pointer to previous element
	node* prev = dummy;
	// vector to store the inorder traversal of the binary
	// tree
	vector<int> traversal;
	in(root, prev);
	// forming the sorted list from the vector obtained
	//form(0, traversal, prev);
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
  cout<<"Printing Binary Search Tree :"<<endl;
  levelOrderTraversal(root);
	// Calling required function
  cout<<"Printing LinkedList :"<<endl;
	print(flatten(root));

	return 0;
}
