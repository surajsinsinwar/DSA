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

	return max(height(root -> right), height(root -> left)) + 1;
}

int solve(Node* root) {
	if (root == NULL) {
		return 0;
	}

	int l = height(root -> left), r = height(root -> right);
	return max(l + r + 1, max(solve(root -> right), solve(root -> left)));
}

int main() {

	Node *root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->left->left = new Node(40);
	root->left->right = new Node(50);
	root->right->left = new Node(60);
	root->right->right = new Node(70);

	cout << solve(root);

	return 0;
}