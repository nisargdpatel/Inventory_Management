// Inventory_Management.cpp : Defines the entry point for the console application.
//Author name: Nisarg Patel
//Assumption: Product id does not start with 0

#include "stdafx.h"
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include "Inventory.h"
#include <sstream>;
#include "AVLTree.h"
#include "Entry.h"
#include "AVLTreeMap.h"
#include <algorithm>
using namespace std;




int main()
{
	ifstream inv0, input, trans1;
	string temp;
	string tempFileName;
	int tempProductId;
	
	/*input.open("input.txt");
	inv0.open("inv0.txt");
	trans1.open("trans1.txt");*/
	string outFname, inFname;
	
	cout << "What is the input file name: ";
	cin >> inFname;


	Inventory myInventory;
	input.open(inFname);
	while (!input.is_open())
	{
		cout << "Error, input file could not be opened. Type again: ";
		cin >> inFname;
		input.open(inFname);
	}

	cout << "What is the output file name: ";
	cin >> outFname;
	
	string temp2;
	while (!input.eof()) {
		getline(input, temp);
		/*cout << temp << endl;*/
		istringstream iss(temp);
		
		iss >> temp2;
		if (temp2 == "open")
		{
			iss >> tempFileName;
			myInventory.open(tempFileName);
		}
		else if (temp2 == "save")
		{
			iss >> tempFileName;
			myInventory.save(tempFileName);
		}
		else if (temp2 == "display")
		{
			if (temp == "display")
			{
				ofstream output;
				output.open(outFname, ofstream::out | ofstream::app);

				myInventory.print(outFname);
				cout << "Inventory size: " << myInventory.size() << endl;
				output << "Inventory size: " << myInventory.size() << endl;
				output.close();
			}
			else {
				iss >> tempProductId;
				myInventory.print_product(outFname, tempProductId);
			}
		}
		else if (temp2 == "process")
		{
			iss >> tempFileName;
			myInventory.process(tempFileName);
		}
		else {
			cout << "Error in input file" << endl;
		}
	}
	system("pause");
    return 0;
}



