
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data, count;
	struct node *left;
	struct node *right;
	node(int k) {
		data = k;
		left = right = NULL;
		count = 0;
	}
};

int solve(node* root, int &n) {
	if (root == NULL) {
		return -1;
	}

	int l = solve(root -> left, n);
	if (l != -1) {
		return l;
	}
	n--;

	if (n == 0) {
		return root -> data;
	}

	return solve(root -> right, n);
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

	int n = 2;
	cout << solve(root, n);

	return 0;
}