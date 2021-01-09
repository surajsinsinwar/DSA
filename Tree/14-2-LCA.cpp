
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	Node(int k) {
		data = k;
		left = right = NULL;
	}
};

Node* solve(Node* root, int n1, int n2) {
	if (root == NULL) {
		return NULL;
	}

	if (root -> data == n1 || root -> data == n2) {
		return root;
	}

	Node* l1 = solve(root -> left, n1, n2);
	Node* l2 = solve(root -> right, n1, n2);

	if (l1 != NULL && l2 != NULL) {
		return root;
	}
	else if (l1 != NULL) {
		return l1;
	}
	else {
		return l2;
	}
}

int main() {

	Node *root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->left->left = new Node(40);
	root->left->right = new Node(50);
	root->right->left = new Node(60);
	root->right->right = new Node(70);

	cout << solve(root, 60, 70) -> data;

	return 0;
}