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

int ma = 0;
int solve(Node* root) {
	if (root == NULL) {
		return 0;
	}

	int l = solve(root -> left);
	int r = solve(root -> right);

	ma = max(ma, l + r + 1);

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

	solve(root);

	cout << ma;

	return 0;
}