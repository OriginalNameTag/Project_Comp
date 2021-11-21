%{
    //Carlos Eduardo da Costa Jordão 2019221373
    //Guilherme Sousa de Oliveira e Cruz Junqueira 2019221958

    #include <string.h>
    #include "y.tab.h"
    #include "struct.h"

    int lflag = 0; 
    int tflag = 0;
    int column =  1;
    int line = 1;
    int semi=0;
    int temp=0;
    int error=0;
    Node* root;
    int yydebug=1;

%}
letter          [A-Za-z]
digit           [0-9]+
inti            [1-9]{digit}*
octal           0[0-7]+
hexadecimal     0[xX][0-9A-Fa-f]+


argument        ({letter}|"_")({letter}|{digit}|"_")*
reserved        break|case|chan|const|continue|default|defer|fallthrough|go|goto|import|interface|map|range|select|struct|switch|type|"++"|"--"
newline         \r\n|\n
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

";"                 {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "SEMICOLON\n");} else return SEMICOLON;}
","                 {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "COMMA\n");} else return COMMA;}
"_"                 {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "BLANKID\n");} else return BLANKID;}
"="                 {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "ASSIGN\n");} else return ASSIGN;}
"*"                 {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "STAR\n");} else return STAR;}
"/"                 {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "DIV\n");} else return DIV;}
"-"                 {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "MINUS\n");} else return MINUS;}
"+"                 {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "PLUS\n");} else return PLUS;}
"=="                {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "EQ\n");} else return EQ;}
">="                {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "GE\n");} else return GE;}
">"                 {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "GT\n");} else return GT;}
"{"                 {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "LBRACE\n");} else return LBRACE;}
"<="                {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "LE\n");} else return LE;}
"("                 {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "LPAR\n");} else return LPAR;}
"["                 {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "LSQ\n");} else return LSQ;}
"<"                 {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "LT\n");} else return LT;}
"%"                 {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "MOD\n");} else return MOD;}
"!="                {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "NE\n");} else return NE;}
"!"                 {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "NOT\n");} else return NOT;}
"&&"                {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "AND\n");} else return AND;}
"||"                {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "OR\n");} else return OR;}
"}"                 {column += yyleng; semi = 1; if (lflag) fprintf(yyout, "RBRACE\n"); else return RBRACE;}
")"                 {column += yyleng; semi = 1; if (lflag) {fprintf(yyout, "RPAR\n");} else return RPAR;}
"]"                 {column += yyleng; semi = 1; if (lflag) {fprintf(yyout, "RSQ\n");} else return RSQ;}
"package"           {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "PACKAGE\n");} else return PACKAGE;}
"return"            {column += yyleng; semi = 1; if (lflag) {fprintf(yyout, "RETURN\n");} else return RETURN;}
"else"              {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "ELSE\n");} else return ELSE;}
"for"               {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "FOR\n");} else return FOR;}
"if"                {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "IF\n");} else return IF;}
"var"               {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "VAR\n");} else return VAR;}
"int"               {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "INT\n");} else return INT;}
"float32"           {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "FLOAT32\n");} else return FLOAT32;}
"bool"              {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "BOOL\n");} else return BOOL;}
"string"            {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "STRING\n");} else return STRING;}
"fmt.Println"       {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "PRINT\n");} else return PRINT;}
"strconv.Atoi"      {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "PARSEINT\n");} else return PARSEINT;}
"func"              {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "FUNC\n");} else return FUNC;}
"os.Args"           {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "CMDARGS\n");} else return CMDARGS;}
"\t"|" "            {if (lflag) column++;}


