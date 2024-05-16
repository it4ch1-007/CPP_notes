// #include <bits/stdc++.h>
// #include <iostream>
// // using namespace std;



// class Node{
//     public:
//         int data;
//         Node* left;
//         Node* right;
//     Node(int a){
//         data=a;
//         this->left = NULL;
//         this->right  = NULL;
//     }
// };
// int height(Node* node);
// Node* newNode(int data);
// Node* newNode(int data)
// {
//     Node* Node;
//     Node->data = data;
//     Node->left = NULL;
//     Node->right = NULL;
 
//     return (Node);
// }
// void printCurrentLevel(Node* root,int level){
//     if(!root)
//         return;
//     if(level==1)
//         std::cout<<root->data<<std::endl;
//     else if(level>1)
//         {
//             printCurrentLevel(root->left,level-1);
//             printCurrentLevel(root->right,level-1);
//         }
// }
// void printLevelOrder(Node* node){
//     int h=height(node);
//     int i;
//     for(i=1;i<=h;i++){
//         printCurrentLevel(node,i);
//     }
// }
// int height(Node* node){
//     if(!node)
//         return 0;
//     else{
//         int lheight = height(node->left);
//         int rheight = height(node->right);

//         if(lheight>rheight)
//             return (lheight+1);
//         else{
//             return (rheight+1);
//         }
//     }
// }
// void inorder_traversal(Node* node){
//     if(!node)
//         return ;
//     inorder_traversal(node->left);
//     std::cout<<node->data;
//     inorder_traversal(node->right);
// }
// void preorder_traversal(Node* node){
//     if(!node)
//         return ;
//     std::cout<<node->data;
//     inorder_traversal(node->left);
//     inorder_traversal(node->right);
// }
// void postorder_traversal(Node* node){
//     if(!node)
//         return ;
    
//     inorder_traversal(node->left);
//     inorder_traversal(node->right);
//     std::cout<<node->data;
// }

// int main(){
//     // Node* root = new Node(40);
//     // Node* left_first = new Node(30);
//     // Node* right_first = new Node(50);
//     // // root.data = 50;
//     // // std::cout<<root.data;
//     // root->left = left_first;
//     // root->right = right_first; 
//     // std::cout<<right_first->data;

//     Node* root = newNode(1);
//     root->left = newNode(2);
//     root->right = newNode(3);
//     root->left->left = newNode(4);
//     root->left->right = newNode(5);

//     printLevelOrder(root);
// }

// Recursive CPP program for level
// order traversal of Binary Tree
#include <bits/stdc++.h>
using namespace std;

// A binary tree node has data,
// pointer to left child
// and a pointer to right child
class node {
public:
	int data;
	node *left, *right;
};

// Function prototypes
void printCurrentLevel(node* root, int level);
int height(node* node);
node* newNode(int data);

// Function to print level order traversal a tree
void printLevelOrder(node* root)
{
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++)
		printCurrentLevel(root, i);
}

// Print nodes at a current level
void printCurrentLevel(node* root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		cout << root->data << " ";
	else if (level > 1) {
		printCurrentLevel(root->left, level - 1);
		printCurrentLevel(root->right, level - 1);
	}
}

// Compute the "height" of a tree -- the number of
// nodes along the longest path from the root node
// down to the farthest leaf node.
int height(node* node)
{
	if (node == NULL)
		return 0;
	else {
		
		// Compute the height of each subtree
		int lheight = height(node->left);
		int rheight = height(node->right);

		// Use the larger one
		if (lheight > rheight) {
			return (lheight + 1);
		}
		else {
			return (rheight + 1);
		}
	}
}

// Helper function that allocates
// a new node with the given data and
// NULL left and right pointers.
node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return (Node);
}
int main()
{
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	printLevelOrder(root);
	return 0;
}
