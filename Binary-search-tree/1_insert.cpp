
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

node* insert(node* root, int n) {
	if (root == NULL) {
		return new node(n);
	}

	if (root -> data > n) {
		root -> left = insert(root -> left, n);
	}
	if (root -> data < n) {
		root -> right = insert(root -> right, n);
	}

	return root;
}

void print(node* root) {
	if (root == NULL) {
		return;
	}

	print(root -> left);
	cout << root -> data << " ";
	print(root -> right);
	return;
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node *root = new node(60);
	root->left = new node(40);
	root->right = new node(80);
	root->left->left = new node(30);
	root->left->right = new node(50);
	root->right->left = new node(70);
	root->right->right = new node(90);

	root = insert(root, 10);

	print(root);

	return 0;
}