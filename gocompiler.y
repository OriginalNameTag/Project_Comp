%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "y.tab.h"


int yylex (void);
void yyerror(char* s);
%}

%union{
    char* tkn;
}

%token <tkn> PACKAGE ID SEMICOLON VAR LPAR RPAR INT FLOAT32 BOOL STRING FUNC COMMA LBRACE RBRACE ASSIGN IF ELSE FOR RETURN PRINT STRLIT BLANKID PARSEINT CMDARFS LSQ RSQ OR AND LT GT EQ NE LE GE PLUS MINUS STAR DIV MOD NOT INTLIT REALLIT 



%%
//{} - zero ou mais repetições, ou seja aparece uma vez
//[] - opcional - 0 ou uma

Program: 
        PACKAGE ID SEMSICOLON Declarations
;
Declarations:
        Declarations VarDeclaration SEMICOLON 
        | Declarations FuncDeclaration SEMICOLON
        |
;
VarDeclaration:
        VAR VarSpec 
        | VAR LPAR VarSpec SEMICOLON RPAR
;
VarSpec:
        ID VarSpecHelper Type
;
VarSpecHelper:
        COMMA ID
        |
;
Type:
        INT 
        | FLOAT32 
        | BOOL 
        | STRING
;
FuncDeclaration:
        FUNC ID LPAR Parameters RPAR Type FuncBody
;
Parameters:
        ID Type COMMA ID Type
;
ParametersHelper:
        COMMA ID Type
        |
;
FuncBody:
        LBRACE VarsAndStatements RBRACE
;
VarsAndStatements:
        VarsAndStatements VarDeclaration
;
Statement:
        ID ASSIGN Expr
        | LBRACE Statement SEMICOLON RBRACE
        | IF Expr LBRACE Statement SEMICOLON
;
ParseArgs:

;
FuncInvocation:

;
Expr:

;