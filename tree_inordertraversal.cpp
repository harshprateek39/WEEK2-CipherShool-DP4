#include <bits/stdc++.h>
using namespace std;


struct Node {
	int data;
	struct Node *left, *right;
    Node(int val){
        data = val;
        left  = nullptr;
        right = nullptr;
    }
};


void printInorder(struct Node* node)
{
	if (node == NULL)
		return;

	printInorder(node->left);

	cout << node->data << " ";

	printInorder(node->right);
}

int main()
{
	struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);


	printInorder(root);


	return 0;
}
