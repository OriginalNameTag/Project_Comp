%{
        //Carlos Eduardo da Costa Jordão 2019221373
        //Guilherme Sousa de Oliveira e Cruz Junqueira 2019221958
                
        #include <stdlib.h>
        #include <stdio.h>
        #include <string.h>

        #include "y.tab.h"
        #include "struct.h"

        int yylex (void);
        extern void yyerror(char* s);
        extern Node * root;
        
%}

%union{
        char* tkn;
        struct Node * node;
}

%token <tkn> PACKAGE ID SEMICOLON VAR LPAR RPAR INT FLOAT32 BOOL STRING FUNC COMMA LBRACE RBRACE ASSIGN IF ELSE FOR RETURN PRINT STRLIT BLANKID PARSEINT CMDARGS LSQ RSQ OR AND LT GT EQ NE LE GE PLUS MINUS STAR DIV MOD NOT INTLIT REALLIT
%type <node> Program Declarations VarDeclaration VarSpec VarSpecHelper Type FuncDeclaration Parameters ParametersHelper FuncBody VarsAndStatements Statement StatementHelper ParseArgs FuncInvocation FuncInvocationHelper Expr ExprHelper PrintHelper
%token <tkn> RESERVED

%left COMMA
%right ASSIGN
%left OR
%left AND
%left EQ NE GE GT LE LT
%left PLUS MINUS
%left STAR DIV MOD
%nonassoc NOT
%nonassoc LPAR
%nonassoc RPAR

%%

Program: 
        PACKAGE ID SEMICOLON Declarations               {$$ = root = create_node("Program", NULL); if($4!=NULL) add_son(root, $4);                           //done
                                                        //printf("root was created\n");
                                                        }
;

Declarations:
        Declarations VarDeclaration SEMICOLON           {if($1 == NULL){$$ = $2;} else {add_sibling($1,$2); $$ = $1;}}                            //done
        | Declarations FuncDeclaration SEMICOLON        {if($1 == NULL){$$ = $2;} else {add_sibling($1,$2); $$ = $1;}}
        |                                               {$$ = NULL;}
;
Type:
        INT                                             {$$ = create_node("Int", NULL);}                                                        //done 
        | FLOAT32                                       {$$ = create_node("Float32", NULL);}
        | BOOL                                          {$$ = create_node("Bool", NULL);}
        | STRING                                        {$$ = create_node("String", NULL);}

;

VarDeclaration:
        VAR VarSpec                                     {$$ = $2;}
        | VAR LPAR VarSpec SEMICOLON RPAR               {$$ = $3;}
;

VarSpec:
        ID VarSpecHelper Type                           {$$ = create_node("VarDecl", NULL);
                                                        add_son($$, $3);
                                                        add_sibling($3, create_node("Id", $1));
                                                        add_sibling($$, $2);
                                                        save_type($$, $3);
                                                        } 
;
VarSpecHelper:
        VarSpecHelper COMMA ID                          {Node* var = create_node("VarDecl", NULL);
                                                        add_son(var,create_node("Id", $3));
                                                        if ($1 != NULL) {
                                                                $$ = $1;
                                                                add_sibling($$,var);
                                                        } else $$ = var;
                                                        }
                                                         

        |                                               {$$ = NULL;}       
;

