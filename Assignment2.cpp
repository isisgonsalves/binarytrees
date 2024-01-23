#include <iostream>
#include <fstream>
#include <cstring>
#include "SortedSet.h"
#include "Seller.h"
	using namespace std;
	
/*My name is Isis Gonsalves and my student ID number is 816026980. */

//additional function prototypes
int menu();
int inOrderArray (BTNode * root, string arr[], int i); //code is in SortedSet.cpp


// write the code for your additional functions here (if needed)
int menu () {
	
	int option;
	bool validOption;
	
	validOption = false;
	
	while (!validOption) {
		cout << endl;
		cout << "\n\n\t\t\t      Isis Gonsalves : 816026980" << endl;
		cout << "\t\t\t\tCOMP 2611 ASSIGNMENT 2" << endl;
		cout << "\t\t\t\t----------------------" << endl;
		cout << endl;
		cout << "\t  Enter 1:  Display all the products sold by a seller (in sorted order)." << endl;
		cout << "\t  Enter 2:  Add a new product to the set of products sold by a seller." << endl;
		cout << "\t  Enter 3:  Delete a product from the set of products sold by a seller." << endl;
		cout << "\t  Enter 4:  Which product sold by a seller comes after (in order)? ." << endl;
		cout << "\t  Enter 5:  Which product sold by a seller comes before (in order)?." << endl;
		cout << "\t  Enter 6:  Display all the products sold by two sellers." << endl;
		cout << "\t  Enter 7:  Display the common products sold by two sellers. "<<endl;
		cout << "\t  Enter 8:  Find all the sellers who sell a certain product. "<<endl;
		cout << "\t  Enter 9:  Quit "<<endl<<endl;
		cout << "\t  Enter Option:  ";
		cin  >> option;
		cout<<endl;
	
		if (option >= 1 && option <= 9)	
			validOption = true;
		else{
			cout<<"\nSorry, option 1 to 9 must be entered. Please try again."<<endl;
		}
			
	}								
	
	return option;
}

