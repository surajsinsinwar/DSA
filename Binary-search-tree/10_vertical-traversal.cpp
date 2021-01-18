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

void solve(node* root) {
	vector<int> v;
	map<int, vector<int>> mp;

	queue<pair<Node*, int>> q;
	q.push({root, 0});
	while (q.empty() == false) {
		auto p = q.front();
		Node *curr = p.first;
		int hd = p.second;
		mp[hd].push_back(curr->data);
		q.pop();
		if (curr->left != NULL)
			q.push({curr->left, hd - 1});
		if (curr->right != NULL)
			q.push({curr->right, hd + 1});
	}
	for (auto x : mp) {
		for (int y : x.second) {
			cout << y << " ";
		}
		cout << "\n";
	}

	return v;
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

	solve(root);

	return 0;
}