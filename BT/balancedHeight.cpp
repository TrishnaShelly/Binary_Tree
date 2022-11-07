
#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int v)
    {
        val = v;
        left = NULL;
        right = NULL;
    }
};

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}

bool isBalanced(Node *root)   //compexity n2
{

    if (root == NULL)
        return true;
    if (isBalanced(root->left) == false)
        return false;
    if (isBalanced(root->right) == false)
        return false;
    int lh = height(root->left);
    int rh = height(root->right);

    if (abs(lh - rh) <= 1)
        return true;
    else
        return false;
}

bool balanced(Node* root,int* height)  // complexity n
{
    if(root==NULL) return true;
    int lh =0,rh=0;
    if(balanced(root->left,&lh)==false)   return false;
    if(balanced(root->right,&rh)==false)   return false;

    *height= max(lh,rh) +1;

    if(abs(lh-rh)<=1)
    return true;
    else return false;
}

int main()
{
    Node* root = new Node(2);
    root->left=new Node(2);
    root->right=new Node(2);
    root->left->left=new Node(2);
    root->right->right=new Node(2);
    int height=0;
    cout<<balanced(root,&height)<<endl;
    return 0;
}