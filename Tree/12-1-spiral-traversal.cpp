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

	queue<Node*> q;
	stack<int> st;
	Node* temp;
	int count;
	bool flag = 0;

	q.push(root);

	while (!q.empty()) {
		count = q.size();

		while (count--) {
			temp = q.front();
			q.pop();

			if (flag) {
				st.push(temp -> data);
			}
			else {
				cout << temp -> data << " ";
			}

			if (temp -> left != NULL) q.push(temp -> left);
			if (temp -> right != NULL) q.push(temp -> right);
		}

		if (flag) {
			while (!st.empty()) {
				cout << st.top() << " ";
				st.pop();
			}
		}

		flag = flag ? 0 : 1;
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