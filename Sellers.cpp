#include <iostream>
#include <fstream>
#include <cstring>
#include "Seller.h"
	using namespace std;

// Write code in readSellers and readSellerProducts which
// will be executed on startup.


int readSellers (Seller sellers[], char filename[]) {
	
	// Reads the names of the sellers from 'filename' and stores them 
	// in the 'sellers' array. Returns the amount of sellers read.
	
	ifstream in;
	in.open(filename);
	
	int numSellers=0;
	
	string sName;
	in>>sName;

	while(sName != "END"){
		
		sellers[numSellers].products = readSellerProducts(sName);
		sellers[numSellers].name = sName;
		numSellers++;
		
		in>>sName;
	}
	
//	printArr(sellers,numSellers);
		
	return numSellers;

}


SortedSet * readSellerProducts (string sellerName) {

	// Reads the products that are sold by 'sellerName'. The products
	// are stored in a SortedSet as they are read from the file. The
	// function returns the SortedSet of products.
	
	SortedSet * tempS;
	tempS=initSortedSet();
	
	string ext= ".txt";
	string sellerF;
	
	sellerF=sellerName + ext; 
	//cout<<sellerF;
	
	int n = sellerF.length();
 
    char sellerFile[n + 1];
 
    strcpy(sellerFile, sellerF.c_str());
 
	int i=0;
	
	ifstream in;
	in.open(sellerFile);
	
	string product;
	in>>product;

	while(product != "END"){
		
		insertSS(tempS, product);
	
		in>>product;
	}
	
	return tempS;
}

// Write code to search for a seller. This is required for most
// of the menu options.
	 
int searchSellers (Seller sellers[], int numSellers, string key) {

	for (int i=0;i<numSellers;i++){ 
	
		if(sellers[i].name == key)
			return i;
	}
	return -1;
}

	

// Write code here for Menu Option 8
	
void listSellers (Seller sellers[], int numSellers, string productName) {
	
	bool found=false;
	int count=0;
	
	cout<<"List of persons that sell ("<<productName<<") : ";
	
	for (int i=0;i<numSellers;i++){
		
		found = containsSS(sellers[i].products, productName);
		
		if(found == true){
			count++;
			cout<<sellers[i].name<<"  ";
		}
	}
	
	if(count == 0){
		cout<<"-";
		cout<<"\nCurrently, there are no sellers of "<<productName<<endl;
	}
}


// Write code here for Menu Option 2

void addProduct (Seller sellers[], int numSellers, string sellerName, string productName) {
	
	int loc=searchSellers(sellers,numSellers,sellerName);
		
	if(loc != -1){
		bool found=false; 
					
		found=containsSS(sellers[loc].products,productName);
					
		if(found == 0){
			cout<<"Adding "<<productName<<"..."<<endl;
			insertSS(sellers[loc].products,productName);
			cout<<"Updated List: ";
			displayElements(sellers[loc].products);
		}
		else
			cout<<"The product "<<productName<<" is already present in the list..."<<endl;
	}
	else
		cout<<"The seller "<<sellerName<<" is not found in the sellers file."<<endl;
				

}

	

// Write code here for Menu Option 3

void deleteProduct (Seller sellers[], int numSellers, string sellerName, string productName) {

	int loc=searchSellers(sellers,numSellers,sellerName);
		
	if(loc != -1){
		bool found=false; 
					
		found=containsSS(sellers[loc].products,productName);
					
		if(found == 1){
			cout<<"Deleting "<<productName<<"..."<<endl;
			deleteSS(sellers[loc].products,productName);
			
			if(isEmptySS(sellers[loc].products)){
					cout<<"\nThere are no more products present in "<<sellerName<< "'s file."<<endl;
			}
			else{
				cout<<"Updated List: ";
				displayElements(sellers[loc].products);
			}
		}
		else
			cout<<"The product "<<productName<<" is not present in the list..."<<endl;
	}
	else
		cout<<"The seller "<<sellerName<<" is not found in the sellers file."<<endl;
}
