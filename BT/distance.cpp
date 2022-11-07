// minimunm number of edges between two nodes  in a binary tree
#include <iostream>
#include<algorithm>
using namespace std;

class Node
{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int v)
    {
        val=v;
        left=NULL;
        right=NULL;
    }
};

Node* lca(Node* root ,int a,int b){
    if(root==NULL) return NULL;
    if(root->val == a || root->val ==b)  return root;

    Node* left=lca(root->left,a,b);
    Node* right=lca(root->right,a,b);

    if(left != NULL && right != NULL)   return root;
    if(left == NULL && right == NULL)   return NULL;
    if(left != NULL)    return  lca(root->left,a,b);
    return lca(root->right,a,b);
}

int findDist(Node* root,int k,int dist)
{
    if(root==NULL)     return -1;
    if(root->val == k) return dist;

    int left = findDist(root->left,k,dist+1);
    if(left !=-1)  return left;

    return findDist(root->right,k,dist+1);
}

int minDist(Node* root,int a,int b)
{
    Node* l=lca(root,a,b);
    int d1=findDist(l,a,0);
    int d2 = findDist(l,b,0);

    return d1+d2;
}

int main()
{
    Node* root = new Node(2);
    root->left=new Node(3);
    root->right=new Node(4);
    root->left->left=new Node(5);
    root->right->right=new Node(6);
    cout<<minDist(root,5,6);
    return 0;
}