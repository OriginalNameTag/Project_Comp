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

%token <tkn> PACKAGE ID SEMICOLON VAR LPAR RPAR INT FLOAT32 BOOL STRING FUNC COMMA LBRACE RBRACE ASSIGN IF ELSE FOR RETURN PRINT STRLIT BLANKID PARSEINT CMDARGS LSQ RSQ OR AND LT GT EQ NE LE GE PLUS MINUS STAR DIV MOD NOT INTLIT REALLIT

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
        PACKAGE ID SEMICOLON Declarations
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
        VarSpecHelper COMMA ID
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
        | FUNC ID LPAR RPAR Type FuncBody
        | FUNC ID LPAR Parameters RPAR FuncBody
        | FUNC ID LPAR RPAR FuncBody
;
Parameters:
        ID Type ParametersHelper
;
ParametersHelper:
        ParametersHelper COMMA ID Type
        |
;
FuncBody:
        LBRACE VarsAndStatements RBRACE
;
VarsAndStatements:
        VarsAndStatements VarDeclaration SEMICOLON
        | VarsAndStatements Statement SEMICOLON
        | VarsAndStatements SEMICOLON
        |
;
Statement:
        ID ASSIGN Expr
        | LBRACE StatementHelper RBRACE
        | IF Expr LBRACE  StatementHelper RBRACE
        | IF Expr LBRACE StatementHelper RBRACE ELSE LBRACE StatementHelper RBRACE
        | FOR Expr LBRACE StatementHelper RBRACE
        | FOR LBRACE StatementHelper RBRACE
        | RETURN Expr
        | RETURN
        | FuncInvocation
        | ParseArgs
        | PRINT LPAR Expr RPAR
        | PRINT LPAR STRLIT RPAR
;
StatementHelper:
        StatementHelper Statement SEMICOLON
        |
;
ParseArgs:
        ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR 
;
FuncInvocation:
        ID LPAR Expr FuncInvocationHelper RPAR
        | ID LPAR RPAR 
;
FuncInvocationHelper:
        FuncInvocationHelper COMMA Expr
        |
;
Expr:
        Expr OR Expr
        | Expr AND Expr
        | Expr LT Expr
        | Expr GT Expr
        | Expr EQ Expr
        | Expr NE Expr
        | Expr LE Expr
        | Expr GE Expr
        | Expr PLUS Expr
        | Expr MINUS Expr
        | Expr STAR Expr
        | Expr DIV Expr
        | Expr MOD Expr
        | NOT Expr
        | MINUS Expr
        | PLUS Expr
        | INTLIT 
        | REALLIT 
        | ID 
        | FuncInvocation
        | LPAR Expr RPAR 
;