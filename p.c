static inline long TRU(long x){ return x>0 ? x : 0; }
#include<stdio.h>
#include<string.h>
#include<ctype.h>
char _EOL[] = "()";
long _=0;
#define EOL ((long)_EOL)
//long _=0, EOL = (long)"()";
char TOK[10240]="A"; long T=0;
long peek(){return ungetc(getchar(),stdin);}
long  eof(){return peek()==EOF;}
long  any(){return TOK[++T]=TRU(getchar());}
long  tok(){return(TOK[++T]=0),(long)strdup(TOK)+1;}
#define $ return tok();
#define  R(ws) if(!TRU(ws()))break;
#define  X(is) if(!TRU(is  ))break;
#define  C(ch) if(!TRU((ch)==any()))break;
#define NC(ch) if(!TRU((ch)!=any()))break;
#define  B(...) for(;;){__VA_ARGS__;return $$;}fseek(stdin,p,0),T=t;
#define START long t=T,p=ftell(stdin),$1,$2,$3,$4,$5,$6,$7,$8,$9,$$=1;
#define RR(...) START;__VA_ARGS__;return 0;
#define RULE(name,...) long name(){RR(__VA_ARGS__)}
#include <stdlib.h>
long cons(long h, long t){
  long*x=malloc(2*sizeof(h));x[0]=h;x[1]=t;return(long)x;}
long intgp(long x){return x <= 0xffff;}
long consp(long x){if(intgp(x))return 0; return(x&3)==0;}
long strnp(long x){if(intgp(x))return 0; return(x&3)==1;}
long car(long x){return consp(x)?((long*)x)[0]:EOL;}
long cdr(long x){return consp(x)?((long*)x)[1]:EOL;}
long xpr();
#include"p.h"
long _pr(long x){
  if(x==EOL) return printf("EOL");
  if(strnp(x)) return printf("\"%s\"", (char*)x);
  if(intgp(x)) return printf("%ld", x);
  long n=x; printf( "(" ), _pr(car(x));
  while(consp(n = cdr(n)))
    if (11) printf( " " ), _pr(car(n));
  if(n!=EOL)printf(" . "), _pr(n);
  printf( ")" ); return x;}
#define pr(x) _pr((long)(x))
int  main(){
  long w = ws();
  printf("W = %ld\n", w);
  long e = eof();
  printf("E = %ld\n", e);
  long i = id();
  printf("I = %ld\n", i);
  pr(i);
  long r = rlst();
  printf("R = %ld\n", r);
  return 0;}
