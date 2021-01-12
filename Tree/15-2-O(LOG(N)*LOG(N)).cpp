
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
	int l, r;
	l = r = 0;

	node* temp = root;
	while (temp != NULL) {
		l++;
		temp = temp -> left;
	}

	temp = root;
	while (temp != NULL) {
		r++;
		temp = temp -> right;
	}

	if (l == r) {
		return pow(2, l) - 1;
	}

	return 1 + solve(root -> left) + solve(root -> right);
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