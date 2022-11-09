%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex();
void yyerror(char *);
char* yytext;

char* concat(char* a, char* b)
{
    char* temp = (char*)malloc(strlen(a) + strlen(b) + 1);
    strcpy(temp,a);
    strcat(temp,b);
    return temp;
}

char* findAndReplace(char *str, char *pattern, char *replacement) {
    if (!str)
        return NULL;
    if (!pattern)
        pattern = "";
    int r = strlen(pattern);
    if (!replacement)
        replacement = "";
    int w = strlen(replacement);

    char *result;
    char *tmp;

    int count;
    char *ins = str;    

    for (count = 0; tmp = strstr(ins, pattern); ++count)
        ins = tmp + r;

    tmp = result = malloc(strlen(str) + (w - r) * count + 1);

    if (!result)
        return NULL;

    for(int i=0; i<count; i++) {
        ins = strstr(str, pattern);
        int f = ins - str;
        tmp = strncpy(tmp, str, f) + f;
        tmp = strcpy(tmp, replacement) + w;
        str += f + r;
    }
    strcpy(tmp, str);
    return result;
}

char** strSplit(char* str, const char d)
{
    int count = 0;
    char* tmp = str;
    char* last = 0;
    
    while (*tmp)
    {
        if (d == *tmp)
        {
            count++;
            last = tmp;
        }
        tmp++;
    }

    if(last < (str + strlen(str) - 1))
        count++;

    char** res = malloc(sizeof(char*) * (count + 1));

    char dstr[2];
    dstr[0] = d;
    dstr[1] = 0;

    if (res)
    {
        int i  = 0;
        char* token = strtok(str, dstr);

        while (token)
        {
            *(res + i) = strdup(token);
            token = strtok(0, dstr);
            i++;
        }
        *(res + i) = 0;
    }

    return res;
}

int noOfmacros = 0;
char* macrosArr[256];
char* macroPars[256];
char* macroBody[256];

void addMacro(char* name,char* body,char* params){
	macrosArr[noOfmacros] = (char*)malloc(strlen(name)+1);
	strcpy(macrosArr[noOfmacros],name);
    macroPars[noOfmacros] = (char*)malloc(strlen(params)+1);
	strcpy(macroPars[noOfmacros],params);
	macroBody[noOfmacros] = (char*)malloc(strlen(body)+1);
	strcpy(macroBody[noOfmacros],body);	
    noOfmacros++;
	return;
}

char* findMacroBody(char* m){
	for(int i=0;i<noOfmacros;i++)
    {
        if(strcmp(macrosArr[i],m))
            continue;
        else
            return macroBody[i];
    }
	char* e = (char*)malloc(2);
	strcpy(e,"");
	return e;
}

char* findMacroPars(char* m){
	for(int i=0;i<noOfmacros;i++)
    {
        if(strcmp(macrosArr[i],m))
            continue;
        else
            return macroPars[i];
    }
	char* e = (char*)malloc(2);
	strcpy(e,"");
	return e;
}

%}

%union {
	char* str;
}

%token <str>  IDENTIFIER INTEGER DIV ASTERISK PLUS MINUS SEMCL COMMA NEG AND OR NEQ LEQ DOT
%token <str>  OPBRC CLBRC OPPAR CLPAR OPBRK CLBRK
%token <str>  KW_EQ KW_CLASS KW_PUBLIC KW_STATIC KW_VOID KW_MAIN KW_STRING PRINTSTM KW_EXTENDS
%token <str>  KW_RETURN KW_INT KW_BOOLEAN KW_IF KW_ELSE KW_WHILE KW_THIS KW_NEW KW_LENGTH HDEF
%token <str>  DEFS DEFS0 DEFS1 DEFS2 DEFE DEFE0 DEFE1 DEFE2
%token <str>  TRUE FALSE


%type <str> goal mainClass typeDeclaration methodDeclaration type statement expression primaryExpression
%type <str> macroDef macroDefStmt macroDefExpr identifier integer typeDecList methodDecList statementList
%type <str> methodArgList macroExprList macroArgList macroDefList typeDefList

%start goal

%%