{hexadecimal}       {column += yyleng; semi = 1; if (lflag) {fprintf(yyout, "INTLIT(%s)\n", yytext);} else {yylval.tkn = strdup(yytext); return INTLIT;}}
{octal}             {column += yyleng; semi = 1; if (lflag) {fprintf(yyout, "INTLIT(%s)\n", yytext);} else {yylval.tkn = strdup(yytext); return INTLIT;}}
{octalERROR}        {if (lflag) fprintf(yyout, "Line %d, column %d: invalid octal constant (%s)\n", yylineno, column, yytext); column += yyleng;};
{real}		        {column += yyleng; semi = 1; if (lflag) {fprintf(yyout, "REALLIT(%s)\n", yytext); } else {yylval.tkn = strdup(yytext); return REALLIT;}}
{intliteral}        {column += yyleng; semi = 1; if (lflag) {fprintf(yyout, "INTLIT(%s)\n", yytext);} else {yylval.tkn = strdup(yytext); return INTLIT;}}

{reserved}          {column += yyleng; semi = 0; if (lflag) {fprintf(yyout, "RESERVED(%s)\n", yytext);} else return RESERVED;}
{newline}           {if (semi)  {semi = 0; column = 1 ;if (lflag) {fprintf(yyout, "SEMICOLON\n");} else return SEMICOLON;}}
{argument}          {column += yyleng; semi = 1; if (lflag) {fprintf(yyout, "ID(%s)\n", yytext);} else{yylval.tkn = strdup(yytext);return ID;}; }
.                   {if (lflag) fprintf(yyout, "Line %d, column %d: illegal character (%s)\n", yylineno, column, yytext);semi=0; column += yyleng;}



<STRLITERAL>{newline}                            {if (lflag) fprintf(yyout, "Line %d, column %d: unterminated string literal\n", yylineno-1, temp); semi=0; column=1; error=1; BEGIN 0;} 
<STRLITERAL>\\                                   {if (lflag) fprintf(yyout, "Line %d, column %d: invalid escape sequence (\\)\n", yylineno, column); semi=0; column+=yyleng; error = 1;}
<STRLITERAL>{escape}                             {column += yyleng;}
<STRLITERAL>\\{escapeERROR}                      {if (lflag) fprintf(yyout, "Line %d, column %d: invalid escape sequence (%s)\n", yylineno, column, yytext); semi=0; column += yyleng; error=1;}
<STRLITERAL>({escape}|{escapeERROR})*\"          {column += yyleng; semi = 1; if (lflag) {fprintf(yyout, "STRLIT(\"%s)\n",yytext);} else {yylval.tkn = strdup(yytext); return STRLIT;} BEGIN 0;}
<STRLITERAL><<EOF>>                              {if (lflag) {fprintf(yyout, "Line %d, column %d: unterminated string literal\n", yylineno, temp);semi=0;column+=yyleng;} yyterminate();}
<STRLITERAL>.                                    {column += yyleng;}
 

<COMMENT>"*/"      {column = temp + 2; temp = 1; BEGIN 0;}
<COMMENT>{newline} {temp = 1;}
<COMMENT><<EOF>>   {if (semi) {semi = 0; if (lflag)fprintf(yyout, "SEMICOLON\n");else return SEMICOLON;} fprintf(yyout, "Line %d, column %d: unterminated comment\n", line, column); yyterminate();}
<COMMENT>.         {temp++;}
 

"//"                   {BEGIN LINECOMMENT;}
<LINECOMMENT>{newline} {column = 1; line++; if (lflag && semi) fprintf(yyout, "SEMICOLON\n"); semi=0; BEGIN 0;}
<LINECOMMENT>.         {column += yyleng;}


<<EOF>>                 {if (semi) {semi = 0; if (lflag) fprintf(yyout, "SEMICOLON\n"); else return SEMICOLON;} yyterminate();}


%%
int main (int argc, char**argv){
    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "-l") == 0){
            lflag = 1;
        }
        else if(strcmp(argv[i], "-t") == 0){
            tflag = 1;
        }   
    }
    if(lflag){
        yylex();
    }
    else {
        yyparse();
        print_tree(root,0);
    }

    return 0;
}
void yyerror(char* s){
    printf("Line %d, column %d: %s %s\n", yylineno, column, s, yytext);
}
int yywrap() {
    return 1;
}