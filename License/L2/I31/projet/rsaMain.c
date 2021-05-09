#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>


int PubKeyPQ(mpz_t p,mpz_t q,mpz_t n,unsigned long int a){
    mpz_t max;
    mpz_init(max);
    int cmp1,cmp2,cont;
    unsigned long int seed;
    seed = time(NULL);
    gmp_randstate_t init;
    gmp_randinit_mt(init);
    gmp_randseed_ui(init, seed);
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

}

void PubKeyED(mpz_t e,mpz_t d,mpz_t p,mpz_t q){
    unsigned long int cmp,cont,seed;
    mpz_t pq,gcdpq;
    cont=1;
    mpz_inits(pq,gcdpq,e,NULL);
    mpz_sub_ui(p,p,cont);
    mpz_sub_ui(q,q,cont);
    mpz_mul(pq,p,q);
    seed = time(NULL);
    gmp_randstate_t init;
    gmp_randinit_mt(init);
    gmp_randseed_ui(init, seed);
    do
    {
        mpz_urandomm(e, init, pq);
        mpz_gcd (gcdpq, e, pq);
        cmp=mpz_cmp_ui(gcdpq,cont);
        if (cmp==0)
        {
            cont=0;
        }
    } while (cont);
    mpz_invert(d,e,pq);
}

void MD9T(mpz_t M,unsigned long int kp){
    int a;
    a=(mpz_sizeinbase(M, 2));
    while (a%kp!=0)
    {
        mpz_mul_ui (M, M, 2);
        a=(mpz_sizeinbase(M, 2));
    }}



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

void txt2int(mpz_t Br){
    mpz_t i,temp;
    mpz_init(temp);
    mpz_init_set_ui (i, 1);
    long int ch;
    FILE *fp = fopen("test.txt", "r");

    if (fp == NULL)
    {
    printf("Fichier introuvable\n");
    return;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        mpz_mul_si (temp, i, ch);
        mpz_add(Br,Br,temp);
        mpz_mul_si (i, i, 1000);
    }

    fclose(fp);
}

void MD9(mpz_t MT,mpz_t M,unsigned long int kp){
    mpz_t a,b,c,temp,temp1;
    mpz_inits(a,b,c,temp,temp1,NULL);
    int i=1;int cmp;int cpt;
    mpz_ui_pow_ui (a, 2, kp*i);
    mpz_ui_pow_ui (b, 2, kp*i-kp);
    mpz_sub_ui(a,a,1);
    mpz_sub_ui(b,b,1);
    mpz_xor (c, a, b);
    mpz_and (temp1, M, c);
    mpz_and (temp, M, c);
    cmp=mpz_sgn(temp);
    while (cmp)
    {
        mpz_xor (MT, MT, temp1);
        i+=1;
        mpz_ui_pow_ui (a, 2, kp*i);
        mpz_ui_pow_ui (b, 2, kp*i-kp);
        mpz_sub_ui(a,a,1);
        mpz_sub_ui(b,b,1);
        mpz_xor (c, a, b);
        mpz_and (temp1, M, c);
        cpt=0;
        while (cpt<(kp*(i-1)))
        {
            mpz_cdiv_q_ui(temp1,temp1,2);
            cpt++;
        }
        
        mpz_and (temp, M, c);
        cmp=mpz_sgn(temp);
    }
}

int main(){
    mpz_t p,q,n,e,d,Br,SBr,nsave,rsv;
    mpz_inits(p,q,n,e,d,Br,SBr,nsave,rsv,NULL);
    char choix;
    unsigned long int pqa;
    printf("###########################\n");
    printf("#   *****  *****  ******  #\n");
    printf("#   *   *  *      *    *  #\n");
    printf("#   *****  *****  ******  #\n");
    printf("#   ***        *  *    *  #\n");
    printf("#   *  *       *  *    *  #\n");
    printf("#   *   *  *****  *    *  #\n");
    printf("###########################\n");
    printf("Taille des signature = ");
    scanf("%lu",&pqa);
    PubKeyPQ(p,q,n,pqa);
    gmp_printf("p= %Zd  ",p);
    gmp_printf("q= %Zd  ",q);
    gmp_printf("n= %Zd  \n",n);
    mpz_set(nsave,n);
    gmp_printf("nsave=%Zd\n",nsave);
    PubKeyED(e,d,p,q);
    gmp_printf("e= %Zd  ",e);
    gmp_printf("d= %Zd  \n",d);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    scanf("%c",&choix);
    printf("note: la signature du fichier se fait sur \"test.txt\" \n");
    txt2int(Br);
    MD9T(Br,pqa);
    gmp_printf("text en int =%Zd\n",Br);
    MD9(SBr,Br,pqa);
    gmp_printf("MD9 avec %d =%Zd\n",pqa,SBr);
    expo(rsv,SBr,d,n);
    gmp_printf("1:m avec %d =%Zd\n",pqa,rsv);
    expo(SBr,rsv,e,n);
    gmp_printf("ver:MD9 avec %d =%Zd\n",pqa,SBr);



}