FuncDeclaration:
        FUNC ID LPAR Parameters RPAR Type FuncBody      {
                                                        $$ = create_node("FuncDecl", NULL);                                                 //done
                                                        Node * header = create_node("FuncHeader", NULL);
                                                        add_son($$, header);
                                                        Node * id =  create_node("Id", $2);
                                                        add_son(header, id);
                                                        add_son(header, $6);
                                                        Node * parametros = create_node("FuncParams", NULL);
                                                        add_son(header,parametros);
                                                        add_son(parametros, $4);
                                                        Node * funcbody = create_node("FuncBody", NULL);
                                                        add_son(funcbody, $7);
                                                        add_son($$, funcbody);
                                                        }

        | FUNC ID LPAR RPAR Type FuncBody               {
                                                        $$ = create_node("FuncDecl", NULL);
                                                        Node * header = create_node("FuncHeader", NULL);
                                                        add_son($$, header);
                                                        Node * id =  create_node("Id", $2);
                                                        add_son(header, id);
                                                        add_son(header, $5);
                                                        Node * parametros = create_node("FuncParams", NULL);
                                                        add_son(header,parametros);
                                                        Node * funcbody = create_node("FuncBody", NULL);
                                                        add_son(funcbody, $6);
                                                        add_son($$, funcbody);
                                                        }

        | FUNC ID LPAR Parameters RPAR FuncBody         {
                                                        $$ = create_node("FuncDecl", NULL);
                                                        Node * header= create_node("FuncHeader", NULL);
                                                        add_son($$, header);
                                                        Node * id =  create_node("Id", $2);
                                                        add_son(header, id);
                                                        Node * parametros = create_node("FuncParams", NULL);
                                                        add_son(header,parametros);
                                                        add_son(parametros, $4);
                                                        Node * funcbody = create_node("FuncBody", NULL);
                                                        add_son(funcbody, $6);
                                                        add_son($$, funcbody);
                                                        }
                                                       

        | FUNC ID LPAR RPAR FuncBody                    {
                                                        $$ = create_node("FuncDecl", NULL);
                                                        Node * header= create_node("FuncHeader", NULL);
                                                        add_son($$, header);
                                                        Node * id =  create_node("Id", $2);
                                                        add_son(header, id);
                                                        Node * parametros = create_node("FuncParams", NULL);
                                                        add_son(header,parametros);
                                                        Node * funcbody = create_node("FuncBody", NULL);
                                                        add_son(funcbody, $5);
                                                        add_son($$, funcbody);
                                                        }
;
Parameters:
        ID Type ParametersHelper                        {
                                                        $$ = create_node("ParamDecl", NULL);
                                                        add_sibling($$, $3);
                                                        add_son($$, $2);
                                                        add_son($$, create_node("Id", $1));
                                                        }
;       
ParametersHelper:
        ParametersHelper COMMA ID Type                  {
                                                        Node* param = create_node("ParamDecl", NULL);
                                                        add_son(param, $4);
                                                        add_son(param, create_node("Id", $3));                                          
                                                        if ($1 == NULL) $$ = param;
                                                        else {
                                                                $$ = $1;
                                                                add_sibling($1, param);
                                                        }
                                                        }
        |                                               {$$ = NULL;} 
;
FuncBody:
        LBRACE VarsAndStatements RBRACE                 {$$ = $2;}
;
VarsAndStatements:
        VarsAndStatements VarDeclaration SEMICOLON      {if($1 != NULL){$$ = $1; add_sibling($$, $2);} else ($$ = $2);}
        | VarsAndStatements Statement SEMICOLON         {if($1 != NULL){$$ = $1; add_sibling($$, $2);} else ($$ = $2);}
        | VarsAndStatements SEMICOLON                   {$$ = $1;}
        |                                               {$$ = NULL;}
;

Statement:
         error                                          {$$=NULL;}
        | ID ASSIGN Expr                                 {
                                                        $$ = create_node("Assign", NULL);
                                                        add_son($$, create_node("Id", $1));
                                                        add_son($$, $3);
                                                        }
        | LBRACE StatementHelper RBRACE                 {
                                                        $$ = create_node("Block", NULL);
                                                        add_son($$, $2);
                                                        }

        | IF Expr LBRACE  StatementHelper RBRACE        {
                                                        $$ = create_node("If", NULL);
                                                        add_son($$, $2);
                                                        Node* ifblock = create_node("Block", NULL);
                                                        add_son($$, ifblock);
                                                        add_son(ifblock, $4);
                                                        Node* elseblock = create_node("Block", NULL);
                                                        add_son($$, elseblock);
                                                        }
        | IF Expr LBRACE StatementHelper RBRACE ELSE LBRACE StatementHelper RBRACE      {
                                                                                        $$ = create_node("If", NULL);
                                                                                        add_son($$, $2);
                                                                                        Node* ifblock = create_node("Block", NULL);
                                                                                        add_son($$, ifblock);
                                                                                        add_son(ifblock, $4);
                                                                                        Node* elseblock = create_node("Block", NULL);
                                                                                        add_son($$, elseblock);
                                                                                        add_son(elseblock, $8);
                                                                                        }
        | FOR Expr LBRACE StatementHelper RBRACE        {
                                                        $$ = create_node("For", NULL);
                                                        add_son($$, $2);
                                                        Node *block = create_node("Block", NULL);
                                                        add_son($$, block);
                                                        add_son(block, $4);
                                                        }
        | FOR LBRACE StatementHelper RBRACE             {
                                                        $$= create_node("For", NULL);
                                                        Node * block = create_node("Block", NULL);
                                                        add_son($$, block);
                                                        add_son(block, $3);
                                                        }
        | RETURN ExprHelper                             {
                                                        $$ = create_node("Return", NULL);
                                                        if($2 != NULL){add_son($$, $2);}
                                                        }
        
        | FuncInvocation                                {$$ = $1;}

        | ParseArgs                                     {$$ = $1;}
                                                        
        | PRINT LPAR PrintHelper RPAR                   {
                                                        $$ =  create_node("Print", NULL);
                                                        add_son($$,$3);
                                                        }
        
