%{
        //Carlos Eduardo da Costa Jordão 2019221373
        //Guilherme Sousa de Oliveira e Cruz Junqueira 2019221958
                
        #include <stdlib.h>
        #include <stdio.h>
        #include <string.h>

        #include "y.tab.h"
        #include "struct.h"

        int yylex (void);
        void yyerror(char* s);
        struct Node * root = NULL;
%}

%union{
        char* tkn;
        struct Node * node;
}

%token <tkn> PACKAGE ID SEMICOLON VAR LPAR RPAR INT FLOAT32 BOOL STRING FUNC COMMA LBRACE RBRACE ASSIGN IF ELSE FOR RETURN PRINT STRLIT BLANKID PARSEINT CMDARGS LSQ RSQ OR AND LT GT EQ NE LE GE PLUS MINUS STAR DIV MOD NOT INTLIT REALLIT
%type <node> Program Declarations VarDeclaration VarSpec VarSpecHelper Type FuncDeclaration Parameters ParametersHelper FuncBody VarsAndStatements Statement StatementHelper ParseArgs FuncInvocation FuncInvocationHelper Expr
%token <tkn> RESERVED

%left COMMA
%right ASSIGN
%left OR
%left AND
%left EQ 
%left NE
%left LE 
%left LT 
%left GT 
%left GE
%left PLUS 
%left MINUS
%left STAR 
%left DIV
%left MOD
%nonassoc NOT
%nonassoc RPAR
%nonassoc LPAR

%%

Program: 
        PACKAGE ID SEMICOLON Declarations               {$$ = root = create_node("Program", NULL); add_son(root, $4);printf("root was created\n");}
;
Declarations:
        Declarations VarDeclaration SEMICOLON           {$$ = $2;}
        | Declarations FuncDeclaration SEMICOLON        {$$ = $2;}
        |                                               {$$ = NULL;}
;
Type:
        INT                                             {$$ = create_node("Int", NULL);}
        | FLOAT32                                       {$$ = create_node("Float32", NULL);}
        | BOOL                                          {$$ = create_node("Bool", NULL);}
        | STRING                                        {$$ = create_node("String", NULL);}

;

VarDeclaration:
        VAR VarSpec                                     {$$ = $2;}
        | VAR LPAR VarSpec SEMICOLON RPAR               {$$ = $3;}
;

VarSpec:
        ID VarSpecHelper Type                           {$$ = $2;}
;
VarSpecHelper:
        VarSpecHelper COMMA ID                          {$$ = $1;}
        |                                               {$$ = NULL;}       
;

FuncDeclaration:
        FUNC ID LPAR Parameters RPAR Type FuncBody      {;}
        | FUNC ID LPAR RPAR Type FuncBody               {;}
        | FUNC ID LPAR Parameters RPAR FuncBody         {;}
        | FUNC ID LPAR RPAR FuncBody                    {$$ = $5;}
;
Parameters:
        ID Type ParametersHelper                        {;}
;       
ParametersHelper:
        ParametersHelper COMMA ID Type                  {;}
        |                                               {$$ = NULL;} 
;
FuncBody:
        LBRACE VarsAndStatements RBRACE                 {$$ = $2;}
;
VarsAndStatements:
        VarsAndStatements VarDeclaration SEMICOLON      {;}
        | VarsAndStatements Statement SEMICOLON         {;}
        | VarsAndStatements SEMICOLON                   {;}
        |                                               {$$ = NULL;}
;
Statement:
        ID ASSIGN Expr                                  {$$ = $3;}
        | LBRACE StatementHelper RBRACE                 {$$ = $2;}
        | IF Expr LBRACE  StatementHelper RBRACE        {$$ = $2;}
        | IF Expr LBRACE StatementHelper RBRACE ELSE LBRACE StatementHelper RBRACE      {$$ = $2;}
        | FOR Expr LBRACE StatementHelper RBRACE        {$$ = $2;}
        | FOR LBRACE StatementHelper RBRACE             {$$ = $3;}
        | RETURN Expr                                   {$$ = $2;}
        | RETURN                                        {;}
        | FuncInvocation                                {$$ = $1;}
        | ParseArgs                                     {$$ = $1;}
        | PRINT LPAR Expr RPAR                          {$$ = $3;}
        | PRINT LPAR STRLIT RPAR                        {;}
        | error                                         {;}
;
StatementHelper:
        StatementHelper Statement SEMICOLON             {$$ = $2;}
        |                                               {$$ = NULL;}
;
ParseArgs:
        ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR         {$$ =  $9;}
        |ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ error RSQ RPAR        {;} 
;
FuncInvocation:
        ID LPAR Expr FuncInvocationHelper RPAR          {$$=$3;}
        | ID LPAR RPAR                                  {$$ = create_node("ID", $1);}
        | ID LPAR error RPAR                            {;}
;
FuncInvocationHelper:
        FuncInvocationHelper COMMA Expr                 {$$ = $3;}
        |                                               {$$ = NULL;}
;
Expr:
        Expr OR Expr                                    {$$ = create_node("OR",NULL); add_son($$, $1); add_son($$, $3);}
        | Expr AND Expr                                 {$$ = create_node("AND",NULL); add_son($$, $1); add_son($$, $3);}
        | Expr LT Expr                                  {$$ = create_node("LT",NULL); add_son($$, $1); add_son($$, $3);}
        | Expr GT Expr                                  {$$ = create_node("GT",NULL); add_son($$, $1); add_son($$, $3);}
        | Expr EQ Expr                                  {$$ = create_node("EQ",NULL); add_son($$, $1); add_son($$, $3);}
        | Expr NE Expr                                  {$$ = create_node("NE",NULL); add_son($$, $1); add_son($$, $3);}
        | Expr LE Expr                                  {$$ = create_node("LE",NULL); add_son($$, $1); add_son($$, $3);}
        | Expr GE Expr                                  {$$ = create_node("GE",NULL); add_son($$, $1); add_son($$, $3);}
        | Expr PLUS Expr                                {$$ = create_node("PLUS",NULL); add_son($$, $1); add_son($$, $3);}
        | Expr MINUS Expr                               {$$ = create_node("MINUS",NULL); add_son($$, $1); add_son($$, $3);}
        | Expr STAR Expr                                {$$ = create_node("STAR",NULL); add_son($$, $1); add_son($$, $3);}
        | Expr DIV Expr                                 {$$ = create_node("DIV",NULL); add_son($$, $1); add_son($$, $3);}
        | Expr MOD Expr                                 {$$ = create_node("MOD",NULL); add_son($$, $1); add_son($$, $3);}
        | NOT Expr                                      {$$ = create_node("NOT",NULL); add_son($$, $2);}
        | MINUS Expr                                    {$$ = create_node("MINUS",NULL); add_son($$, $2);}
        | PLUS Expr                                     {$$ = create_node("PLUS",NULL); add_son($$, $2);}
        | INTLIT                                        {$$ = create_node("INTLIT", $1);}
        | REALLIT                                       {$$ = create_node("REALLIT", $1);}
        | ID                                            {$$ = create_node("ID", $1);}
        | FuncInvocation                                {$$ = create_node("FuncInvocation",NULL); add_son($$, $1);}
        | LPAR Expr RPAR                                {$$ = create_node("Expr", NULL); add_son($$, $2);}
        | LPAR error RPAR                               {;}
;

%%