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



 Node* build(vector<int>& preorder, vector<int>& inorder,int &idx , int left , int ryt){
        if(left > ryt) return nullptr;
        int pivot = left;
        while(inorder[pivot] != preorder[idx]) pivot++;
        idx++;
        Node* newNode = new Node(inorder[pivot]);
        newNode->left = build(preorder , inorder , idx , left , pivot-1);
        newNode->right = build(preorder , inorder , idx , pivot+1 , ryt);

        return newNode;
    }

    Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
            int idx = 0;
        return build(preorder , inorder , idx  , 0 , inorder.size()-1);
        
    }

    int main()
    {
        vector<int> preorder = { 2,3,4,5,7,8};
        vector<int> inorder = {5,3,2,7,8,4};
        buildTree(preorder, inorder);
        
        
    }