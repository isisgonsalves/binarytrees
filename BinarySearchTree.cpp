#include <iostream>
#include <cstdlib>
#include "NodeTypes.h"
#include "BinaryTree.h"
#include "BinarySearchTree.h"

using namespace std;



BTNode * insertBST (BTNode * root, string key) {
	
	BTNode * newNode;
	BTNode * curr;
	
	newNode = createBTNode (key);
	
	if (root == NULL) {
		cout << "\n(Root of BST created with " << newNode->data <<")"<< endl;
		return newNode;
	}
	
	curr = root;
	
	while (true) {
		if (key < curr->data) {
			if (curr->left == NULL) {
				curr->left = newNode;
				newNode->parent = curr;
				return root;
			}
			curr = curr->left;
		}		
		else {
			if (curr->right == NULL) {
				curr->right = newNode;
				newNode->parent = curr;						
				return root;
			}
			curr = curr->right;
		}
	}
}



BTNode * containsBST (BTNode * root, string key) {

	if (root == NULL)
		return NULL;
		
	if (root->data == key)
		return root;
		
	if (key < root->data)
		return (containsBST (root->left, key));
	else
		return (containsBST (root->right, key));
}



// Write code for deleteBST function

BTNode * deleteBST (BTNode * root, string key) {
	
	if(root == NULL)
		return root;
	
	if(key < root->data)
		root->left = deleteBST(root->left,key);
	else
		if(key > root->data)
			root->right = deleteBST(root->right,key);
		else{
			if (root->left==NULL and root->right==NULL)
           		 return NULL;
           	else 
			   if (root->left == NULL) {
		            BTNode * temp = root->right;
		            free(root);
		            return temp;
		        }
		        else 
					if (root->right == NULL) {
			            BTNode* temp = root->left;
			            free(root);
			            return temp;
		        }
		        
		
		    BTNode * temp = minimumBST(root->right);
		    root->data = temp->data;
		    root->right = deleteBST(root->right, temp->data);
	}
	
	return root;
}



BTNode * minimumBST (BTNode * root) {
	if (root == NULL)
		return NULL;
		
	while (root->left != NULL)
		root = root->left;
	
	return root;
}



BTNode * maximumBST (BTNode * root) {
	if (root == NULL)
		return NULL;
		
	while (root->right != NULL)
		root = root->right;
	
	return root;
}



int nodeDepth (BTNode * node) {
	int branch;
	
	branch = 0;
	
	while (node->parent != NULL) {
		node = node->parent;
		branch++;
	}
	
	return branch;
}



bool deleteLeafNode (BTNode * node) {
	BTNode * parent;
	
	if (node->left == NULL && node->right == NULL) {
		parent = node->parent;
		if (parent->left == node)
			parent->left = NULL;
		else
			parent->right = NULL;
		
		delete (node);
		
		return true;
	}
	
	return false;
}


// Write code for inOrderSuccessor function

BTNode * inOrderSuccessor (BTNode * btNode) {
	
	if (btNode == NULL)
		return NULL;
		
	if (btNode->right != NULL)
		return minimumBST (btNode->right);
		
	BTNode * parent;

	parent = btNode->parent;
	while (parent != NULL && btNode == parent->right) {
		btNode = parent;
		parent = parent->parent;
	}
	return parent;	
}


BTNode * inOrderPredecessor (BTNode * btNode) {
	
	if (btNode == NULL)
		return NULL;
		
	if (btNode->left != NULL)
		return maximumBST (btNode->left);
		
	BTNode * parent;

	parent = btNode->parent;
	while (parent != NULL && btNode == parent->left) {
		btNode = parent;
		parent = parent->parent;
	}
	return parent;	
}

