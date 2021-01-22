
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

node* delnode(node* root, int n) {
	if (root == NULL) {
		return NULL;
	}

	if (root -> data > n) {
		root -> left = delnode(root -> left, n);
	}
	else if (root -> data < n) {
		root -> right = delnode(root -> right, n);
	}
	else {

		if (root -> left == NULL) {
			node* temp = root -> right;
			delete(root);
			return temp;
		}
		else if (root -> right == NULL) {
			node* temp = root -> left;
			delete(root);
			return temp;
		}
		else {
			node* temp = root -> right;
			while (temp && temp -> left != NULL) {
				temp = temp -> left;
			}

			root -> data = temp -> data;
			root -> right = delnode(root -> right, temp -> data);
		}
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

	root = delnode(root, 90);

	print(root);

	return 0;
}