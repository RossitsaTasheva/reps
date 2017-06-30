//============================================================================
// Name        : PrintArr.cpp
// Author      : t
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;

void PrintArr(int matrix[][7], int size)
{
	cout << "{" << endl;
	for (int row = 0; row < size; row++)
	{
		cout << "   {";
		for (int col = 0; col < 7; col++)
		{
			cout << setw(5) << matrix[row][col];
		}
		cout << "   }," << endl;
	}
	cout << "}" << endl;
}

int main()
{
	int size = 7;
	int matrix[size][7];

	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < 7; col++)
		{
			matrix[row][col] = rand() % 100;
		}
	}
	PrintArr(matrix, 7);
	/*	int i, s, t, j, mas[7][7], B[49], C[49];
	 s = 0;
	 t = 0;

	 for (int row = 0; row < 7; i++) {
	 for (j = 0; j < 7; j++) {
	 mas[i][j] = rand() % 100;
	 printf("%4d", mas[i][j]);
	 }
	 }
	 printf("\n");

	 for (i = 0; i < 7; i++) {
	 for (j = 0; j < 7; j++) {
	 if (mas[i][j] % 2 == 0 && mas[i][j] != 0) {
	 B[t] = mas[i][j];
	 t++;
	 } else {
	 C[s] = mas[i][j];
	 s++;
	 }
	 }
	 }

	 printf("vektor B:");
	 for (i = 0; i < t; i++) {
	 printf("%4d", B[i]);
	 }
	 printf("\n");

	 printf("vektor C:");
	 for (i = 0; i < s; i++) {
	 printf("%4d", C[i]);
	 }
	 printf("\n");*/

	return 0;
}
