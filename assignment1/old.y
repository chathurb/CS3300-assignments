%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int yylex();
extern void yyerror(char *);
extern char* yytext;

typedef struct Node{
    char* str;
    struct Node* next;
}node;

typedef struct NodeList{
    node* head;
    node* tail;
}list;

void printList(list *currList)
{
    node* temp = currList->head;
    while(temp)
    {
        printf("%s ", temp->str);
        temp = temp->next;
    }
}

list* create()
{
    list* l = malloc(sizeof(list));
    l->head = NULL;
    l->tail = NULL;
    return l;
}

list* insert(list* l, node* n)
{
    if(l->head == NULL)
    {
        l->head = n;
        l->tail = n;
    }
    else
    {
        l->tail->next = n;
        l->tail = n;
    }

    return l;
}

list* merge(list* f, list* s)
{
    list* n = create();
    if(f->head == NULL)
        return s;
    
    if(s->head == NULL)
        return s;

    n->head = f->head;
    f->tail->next = s->head;
    n->tail = s->tail;

    return n;
}


%}

%union{
    char* str;
    node* n;
    list* l;
}

%token <n> IDENTIFIER
%token <n> INTEGER

%token <n> DEFE
%token <n> DEFE0
%token <n> DEFE1
%token <n> DEFE2
%token <n> DEFS
%token <n> DEFS0
%token <n> DEFS1
%token <n> DEFS2

%token <n> OPBRC
%token <n> CLBRC
%token <n> OPBRK
%token <n> CLBRK
%token <n> OPPAR
%token <n> CLPAR

%token <n> COMMA
%token <n> SEMCL
%token <n> DOT
%token <n> AND
%token <n> OR
%token <n> NEQ
%token <n> LEQ
%token <n> PLUS
%token <n> MINUS
%token <n> ASTERISK
%token <n> DIV
%token <n> NEG
%token <n> TRUE
%token <n> FALSE
%token <n> PRINTSTM

%token <n> KW_CLASS
%token <n> KW_PUBLIC
%token <n> KW_STATIC
%token <n> KW_VOID
%token <n> KW_MAIN
%token <n> KW_STRING
%token <n> KW_INT
%token <n> KW_BOOLEAN
%token <n> KW_EXTENDS
%token <n> KW_RETURN
%token <n> KW_EQ
%token <n> KW_IF
%token <n> KW_ELSE
%token <n> KW_WHILE
%token <n> KW_LENGTH
%token <n> KW_THIS
%token <n> KW_NEW

%type <l> goal macros mainClass typeDeclarations macroDef identifier expression typeDeclaration typeDecStmts methodDecStmts
%type <l> type methodArgs statements extraArgs statement expressionList extraExprs primaryExpression macroDefExpr macroDefStmt identifierList integer

%%

goal: macros mainClass typeDeclarations { $$ = merge($1, $2); $$ = merge($$, $3); printList($$); }
;

macros: { $$ = create(); }
		| macroDef macros { $$ = $1; $$ = merge($$, $2); }
;

mainClass: KW_CLASS identifier OPBRC KW_PUBLIC KW_STATIC KW_VOID KW_MAIN OPPAR KW_STRING OPBRK CLBRK identifier CLPAR OPBRC PRINTSTM OPPAR expression CLPAR SEMCL CLBRC CLBRC
            { $$ = create(); $$ = insert($$, $1); $$ = merge($$, $2); $$ = insert($$, $3); $$ = insert($$, $4); $$ = insert($$, $5); $$ = insert($$, $6); $$ = insert($$, $7); $$ = insert($$, $8); $$ = insert($$, $9); $$ = insert($$, $10); $$ = insert($$, $11);
            $$ = merge($$, $12); $$ = insert($$, $13);$$ = insert($$, $14);$$ = insert($$, $15);$$ = insert($$, $16); $$ = merge($$, $17); $$ = insert($$, $18);$$ = insert($$, $19);$$ = insert($$, $20);$$ = insert($$, $21);}
;

typeDeclarations: { $$ = create(); }
				| typeDeclarations typeDeclaration { $$ = $1; $$ = merge($$, $2); printList($$);}
;

