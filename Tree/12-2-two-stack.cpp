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

void solve(Node* root) {
	if (root == NULL) {
		return;
	}

	stack<Node*> s1, s2;
	s1.push(root);
	Node* temp;

	while (!s1.empty() || !s2.empty()) {
		while (!s1.empty()) {
			temp = s1.top();
			s1.pop();

			cout << temp -> data << " ";

			if (temp -> left != NULL) s2.push(temp -> left);
			if (temp -> right != NULL) s2.push(temp -> right);
		}

		while (!s2.empty()) {
			temp = s2.top();
			s2.pop();

			cout << temp -> data << " ";

			if (temp -> right != NULL) s1.push(temp -> right);
			if (temp -> left != NULL) s1.push(temp -> left);
		}
	}

	return;
}

int main() {

	Node *root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->left->left = new Node(40);
	root->left->right = new Node(50);
	root->right->left = new Node(60);
	root->right->right = new Node(70);

	solve(root);

	return 0;
}