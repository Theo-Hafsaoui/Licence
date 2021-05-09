#include <stdio.h>
#include <math.h>
#include <string.h>

typedef enum{False=0,True} tbool;

tbool BeginW(char *ch, char *chB){
    int len = strlen(chB);int i=0;
    while ((ch[i]==chB[i]) && (i<len))
    {
        i++;
    }
    return(i==len);
}

tbool correctP(char *e){
    int i=0;int len =strlen(e);int s=0;
    while (i<len)
    {
        if(e[i]=='('){
            s++;
        }

        if(e[i]==')'){
            s--;
        }
        i++;
    }
    return(s==0);
    
}
void main(int argc, char* ch[]){
    tbool bol;
    bol=BeginW(ch[1],ch[2]);
    printf("%d\n",bol);
	char chaine[] = "((3+2(5−1))";
	printf("%d\n", correctP(chaine));
}


