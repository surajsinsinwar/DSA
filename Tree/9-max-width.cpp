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

int maxWidth(Node* root) {
	if (root == NULL) {
		return 0;
	}

	queue<Node*> q;
	q.push(root);
	int n = 1, ma = 1;
	Node* temp = NULL;

	while (!q.empty()) {
		n = q.size();
		ma = max(ma, n);
		while (n--) {
			temp = q.front();
			q.pop();

			if (temp -> left != NULL) {
				q.push(temp -> left);
			}
			if (temp -> right != NULL) {
				q.push(temp -> right);
			}
		}
	}

	return ma;
}

int main() {

	Node *root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->left->left = new Node(40);
	root->left->right = new Node(50);
	root->right->left = new Node(60);
	root->right->right = new Node(70);

	cout << maxWidth(root);

	return 0;
}