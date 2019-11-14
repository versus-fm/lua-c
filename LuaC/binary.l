%top{
    #include "binary.tab.hh"
    #include <string>
    #define YY_DECL yy::parser::symbol_type yylex()

}
%option noyywrap nounput batch noinput
%x STRING
%x STRINGSINGLE
%%
 
<INITIAL>' { BEGIN(STRING); }
<INITIAL>\" { BEGIN(STRINGSINGLE); }
<STRING>' { BEGIN(INITIAL); }
<STRINGSINGLE>\" { BEGIN(INITIAL); }
<STRING>[^']* { return yy::parser::make_STRING(yytext); }
<STRINGSINGLE>[^"]* { return yy::parser::make_STRING(yytext); }
"and" { return yy::parser::make_AND(yytext); }
"break" { return yy::parser::make_BREAK(yytext); }
"do" { return yy::parser::make_DO(yytext); }
"else" { return yy::parser::make_ELSE(yytext); }
"elseif" { return yy::parser::make_ELSEIF(yytext); }
"end" { return yy::parser::make_END(yytext); }
"false" { return yy::parser::make_FALSE(yytext); }
"for" { return yy::parser::make_FOR(yytext); }
"function" { return yy::parser::make_FUNCTION(yytext); }
"if" { return yy::parser::make_IF(yytext); }
"in" { return yy::parser::make_IN(yytext); }
"local" { return yy::parser::make_LOCAL(yytext); }
"nil" { return yy::parser::make_NIL(yytext); }
"not" { return yy::parser::make_NOT(yytext); }
"or" { return yy::parser::make_OR(yytext); }
"repeat" { return yy::parser::make_REPEAT(yytext); }
"return" { return yy::parser::make_RETURN(yytext); }
"then" { return yy::parser::make_THEN(yytext); }
"true" { return yy::parser::make_TRUE(yytext); }
"until" { return yy::parser::make_UNTIL(yytext); }
"while" { return yy::parser::make_WHILE(yytext); }


"(" { return yy::parser::make_PARANTHESIS_L(yytext); }
")" { return yy::parser::make_PARANTHESIS_R(yytext); }
"]" { return yy::parser::make_SQUARE_R(yytext); }
"[" { return yy::parser::make_SQUARE_L(yytext); }
"}" { return yy::parser::make_BRACES_R(yytext); }
"{" { return yy::parser::make_BRACES_L(yytext); }
"+" { return yy::parser::make_PLUS(yytext); }
"-" { return yy::parser::make_MINUS(yytext); }
"*" { return yy::parser::make_MULTI(yytext); }
"/" { return yy::parser::make_DIVISION(yytext); }
"%" { return yy::parser::make_MODULUS(yytext); }
"^" { return yy::parser::make_POWER(yytext); }
"#" { return yy::parser::make_HASH(yytext); }
"<" { return yy::parser::make_LESSER(yytext); }
">" { return yy::parser::make_GREATER(yytext); }
":" { return yy::parser::make_COLON(yytext); }
"." { return yy::parser::make_DOT(yytext); }
"," { return yy::parser::make_COMMA(yytext); }
"=" { return yy::parser::make_ASSIGN(yytext); }
";" { return yy::parser::make_SEMICOLON(yytext); }

"==" { return yy::parser::make_EQUALS(yytext); }
"~=" { return yy::parser::make_NOTEQUALS(yytext); }
">=" { return yy::parser::make_GREATERTHANEQUAL(yytext); }
"<=" { return yy::parser::make_LESSERTHANEQUAL(yytext); }
".." { return yy::parser::make_CONCAT(yytext); }
"..." { return yy::parser::make_VARARGS(yytext); }

[0-9]*(\.[0-9]+)* { return yy::parser::make_NUMBER(yytext); }
[a-zA-Z_][a-zA-Z0-9_]* { return yy::parser::make_NAME(yytext); }


[ \t]									{ }
[\n]									{ }
<<EOF>> { 
    return yy::parser::make_EOFFF();
    }
%%