%{
  #include <stdio.h>
  #include <ctype.h>
  #include <stdlib.h>
  #include <math.h>
  
  int yylval;
  int yylex();
  int yyerror(char *msg);
  static int t[26];
  
  
%}


%token NB PLUS FIN PO PF MEM AFFECT 
%left PLUS MOINS
%left MULT DIV
%right POW
%start PROG

%%

PROG : %empty
|PROG EXP FIN{ printf("%d\n", $2 );}
EXP  : NB { $$ = $1 ;} 
| EXP AFFECT EXP { $$ = $1 + $3 ;}
| EXP PLUS EXP { $$ = $1 + $3 ;}
| EXP MOINS EXP { $$ = $1 - $3 ;}
| EXP MULT EXP { $$ = $1 * $3 ;}
| EXP DIV EXP { $$ = $1 / $3 ;}
| PO EXP PF { $$ = $2;}
| EXP POW EXP { $$ = pow($1,$3);}
| MEM {$$=t[$1];}
;
%%

int main( void ) {
  yyparse() ;
  return 0;
}

int yylex( ){
  int car;int nb;int po=10;
  car = getchar() ;
  while((car=='\t')||(car==' ')){
    car = getchar() ;
  }
  if(car>='A'&&car<='Z'){
    yylval = car-'A';
    return MEM;
  }
  if (isdigit(car)) {
    nb = car - '0';
    car = getchar() ;
    while( isdigit(car) ){
      nb = nb*po+(car - '0');
      po*=10;
      car = getchar();
    }
    ungetc(car,stdin);
    yylval = nb;
    return NB;
  }
  switch ( car ) {
  case '+' : return PLUS;
  case '*' : return MULT;
  case '^' : return POW;
  case '-' : return MOINS;
  case '/' : return DIV;
  case '(' : return PO;
  case ')' : return PF;
  case '=' : return AFFECT;
  case '\n': return FIN;
  }
  return -1;
}
 
int yyerror(char *msg) {
  printf("\n%s\n", msg);
  return 1;
}

