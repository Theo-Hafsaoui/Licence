#include <gmp.h>
#include <stdio.h>

int main(){
    mpz_t p,q,max,n;
    int cmp1,cmp2,cont;
    unsigned long int seed,a;
    seed = time(NULL);
    mpz_inits(p,q,max,n);
    gmp_randstate_t init;
    gmp_randinit_mt(init);
    gmp_randseed_ui(init, seed);
    scanf("%lu",&a);
    mpz_ui_pow_ui (max, 2, a-1);
    do
    {
        mpz_urandomb(p, init, a);
        mpz_urandomb(q, init, a);
        mpz_nextprime(p,p);
        mpz_nextprime(q,q);
        cmp1=mpz_cmp(p,max);
        cmp2=mpz_cmp(q,max);
        cont=mpz_cmp(p,q);
        if (cmp1==-1 | cmp2==-1)
        {
            cmp1=0;
        }
        if (cont==0)
        {
            cmp1=0;
        }
        
    } while (!(cmp1 && cmp2));
    mpz_mul (n, p, q);
    printf("~~~~~\n");
    gmp_printf("p= %Zd\n", p);
    gmp_printf("q= %Zd\n", q);    
    gmp_printf("n= %Zd\n", n);
}
