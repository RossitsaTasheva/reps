//============================================================================
// Name        : lib_05_Task5.cpp
// Author      : t
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void  RandElementsArr (int Arr[][5],int size ){

	srand(time(0));
		int arr[5];
		for (int row = 0; row < 5; row++)
		{
			for (int col = 0; col < 5; col++)
			{
				arr[rand() % 6-1] = Arr[row][col];

			}
		}
		for (int i = 0; i < size; i++)
			cout << setw(3) << arr[i] << "/";

}

int main() {
	const short int n = 5;
	int A[n][n];
	srand(time(0));

	cout << "\n\n\t Array...\n";
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			A[row][col] = rand() % 100;
		}
	}
	//----------------------------------------------------------------
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			cout << setw(4) << A[row][col];
		}
		cout << endl;
	}
	//--------------------------------------------------------------
	cout<<"\nRand five elements:\n"<<endl;
	RandElementsArr (A,5 );


	return 0;
}

