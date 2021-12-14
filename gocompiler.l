%{
    //Carlos Eduardo da Costa Jordão 2019221373
    //Guilherme Sousa de Oliveira e Cruz Junqueira 2019221958

    #include <string.h>
    #include "y.tab.h"
    #include "struct.h"
    #include "symtab.h"
    #include "semantics.h"

    int lflag = 0; 
    int tflag = 0;
    int sflag = 0;
    int column =  1;
    int line = 1;
    int semi=0;
    int temp=0;
    int error=0;
    Node* root;
    int col_yacc = 1, line_yacc = 1;
    int yydebug=1;
    int erro = 0;
    symtab* global;

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
\"                  {temp = column; col_yacc = column; column += yyleng; error = 0;BEGIN STRLITERAL;}
"/*"                {temp = column + 2; line = yylineno; BEGIN COMMENT;}

";"                 {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "SEMICOLON\n");} else return SEMICOLON;}
","                 {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "COMMA\n");} else return COMMA;}
"_"                 {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "BLANKID\n");} else return BLANKID;}
"="                 {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "ASSIGN\n");} else return ASSIGN;}
"*"                 {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "STAR\n");} else return STAR;}
"/"                 {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "DIV\n");} else return DIV;}
"-"                 {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "MINUS\n");} else return MINUS;}
"+"                 {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "PLUS\n");} else return PLUS;}
"=="                {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "EQ\n");} else return EQ;}
">="                {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "GE\n");} else return GE;}
">"                 {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "GT\n");} else return GT;}
"{"                 {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "LBRACE\n");} else return LBRACE;}
"<="                {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "LE\n");} else return LE;}
"("                 {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "LPAR\n");} else return LPAR;}
"["                 {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "LSQ\n");} else return LSQ;}
"<"                 {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "LT\n");} else return LT;}
"%"                 {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "MOD\n");} else return MOD;}
"!="                {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "NE\n");} else return NE;}
"!"                 {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "NOT\n");} else return NOT;}
"&&"                {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "AND\n");} else return AND;}
"||"                {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "OR\n");} else return OR;}
"}"                 {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 1; if (lflag) fprintf(yyout, "RBRACE\n"); else return RBRACE;}
")"                 {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 1; if (lflag) {fprintf(yyout, "RPAR\n");} else return RPAR;}
"]"                 {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 1; if (lflag) {fprintf(yyout, "RSQ\n");} else return RSQ;}
"package"           {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "PACKAGE\n");} else return PACKAGE;}
"return"            {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 1; if (lflag) {fprintf(yyout, "RETURN\n");} else return RETURN;}
"else"              {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "ELSE\n");} else return ELSE;}
"for"               {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "FOR\n");} else return FOR;}
"if"                {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "IF\n");} else return IF;}
"var"               {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "VAR\n");} else return VAR;}
"int"               {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "INT\n");} else return INT;}
"float32"           {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "FLOAT32\n");} else return FLOAT32;}
"bool"              {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "BOOL\n");} else return BOOL;}
"string"            {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "STRING\n");} else return STRING;}
"fmt.Println"       {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "PRINT\n");} else return PRINT;}
"strconv.Atoi"      {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "PARSEINT\n");} else return PARSEINT;}
"func"              {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "FUNC\n");} else return FUNC;}
"os.Args"           {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "CMDARGS\n");} else return CMDARGS;}
"\t"|" "            {column++;col_yacc = column;}


