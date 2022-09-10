#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>


void PubKeyPQ(mpz_t p,mpz_t q,mpz_t n,unsigned long int a){
/*
 * PubkeyPQ
 * --------------------
 * Premiere partie de la generation de la clee publique du protocole
 * RSA
 *  donne p et q,deux premier,de taille a, et leur produit n
 *
 *  Ne retourne rien mais stock les resultat dans les variable globale
 *  ATTENTION avec n qui est modifier par d'autre fonction
 */
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
    mpz_clear(max);
    mpz_mul (n, p, q);

}

void PubKeyED(mpz_t e,mpz_t d,mpz_t p,mpz_t q){
/*
 * PubkeyED
 * --------------------
 * Deuxieme partie de la generation de la clee publique ainsi que la
 * generation de la clee publique
 *  donne e et d,telle que e premier avec phi(n) et inferieur a celui ci.
 *  d lui et l'inverse de e mod[phi(n)]
 *
 */
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
    mpz_clears(pq,gcdpq,NULL);
}

void MD9T(mpz_t M,unsigned long int kp){
/*
 * MD9T
 * --------------------
 * Prend un mpz_t et shift par la gauche jusqu'a que sa
 *longueur soit un multiple de kp
 *
 */
    int a;
    a=(mpz_sizeinbase(M, 2));
    while (a%kp!=0)
    {
        mpz_mul_ui (M, M, 2);
        a=(mpz_sizeinbase(M, 2));
    }}



void expo(mpz_t rex,mpz_t a,mpz_t b,mpz_t m){
/*
 * expo
 * --------------------
 * Fait a**b[mod m], mais utulise des des multipliaction sucessive
 * afin de reduire la complexite.
 * 
 * Le resultat et stocker dans rex.
 * 
 */
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
    mpz_clear(mod);
    
}
/*
 * txt2int
 * --------------------
 * Ouvre un fichier txt et concatene la valeur ascii de sont
 * contenue dans un mpz.
 * 
 */

void txt2int(mpz_t Br){
    mpz_t i,temp;
    mpz_init(temp);
    mpz_init_set_ui (i, 1);
    long int ch;
    FILE *fp = fopen("amour.txt", "r");

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
    mpz_clear(temp);
}

void MD9(mpz_t MT,mpz_t M,unsigned long int kp){
/*
 * MD9
 * --------------------
 * divise M en packet de taille kp bit, et fait un xor entre ces
 * paquet
 * 
 * Pour la division en packet la fonction calcule un masque et
 * utulise un AND pour selectionner.
 * 
 * ATTENTION la fonction doit imperativment dabord passer par MD9T
 * 
 */
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
    mpz_clears(a,b,c,temp,temp1,NULL);
}

int main(){
    mpz_t p,q,n,e,d,Br,SBr,nsave,rsv,MD9sv;
    mpz_inits(p,q,n,e,d,Br,SBr,nsave,rsv,MD9sv,NULL);
    char choix;
    unsigned long int pqa,cmpsv;
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
    if (pqa==1)
    {
        printf("TAILLE INCORRECTE");
        return(-1);
    }
    PubKeyPQ(p,q,n,pqa);
    gmp_printf("p= %Zd  \n",p);
    gmp_printf("q= %Zd  \n",q);
    gmp_printf("n= %Zd  \n",n);
    mpz_set(nsave,n);
    PubKeyED(e,d,p,q);
    gmp_printf("e= %Zd  \n",e);
    gmp_printf("d= %Zd  \n",d);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("note: la signature du fichier se fait sur \"amour.txt\" \n");
    txt2int(Br);
    MD9T(Br,pqa);
    gmp_printf("text en int =%Zd\n",Br);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    MD9(SBr,Br,pqa);
    gmp_printf("MD9 brut avec %d =%Zd\n",pqa,SBr);
    mpz_set(MD9sv,SBr);
    expo(rsv,SBr,d,n);
    gmp_printf("Signature du doc =%Zd\n",rsv);
    expo(SBr,rsv,e,n);
    gmp_printf("verification =%Zd\n",SBr);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    cmpsv=mpz_cmp(MD9sv,SBr);
    if (cmpsv==0)
    {
        printf("Verification...CORRECT");
    }
    else
    {
        printf("ERREUR Verification");
    }
    mpz_clears(p,q,n,e,d,Br,SBr,nsave,rsv,MD9sv,NULL);
    
}
