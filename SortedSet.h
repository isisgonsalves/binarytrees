#ifndef _SORTEDSET_H
#define _SORTEDSET_H

#include "NodeTypes.h"

struct SortedSet {
	BTNode * root;
	int size;
};

// Function prototypes for functions to be written in Assigment #2
void deleteElement ( string A[], int n, int loc);
SortedSet * initSortedSet ();
bool containsSS (SortedSet * s, string key);
void insertSS (SortedSet * s, string data);
void deleteSS (SortedSet * s, string key);
SortedSet * copySS (SortedSet * s);
SortedSet * unionSS (SortedSet * s1, SortedSet * s2);
SortedSet * intersectionSS (SortedSet * s1, SortedSet * s2);
bool isEmptySS (SortedSet * s);
int sizeSS (SortedSet * s);
void displayElements (SortedSet * s);
string nextKey (SortedSet * s, string key);
string previousKey (SortedSet * s, string key);

#endif
