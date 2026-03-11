%{
#include <stdio.h>

int yywrap(void) { return 1; }
%}

%%

// remove whitespace
[ \t\r\n]+                { }

// remove comments
"//".*                    { }
"/*"([^*]|\*+[^*/])*"*/"  { }

// tokenize preprocessor directives
#"include"[^\n]*          { printf("INCLUDE "); }
#"define"[^\n]*           { printf("DEFINE "); }

// tokenize control keywords
"if"                      { printf("IF "); }
"else"                    { printf("ELSE "); }
"for"                     { printf("FOR "); }
"do"                      { printf("DO "); }
"while"                   { printf("WHILE "); }
"return"                  { printf("RETURN "); }
"break"                   { printf("BREAK "); }
"continue"                { printf("CONTINUE "); }

// tokenize types
"int"                     { printf("INT "); }
"void"                    { printf("VOID "); }
"char"                    { printf("CHAR "); }

// tokenize literals
\"([^\"\\]|\\.)*\"  { printf("STRINGCONST "); }
'([^'\\]|\\.)'          { printf("CHARCONST "); }

// tokenize identifiers (variables and function names)
[a-zA-Z_][a-zA-Z0-9_]*     { printf("VARIABLE "); }

// tokenize numbers
[0-9]+"."[0-9]+           { printf("NUM "); }
[0-9]+                     { printf("NUM "); }

// tokenize operators
"++"|"--"|"+"|"-"|"*"|"/"|"%"|
"=="|"!="|"="|
"<="|">="|"<"|">"|
"&&"|"||"|"!"|"&"
                            { printf("OP "); }

// tokenize delimiters
[(){}\[\];,:]             { printf("%s ", yytext); }

// catch illegal characters
.                          { printf("ILLEGAL(%c) ", *yytext); }

%%