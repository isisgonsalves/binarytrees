#include <iostream>
#include <cstdlib>
#include "NodeTypes.h"
#include "BinaryTree.h"
#include "BinarySearchTree.h"
#include "SortedSet.h"

using namespace std;


SortedSet * initSortedSet () {
	
	SortedSet * s = new SortedSet;
	
	s->root = NULL;
	s->size = 0;
	
	return s;
}


int inOrderArray (BTNode * root, string arr[], int i) {
	
	//doing an inOrder traversal to store elements in an array
	
	if (root == NULL)
		return i;

	if(root->left != NULL )
		i=inOrderArray (root->left,arr,i);
	
	arr[i]= root->data;
	i++;
	
	if(root->right != NULL )
		i=inOrderArray (root->right,arr,i);
	
	return i;
}



bool containsSS (SortedSet * s, string key) {
	
	if(containsBST(s->root,key) != NULL)
		return true;
	else 
		return false;
}



void insertSS (SortedSet * s, string data) {
	
	s->root=insertBST(s->root,data);
	s->size++;
}



void deleteSS (SortedSet * s, string key) {

	s->root=deleteBST(s->root, key);
	s->size--;
	
}

SortedSet * copySS (SortedSet * s) {
	
	SortedSet * copied= initSortedSet();
	
	copied->root=copyBT(s->root);
	
	return copied;
}


SortedSet * unionSS (SortedSet * s1, SortedSet * s2) {

	SortedSet * totalSet= initSortedSet();
	
	int size1 = sizeSS(s1);
	int size2 = sizeSS(s2);
	
	string combined1[size1];
	int i=0;
	
	string combined2[size2];
	int c=0;
	
	i= inOrderArray(s1->root, combined1,i);
	c= inOrderArray(s2->root, combined2,c);	
	
	string combined[size1+size2];
	
	int one=0,two=0,both=0;
	
	while (one < size1 && two < size2) {
        if (combined1[one] < combined2[two]){
        	insertSS(totalSet,combined1[one]);
        	one++;
		}
        else 
	        if (combined2[two] < combined1[one]){
	        	insertSS(totalSet,combined2[two]);
	        	two++;
			}
  	        else {
	            insertSS(totalSet,combined2[two]);
	            two++;
	            one++;
	        }
    }
  
    while (one < size1){
	
        insertSS(totalSet,combined1[one]);
		one++;
  	}
    while (two < size2){
    
        insertSS(totalSet,combined2[two]);
		two++;
	}

	return totalSet;
}
	
	
SortedSet * intersectionSS (SortedSet * s1, SortedSet * s2) {
	
	int size1 = sizeSS(s1);
	int size2 = sizeSS(s2);
	
	string combined1[size1];
	int i=0;
	
	string combined2[size2];
	int c=0;
	
	i= inOrderArray(s1->root, combined1,i);
	c= inOrderArray(s2->root, combined2,c);	
	
	int one=0,two=0,both=0;

	SortedSet * commonSet= initSortedSet();
	
	while (one < size1 && two < size2) {
        if (combined1[one] < combined2[two])
            one++;
        else 
			if (combined2[two] < combined1[one])
	            two++;
	        else 
				if (combined1[one] == combined2[two]){	
		            insertSS(commonSet, combined2[two]);
		            one++;
		            two++;
		        }
    }
	
	return commonSet;
}



bool isEmptySS (SortedSet * s) {

	return (s->size == 0);
}



int sizeSS (SortedSet * s) {
	
	return s->size;
}



void displayElements (SortedSet * s) {
	
	inOrder(s->root);

}


string nextKey (SortedSet * s, string key) {

	BTNode * newNext = new BTNode;
	
	SortedSet * succ= initSortedSet();
	SortedSet * copy= initSortedSet();
	
	succ->root=containsBST(s->root,key);
	
	newNext=inOrderSuccessor(succ->root);
	
	if(newNext == NULL){ 
		return "";
	}
	else
		return newNext->data; 
}

 

string previousKey (SortedSet * s, string key) {
	
	
	BTNode * newPred = new BTNode;
	SortedSet * pred= initSortedSet();
	SortedSet * copyPrev= initSortedSet();
	
	copyPrev=copySS(s);
	
	pred->root=containsBST(s->root,key);
	
	newPred=inOrderPredecessor(pred->root);
	
	if(newPred == NULL){
		return "";
	}
	else
		return newPred->data;  

}