goal: mainClass	{sprintf($$,"%s\n",$1); printf("%s\n",$$);}	
	|	macroDefList mainClass {sprintf($$,"%s\n",$2); printf("%s\n",$$);}	
	|	mainClass typeDefList {sprintf($$,"%s %s\n",$1,$2); printf("%s\n",$$);}
	|	macroDefList mainClass typeDefList 	{sprintf($$,"%s %s\n",$2,$3); printf("%s\n",$$);}


mainClass: KW_CLASS identifier OPBRC KW_PUBLIC KW_STATIC KW_VOID KW_MAIN OPPAR KW_STRING OPBRK CLBRK identifier CLPAR OPBRC PRINTSTM OPPAR expression CLPAR SEMCL CLBRC CLBRC
            {sprintf($$,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",$1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13,$14,$15,$16,$17,$18,$19,$20,$21);}
;

typeDeclaration: KW_CLASS identifier OPBRC CLBRC {sprintf($$,"%s %s %s %s",$1,$2,$3,$4);}
		|	KW_CLASS identifier OPBRC methodDecList CLBRC  {sprintf($$,"%s %s %s %s %s",$1,$2,$3,$4,$5);}
		| 	KW_CLASS identifier OPBRC typeDecList CLBRC   {sprintf($$,"%s %s %s %s %s",$1,$2,$3,$4,$5);}
		|	KW_CLASS identifier OPBRC typeDecList methodDecList CLBRC	{sprintf($$,"%s %s %s %s %s %s",$1,$2,$3,$4,$5,$6);}
		|	KW_CLASS identifier KW_EXTENDS identifier OPBRC CLBRC	{sprintf($$,"%s %s %s %s %s %s",$1,$2,$3,$4,$5,$6);}
		|	KW_CLASS identifier KW_EXTENDS identifier OPBRC methodDecList CLBRC	{sprintf($$,"%s %s %s %s %s %s %s",$1,$2,$3,$4,$5,$6,$7);}
		|	KW_CLASS identifier KW_EXTENDS identifier OPBRC typeDecList CLBRC	{sprintf($$,"%s %s %s %s %s %s %s",$1,$2,$3,$4,$5,$6,$7);}
		|	KW_CLASS identifier KW_EXTENDS identifier OPBRC typeDecList methodDecList CLBRC	{sprintf($$,"%s %s %s %s %s %s %s %s",$1,$2,$3,$4,$5,$6,$7,$8);}
;

typeDecList: type identifier SEMCL 	{sprintf($$,"%s %s %s",$1,$2,$3);}
	|	type identifier SEMCL typeDecList	{sprintf($$,"%s %s %s %s",$1,$2,$3,$4);}
;

methodDecList: methodDeclaration 	{sprintf($$,"%s",$1);}
	|	methodDeclaration methodDecList	{sprintf($$,"%s %s",$1,$2);}
;

methodDeclaration: KW_PUBLIC type identifier OPPAR CLPAR OPBRC KW_RETURN expression SEMCL CLBRC
                    {sprintf($$,"%s %s %s %s %s %s %s %s %s %s",$1,$2,$3,$4,$5,$6,$7,$8,$9,$10);}
		|	KW_PUBLIC type identifier OPPAR CLPAR OPBRC statementList KW_RETURN expression SEMCL CLBRC
        {sprintf($$,"%s %s %s %s %s %s %s %s %s %s %s",$1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11);}
		|	KW_PUBLIC type identifier OPPAR type identifier CLPAR OPBRC KW_RETURN expression SEMCL CLBRC
        {sprintf($$,"%s %s %s %s %s %s %s %s %s %s %s %s",$1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12);}	
		|	KW_PUBLIC type identifier OPPAR type identifier CLPAR OPBRC statementList KW_RETURN expression SEMCL CLBRC
        {sprintf($$,"%s %s %s %s %s %s %s %s %s %s %s %s %s",$1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13);}		
		|	KW_PUBLIC type identifier OPPAR type identifier methodArgList CLPAR OPBRC KW_RETURN expression SEMCL CLBRC
        {sprintf($$,"%s %s %s %s %s %s %s %s %s %s %s %s %s",$1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13);}
		|	KW_PUBLIC type identifier OPPAR type identifier methodArgList CLPAR OPBRC statementList KW_RETURN expression SEMCL CLBRC
        {sprintf($$,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s",$1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12,$13,$14);}
;

statementList: statement	{sprintf($$,"%s",$1);}
	|	statement statementList	{sprintf($$,"%s %s",$1,$2);}
;

methodArgList: COMMA type identifier		{sprintf($$,"%s %s %s",$1,$2,$3);}
	|	COMMA type identifier methodArgList	{sprintf($$,"%s %s %s %s",$1,$2,$3,$4);}
;

type: KW_INT   {sprintf($$,"%s",$1);}
	|	KW_BOOLEAN	{sprintf($$,"%s",$1);}
	|	KW_INT OPBRK CLBRK	{sprintf($$,"%s %s %s",$1,$2,$3);}
	|	identifier	{sprintf($$,"%s",$1);}
;

statement: OPBRC CLBRC	{sprintf($$,"%s %s",$1,$2);}
	|	OPBRC statementList CLBRC	{sprintf($$,"%s %s %s",$1,$2,$3);}
	|	PRINTSTM OPPAR expression CLPAR SEMCL	{sprintf($$,"%s %s %s %s %s",$1,$2,$3,$4,$5);}
	|	identifier KW_EQ expression SEMCL	{sprintf($$,"%s %s %s %s",$1,$2,$3,$4);}
	|	identifier OPBRK expression CLBRK KW_EQ expression SEMCL	{sprintf($$,"%s %s %s %s %s %s %s",$1,$2,$3,$4,$5,$6,$7);}
	|	KW_IF OPPAR expression CLPAR statement	{sprintf($$,"%s %s %s %s %s",$1,$2,$3,$4,$5);}
	|	KW_IF OPPAR expression CLPAR statement KW_ELSE statement	{sprintf($$,"%s %s %s %s %s %s %s",$1,$2,$3,$4,$5,$6,$7);}
	|	KW_WHILE OPPAR expression CLPAR statement	{sprintf($$,"%s %s %s %s %s",$1,$2,$3,$4,$5);}
	|	identifier OPPAR CLPAR SEMCL
    {if(strcmp(findMacroBody($1),"")!=0){sprintf($$,"%s",findMacroBody($1));} else{sprintf($$,"%s %s %s %s",$1,$2,$3,$4);}}
	|	identifier OPPAR expression CLPAR SEMCL
    {if(strcmp(findMacroBody($1),"")!=0){sprintf($$,"%s",findAndReplace(findMacroBody($1),findMacroPars($1),$3));}else{sprintf($$,"%s %s %s %s %s",$1,$2,$3,$4,$5);}}
	|	identifier OPPAR expression macroExprList CLPAR SEMCL	{
		char* stmt = (char*)malloc(1024);
		strcpy(stmt,findMacroBody($1));
        if(strcmp(stmt,"")!=0){
			char** tmptks = strSplit(concat($3, $4),',');
			char** partks = strSplit(findMacroPars($1),',');
			
			if (partks)
			{
				int i;
				for (i = 0; *(partks + i); i++)
				{
				    strcpy(stmt,findAndReplace(stmt,*(partks + i),*(tmptks + i)));
				    free(*(partks + i));
				    free(*(tmptks + i));
				}
			}
            free(partks);
			free(tmptks);
			sprintf($$,"%s",stmt);
            free(stmt);
		}
		else{sprintf($$,"%s %s %s %s %s %s",$1,$2,$3,$4,$5,$6);}}
	| 	type identifier SEMCL	{sprintf($$,"%s %s %s",$1,$2,$3);}
;

expression: primaryExpression PLUS primaryExpression	{sprintf($$,"%s %s %s",$1,$2,$3);}
	|	primaryExpression MINUS primaryExpression	{sprintf($$,"%s %s %s",$1,$2,$3);}
	|	primaryExpression ASTERISK primaryExpression		{sprintf($$,"%s %s %s",$1,$2,$3);}
	|	primaryExpression DIV primaryExpression		{sprintf($$,"%s %s %s",$1,$2,$3);}
	|   primaryExpression AND primaryExpression	{sprintf($$,"%s %s %s",$1,$2,$3);}
	|	primaryExpression OR primaryExpression	{sprintf($$,"%s %s %s",$1,$2,$3);}
	|	primaryExpression NEQ primaryExpression	{sprintf($$,"%s %s %s",$1,$2,$3);}
	|	primaryExpression LEQ primaryExpression	{sprintf($$,"%s %s %s",$1,$2,$3);}
	|	primaryExpression OPBRK primaryExpression CLBRK	{sprintf($$,"%s %s %s %s",$1,$2,$3,$4);}
	|	primaryExpression DOT KW_LENGTH		{sprintf($$,"%s %s %s",$1,$2, $3);}
	|	primaryExpression		{sprintf($$,"%s",$1);}
	|	primaryExpression DOT identifier OPPAR CLPAR
    {if(strcmp(findMacroBody($3),"")!=0){sprintf($$,"%s %s %s %s %s",$1,$2,$4,findMacroBody($3),$5);}else{sprintf($$,"%s %s %s %s %s",$1,$2,$3,$4,$5);}}
	|	primaryExpression DOT identifier OPPAR expression CLPAR
    {if(strcmp(findMacroBody($3),"")!=0){sprintf($$,"%s %s %s %s %s",$1,$2,$4,findAndReplace(findMacroBody($3),findMacroPars($3),$5),$6);}else{sprintf($$,"%s %s %s %s %s %s",$1,$2,$3,$4,$5,$6);}}
	|	primaryExpression DOT identifier OPPAR expression macroExprList CLPAR	  {
		char* stmt = (char*)malloc(1024);
		strcpy(stmt,findMacroBody($1));
        if(strcmp(stmt,"")!=0){
			char** tmptks = strSplit(concat($5, $6),',');
			char** partks = strSplit(findMacroPars($1),',');
			
			if (partks)
			{
				int i;
				for (i = 0; *(partks + i); i++)
				{
				    strcpy(stmt,findAndReplace(stmt,*(partks + i),*(tmptks + i)));
				    free(*(partks + i));
				    free(*(tmptks + i));
				}
			}
            free(partks);
			free(tmptks);
			sprintf($$,"%s %s %s %s %s",$1,$2,$4,stmt,$7);
            free(stmt);
		}
		else{sprintf($$,"%s %s %s %s %s %s %s",$1,$2,$3,$4,$5,$6,$7);}}
	|	identifier OPPAR CLPAR	{if(strcmp(findMacroBody($1),"")!=0){sprintf($$,"%s %s %s",$2,findMacroBody($1),$3);}else{sprintf($$,"%s %s %s",$1,$2,$3);}}
	|	identifier OPPAR expression CLPAR
    {if(strcmp(findMacroBody($1),"")!=0){sprintf($$,"%s %s %s",$2,findAndReplace(findMacroBody($1),findMacroPars($1),$3),$4);}else{sprintf($$,"%s %s %s %s",$1,$2,$3,$4);}}
	|	identifier OPPAR expression macroExprList CLPAR  {
		char* stmt = (char*)malloc(1024);
		strcpy(stmt,findMacroBody($1));
        if(strcmp(stmt,"")!=0){
			char** tmptks = strSplit(concat($3, $4),',');
			char** partks = strSplit(findMacroPars($1),',');
			
			if (partks)
			{
				int i;
				for (i = 0; *(partks + i); i++)
				{
				    strcpy(stmt,findAndReplace(stmt,*(partks + i),*(tmptks + i)));
				    free(*(partks + i));
				    free(*(tmptks + i));
				}
			}
            free(partks);
            free(tmptks);
			sprintf($$,"%s %s %s",$2,stmt,$5);
            free(stmt);
		}
		else{sprintf($$,"%s %s %s %s %s",$1,$2,$3,$4,$5);}}
;

primaryExpression: integer	{sprintf($$,"%s",$1);}
		|	TRUE	{sprintf($$,"%s",$1);}
		|	FALSE	{sprintf($$,"%s",$1);}
		|	identifier	{sprintf($$,"%s",$1);}
		|	KW_THIS	{sprintf($$,"%s",$1);}
		|	KW_NEW KW_INT OPBRK expression CLBRK	 {sprintf($$,"%s %s %s %s %s",$1,$2,$3,$4,$5);}
		|	KW_NEW identifier OPPAR CLPAR	 {sprintf($$,"%s %s %s %s",$1,$2,$3,$4);}
		|	NEG expression		 {sprintf($$,"%s %s",$1,$2);}
		|	OPPAR expression CLPAR	 {sprintf($$,"%s %s %s",$1,$2,$3);}
;

macroDef: macroDefExpr	{sprintf($$,"%s",$1);}
		|	macroDefStmt	{sprintf($$,"%s",$1);}
;

macroDefStmt:DEFS identifier OPPAR identifier macroArgList CLPAR OPBRC CLBRC
        {char* temp=concat($4, $5);addMacro($2,"",temp);free(temp);sprintf($$,"%s %s %s %s %s %s %s %s",$1,$2,$3,$4,$5,$6,$7,$8);}
		|   DEFS identifier OPPAR identifier macroArgList CLPAR OPBRC statementList CLBRC
        {char* temp=concat($4, $5);addMacro($2,$8,temp);free(temp);sprintf($$,"%s %s %s %s %s %s %s %s %s",$1,$2,$3,$4,$5,$6,$7,$8,$9);}
        |   DEFS0 identifier OPPAR CLPAR OPBRC CLBRC	{addMacro($2,"",""); sprintf($$,"%s %s %s %s %s %s",$1,$2,$3,$4,$5,$6);}
		|	DEFS0 identifier OPPAR CLPAR OPBRC statementList CLBRC	{addMacro($2,$6,""); sprintf($$,"%s %s %s %s %s %s %s",$1,$2,$3,$4,$5,$6,$7);}
		|	DEFS1 identifier OPPAR identifier CLPAR OPBRC CLBRC	{addMacro($2,"",$4); sprintf($$,"%s %s %s %s %s %s %s",$1,$2,$3,$4,$5,$6,$7);}
		|	DEFS1 identifier OPPAR identifier CLPAR OPBRC statementList CLBRC	{addMacro($2,$7,$4); sprintf($$,"%s %s %s %s %s %s %s %s",$1,$2,$3,$4,$5,$6,$7,$8);}
;


macroDefExpr: DEFE identifier OPPAR identifier macroArgList CLPAR OPPAR expression CLPAR
        {char* temp=concat($4, $5);addMacro($2,$8,temp);free(temp);sprintf($$,"%s %s %s %s %s %s %s %s %s",$1,$2,$3,$4,$5,$6,$7,$8,$9);}
        |   DEFE0 identifier OPPAR CLPAR OPPAR expression CLPAR	{addMacro($2,$6,""); sprintf($$,"%s %s %s %s %s %s %s",$1,$2,$3,$4,$5,$6,$7);}
		|	DEFE1 identifier OPPAR identifier CLPAR OPPAR expression CLPAR	{addMacro($2,$7,$4); sprintf($$,"%s %s %s %s %s %s %s %s",$1,$2,$3,$4,$5,$6,$7,$8);}
;

macroArgList : COMMA identifier	{sprintf($$,"%s %s",$1,$2);}
	|	COMMA identifier macroArgList	{sprintf($$,"%s %s %s",$1,$2,$3);}
;

identifier: IDENTIFIER  {sprintf($$,"%s",$1);}
;

integer: INTEGER    {sprintf($$,"%s",$1);}
;

macroExprList: COMMA expression	{sprintf($$,"%s %s",$1,$2);}
	|	COMMA expression macroExprList	{sprintf($$,"%s %s %s",$1,$2,$3);}
;


macroDefList: macroDef macroDefList	{sprintf($$,"%s %s",$1,$2);}
	|	macroDef    {sprintf($$,"%s",$1);}
;

typeDefList: typeDeclaration typeDefList	{sprintf($$,"%s %s",$1,$2);}
	|	typeDeclaration		{sprintf($$,"%s",$1);}
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
