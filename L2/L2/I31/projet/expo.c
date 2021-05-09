#include <gmp.h>
#include <stdio.h>
void expo(mpz_t rex,mpz_t a,mpz_t b,mpz_t m){
    unsigned long int sig,cmp;
    mpz_t mod;
    mpz_init(mod);
    mpz_set_ui (rex, 1);
    mpz_mod(mod,a,m);
    sig=mpz_sgn(mod);
    if (!(sig))
    {
        mpz_set_ui (rex, 0);
        return;
    }
    sig=mpz_sgn(b);
    while (sig)
    {
        mpz_mod_ui(mod,b,2);
        cmp=mpz_cmp_ui(mod,1);
        if (!(cmp)){
            mpz_mul (rex, rex, a);
            mpz_mod(rex,rex,m);
        }
        mpz_tdiv_q_2exp (b, b, 1);
        mpz_mul (a, a, a);
        mpz_mod(a,a,m);
        sig=mpz_sgn(b);
    }
    
}
int main(){
    mpz_t a,b,m,rex;
    mpz_inits(a,b,m,rex,NULL);
    mpz_set_ui (rex, 26);
    mpz_set_ui (b, 183);
    mpz_set_ui (m, 667);
    expo(rex,rex,b,m);
    gmp_printf("%Zd",rex);

}