/*
Project:     ENGR 1405 Lab #14
File:        lab14.cpp
Purpose:     Sort Vectors With Random Numbers
Author:      Kylon Mortenson
Date:        24 Nov 2020
*/

//INCLUDE
#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<iomanip>

using namespace std;

//Function prototypes
void sort(vector<int>);
void vectorLoad(vector <int>&);

/*
Purpose:  Controls function
Input:        None
Output:       Greeting
*/
int main()
{
	//Vector
	vector <int> numbers(25);

	//Greeting
	cout << "This program show the bubble sort on integers!" << endl;

	//Function calls
	vectorLoad(numbers);
	sort(numbers);
	return 0;
}

/*
Purpose:      Load the Funciton with Random Numbers
Input:        None
Output:       List of random integers
Parameters:   The empty vector
Arguments:    None
*/
void vectorLoad(vector <int>& numbers)
{
	//Load the vector with integers
	srand(time(0));
	for (int i = 0; i < numbers.size(); i++)
	{
		numbers[i] = rand() % 100;
	}

	//Output the original list
	cout << "Original:";
	for (int i = 0; i < numbers.size(); i++)
		cout << setw(3) << numbers[i];
	cout << endl;
}

/*
Purpose:     Sort the list of Integers
Input:       None
Output:      Each Pass of the bubble sort
Parameters:  The loaded vector
Arguments:   None
*/
void sort(vector <int> list)
{
	//Variables
	int temperaryValue, pass;
	bool done = false;
	//Bubble sort
	for (pass = 0; pass < list.size() && !done; pass++)
	{
		done = true;
		for (int i = 0; i < list.size() - pass; i++)
		{
			if ((i + 1) < list.size() && list[i] > list[i + 1])
			{
				temperaryValue = list[i];
				list[i] = list[i + 1];
				list[i + 1] = temperaryValue;
				done = false;
			}
		}

		//Output the current pass
		cout << "Pass #" << setw(2) << pass << ":";
		for (int index = 0; index < 25; index++)
			cout << setw(3) << list[index];
		cout << endl;
	}
}