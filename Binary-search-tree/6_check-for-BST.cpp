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

bool solve(node* root, int mi, int ma) {
	if (root == NULL) {
		return true;
	}

	return ( root -> data > mi && root -> data < ma && solve(root -> left, mi, root -> data) && solve(root -> right, root -> data, ma));
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
	root->right->right = new node(50);

	cout << solve(root, INT_MIN, INT_MAX);

	return 0;
}