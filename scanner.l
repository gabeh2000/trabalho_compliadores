 /* Secao das declaracoes */

%option noyywrap
  /* Sera copiado no .c final */
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
   
    /* este include eh importante... */
    //#include "tokens.h"
    #include "y.tab.h"
    #include "symbol_table.h"
    #include "lista.h"


    extern symbol_t symbol_table;
%}

%option yylineno
%option noyywrap
/*%{
#define YY_USER_ACTION yylloc.first_line = yylineno;
#define YY_USER_INIT yylineno = 1;
%} */

  /* Definicoes regulares (A COMPLETAR conforme a especificacao) */
digito     [0-9]
inteiro    ("-")?{digito}+
frac       "."{digito}+
num        {inteiro}({frac})?
caractere  [a-zA-Z]
literal    {caractere}+
var        {literal}({literal}|{digito}+)?
text        ["]([^"\\\n]|\\.|\\\n)*["]

%%

 /* Secao das Regras de traducao */
 /* O que consta aqui eh puramente ilustrativo... A COMPLETAR ! 
  * Ver tambem "tokens.h".
  */

int    {printf("INT\n"); return(INT); }
double { return(DOUBLE);}
char   { return(CHAR); }
float  { return(FLOAT); }
string  { return(STRING); }
"++"   { return(INC);}
"--"   { return(DEC);}
","    { return(COMA);}
"="    { return(ATRIB);}
":"    { return(COLON);}
"."    { return(PERIOD);}
"]"    { return(BRAKCLOSE);}
"["    { return(BRAKOPN);}
")"    { return(PARCLOSE);}
"("    { printf("ABRE PAR\n");return(PAROPN);}
"+"    { return(PLUS);}
"\'"   { return(QUOTE);}
"\""   { return(DQUOTE);}
"-"    { return(MIN);}
"/"    { return(BAR);}
"*"    { return(AST);}
"{"    { printf("ABRE CHAVE\n"); return(KOPN);}
"}"    { printf("FECHA CHAVE\n");return(KCLOSE);}
"<"    { printf("MENOR\n");return(LESS);}
">"    { return(GREAT);}
"<="   { return( LE ) ; }
">="   { return(GE);}
"=="   { return(EQ);}
"!="   { return(NE);}
"!"    { return(NOT);}
";"    { printf("PNT VIRGULA\n"); return(SEMICOLON);}
or     { return(OR);}
and    { return(AND);}
if     { printf("IF\n"); return( IF ); }
then   { return(THEN);}
else   { return(ELSE); }
while  { return (WHILE); }
for    { return(FOR);}
class  { return(CLASS);}
public { return(PUBLIC);}
private { return(PRIVATE);}
protected  { return(PROTECTED);}
void    { return(VOID);}
"NULL"    { return(NUL);}
const    { return(CONST);}
static    { return(STATIC);}
{inteiro}   { printf("INTEIRO\n");return(INT_LIT);}
{num}     { printf("NUM\n");return(F_LIT);}
{var}    { printf("VAR\n");return(IDF);}
{text}    { return(TEXT);}
[ \n\t\r]+ { printf("BRANCO\n"); }

  /* Tratamento dos erros lexicais: a regra seguinte pega tudo o que nao
   * fechou com uma Regexp anterior.
   */
. { printf("Erro léxico: caractere desconhecido '%c' (%d).\n",
        yytext[0], yytext[0]); }
%%
 /* Secao dos  Procedimentos auxiliares  */

 /* Para redefinir a entrada padrao do LEX. 
  * Redefinir a variavel 'yyin' para ler de um arquivo. Por exemplo:
     yyin = fopen("Meu_programa.c", "r");
  * ira mandar ler o programa a ser compilado pelo analisador lexical
  * em 'Meu_programa.c'.
  * O default eh ler da entrada standard (o teclado).
  */
/*
extern FILE *yyin;
int main(int argc, char* argv[]) {
   int token;
   if (argc != 2) {
     printf("uso: %s <input_file>. Try again!\n", argv[0]);
     exit(50);
   }
   yyin = fopen(argv[1], "r");
   if (!yyin) {
     printf("Uso: %s <input_file>. Could not find %s. Try again!\n", 
         argv[0], argv[1]);
     exit(55);
   }
*/
  /* agora a entrada padrao eh o arquivo especificado como 1o argumento ao
   * executavel (argv[1]).
   * Soh chama o analisador lexical default fornecido pelo output do Flex:
   */
//  while (token=yylex()) { 
     /* neste laco, obtem-se "palavra por palavra" os tokens reconhecidos
      * pelo scanner fornecido pelo Lex. Poderia ser feita a analise
      * sintatica... Sera feito depois!
      */
/*     printf("Meu analisador lexical reconheceu o token %d\n", token);
  }
  return(0);
}
*/
