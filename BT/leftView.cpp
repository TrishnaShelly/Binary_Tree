#include<iostream>
#include<queue>
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

void leftView(Node* root)
{
    if(root==NULL)
    return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int n= q.size();
        for(int i =0;i<n;i++)
        {
            Node* curr = q.front();
            q.pop();
            if(i ==0)
            cout<<curr->val<<" ";

            if(curr->left!=NULL) q.push(curr->left);
             if(curr->right!=NULL) q.push(curr->right);
        }
    }
}

int main() 
{
    Node* root = new Node(2);
    root->left=new Node(3);
    root->right=new Node(4);
    root->left->left=new Node(5);
    root->right->right=new Node(6);
    leftView(root);
    return 0;
}