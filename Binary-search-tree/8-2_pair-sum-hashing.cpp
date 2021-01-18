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


bool solve(node* root, unordered_set<int> &s, int sum) {
	if (root == NULL) {
		return false ;
	}

	if (solve(root -> left, s, sum)) {
		return true;
	}

	if (s.find(sum - root -> data) != s.end()) {
		return true;
	}

	s.insert(root -> data);

	return solve(root -> right, s, sum);
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

	unordered_set<int> s;

	cout << solve(root, s, 10);

	return 0;
}