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

void print(node* root) {
	if (root == NULL) {
		return;
	}

	print(root -> left);
	cout << root -> data << " ";
	print(root -> right);
	return;
}


node *prevv = NULL, *f = NULL, *s = NULL;

void solve(node* root) {
	if (root == NULL) {
		return;
	}

	solve(root -> left);

	if (prevv != NULL && root -> data < prevv -> data) {
		if (f == NULL) {
			f = prevv;
		}
		s = root;
	}

	prevv = root;

	solve(root -> right);
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
	root->left->left = new node(90);
	root->left->right = new node(50);
	root->right->left = new node(70);
	root->right->right = new node(10);

	print(root);
	cout << "\n";
	solve(root);
	int temp = f -> data;
	f -> data = s -> data;
	s -> data = temp;

	print(root);

	return 0;
}