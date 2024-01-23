#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include "NodeTypes.h"
	
// function prototype for copyBT function to be written in Assignment #2

BTNode * copyBT (BTNode * root);


// function prototypes for functions provided with Assignment #2

BTNode * createBTNode (string data);
void preOrder (BTNode * root);
void inOrder (BTNode * root);
void postOrder (BTNode * root);

int moment (BTNode * root);
int numOneChild (BTNode * root);
int numNonTerminal (BTNode * root);

#endif