{hexadecimal}       {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 1; if (lflag) {fprintf(yyout, "INTLIT(%s)\n", yytext);} else {yylval.tkn = strdup(yytext); return INTLIT;}}
{octal}             {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 1; if (lflag) {fprintf(yyout, "INTLIT(%s)\n", yytext);} else {yylval.tkn = strdup(yytext); return INTLIT;}}
{octalERROR}        {if (lflag) fprintf(yyout, "Line %d, column %d: invalid octal constant (%s)\n", yylineno, column, yytext); column += yyleng;};
{real}		        {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 1; if (lflag) {fprintf(yyout, "REALLIT(%s)\n", yytext); } else {yylval.tkn = strdup(yytext); return REALLIT;}}
{intliteral}        {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 1; if (lflag) {fprintf(yyout, "INTLIT(%s)\n", yytext);} else {yylval.tkn = strdup(yytext); return INTLIT;}}
{reserved}          {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 0; if (lflag) {fprintf(yyout, "RESERVED(%s)\n", yytext);} else return RESERVED;}
{newline}           {col_yacc = column; line_yacc = yylineno-1; column = 1; if (semi)  {semi = 0; if (lflag) {fprintf(yyout, "SEMICOLON\n");} else return SEMICOLON;}}
{argument}          {col_yacc = column; line_yacc = yylineno; column+= yyleng; semi = 1; if (lflag) {fprintf(yyout, "ID(%s)\n", yytext);} else{yylval.tkn = strdup(yytext);return ID;}; }
.                   {if (lflag) {fprintf(yyout, "Line %d, column %d: illegal character (%s)\n", yylineno, column, yytext);}semi=0; column += yyleng;}



<STRLITERAL>\"                                   {column = temp + 2; col_yacc = column + 2;temp = 1; BEGIN 0;}
<STRLITERAL>{newline}                            {col_yacc = temp; semi=0; column=1; error=1; BEGIN 0; fprintf(yyout, "Line %d, column %d: unterminated string literal\n", yylineno-1, temp); } 
<STRLITERAL>\\                                   {semi=0; column+=yyleng; col_yacc = column; error = 1; fprintf(yyout, "Line %d, column %d: invalid escape sequence (\\)\n", yylineno, column); }
<STRLITERAL>{escape}                             {column += yyleng; col_yacc = column;}
<STRLITERAL>\\{escapeERROR}                      {fprintf(yyout, "Line %d, column %d: invalid escape sequence (%s)\n", yylineno, column, yytext); semi=0; column += yyleng; error=1; col_yacc = column + 2;}
<STRLITERAL>({escape}|{escapeERROR})*\"          {line_yacc = yylineno; column+= yyleng; semi = 1; BEGIN 0; if (lflag) {fprintf(yyout, "STRLIT(\"%s)\n",yytext);} else{ char* str = malloc(yyleng+2); sprintf(str, "\"%s", yytext); yytext = str; yylval.tkn = str; return STRLIT;}}
<STRLITERAL><<EOF>>                              {semi=0;column+=yyleng; col_yacc = column; fprintf(yyout, "Line %d, column %d: unterminated string literal\n", yylineno, column); yyterminate();}
<STRLITERAL>.                                    {column += yyleng;col_yacc = column;}
 

<COMMENT>"*/"      {column = temp + 2; temp = 1; BEGIN 0; col_yacc = column;}
<COMMENT>{newline} {temp = 1; col_yacc = 1; line_yacc = yylineno-1; if (semi) {semi = 0; if (lflag)fprintf(yyout, "SEMICOLON\n");else return SEMICOLON;}}
<COMMENT><<EOF>>   {fprintf(yyout, "Line %d, column %d: unterminated comment\n", line, column); yyterminate();}
<COMMENT>.         {temp+= yyleng;}
 

"//"                   {BEGIN LINECOMMENT;}
<LINECOMMENT>{newline} {col_yacc = column; line_yacc = yylineno-1; column = 1; line++;BEGIN 0; if (semi){ semi=0; if (lflag){fprintf(yyout, "SEMICOLON\n");} else return SEMICOLON;}}
<LINECOMMENT>.         {column += yyleng;}


<<EOF>>                 {col_yacc = column ; line_yacc = yylineno; if (semi) {semi = 0; if (lflag) fprintf(yyout, "SEMICOLON\n"); else return SEMICOLON;} yyterminate();}


%%
int main (int argc, char**argv){
    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "-l") == 0){
            lflag = 1;
        }
        else if(strcmp(argv[i], "-t") == 0){
            tflag = 1;
        } 
        else if(strcmp(argv[i], "-s") == 0){
            sflag = 1;
        }  
    }
    if(lflag){
        yylex();
    }
    else {
        yyparse();
        if(erro == 0 && tflag){
        print_tree(root,0);
        }
        else if (sflag){
            show_table(global);
        }
    }

    return 0;
}
void yyerror(char* s){
    erro = 1;
    printf("Line %d, column %d: %s: %s\n", line_yacc, col_yacc, s, yytext);
}
int yywrap() {
    return 1;
}