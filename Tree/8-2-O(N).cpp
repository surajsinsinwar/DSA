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

int isBalanced(Node* root) {
	if (root == NULL) {
		return 0;
	}

	if (root -> left == NULL && root -> right == NULL) {
		return 1;
	}

	int l = isBalanced(root -> left), r = isBalanced(root -> right);
	if (l == -1 || r == -1 || abs(l - r) > 1) {
		return -1;
	}

	return max(l, r) + 1;
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