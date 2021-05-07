#include <stdio.h>
#include <math.h>

typedef unsigned long long ullong;
typedef unsigned char uchar;

uchar increment(uchar * tab, uchar n, uchar b)
{
	uchar num_of_mod = 0, i = 0;
	int flag = 1 ;
	while(i < n && flag) 
	{	
		if (tab[i] == b-1)
		{
			tab[i] = 0;
			i++;
		}
		else
		{
			tab[i]++;
			flag = 0;
		}
		num_of_mod++;
	}
	return num_of_mod;
}

ullong test(uchar n, uchar b)
{
	uchar test_array[n];
	ullong total_of_mod = 0;
	ullong hnum = pow(b, n) ;
	uchar tmp; 
	printf("sadsasadas%d\n", hnum);
	for(int i = 0; i < n; i++)
		test_array[i] = 0;
	for(int i = 0; i <= hnum; i++)
	{
		tmp = increment(test_array, n, b);
		total_of_mod += tmp;
	}
	printf("%llu\n", total_of_mod);
	return total_of_mod;
}

	
		

void print_array(uchar * array, uchar n)
{
	printf("[");
	for(int i = 0; i < n - 1; i++)
		printf("%d,", array[i]);
	printf("%d]\n", array[n-1]);
}

int  main()
{
	/*
	uchar array[10] = {9,9,9,9,9,9,9,9,9,9};
	print_array(array, 10);
	increment(array, 10, 10);
	print_array(array, 10);
	*/
	test(4, 10);
}

		
		


