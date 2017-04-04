#include "secondOrder.h"
#include "firstOrder.h"
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
	
	int * lineArray = new int [length + 1];


        for (int i = 0; i < length; ++i)
        {
                for (int j = 0; j < length; ++j)
                {
			if(i ==0)
			{
				lineArray[j] = m[i][j];
			}
		}
	}
	//line(lineArray , length);

	First f1(lineArray, length);

	cout << f1.getLength() << endl;
	
	delete [] lineArray;

	for (int i = 0; i < rows; ++i)
    		delete [] m[i];
	delete [] m;

}
