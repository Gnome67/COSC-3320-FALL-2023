#include <bits/stdc++.h>
using namespace std;

struct Node
{
	struct Node* left, *right;
	int key;
};

struct Node* newNode(int key)
{
	struct Node* ptr = new Node;
	ptr->key = key;
	ptr->left = ptr->right = NULL;
	return ptr;
}

struct Node* insert(struct Node* root, int key)
{
	if (!root) { root = newNode(key); }
	else if (root->key > key) { root->left = insert(root->left, key); }
	else if (root->key < key) { root->right = insert(root->right, key); }
	return root;
}

int distanceFromRoot(struct Node* root, int x)
{
	if (root->key == x) { return 0; }
	else if (root->key > x) { return 1 + distanceFromRoot(root->left, x); }
	return 1 + distanceFromRoot(root->right, x);
}

int distanceBetween2(struct Node* root, int a, int b)
{
	if (!root) { return 0; }
	if (root->key > a && root->key > b) { return distanceBetween2(root->left, a, b); }
	if (root->key < a && root->key < b) { return distanceBetween2(root->right, a, b); }
	if (root->key >= a && root->key <= b) { return distanceFromRoot(root, a) + distanceFromRoot(root, b); }
}

int findDistWrapper(Node *root, int a, int b)
{
	if (a > b) { swap(a, b); }
	return distanceBetween2(root, a, b);
}

int main()
{
	string numbers;
	int node1 = 0, node2 = 0; 
	vector<int> question;
	struct Node* root = NULL;
	getline(cin, numbers);
	for(int x = 0; x < numbers.size(); x++)
	{
		if(!(isspace(numbers[x]))) { question.push_back(numbers[x] - 48); }
	}
	root = insert(root, question[0]);
	for(int y = 1; y < question.size(); y++) { insert(root, question[y]);  }
	cin >> node1; 
	cin >> node2;
	cout << findDistWrapper(root, node1, node2);
	return 0;
}
