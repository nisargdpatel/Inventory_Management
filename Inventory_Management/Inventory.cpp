//Author name: Nisarg Patel

#include "stdafx.h"
#include "Inventory.h"
#include <algorithm>

Inventory::Inventory()
{
	n = 0;
	
	output.open("output.txt", ofstream::out | ofstream::app);
	//count[123] = 1;
	//count[15] = 50;
	//count[2667] = 8;
}

int Inventory::num_products()		//return n (# of products)
{
	return n;
}

int Inventory::available(int product_id)	//return value of count[product_id]
{
	/*return count[product_id];*/
	AVLTreeMap< Entry<int, int> >::Iterator w = count.find(product_id);

	if (w == count.end()) cout << "No map value found for key " << product_id << endl;
	else return (*w).value();
}

int Inventory::size()		//size of the current inventory
{
	/*int counter = 0;*/
	return count.size();
	/*map<int, int>::iterator temp = count.begin();
	for (temp; temp != count.end(); temp++)
	{
		counter += temp->second;
	}
	return counter;*/
}

void Inventory::in(int product_id, int num_items)		//increase number of items of product_id
{														//available by num_items
	/*if (count.find(product_id) != count.end()) {*/
		/*count[product_id] += num_items;*/
		int temp = available(product_id);
		count.put(product_id, num_items + temp);
		
	/*}
	else {
		cout << "Error in IN FUNCTION" << endl;
	}*/
}

void Inventory::out(int product_id, int num_items)	//decrease number of items of product_id
{													//available by num_items

		if (available(product_id) - num_items >= 0) {
			int temp = available(product_id);
			count.put(product_id, temp - num_items);
			/*cout << product_id << endl;*/
		}
		else {
			cout << "error: Insufficient inventory: Product ID " << product_id << ", " << num_items << " requested, " << available(product_id) << " available" << endl;
			output << "error: Insufficient inventory: Product ID " << product_id << ", " << num_items << " requested, " << available(product_id) << " available" << endl;
		}
}

void Inventory::print_product(string out_fname, int product_id)		//print to file the current
{																//inventory for product
	ofstream output;
	output.open(out_fname, ofstream::out | ofstream::app);
	if (available(product_id) != 0) {
		output << product_id << " " << available(product_id) << endl;
		cout << product_id << " " << available(product_id) << endl;
	}
	/*output.close();*/
}

void Inventory::print(string out_fname)		//print to file the current inventory for every product
{
	/*ofstream output;
	output.open(out_fname, ofstream::out || ofstream::app);*/
	
	for (auto const& iterator:count)
	{
		if (iterator.value() != 0) {
			output << iterator.key() << " " << iterator.value() << endl;
			cout << iterator.key() << " " << iterator.value() << endl;
		}
	}
	/*output.close();*/
}

void Inventory::save(string inventory_fname)	//save current inventory to file
{
	/*ofstream output;
	output.open("output.txt", ofstream::out | ofstream::app);*/
	print(inventory_fname);
}

void Inventory::open(string inventory_fname)	//read the current inventory from a file
{
	ifstream input;
	input.open(inventory_fname);

	while (!input.eof())
	{
		int key, value;
		input >> key;
		input >> value;
		count.put(key, value);
		/*count[key] = value;*/
	}
	input.close();
}

void Inventory::process(string transaction_fname)	//process transactions on the current inventory
{
	ifstream input;
	input.open(transaction_fname);
	string temp;
	string temp2;
	
	while (!input.eof() && input.good())
	{
		getline(input, temp);
		istringstream iss(temp);
		int product_id, num_items;
		iss >> temp2;
		if (temp2 == "in")
		{
			if (temp.length() == temp2.length())
			{
				iss >> product_id;
				iss >> num_items;
				in(product_id, 1);
			}
			else {
				iss >> product_id;
				iss >> num_items;
				in(product_id, num_items);
			}
		}
		else if (temp2 == "out")
		{
			if (temp.length() == temp2.length())
			{
				iss >> product_id;
				iss >> num_items;
				out(product_id, 1);
			}
			else {
				iss >> product_id;
				iss >> num_items;
				out(product_id, num_items);
			}
		}
		else {
			cout << "Error reading transaction file" << endl;
		}
	}
	input.close();
}