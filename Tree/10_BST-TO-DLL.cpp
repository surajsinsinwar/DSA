#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;

	node(int key) {
		this -> data = key;
		this -> left = this -> right = NULL;
	}
};

node* solve(node* root) {

	if (root == NULL) {
		return root;
	}


	static node* head = NULL;
	static node* prev = NULL;

	solve(root -> left);

	if (prev == NULL) {
		head = root;
	}
	else {
		root -> left = prev;
		prev -> right = root;

	}

	prev = root;

	solve(root -> right);
	return head;
}

int main() {

	node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);

	root = solve(root);

	while (root != NULL) {
		cout << root -> data << " ";
		root = root -> right;
	}

	return 0;
}