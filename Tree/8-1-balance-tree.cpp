#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	Node(int k) {
		data = k;
		left = right = NULL;
	}
};

int height(Node* root) {
	if (root == NULL) {
		return 0;
	}

	return max(height(root -> left), height(root -> right)) + 1;
}

bool isBalanced(Node* root) {
	if (root == NULL) {
		return true;
	}

	if (root -> left == NULL && root -> right == NULL) {
		return true;
	}

	int l = height(root -> left), r = height(root -> right);
	if (abs(l - r) > 1) {
		return false;
	}
	return isBalanced(root -> left) && isBalanced(root -> right);
}

int main() {

	Node *root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->left->left = new Node(40);
	root->left->right = new Node(50);
	root->right->left = new Node(60);
	root->right->right = new Node(70);

	cout << isBalanced(root);

	return 0;
}