typeDeclaration: KW_CLASS identifier OPBRC typeDecStmts methodDecStmts CLBRC
                { $$ = create(); $$ = insert($$, $1); $$ = merge($$, $2); $$ = insert($$, $3); $$ = merge($$, $4); $$ = merge($$, $5); $$ = insert($$, $6); printList($$);}
				| KW_CLASS identifier KW_EXTENDS identifier OPBRC typeDecStmts methodDecStmts CLBRC
                { $$ = create(); $$ = insert($$, $1); $$ = merge($$, $2); $$ = insert($$, $3); $$ = merge($$, $4); $$ = insert($$, $5); $$ = merge($$, $6); $$ = merge($$, $7); $$ = insert($$, $8);}
;

typeDecStmts: { $$ = create(); }
			| typeDecStmts type identifier SEMCL { $$ = $1; $$ = merge($$, $2); $$ = merge($$, $3); $$ = insert($$, $4); }
;

methodDecStmts: { $$ = create(); }
				| KW_PUBLIC type identifier OPPAR methodArgs CLPAR OPBRC typeDecStmts statements KW_RETURN expression SEMCL CLBRC methodDecStmts
                { $$ = create(); $$ = insert($$, $1); $$ = merge($$, $2); $$ = merge($$, $3); $$ = insert($$, $4); $$ = merge($$, $5); $$ = insert($$, $6); $$ = insert($$, $7); $$ = merge($$, $8);
                 $$ = merge($$, $9); $$ = insert($$, $10); $$ = merge($$, $11); $$ = insert($$, $12); $$ = insert($$, $13); $$ = merge($$, $14); printList($$);}
;

methodArgs: { $$ = create(); }
			| type identifier extraArgs { $$ = $1; $$ = merge($$, $2); $$ = merge($$, $3); printList($$);}
;

extraArgs: { $$ = create(); }
			| extraArgs COMMA type identifier { $$ = $1; $$ = insert($$, $2); $$ = merge($$, $3); $$ = merge($$, $4); }
;

type: KW_INT OPBRK CLBRK { $$ = create(); $$ = insert($$, $1); $$ = insert($$, $2); $$ = insert($$, $3); }
	| KW_BOOLEAN { $$ = create(); $$ = insert($$, $1); }
	| KW_INT { $$ = create(); $$ = insert($$, $1); }
	| identifier { $$ = $1; }
;

statements: { $$ = create(); }
			| statement statements { $$ = $1; $$ = merge($$, $2); printList($1);}
;

statement: OPBRC statements CLBRC { $$ = create(); $$ = insert($$, $1); $$ = merge($$, $2); $$ = insert($$, $3); }
			| PRINTSTM OPPAR expression CLPAR SEMCL { $$ = create(); $$ = insert($$, $1); $$ = insert($$, $2); $$ = merge($$, $3); $$ = insert($$, $4); $$ = insert($$, $5); }
			| identifier KW_EQ expression SEMCL { $$ = $1; $$ = insert($$, $2); $$ = merge($$, $3); $$ = insert($$, $4); }
			| identifier OPBRK expression CLBRK KW_EQ expression SEMCL 
            { $$ = $1; $$ = insert($$, $2); $$ = merge($$, $3); $$ = insert($$, $4); $$ = insert($$, $5); $$ = merge($$, $6); $$ = insert($$, $7); }
			| KW_IF OPPAR expression CLPAR statement { $$ = create(); $$ = insert($$, $1); $$ = insert($$, $2); $$ = merge($$, $3); $$ = insert($$, $4); $$ = merge($$, $5); }
			| KW_IF OPPAR expression CLPAR statement KW_ELSE statement 
            { $$ = create(); $$ = insert($$, $1); $$ = insert($$, $2); $$ = merge($$, $3); $$ = insert($$, $4); $$ = merge($$, $5); $$ = insert($$, $6); $$ = merge($$, $7); }
			| KW_WHILE OPPAR expression CLPAR statement { $$ = create(); $$ = insert($$, $1); $$ = insert($$, $2); $$ = merge($$, $3); $$ = insert($$, $4); $$ = merge($$, $5); }
			| identifier OPPAR expressionList CLPAR { $$ = $1; $$ = insert($$, $2); $$ = merge($$, $3); $$ = insert($$, $4); }
;

expressionList: { $$ = create(); }
				| expression extraExprs { $$ = $1; $$ = merge($$, $2); }
;

extraExprs: { $$ = create(); }
				| extraExprs COMMA expression { $$ = $1; $$ = insert($$, $2); $$ = merge($$, $3); }
;

