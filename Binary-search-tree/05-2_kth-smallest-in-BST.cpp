
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

node* insert(node* root , int n) {
	if (root == NULL) {
		return new node(n);
	}

	if (root -> data > n) {
		root -> count += 1;
		root -> left = insert(root -> left, n);
	}
	else if (root -> data < n) {
		root -> right = insert(root -> right, n);
	}

	return root;
}

node* solve(node* root, int n) {
	if (root == NULL) {
		return root;
	}

	if (n == root -> count + 1) {
		return root;
	}

	if (n > root -> count + 1) {
		return solve(root -> right, n - root -> count - 1);
	}
	if (n < root -> count + 1) {
		return solve(root -> left, n);
	}

	return NULL;
}

void print(node* root) {
	if (root == NULL) {
		return;
	}

	print(root -> left);
	cout << root -> data << " " << root -> count << "\n";
	print(root -> right);
	return;
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node *root = NULL;

	root = insert(root, 60);
	root = insert(root, 40);
	root = insert(root, 30);
	root = insert(root, 50);
	root = insert(root, 80);
	root = insert(root, 70);
	root = insert(root, 90);

	cout << solve(root, 4) -> data;

	return 0;
}