#include <bits/stdc++.h>
#include <iostream>


class Node{
    public:
        int data;
        int height;
        Node* left;
        Node* right;
};

Node* newNode(int key)  
{  
    Node* node = new Node(); 
    node->data = key;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1; 
    return(node);  
} 

int max(int a,int b){
    return (a>b)?a:b;
}
int height(Node* node){
    if(!node)
        return 0;
    return node->height;
}
Node* rightRotate(Node* y){
    Node* x=y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left),height(y->right)) + 1;
    x->height = max(height(x->left),height(x->right)) + 1;
    return x;
}
Node *leftRotate(Node *x)  
{  
    Node *y = x->right;  
    Node *T2 = y->left;  
  
    // Perform rotation  
    y->left = x;  
    x->right = T2;  
  
    // Update heights  
    x->height = max(height(x->left),     
                    height(x->right)) + 1;  
    y->height = max(height(y->left),  
                    height(y->right)) + 1;  
  
    // Return new root  
    return y;  
}
int getBalance(Node* node){
    if(!node){
        return 0;
    }
    return height(node->left) - height(node->right);
}
Node* insert(Node* node,int key){
    if(!node)
        return newNode(key);
    if(key<node->data)
        node->left = insert(node->left,key);
    else if(key>node->data)
        node->right = insert(node->right,key);
    else
        return node; 

    node->height = max(height(node->left),height(node->right)) + 1;

    int balance = getBalance(node);

    // Left Left imbalance case
    if(balance>1 && key<node->left->data)
        return rightRotate(node);
    // Right Right imbalance case
    if(balance<-1 && key>node->right->data)
        return leftRotate(node);
    // Left Right Case  
    if (balance > 1 && key > node->left->data)  
    {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
  
    // Right Left Case  
    if (balance < -1 && key < node->right->data)  
    {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    } 
    return node;
}

void inorder_traversal(Node* node){
    if(node){
    node=node->left;
    std::cout<<node->data<<std::endl;
    node = node->right;
    }
}
int main(){
    Node* root = NULL;
    root = insert(root, 10);  
    root = insert(root, 20);  
    root = insert(root, 30);  
    root = insert(root, 40);  
    root = insert(root, 50);  
    root = insert(root, 25); 
    inorder_traversal(root);
}