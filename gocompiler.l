%{
//Guilherme Sousa de Oliveira e Cruz Junqueira 2019221958
//Carlos Eduardo da Costa Jordão 2019221373
#include <string.h>
int lflag = 0; 
int column =  1;
int line = 1;
int semi=0;
int temp=0;
int error=0;

%}
letter          [A-Za-z]
digit           [0-9]+
inti            [1-9]{digit}*
octal           0[0-7]+
hexadecimal     0[xX][0-9A-Fa-f]*
float           {digit}[.,]{digit}

argument        ({letter}|"_")({letter}|{digit}|"_")*
reserved        break|case|chan|const|continue|default|defer|fallthrough|go|goto|import|interface|map|range|select|struct|switch|type|"++"|"--"
newline         \r\n|\n|\r
intliteral      {digit}|{inti}
exponent        ([eE]([+-]?){digit}+)
real            ({digit}+"."({digit}+)?{exponent}?)|({digit}+{exponent})|("."{digit}+{exponent}?)
octalERROR      0[0-9]+

escape          \\f|\\n|\\r|\\t|\\\\|\\\"
escapeERROR     [^\n\r\"\\]


%option yylineno
%x COMMENT LINECOMMENT STRLITERAL
%%
\"                  {temp = column ; column += yyleng; error = 0;BEGIN STRLITERAL;}
"/*"                {temp = column + 2; line = yylineno; BEGIN COMMENT;}

";"                 {if (lflag) fprintf(yyout, "SEMICOLON\n");column += yyleng; semi = 0;}
","                 {if (lflag) fprintf(yyout, "COMMA\n");column += yyleng; semi = 0;}
"_"                 {if (lflag) fprintf(yyout, "BLANKID\n");column += yyleng; semi = 0;}
"="                 {if (lflag) fprintf(yyout, "ASSIGN\n");column += yyleng; semi = 0;}
"*"                 {if (lflag) fprintf(yyout, "STAR\n");column += yyleng; semi = 0;}
"/"                 {if (lflag) fprintf(yyout, "DIV\n");column += yyleng; semi = 0;}
"-"                 {if (lflag) fprintf(yyout, "MINUS\n");column += yyleng; semi = 0;}
"+"                 {if (lflag) fprintf(yyout, "PLUS\n");column += yyleng; semi = 0;}
"=="                {if (lflag) fprintf(yyout, "EQ\n");column += yyleng; semi = 0;}
">="                {if (lflag) fprintf(yyout, "GE\n");column += yyleng; semi = 0;}
">"                 {if (lflag) fprintf(yyout, "GT\n");column += yyleng; semi = 0;}
"{"                 {if (lflag) fprintf(yyout, "LBRACE\n");column += yyleng; semi = 0;}
"<="                {if (lflag) fprintf(yyout, "LE\n");column += yyleng; semi = 0;}
"("                 {if (lflag) fprintf(yyout, "LPAR\n");column += yyleng; semi = 0;}
"["                 {if (lflag) fprintf(yyout, "LSQ\n");column += yyleng; semi = 0;}
"<"                 {if (lflag) fprintf(yyout, "LT\n");column += yyleng; semi = 0;}
"%"                 {if (lflag) fprintf(yyout, "MOD\n");column += yyleng; semi = 0;}
"!="                {if (lflag) fprintf(yyout, "NE\n");column += yyleng; semi = 0;}
"!"                 {if (lflag) fprintf(yyout, "NOT\n");column += yyleng; semi = 0;}
"&&"                {if (lflag) fprintf(yyout, "AND\n");column += yyleng; semi = 0;}
"||"                {if (lflag) fprintf(yyout, "OR\n");column += yyleng; semi = 0;}
"}"                 {if (lflag) fprintf(yyout, "RBRACE\n");column += yyleng; semi = 1;}
")"                 {if (lflag) fprintf(yyout, "RPAR\n");column += yyleng; semi = 1;}
"]"                 {if (lflag) fprintf(yyout, "RSQ\n");column += yyleng; semi = 1;}
"package"           {if (lflag) fprintf(yyout, "PACKAGE\n");column += yyleng; semi = 0;}
"return"            {if (lflag) fprintf(yyout, "RETURN\n");column += yyleng; semi = 1;}
"else"              {if (lflag) fprintf(yyout, "ELSE\n");column += yyleng; semi = 0;}
"for"               {if (lflag) fprintf(yyout, "FOR\n");column += yyleng; semi = 0;}
"if"                {if (lflag) fprintf(yyout, "IF\n");column += yyleng; semi = 0;}
"var"               {if (lflag) fprintf(yyout, "VAR\n");column += yyleng; semi = 0;}
"int"               {if (lflag) fprintf(yyout, "INT\n");column += yyleng; semi = 0;}
"float32"           {if (lflag) fprintf(yyout, "FLOAT32\n");column += yyleng; semi = 0;}
"bool"              {if (lflag) fprintf(yyout, "BOOL\n");column += yyleng; semi = 0;}
"string"            {if (lflag) fprintf(yyout, "STRING\n");column += yyleng; semi = 0;}
"fmt.Println"       {if (lflag) fprintf(yyout, "PRINT\n");column += yyleng; semi = 0;}
"strconv.Atoi"      {if (lflag) fprintf(yyout, "PARSEINT\n");column += yyleng; semi = 0;}
"func"              {if (lflag) fprintf(yyout, "FUNC\n");column += yyleng; semi = 0;}
"os.Args"           {if (lflag) fprintf(yyout, "CMDARGS\n");column += yyleng; semi = 0;}
"\t"|" "            {if (lflag) column++;}


{hexadecimal}       {if (lflag) fprintf(yyout, "INTLIT(%s)\n", yytext);column += yyleng; semi = 1;}
{octal}             {if (lflag) fprintf(yyout, "INTLIT(%s)\n", yytext);column += yyleng; semi = 1;}
{octalERROR}        {if (lflag) fprintf(yyout, "Line %d, column %d: invalid octal constant (%s)\n", yylineno, column, yytext); column += yyleng;};
{real}		        {if (lflag) fprintf(yyout, "REALLIT(%s)\n", yytext); column += yyleng; semi = 1;}
{intliteral}        {if (lflag) fprintf(yyout, "INTLIT(%s)\n", yytext); column += yyleng; semi = 1;}

{reserved}          {if (lflag) fprintf(yyout, "RESERVED(%s)\n", yytext); column += yyleng; semi = 0;}
{newline}           {if (lflag && semi) fprintf(yyout, "SEMICOLON\n"); line += 2; column = 1; semi = 0;}
{argument}          {if (lflag) fprintf(yyout, "ID(%s)\n", yytext); column += yyleng; semi = 1;}
.                   {if (lflag) fprintf(yyout, "Line %d, column %d: illegal character (%s)\n", yylineno, column, yytext);semi=0; column += yyleng;}



<STRLITERAL>{newline}                            {if (lflag) fprintf(yyout, "Line %d, column %d: unterminated string literal\n", yylineno-1, temp); semi=0; column=1; error=1; BEGIN 0;} 
<STRLITERAL>\\                                   {if (lflag) fprintf(yyout, "Line %d, column %d: invalid escape sequence (\\)\n", yylineno, column); semi=0; column+=yyleng; error = 1;}
<STRLITERAL>{escape}                             {column += yyleng;}
<STRLITERAL>\\{escapeERROR}                      {if (lflag) fprintf(yyout, "Line %d, column %d: invalid escape sequence (%s)\n", yylineno, column, yytext); semi=0; column += yyleng; error=1;}
<STRLITERAL>({escape}|{escapeERROR})*\"          {if (lflag && error==0) {fprintf(yyout, "STRLIT(\"%s)\n",yytext);  semi = 1;}column += yyleng; BEGIN 0;}
<STRLITERAL><<EOF>>                              {if (lflag) fprintf(yyout, "Line %d, column %d: unterminated string literal\n", yylineno, temp);semi=0;column+=yyleng; exit(0);}
<STRLITERAL>.                                    {column += yyleng;}
 

<COMMENT>"*/"      {column = temp + 2; temp = 1; BEGIN 0;}
<COMMENT>{newline} {temp = 1;}
<COMMENT><<EOF>>   {if (lflag && semi) fprintf(yyout, "SEMICOLON\n"); fprintf(yyout, "Line %d, column %d: unterminated comment\n", line, column); exit(0);}
<COMMENT>.         {temp++;}
 

"//"                   {BEGIN LINECOMMENT;}
<LINECOMMENT>{newline} {column = 1; line++; if (lflag && semi) fprintf(yyout, "SEMICOLON\n");semi=0;  BEGIN 0;}
<LINECOMMENT>.         {column += yyleng;}


<<EOF>>                 {if (lflag && semi) fprintf(yyout, "SEMICOLON\n"); exit(0);}


%%
int main (int argc, char**argv){
    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "-l") == 0){
            lflag = 1;
        }
    }
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}