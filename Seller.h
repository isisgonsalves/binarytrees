#ifndef _SELLER_H
#define _SELLER_H

#include <cstdlib>
#include "SortedSet.h"
	using namespace std;
	
struct Seller {
   string name;
   SortedSet * products;
};

int readSellers (Seller sellers[], char filename[]);

	// Reads the names of the sellers from 'filename' and stores them 
	// in the 'sellers' array. Returns the amount of sellers read.
	

SortedSet * readSellerProducts (string sellerNames);

	// Reads the products that are sold by 'sellerName'. The products
	// are stored in a SortedSet as they are read from the file. The
	// function returns the SortedSet of products.

	 
int searchSellers (Seller sellers[], int numSellers, string key);

	// Searches the sellers in the 'sellers' array for 'key'. 
	// Returns the location where 'key' was found or -1, otherwise.
	
	
void listSellers (Seller sellers[], int numSellers, string productName) ;

	// Displays all the sellers that sell 'productName'.

	
void addProduct (Seller sellers[], int numSellers, string sellerName, string productName);

	// Adds a new product 'productName' to the set of products sold by 'sellerName'.
	

void deleteProduct (Seller sellers[], int numSellers, string sellerName, string productName);

	// Deletes a product 'productName' from the set of products sold by 'sellerName'.
	
#endif
