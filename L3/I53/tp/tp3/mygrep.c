# include <regex.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct{
	char** t;
	int n;
} t_slice;

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

char* underline(short st,short ed){
	char* sl_ch=calloc(256, sizeof(char));
	for (int i=0; i<=ed; i++) {
		if (i>=st) {
			sl_ch[i]='^';
		}	
		else {
		sl_ch[i]=' ';
		}
	}
	printf("SL:\n%s",sl_ch);
	return sl_ch;
}


int main(int argc , char * argv[])
{
	FILE* fl=fopen(argv[2], 'r');
}
