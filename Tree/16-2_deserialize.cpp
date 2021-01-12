
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


int n = 0;
node* solve(vector<int> &v) {
	if (n == (int)v.size()) {
		return NULL;
	}

	int temp = v[n++];

	if (temp == -1) {
		return NULL;
	}

	node* root = new node(temp);

	root -> left = solve(v);
	root -> right = solve(v);
	return root;
}

void print(node* root) {
	if (root == NULL) {
		return;
	}

	cout << root -> data << " ";
	print(root -> left);
	print(root -> right);
	return;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// node *root = new node(10);
	// root->left = new node(20);
	// root->right = new node(30);
	// root->left->left = new node(40);
	// root->left->right = new node(50);
	// root->right->left = new node(60);
	// root->right->right = new node(70);

	vector<int> v(15);
	for (int i = 0; i < 15; i++) {
		cin >> v[i];
	}

	node* root = solve(v);

	print(root);

	return 0;
}