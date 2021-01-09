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

int height(node* root) {
	if (root == NULL) {
		return 0;
	}

	return max(height(root -> left), height(root -> right)) + 1;
}

void printKthLevel(node* root, int k) {
	if (root == NULL) {
		return;
	}

	if (k == 0) {
		cout << root -> data << " ";
		return;
	}

	printKthLevel(root -> left, k - 1);
	printKthLevel(root -> right, k - 1);

	return;
}

int main() {

	node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);

	printKthLevel(root, 1);

	return 0;
}