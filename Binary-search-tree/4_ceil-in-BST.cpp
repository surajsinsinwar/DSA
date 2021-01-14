
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

int solve(node* root, int n) {
	int ma = INT_MAX;

	while (root != NULL) {
		if (root -> data == n) {
			return n;
		}
		else if (root -> data > n) {
			ma = min(ma, root -> data);
			root = root -> left;
		}
		else {
			root = root -> right;
		}
	}

	return ma;
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

	cout << solve(root, 88);

	return 0;
}