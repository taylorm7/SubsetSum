#include "secondOrder.h"
#include <vector>
#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;


void printMatrix(int ** mat, int length)
{

    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < length; ++j)
        {
            cout << setw(4)  << mat[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void matrix(int * array, int length)
{

        printf("Matrix!\n");


	int rows = length;
	int  cols = length;

	int** m = new int*[rows];
	for (int i = 0; i < rows; ++i)
    		m[i] = new int[cols];

	for (int i = 0; i < length; ++i)
    	{
        	for (int j = 0; j < length; ++j)
        	{
            		if( i == 0)
			{
				m[i][j] = array[j];
			}	
			else if (i % 2 == 1)
			{
				m[i][j] = m[i-1][ (j + (length/2))%length ];
			}
			else if (i % 2 == 0)
			{
				m[i][j] = m[i-1][ (j + length - 2) % length];
			}
        	}
    	}



	printMatrix(m, length);
	

	std::vector< std::vector<int> > a;



	for (int i = 0; i < rows; ++i)
    		delete [] m[i];
	delete [] m;

	//m * n is the size of the matrix
/*
    	int m = length, n = length;
    	//Grow rows by m
    	a.resize(m);
    	for(int i = 0 ; i < m ; ++i)
    	{
        	//Grow Columns by n
        	a[i].resize(n);
    	}
    	//Now you have matrix m*n with default values

    	//you can use the Matrix, now
    	a[1][0]=1;
    	a[1][1]=2;
    	a[1][2]=3;
    	a[1][3]=4;

	//OR
	for(i = 0 ; i < m ; ++i)
	{
    		for(int j = 0 ; j < n ; ++j)
    		{      //modify matrix
        	int x = a[i][j];
    		}

	}
*/
}
