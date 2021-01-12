#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
	node(int k) {
		data = k;
		left = right = NULL;
	}
};

int solve(node* root) {
	if (root == NULL) {
		return 0;
	}

	int l = solve(root -> left);
	int r = solve(root -> right);

	return l + r + 1;
}

int main() {

	node *root = new node(10);
	root->left = new node(20);
	root->right = new node(30);
	root->left->left = new node(40);
	root->left->right = new node(50);
	root->right->left = new node(60);
	root->right->right = new node(70);

	cout << solve(root);

	return 0;
}