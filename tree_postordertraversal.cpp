#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }


};

void postorder(Node* root){
    if(root == nullptr) return ;
    if(root->left) postorder(root->left);
    if(root->right) postorder(root->right);
    cout<<root->data<<" ";

}
int main()
{
    struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);


	postorder(root);


	return 0;

}