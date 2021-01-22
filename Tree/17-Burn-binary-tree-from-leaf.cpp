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

int ma = 0;

int solve(node* root, int n, int &d) {
	if (root == NULL) {
		return 0;
	}

	if (root -> data == n) {
		d = 0;
		return 1;
	}

	int ld = -1, rd = -1;
	int l = solve(root -> left, n, ld);
	int r = solve(root -> right, n, rd);

	if (ld != -1) {
		d = ld + 1;
		ma = max(ma, ld + r);
	}
	else if (rd != -1) {
		d = rd + 1;
		ma = max(ma, rd + l);
	}

	return max(l, r) + 1;
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node *root = new node(10);
	root->left = new node(20);
	root->right = new node(30);
	root->left->left = new node(40);
	root->left->right = new node(50);
	root->right->left = new node(60);
	root->right->right = new node(70);

	int d = -1;
	solve(root, 40, d);
	cout << ma;

	return 0;
}