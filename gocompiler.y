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
%right NOT
%left RPAR
%left LPAR

%%

Program: 
        PACKAGE ID SEMICOLON Declarations               {root = create_node("Program", NULL); add_son(root, $4)}
;
Declarations:
        Declarations VarDeclaration SEMICOLON           {$$ = $2;}
        | Declarations FuncDeclaration SEMICOLON        {$$ = $2;}
        |                                               {$$ = NULL;}
;
VarDeclaration:
        VAR VarSpec                                     {$$ = $2;}
        | VAR LPAR VarSpec SEMICOLON RPAR               {$$ = $2;}
;
VarSpec:
        ID VarSpecHelper Type                           {$$ = $2;}
;
VarSpecHelper:
        VarSpecHelper COMMA ID                          {$$ = $1;}
        |                                               {$$ = NULL;}       
;
Type:
        INT                                             {$$ = create_node("Int", NULL)}
        | FLOAT32                                       {$$ = create_node("Float32", NULL)}
        | BOOL                                          {$$ = create_node("Bool", NULL)}
        | STRING                                        {$$ = create_node("String", NULL)}
;
FuncDeclaration:
        FUNC ID LPAR Parameters RPAR Type FuncBody      {$$ = $;}
        | FUNC ID LPAR RPAR Type FuncBody               {$$ = $;}
        | FUNC ID LPAR Parameters RPAR FuncBody         {$$ = $;}
        | FUNC ID LPAR RPAR FuncBody                    //dont need?
;
Parameters:
        ID Type ParametersHelper                        {$$ = $;}
;       
ParametersHelper:
        ParametersHelper COMMA ID Type                  {$$ = $;}
        |                                               {$$ = $;}
;
FuncBody:
        LBRACE VarsAndStatements RBRACE                 {$$ = $;}
;
VarsAndStatements:
        VarsAndStatements VarDeclaration SEMICOLON      {$$ = $;}
        | VarsAndStatements Statement SEMICOLON         {$$ = $;}
        | VarsAndStatements SEMICOLON                   {$$ = $;}
        |                                               {$$ = $;}
;
Statement:
        ID ASSIGN Expr                                  {$$ = $3;}
        | LBRACE StatementHelper RBRACE                 {$$ = $2;}
        | IF Expr LBRACE  StatementHelper RBRACE        {$$ = $2;}
        | IF Expr LBRACE StatementHelper RBRACE ELSE LBRACE StatementHelper RBRACE      {$$ = $2;}
        | FOR Expr LBRACE StatementHelper RBRACE        {$$ = $2;}
        | FOR LBRACE StatementHelper RBRACE             {$$ = $3;}
        | RETURN Expr                                   {$$ = $2;}
        | RETURN                                        {$$ = $1;}
        | FuncInvocation                                {$$ = $1;}
        | ParseArgs                                     {$$ = $1;}
        | PRINT LPAR Expr RPAR                          {$$ = $3;}
        | PRINT LPAR STRLIT RPAR                        {$$ = $1;}
;
StatementHelper:
        StatementHelper Statement SEMICOLON             {$$ = $2;}
        |                                               {$$ = NULL;}
;
ParseArgs:
        ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR         {$$ = $9;} 
;
FuncInvocation:
        ID LPAR Expr FuncInvocationHelper RPAR          {$$ = $3;}
        | ID LPAR RPAR                                  {$$ = $1;}
;
FuncInvocationHelper:
        FuncInvocationHelper COMMA Expr                 {$$ = $2;}
        |                                               {$$ = NULL;}
;
Expr:
        Expr OR Expr                                    {$$ = $create_node("Or",NULL); add_son($$, $1); add_son($$, $3);}
        | Expr AND Expr                                 {$$ = $create_node(); add_son($$, $1); add_son($$, $3);}
        | Expr LT Expr                                  {$$ = $create_node(); add_son($$, $1); add_son($$, $3);}
        | Expr GT Expr                                  {$$ = $create_node(); add_son($$, $1); add_son($$, $3);}
        | Expr EQ Expr                                  {$$ = $create_node(); add_son($$, $1); add_son($$, $3);}
        | Expr NE Expr                                  {$$ = $create_node(); add_son($$, $1); add_son($$, $3);}
        | Expr LE Expr                                  {$$ = $create_node(); add_son($$, $1); add_son($$, $3);}
        | Expr GE Expr                                  {$$ = $create_node(); add_son($$, $1); add_son($$, $3);}
        | Expr PLUS Expr                                {$$ = $create_node(); add_son($$, $1); add_son($$, $3);}
        | Expr MINUS Expr                               {$$ = $create_node(); add_son($$, $1); add_son($$, $3);}
        | Expr STAR Expr                                {$$ = $create_node(); add_son($$, $1); add_son($$, $3);}
        | Expr DIV Expr                                 {$$ = $create_node(); add_son($$, $1); add_son($$, $3);}
        | Expr MOD Expr                                 {$$ = $create_node(); add_son($$, $1); add_son($$, $3);}
        | NOT Expr                                      {$$ = $1;}
        | MINUS Expr                                    {$$ = $1;}
        | PLUS Expr                                     {$$ = $1;}
        | INTLIT                                        {$$ = create_node("Intlit", $1);}
        | REALLIT                                       {$$ = create_node("Reallit", $1);}
        | ID                                            {$$ = create_node("Id", $1);}
        | FuncInvocation                                {$$ = $1;}
        | LPAR Expr RPAR                                {$$ = $2;}
;

%%
