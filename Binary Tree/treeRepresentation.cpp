#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *left, *right;
    Node(){
        this->data = 0;
        left = NULL;
    }
    Node(int data){
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

Node* solve(vector<int>&arr,int start){
    if(start>=arr.size())
        return NULL;
    Node *root=new Node(arr[start]);

    root->left=solve(arr,start*2+1);
    root->right=solve(arr,start*2+2);

    return root;
}
Node* createTree(vector<int>&arr){
    return solve(arr,0);
}


int main(){
    vector<int>arr={1,2,3,4,5,6,7};
    Node* root=createTree(arr);
    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->right->data<<endl;
    cout<<root->left->left->data<<endl;
    cout<<root->left->right->data<<endl;
    cout<<root->right->left->data<<endl;
    cout<<root->right->right->data<<endl;
   return 0;
}