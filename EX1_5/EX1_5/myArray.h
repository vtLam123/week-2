#pragma once
#include <iostream>
using namespace std;

/// <summary>
/// 
///		A MY_ARRAY class has:
///			element	: element of array
///			size	: of array
/// 
/// </summary>

class MY_ARRAY {
private:
	int* element;
	int size;

	bool increase(int, int);
	bool decrease(int, int);

	void merge(int arr[], int l, int m, int r, bool (MY_ARRAY::* sortType)(int, int));
	void Sort(int arr[], int l, int r, bool (MY_ARRAY::* sortType)(int, int));

public:
	//init and cancel value in class
	MY_ARRAY();
	~MY_ARRAY();

	//input and output data in class
	friend istream& operator>>(istream&, MY_ARRAY&);	
	friend ostream& operator<<(ostream& os, MY_ARRAY& array);

	//function find a position, value, copy and size of array
	int operator[](int);
	void copyArray(MY_ARRAY&);
	int getSize();	
	int find(int);	

	//Sort function group
	void sortIncrease();
	void sortDecrease();	
};