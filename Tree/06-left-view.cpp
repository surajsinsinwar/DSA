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

void printLeft(Node* root) {
	if (root == NULL) {
		return;
	}

	queue<Node*> q;

	q.push(root);
	int n = 1;
	Node* temp = NULL;

	while (!q.empty()) {

		cout << q.front() -> data << " ";
		while (n--) {
			temp = q.front();
			q.pop();

			if (temp -> left != NULL) q.push(temp -> left);
			if (temp -> right != NULL) q.push(temp -> right);
		}
		n = q.size();
	}

	return;
}

int maxL = 0;
void printLeftRec(Node* root, int l) {
	if (root == NULL) {
		return;
	}

	if (maxL < l) {
		cout << root -> data << " ";
		maxL = l;
	}

	printLeftRec(root -> left, l + 1);
	printLeftRec(root -> right, l + 1);
}

int main() {

	Node *root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->left->left = new Node(40);
	root->left->right = new Node(50);
	root->right->left = new Node(60);
	root->right->right = new Node(70);

	printLeft(root);
	cout << "\n";
	printLeftRec(root, 1);

	return 0;
}