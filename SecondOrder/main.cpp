#include <stdio.h>
#include <stdlib.h>
#include <new>
#include <sstream>

#include "firstOrder.h"
#include "secondOrder.h"



void makeArray(int * array, int length)
{
	int i = 0;
	int val = 1;
	for(i; i < length; i++)
	{
		array[i] = val << i; 
	}
}


int main(int argc, char *argv[])
{
	int N;
    	if (argc >= 2)
    	{
        	std::istringstream iss( argv[1] );
        	int val;

        	if (iss >> val)
        	{
            		// Conversion successful
			N = val;
        	}
    	}
	else
	{
		N = 6;
	}

	
	int * sums = new int [1 << N];

	printf("N:%d sums length:%d\n", N, 2<<N);

	int arr[N];

	makeArray(arr, N);

	printArray(arr,N);
	printf("\n");

	matrix(arr, N);

	delete[] sums;
}
