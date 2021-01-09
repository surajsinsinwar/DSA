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

bool path(node* root, vector<int> &v, int n) {
	if (root == NULL) {
		return 0;
	}

	v.push_back(root -> data);

	if (root -> data == n || path(root -> left, v, n) || path(root -> right, v, n)) {
		return 1;
	}

	v.pop_back();
	return 0;
}

void solve(node* root, int n1, int n2) {
	vector<int> v1, v2;


	if (path(root, v1, n1) && path(root, v2, n2)) {

		for (int i = 0; i < min(v1.size(), v2.size()); i++) {
			if (v1[i + 1] != v2[i + 1]) {
				cout << v1[i];
				return;
			}
		}
	}
	cout << "NULL";
	return;
}

int main() {

	node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);

	solve(root, 4, 5);

	return 0;
}