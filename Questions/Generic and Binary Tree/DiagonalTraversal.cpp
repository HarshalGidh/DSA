#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> diagonal(Node *root) {
    vector<int> ans;
    queue<Node*> q;
    if (!root) return ans;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        while (temp) {
            ans.push_back(temp->data);
            if (temp->left) {
                q.push(temp->left);
            }
            temp = temp->right;
        }
    }
    return ans;
}

int main() {
    // Create a sample binary tree for testing
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Test the diagonal function
    vector<int> result = diagonal(root);

    // Display the result
    cout << "Diagonal Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
