//Author name: Nisarg Patel

#pragma once
#include "stdafx.h"
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include "AVLTree.h"
#include "Entry.h"
#include "AVLTreeMap.h"
#include <algorithm>
using namespace std;
class Inventory {
	private:
		int n;	//number of products
		//map<int, int> count;	//number of items
		AVLTreeMap< Entry<int, int> > count;

	public:
		
		//Functions...
		ofstream output;
		Inventory();
		int num_products();		//return n (# of products)
		int available(int product_id);	//return value of count[product_id]
		int size();		//size of the current inventory
		void in(int product_id, int num_items);		//increase number of items of product_id
													//available by num_items
		void out(int product_id, int num_items);	//decrease number of items of product_id
													//available by num_items
		void print_product(string out_fname, int product_id);		//print to file the current
																	//inventory for product
		void print(string out_fname);		//print to file the current inventory for every product
		void save(string inventory_fname);	//save current inventory to file
		void open(string inventory_fname);	//read the current inventory from a file
		void process(string transaction_fname);	//process transactions on the current inventory
};

