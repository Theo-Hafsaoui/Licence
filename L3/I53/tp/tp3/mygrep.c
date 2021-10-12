# include <regex.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int* find ( int argc , char * argv[])
{
	int* res=(int*) calloc(2,sizeof(int));
	regex_t regex ;
	size_t nmatch = 2;
	regmatch_t pmatch[2];
	if ( regcomp (&regex, argv[1], REG_EXTENDED )!=0)
		return 0;
	if ( regexec (&regex, argv[2], nmatch, pmatch, 0)==0)
		printf ( "################" );
	else
		printf ( "motif non trouve fichtre !!\n" );
	res[0]=pmatch->rm_so;
	res[1]=pmatch->rm_eo;
	regfree(&regex);
	return res;
}


int main(int argc , char * argv[])
{
	char* temp=argv[1];
	mouton_decoupe(temp);
	printf("N\n %s",temp);
}
