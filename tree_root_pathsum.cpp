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


bool hasPathSum(Node *root, int tSum) {
    // Your code here
     if(root == NULL) return 0;
        bool ans = 0;
        int sbSum = tSum - root->data;
        if(sbSum == 0 && root->left ==NULL && root->right == NULL)
            return 1;
        if(root->left)
            ans=ans||hasPathSum(root->left  , sbSum);
        if(root->right)
            ans= ans ||hasPathSum(root->right  , sbSum);
        
        return ans;
}


 int main()
{
    struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);


	cout<<hasPathSum(root , 8)<<endl;



	return 0;

}