expression: primaryExpression AND primaryExpression { $$ = $1; $$ = insert($$, $2); $$ = merge($$, $3); }
			| primaryExpression OR primaryExpression { $$ = $1; $$ = insert($$, $2); $$ = merge($$, $3); }
			| primaryExpression NEQ primaryExpression { $$ = $1; $$ = insert($$, $2); $$ = merge($$, $3); }
			| primaryExpression LEQ primaryExpression { $$ = $1; $$ = insert($$, $2); $$ = merge($$, $3); }
			| primaryExpression PLUS primaryExpression { $$ = $1; $$ = insert($$, $2); $$ = merge($$, $3); }
			| primaryExpression MINUS primaryExpression { $$ = $1; $$ = insert($$, $2); $$ = merge($$, $3); }
			| primaryExpression ASTERISK primaryExpression { $$ = $1; $$ = insert($$, $2); $$ = merge($$, $3); }
			| primaryExpression DIV primaryExpression { $$ = $1; $$ = insert($$, $2); $$ = merge($$, $3); }
			| primaryExpression OPBRK primaryExpression CLBRK { $$ = $1; $$ = insert($$, $2); $$ = merge($$, $3); $$ = insert($$, $4); }
			| primaryExpression DOT KW_LENGTH { $$ = $1; $$ = insert($$, $2); $$ = insert($$, $3);}
			| primaryExpression { $$ = $1; }
			| primaryExpression DOT identifier OPPAR expressionList CLPAR
            { $$ = $1; $$ = insert($$, $2); $$ = merge($$, $3); $$ = insert($$, $4); $$ = merge($$, $5); $$ = insert($$, $6); }
			| identifier OPPAR expressionList CLPAR { $$ = $1; $$ = insert($$, $2); $$ = merge($$, $3); $$ = insert($$, $4); }
;

primaryExpression: integer {$$ = $1;}
					| TRUE {$$ = create(); $$ = insert($$, $1);}
					| FALSE {$$ = create(); $$ = insert($$, $1);}
                    | KW_THIS {$$ = create(); $$ = insert($$, $1);}
					| identifier {$$ = $1;}
					| KW_NEW KW_INT OPBRK expression CLBRK {$$ = create(); $$ = insert($$, $1); $$ = insert($$, $2); $$ = insert($$, $3); $$ = merge($$, $4); $$ = insert($$, $5);}
					| KW_NEW identifier OPPAR CLPAR { $$ = create(); $$ = insert($$, $1); $$ = merge($$, $2); $$ = insert($$, $3); $$ = insert($$, $4); }
					| NEG expression { $$ = create(); $$ = insert($$, $1); $$ = merge($$, $2); }
					| OPPAR expression CLPAR { $$ = create(); $$ = insert($$, $1); $$ = merge($$, $2); $$ = insert($$, $3); }
;

macroDef: macroDefExpr {$$ = $1;}
        | macroDefStmt {$$ = $1;}
;

macroDefExpr: DEFE identifier OPPAR identifier COMMA identifier COMMA identifier identifierList CLPAR OPPAR expression CLPAR { $$ = create(); }
            | DEFE0 identifier OPPAR CLPAR OPPAR expression CLPAR { $$ = create(); }
            | DEFE1 identifier OPPAR identifier CLPAR OPPAR expression CLPAR { $$ = create(); }
            | DEFE2 identifier OPPAR identifier COMMA identifier CLPAR OPPAR expression CLPAR { $$ = create(); }
;

macroDefStmt: DEFS identifier OPPAR identifier COMMA identifier COMMA identifier identifierList CLPAR OPBRC statements CLBRC { $$ = create(); }
            | DEFS0 identifier OPPAR CLPAR OPBRC statements CLBRC { $$ = create(); }
            | DEFS1 identifier OPPAR identifier CLPAR OPBRC statements CLBRC { $$ = create(); }
            | DEFS2 identifier OPPAR identifier COMMA identifier CLPAR OPBRC statements CLBRC { $$ = create(); }
;

identifierList: { $$ = create(); }
                | identifierList COMMA identifier { $$ = $1; $$ = insert($$, $2); $$ = merge($$, $3); }
;

identifier: IDENTIFIER {$$ = create(); $$ = insert($$, $1);}
;

integer: INTEGER {$$ = create(); $$ = insert($$, $1);}
;


%%

void yyerror(char *str){
    printf("parse failed: %s\n", yytext);
}

int main() {
    yyparse();
    return 0;
}

#include "lex.yy.c"