;
ExprHelper:
        Expr                                            {$$ = $1;}
        |                                               {$$ = NULL;}
;
PrintHelper:
        Expr                                            {$$ = $1;}
        |STRLIT                                         {$$ = create_node("StrLit", $1);}
;
StatementHelper:
        StatementHelper Statement SEMICOLON             {
                                                        if($1 == NULL) $$ = $2;
                                                        else if($2 == NULL) $$ = $1;
                                                        else {$$ = $2; 
                                                        add_sibling($$, $1);}
                                                        }
        |                                               {$$ = NULL;}
;
ParseArgs:
        ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ Expr RSQ RPAR         {$$ = create_node("ParseArgs", NULL);
                                                                                add_son($$, create_node("Id", $1));
                                                                                add_son($$, $9); 
                                                                                }
        |ID COMMA BLANKID ASSIGN PARSEINT LPAR CMDARGS LSQ error RSQ RPAR        {$$= NULL;} 
;
FuncInvocation:
        ID LPAR Expr FuncInvocationHelper RPAR          {$$ = create_node("Call", NULL);
                                                        add_son($$, create_node("Id", $1));
                                                        add_son($$, $3);
                                                        add_son($$, $4);
                                                        }
        | ID LPAR RPAR                                  {$$ = create_node("Call", NULL);
                                                        add_son($$, create_node("Id", $1));}
        | ID LPAR error RPAR                            {$$= NULL;}
;
FuncInvocationHelper:
        FuncInvocationHelper COMMA Expr                 {                                                                                            //todd
                                                        if($1 == NULL) $$ = $3;
                                                        else if($3 == NULL) $$ = $1;
                                                        else $$ = add_sibling($1, $3);
                                                        }
        |                                               {$$ = NULL;}
;
Expr:
        Expr OR Expr                                    {$$ = create_node("Or", NULL);  add_son($$, $1); add_son($$, $3);}                               //done
        | Expr AND Expr                                 {$$ = create_node("And", NULL); add_son($$, $1); add_son($$, $3);}
        | Expr LT Expr                                  {$$ = create_node("Lt", NULL);  add_son($$, $1); add_son($$, $3);}
        | Expr GT Expr                                  {$$ = create_node("Gt", NULL);  add_son($$, $1); add_son($$, $3);}
        | Expr EQ Expr                                  {$$ = create_node("Eq", NULL);  add_son($$, $1); add_son($$, $3);}
        | Expr NE Expr                                  {$$ = create_node("Ne", NULL);  add_son($$, $1); add_son($$, $3);}
        | Expr LE Expr                                  {$$ = create_node("Le", NULL);  add_son($$, $1); add_son($$, $3);}
        | Expr GE Expr                                  {$$ = create_node("Ge", NULL);  add_son($$, $1); add_son($$, $3);}
        | Expr PLUS Expr                                {$$ = create_node("Add", NULL); add_son($$, $1); add_son($$, $3);}
        | Expr MINUS Expr                               {$$ = create_node("Sub", NULL); add_son($$, $1); add_son($$, $3);}
        | Expr STAR Expr                                {$$ = create_node("Mul", NULL); add_son($$, $1); add_son($$, $3);}
        | Expr DIV Expr                                 {$$ = create_node("Div", NULL); add_son($$, $1); add_son($$, $3);}
        | Expr MOD Expr                                 {$$ = create_node("Mod", NULL); add_son($$, $1); add_son($$, $3);}
        | NOT Expr                                      {$$ = create_node("Not", NULL); add_son($$, $2);}
        | MINUS Expr                                    {$$ = create_node("Minus", NULL); add_son($$, $2);}
        | PLUS Expr                                     {$$ = create_node("Plus", NULL);  add_son($$, $2);}
        | INTLIT                                        {$$ = create_node("IntLit", $1);}
        | REALLIT                                       {$$ = create_node("RealLit", $1);}
        | ID                                            {$$ = create_node("Id", $1);}
        | FuncInvocation                                {$$ = $1;}
        | LPAR Expr RPAR                                {$$ = $2;}
        | LPAR error RPAR                               {$$ = NULL;}
;

%%