// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

// A Binary Tree node 
struct Node {

	int key;
	struct Node *left, *right;

};

Node * newNode(int k) {

	Node *temp = new Node;
	temp->key = k;
	temp->left = temp->right = NULL;
	return temp;
}

bool findPath(Node *root, vector<int> &path, int k) {

	if (root == NULL)
		return false;

	path.push_back(root->key);

	if (root->key == k)
		return true;

	if ((root->left && findPath(root->left, path, k)) ||
		(root->right && findPath(root->right, path, k)))
		return true;

	path.pop_back();
	return false;
}

int findLCA(Node *root, int n1, int n2) {

	vector<int> path1, path2;

	if (!findPath(root, path1, n1) || !findPath(root, path2, n2))
		return -1;

	int i;
	for (i = 0; i < path1.size() && i < path2.size(); i++)
		if (path1[i] != path2[i])
			break;
	return path1[i - 1];
}

int main() {

	Node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	cout << "LCA(4, 5) = " << findLCA(root, 4, 5);
	cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6);
	cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4);
	cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
