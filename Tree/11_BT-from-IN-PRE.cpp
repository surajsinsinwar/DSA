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


node* solve(int in[], int pre[], int s, int e) {

	static int prev = 0;

	if (s > e) {
		return NULL;
	}

	node* root = new node(pre[prev++]);

	int index = 0;
	for (int i = s; i <= e; i++) {
		if (root -> data == in[i]) {
			index = i;
			break;
		}
	}

	root -> left = solve(in, pre, s, index - 1);
	root -> right = solve(in, pre, index + 1, e);
	return root;
}

void inorder(node *root) {
	if (root == NULL) {
		return;
	}

	solve(root -> left);
	cout << root -> data << " ";
	solve(root -> right);

	return;
}

int main() {

	int in[] = {40, 20, 50, 10, 30, 80, 70};
	int pre[] = {10, 20, 40, 50, 30, 70, 80, 90};

	node* root = solve(in, pre, 0, 6);

	inorder(root);

	return 0;
}