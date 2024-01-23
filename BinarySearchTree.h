#ifndef _BINARYSEARCHTREE_H
#define _BINARYSEARCHTREE_H

// function prototypes for functions to be written in Assignment #2

BTNode * deleteBST (BTNode * root, string key);
BTNode * inOrderSuccessor (BTNode * btNode);


// function prototypes for functions provided with Assignment #2

BTNode * insertBST (BTNode * root, string data);
BTNode * containsBST (BTNode * root, string key);
BTNode * minimumBST (BTNode * root);
BTNode * maximumBST (BTNode * root);
BTNode * inOrderPredecessor (BTNode * btNode);

int nodeDepth (BTNode * node);
bool deleteLeafNode (BTNode * node);

#endif
