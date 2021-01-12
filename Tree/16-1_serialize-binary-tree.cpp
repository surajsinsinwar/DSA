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

void solve(node* root, vector<int> &v) {
	if (root == NULL) {
		v.push_back(-1);
		return;
	}

	v.push_back(root -> data);
	solve(root -> left, v);
	solve(root -> right, v);
	return;
}

int main() {

	node *root = new node(10);
	root->left = new node(20);
	root->right = new node(30);
	root->left->left = new node(40);
	root->left->right = new node(50);
	root->right->left = new node(60);
	root->right->right = new node(70);

	vector<int> v;
	solve(root, v);

	for (auto i : v) {
		cout << i << " ";
	}

	return 0;
}