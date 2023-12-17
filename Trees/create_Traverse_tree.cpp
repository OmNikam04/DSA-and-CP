#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left, *right;
};

void preorder_traversal(node *root){
    if(root==NULL)return;
    cout<<root->val<<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}
void postorder_traversal(node *root){
    if(root==NULL)return;
    preorder_traversal(root->left);
    preorder_traversal(root->right);
    cout<<root->val<<" ";
}
void inorder_traversal(node *root){
    if(root==NULL)return;
    preorder_traversal(root->left);
    cout<<root->val<<" ";
    preorder_traversal(root->right);
}

node* createNode(int data){
    node* n = new node;
    n->val = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int main()
{
    // ? Creating each node separately
    node *root = createNode(10);
    node *n1 = createNode(20);
    node *n1_1 = createNode(40);
    node *n1_2 = createNode(50);
    node *n2 = createNode(30);
    node *n2_1 = createNode(60);
    node *n2_2 = createNode(70);

    // ? Linking each and every node to make tree
    root->left = n1;
    root->right = n2;

    n1->left = n1_1;
    n1->right = n1_2;

    n2->left = n2_1;
    n2->right = n2_2;

    // ? Traversing tree
    preorder_traversal(root);
    cout<<endl;
    postorder_traversal(root);
    cout<<endl;
    inorder_traversal(root);
    cout<<endl;
    return 0;
}