
COMMENT             "//".*

LIDENTIFIER         [a-zA-Z][a-zA-Z0-9_]*
LINTEGER            [1-9][0-9]*|"0"

%%

{COMMENT}

"class"             { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return KW_CLASS; }
"public"            { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return KW_PUBLIC; }
"static"            { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return KW_STATIC; }
"void"              { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return KW_VOID; }
"main"              { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return KW_MAIN; }
"System.out.println"    { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return PRINTSTM; }
"String"            { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return KW_STRING; }
"int"               { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return KW_INT; }
"boolean"           { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return KW_BOOLEAN; }
"true"              { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return TRUE; }
"false"             { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return FALSE; }
"return"            { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return KW_RETURN; }
"extends"           { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return KW_EXTENDS; }
"if"                { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return KW_IF; }
"else"              { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return KW_ELSE; }
"while"             { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return KW_WHILE; }
"length"            { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return KW_LENGTH; }
"this"              { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return KW_THIS; }
"new"               { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return KW_NEW; }

"#defineStmt"       { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return DEFS; }
"#defineStmt0"      { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return DEFS0; }
"#defineStmt1"      { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return DEFS1; }
"#defineStmt2"      { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return DEFS; }
"#defineExpr"       { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return DEFE; }
"#defineExpr0"      { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return DEFE0; }
"#defineExpr1"      { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return DEFE1; }
"#defineExpr2"      { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return DEFE; }

";"                 { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return SEMCL; }
","                 { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return COMMA; }
"."                 { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return DOT; }
"="                 { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return KW_EQ; }
"("                 { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return OPPAR; }
")"                 { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return CLPAR; }
"["                 { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return OPBRK; }
"]"                 { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return CLBRK; }
"{"                 { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return OPBRC; }
"}"                 { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return CLBRC; }
"&&"                { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return AND; }
"||"                { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return OR; }
"!="                { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return NEQ; }
"<="                { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return LEQ; }
"!"                 { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return NEG;}
"+"                 { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return PLUS; }
"-"                 { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return MINUS; }
"\*"                { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return ASTERISK; }
"/"                 { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return DIV; }

{LIDENTIFIER}       { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return IDENTIFIER; }
{LINTEGER}          { yylval.str = (char*)malloc(strlen(yytext)+1); strcpy(yylval.str,yytext); return INTEGER; }
[ \t\r\f\n]

<<eof>>             { return 0; }

%%
