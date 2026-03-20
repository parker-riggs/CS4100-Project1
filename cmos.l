%{
#include <stdio.h>

int yywrap(void) { return 1; }
%}

%%

    /* remove whitespace */
[ \t\r\n]+                { }

    /* remove comments */
"//".*                    { }
"/*"([^*]|\*+[^*/])*"*/"  { }

    /* tokenize preprocessor directives */
#"include"[^\n]*          { printf("001 "); }

    /* tokenize control keywords */
"if"                      { printf("010 "); }
"else"                    { printf("011 "); }
"for"                     { printf("012 "); }
"do"                      { printf("013 "); }
"while"                   { printf("014 "); }
"return"                  { printf("015 "); }
"break"                   { printf("016 "); }
"continue"                { printf("017 "); }

    /* tokenize types */
"int"                     { printf("020 "); }
"void"                    { printf("021 "); }
"char"                    { printf("022 "); }

    /* tokenize literals */
\"([^\"\\]|\\.)*\"  { printf("030 "); }
'([^'\\]|\\.)'          { printf("031 "); }

    /* tokenize identifiers (variables and function names) */
[a-zA-Z_][a-zA-Z0-9_]*     { printf("040 "); }

    /* tokenize numbers */
[0-9]+"."[0-9]+           { printf("050 "); }
[0-9]+                     { printf("050 "); }

    /* tokenize operators */
"++"|"--"|"+"|"-"|"*"|"/"|"%"|"=="|"!="|"="|"<="|">="|"<"|">"|"&&"|"||"|"!"|"&" { printf("060 "); }

    /* tokenize delimiters */
[(){}\[\];,:]             { printf("070 "); }

    /* catch illegal characters */
.                          { printf("999 "); }

%%

/* This main redirects lexer output to scanner_out.txt then calls yylex().
 
    - PlagarismDetector appends scanner_out.txt into tokens.txt.
*/
int main(void)
{
    if (freopen("scanner_out.txt", "w", stdout) == NULL)
    {
        return 1;
    }

    yylex();
    return 0;
}