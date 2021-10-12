# include <regex.h>
# include <stdio.h>
# include <stdlib.h>

int main ( int argc , char * argv[])
{
	regex_t regex ;
	size_t nmatch = 2;
	regmatch_t pmatch[2];
	if ( regcomp (&regex, argv[1], REG_EXTENDED )!=0)
		return 1;
	if ( regexec (&regex, argv[2], nmatch, pmatch, 0)==0)
		printf ( "motif trouve !\n" );
	else
		printf ( "motif non trouve fichtre !!\n" );
	printf("info so=%d\n",pmatch->rm_so);
	printf("info eo=%d\n",pmatch->rm_eo);
	regfree(&regex);
	return 0;
}
