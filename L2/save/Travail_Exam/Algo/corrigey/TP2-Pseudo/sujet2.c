#include <stdio.h>

typedef unsigned int unit;
typedef unsigned short ushort;

void print_array(int* array, ushort size)
{
	printf ("[");
	for (int i = 0; i < size - 1; i++)
		printf("%d, ", array[i]);
	printf("%d]\n", array[size-1]);
}
	
		

void selection_sort( int* array, ushort size)
{
	int min, index_min, tmp;
	for (int i = 0; i < size; i++)
	{
		min = array[i];
		index_min = i;
		for (int j = i; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				index_min = j;
			}
		}
		tmp = array[i];
		array[i] = array[index_min];
		array[index_min] = tmp;
	}
}

void main()
{
	int tab[10] = {9,7,4,1,2,3,5,6,8};
	print_array(tab, 10);
	selection_sort(tab,10);
	print_array(tab,10);
}	
		
			



