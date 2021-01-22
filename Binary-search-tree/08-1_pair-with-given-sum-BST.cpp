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


void solve(node* root, vector<int> &v) {
	if (root == NULL) {
		return;
	}

	solve(root -> left, v);
	v.push_back(root -> data);
	solve(root -> right, v);
	return;
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

	vector<int> v;

	solve(root, v);

	int i = 0, j = v.size() - 1;
	bool flag = 0;

	int sum = 60;

	while (i < j) {
		if (v[i] + v[j] == sum) {
			cout << "YES\n";
			flag = 1;
			break;
		}
		else if (v[i] + v[j] < sum) {
			i++;
		}
		else {
			j--;
		}
	}

	if (!flag) {
		cout << "NO\n";
	}

	return 0;
}