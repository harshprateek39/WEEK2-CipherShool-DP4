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


int findans(Node* root , int &hyt){
    if(root == nullptr){
        return 0;
    }
    int lh = findans(root->left , hyt);
    int rh = findans(root->right , hyt);
    hyt = max(hyt , lh+rh);
    return 1+max(lh , rh);
}
    int diameterOfBinaryTree(Node* root) {
        int hyt = 0;
        findans(root ,hyt)-1;
        return hyt;
    }


    int main()
{
    struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);


	cout<<diameterOfBinaryTree(root)<<endl;



	return 0;

}