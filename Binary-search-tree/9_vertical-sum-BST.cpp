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


void solve(node* root, unordered_map<int, int> &m, int n) {
	if (root == NULL) {
		return;
	}

	solve(root -> left, m, n - 1);
	m[n] += root -> data;
	solve(root -> right, m, n + 1);

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
	root->left->left = new node(10);
	root->left->right = new node(50);
	root->right->left = new node(70);
	root->right->right = new node(90);

	unordered_map<int, int> m;
	cout << "y";


	solve(root, m, 0);

	cout << m.size();

	for (auto i : m) {
		cout << i.second << " ";
	}

	return 0;
}