#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define N 100
typedef unsigned int uint;

double power_naif(float x, uint n, uint* nbr_mult)
{
	double res = 1;
	for(int i = 0; i < n; i++)
	{
		res *= x;
	}
    *nbr_mult += n;
	return res; 
}

double square_and_multiply(float x, uint n, uint* nbr_mult)
{
	double res = 1;
	while(n != 0)
	{
		if (n & 1)
        {
			res *= x;
            *nbr_mult += 1;
        }
		x *= x;
        *nbr_mult += 1;
		n >>= 1;
	}
	return res;
}

float eval_naif(float* poly, float a, uint n, uint* nbr_mult )
{
    float a_tmp = 1, res = 0;
    for(uint i = 0; i < n; i++)
    {
        a_tmp = power_naif(a, i, nbr_mult);
        res += poly[i] * a_tmp;
    }
    *nbr_mult += n;
    return res;
}

float eval_horner(float *poly, float a, uint n, uint* nbr_mult)
{
    float res = 0;

    for(uint i = 0; i < n; i++)
    {
        res = res * a + poly[i];
        *nbr_mult += 1;
    }
    return res;
}        



float eval_sm(float* poly, float a, uint n, uint* nbr_mult)
{
    float a_tmp = 1, res = 0;
    for(uint i = 0; i < n; i++)
    {
        a_tmp = square_and_multiply(a, i, nbr_mult);
        res += poly[i] * a_tmp;
    }
    *nbr_mult += n;
    return res;
}

float* create_poly(uint n)
{
    int random_num;
    float* poly = (float*) malloc(sizeof(float)*n+1);

    for(int i = 0; i <= n; i++)
    {
        poly[i] = 1 + rand() % 100;
    }
    return poly;
}

void print_array(float* p, uint n)
{
    printf("[");
    for(uint i = 0; i < n - 1; i++)
    {
        printf("%f, ", p[i]);
    }
    printf("%f]\n", p[n-1]);
}

void main()
{
    /*
    float P[5] = {1, 2, 3, 4, 5};
    uint mults = 0;
    printf("eval naif \n");
    printf("The result is %f\n", eval_naif(P, 5, 5, &mults));
    printf("The number of mults is %d\n", mults);

    mults = 0;
    printf("eval sm\n");
    printf("The result is %f\n", eval_sm(P, 5, 5, &mults));
    printf("The number of mults is %d\n", mults);
    for(int i = 0; i < 10; i++)
    {
       sleep(1);
       float* poly = create_poly(5); 
       print_array(poly, 6);
    }
    */
    srand(time(NULL));
    FILE* file = fopen("fichier_eval_naif", "w");
    uint num_mult;

    for(uint i = 0; i < N ; i++)
    {
        float* curr_poly = create_poly(i);
        eval_naif(curr_poly, 5, i+1, &num_mult);
        fprintf(file, "%d, %d\n", i, num_mult);
        num_mult = 0;
    }

    FILE* file1 = fopen("fichier_eval_sm", "w");
    num_mult = 0;  

    for(uint i = 0; i < N ; i++)
    {
        float* curr_poly = create_poly(i);
        eval_sm(curr_poly, 5, i+1, &num_mult);
        fprintf(file1, "%d, %d\n", i, num_mult);
        num_mult = 0;
    }
    
    FILE* file2 = fopen("fichier_eval_horner", "w");
    num_mult = 0;  

    for(uint i = 0; i < N ; i++)
    {
        float* curr_poly = create_poly(i);
        eval_horner(curr_poly, 5, i+1, &num_mult);
        fprintf(file2, "%d, %d\n", i, num_mult);
        num_mult = 0;
    }

}