int main() {
	
	Seller sellers[1000];
	int numSellers;
	char filename [100] = "Sellers.txt";
  	int i;
  	
  	numSellers=readSellers(sellers,filename);
  	
	string sellerName;
	string product;

 	// write code to display menu and process options selected by user
	
	// you will need to call functions from Sellers.cpp and SortedSet.cpp.
	
	int choice= menu();
	
	while (choice != 9){
		
		if (choice == 1){
			
			cout<<"------Display all the products sold by a seller------"<<endl<<endl;
			
			cout<<"Enter seller name to display all products: ";
		  	cin>>sellerName;
			
			int loc=searchSellers(sellers,numSellers,sellerName); 
			
			if(loc != -1){
				
				if(isEmptySS(sellers[loc].products)){
					cout<<"\nCurrently, there are no products in "<<sellerName<< "'s file."<<endl;
				}
				else{
					cout<<"\nProducts sold by " <<sellerName<<": ";
					displayElements(sellers[loc].products);
				}
			}
			else
				cout<<"\nThe seller "<<sellerName<<" is not found in the seller file."<<endl;
				
		}
		else
			if (choice == 2){
				
				cout<<"------Add a new product to the set of products sold by a seller------"<<endl<<endl;
				
				cout<<"Enter a seller name to add a product to their file: ";
		  		cin>>sellerName;
		  		cout<<"\nEnter name of Product you wish to add : ";
		  		cin>>product;
		  		
		  		cout<<endl;
		  		addProduct(sellers,numSellers,sellerName,product);
		
			}
			else
				if (choice == 3){
					
					cout<<"------Delete a product from the set of products sold by a seller------"<<endl<<endl;
					
					cout<<"Enter a seller name to delete a product from their file:  ";
			  		cin>>sellerName;
			  		cout<<"\nEnter name of Product you wish to delete : ";
			  		cin>>product;
			  		
			  		cout<<endl;
			  		deleteProduct(sellers,numSellers,sellerName,product);
					
				}
				else
					if (choice == 4){
						
						cout<<"------Successor of a specific product sold by a seller------"<<endl<<endl;
						
						cout<<"Enter name of seller to display the successor: ";
				  		cin>>sellerName;
				  		cout<<"Enter Product to determine the successor of: ";
				  		cin>>product;
				  		
				  		bool needed=false;
				  		
				  		int loc=searchSellers(sellers,numSellers,sellerName);
						
						if(loc != -1){
							
							if(containsSS(sellers[loc].products,product)==true)  //checking if the item is present
								needed=false;
							else
								needed=true;
								
							if (needed == true) //therefore i need to add to file teporarily
								insertSS(sellers[loc].products,product);
							
							string suc = nextKey(sellers[loc].products, product); //find successor
							if(suc != "")
								cout<<"Successor of " <<product<< ": "<<suc<<endl;
							else
								cout<<"Successor of " <<product<<" does not exist."<<endl;
						}
						else
							if(loc == -1)
								cout<<"\nThe seller "<<sellerName<<" is not found in the seller file."<<endl;
							
						if(needed == true) //then delete the temp value if it was needed in the first place
							deleteSS(sellers[loc].products,product);
					}
					else
						if (choice == 5){
							
							cout<<"------Predecessor of a specific product sold by a seller------"<<endl<<endl;
							
							cout<<"Enter name of seller to display the predecessor: ";
					  		cin>>sellerName;
					  		cout<<"Enter Product to determine the predecessor of: ";
					  		cin>>product;
					  		
					  		bool needed=false;
				  		
					  		int loc=searchSellers(sellers,numSellers,sellerName);
							
							if(loc != -1){
								
								if(containsSS(sellers[loc].products,product)==true) //check if the product is found
									needed=false;
								else
									needed=true;
									
								if (needed == true)//if it wasnt found, its needed so insert in the file temporarily
									insertSS(sellers[loc].products,product);
								
								string pred=previousKey(sellers[loc].products, product);
								if(pred != "")
									cout<<"Predecessor  of " <<product<< ": " <<pred<<endl;
								else
									cout<<"Predecessor of " <<product<<" does not exist."<<endl;
							}
							else
								cout<<"\nThe seller "<<sellerName<<" is not found in the seller file."<<endl;
							
							if(needed == true) //then delete the temp value if it was needed in the first place
								deleteSS(sellers[loc].products,product);
								
						}
						else
							if (choice == 6){
								
								cout<<"------Display the union of all the products sold by two sellers.------"<<endl<<endl;
								
								SortedSet * totalSet= initSortedSet();
								string sellerName1;
								string sellerName2;
								
								cout<<"Enter first seller name: ";
						  		cin>>sellerName1;
						  		cout<<"Enter second seller name: ";
						  		cin>>sellerName2;
						  		
						  		int loc1=searchSellers(sellers,numSellers,sellerName1);
						  		int loc2=searchSellers(sellers,numSellers,sellerName2);
						  		
						  		if(loc1 != -1 && loc2 != -1){
						  			totalSet=unionSS(sellers[loc1].products, sellers[loc2].products);
						  			cout<<"Union Products of " <<sellerName1<<" and " << sellerName2 <<": ";
						  			displayElements(totalSet);
								}
								else
									if(loc1 == -1){
										cout<<sellerName1<< " is not present in the seller file. Try again."<<endl;
									}
									if(loc2 == -1){
										cout<<sellerName2<< " is not present in the seller file. Try again."<<endl;
									}
							}
							else
								if (choice == 7){
									
									cout<<"------Display the intersection of all the products sold by two sellers.------"<<endl<<endl;
									
									SortedSet * commonSet= initSortedSet();
									string sellerName1;
									string sellerName2;
									
									cout<<"Enter first seller name: ";
							  		cin>>sellerName1;
							  		cout<<"Enter second seller name: ";
							  		cin>>sellerName2;
							  		
							  		int loc1=searchSellers(sellers,numSellers,sellerName1);
							  		int loc2=searchSellers(sellers,numSellers,sellerName2);
							  		
							  		if(loc1 != -1 && loc2 != -1){
							  			commonSet=intersectionSS(sellers[loc1].products, sellers[loc2].products);
							  			
							  			if(isEmptySS(commonSet)){
											cout<<"\nCurrently, there are no products similar between "<<sellerName1<< " and "<< sellerName2<< endl;
										}
										else{
								  			cout<<"Common Products of " <<sellerName1<<" and " << sellerName2 <<": ";
								  			displayElements(commonSet);
											}
									}
									else
										if(loc1 == -1){
											cout<<sellerName1<< " is not present in the seller file. Try again."<<endl;
										}
										else
											if(loc2 == -1){
											cout<<sellerName2<< " is not present in the seller file. Try again."<<endl;
										}
								
								}
								else{
									
									cout<<"------Display all the sellers who sell a certain product------"<<endl<<endl;
									
									cout<<"Enter Product to list all sellers of that product: ";
				 					cin>>product;
				  					
				  					listSellers(sellers,numSellers,product);
									 
									}
								
										
		choice=menu();
	}
	
	cout<<"\nExit successful... "<<endl;
	
	 	
	return 0;
}

