%skeleton "lalr1.cc"
%defines
%define api.value.type variant
%define api.token.constructor
%error-verbose
%code requires{
    #include "Statement.h"
	#include "Expression.h"
	#include "Sequence.h"
	#include "Call.h"
	#include "Constant.h"
	#include "Variable.h"
	#include "If.h"
	#include "Return.h"
	#include "BinaryOperator.h"
	#include "UnaryOperator.h"
	#include "ForLoop.h"
	#include "CallStatement.h"
	#include "ExpressionList.h"
	#include "Function.h"
	#include "Subaccess.h"
	#include "Repeat.h"
	#include "ArrayAccess.h"
}
%code{
    #include <string>
    #include <iostream>
    #define YY_DECL yy::parser::symbol_type yylex()
    YY_DECL;
    Sequence* root = new Sequence();        
}

%type <Expression*> exp
%type <Sequence*> chunk
%type <Sequence*> chunkrep
%type <Statement*> statement
%type <Statement*> laststatement
%type <Sequence*> block
%type <Statement*> function
%type <Function*> funcbody
%type <Call*> functioncall
%type <Expression*> args
%type <Expression*> prefixexp
%type <Expression*> var
%type <Expression*> field

%type <ExpressionList*> explist
%type <ExpressionList*> optexplist
%type <ExpressionList*> varlist
%type <ExpressionList*> fieldrep

%type <ExpressionList*> fieldlist
%type <ExpressionList*> optfieldlist
%type <ExpressionList*> tableconstructor

%type <ExpressionList*> parlist
%type <ExpressionList*> optparlist
%type <std::list<std::string>> namelist

%type <Expression*> operator
%type <Statement*> if
%type <std::list<Statement*>> elseifs
%type <std::list<Statement*>> optelseifs
%type <Statement*> optelse

%type <ExpressionList*> optexpliste
%type <Expression*> optexpc

%type <std::string> optvarargs
%type <std::string> funcname
%type <std::string> optname
%type <std::string> repeatname1

%token <std::string> NAME
%token <std::string> STRING
%token <std::string> NUMBER

%token <std::string> AND
%token <std::string> BREAK
%token <std::string> DO
%token <std::string> ELSE
%token <std::string> ELSEIF
%token <std::string> END
%token <std::string> FALSE
%token <std::string> FOR
%token <std::string> FUNCTION
%token <std::string> IF
%token <std::string> IN
%token <std::string> LOCAL
%token <std::string> NIL
%token <std::string> NOT
%token <std::string> OR
%token <std::string> REPEAT
%token <std::string> RETURN
%token <std::string> THEN
%token <std::string> TRUE
%token <std::string> UNTIL
%token <std::string> WHILE

%token <std::string> PARANTHESIS_L
%token <std::string> PARANTHESIS_R
%token <std::string> SQUARE_R
%token <std::string> SQUARE_L
%token <std::string> BRACES_R
%token <std::string> BRACES_L
%token <std::string> PLUS
%token <std::string> MINUS
%token <std::string> MULTI
%token <std::string> DIVISION
%token <std::string> MODULUS
%token <std::string> POWER
%token <std::string> HASH
%token <std::string> LESSER
%token <std::string> GREATER
%token <std::string> COLON
%token <std::string> DOT
%token <std::string> ASSIGN
%token <std::string> COMMA
%token <std::string> SEMICOLON

%token <std::string> EQUALS
%token <std::string> NOTEQUALS
%token <std::string> GREATERTHANEQUAL
%token <std::string> LESSERTHANEQUAL
%token <std::string> CONCAT
%token <std::string> VARARGS

%left OR
%left AND
%left LESSER GREATER LESSERTHANEQUAL GREATERTHANEQUAL NOTEQUALS EQUALS
%right CONCAT
%left PLUS MINUS
%left MULTI DIVISION MODULUS
%right NOT
%right POWER


%token EOFFF 0 "end of file"
%%

block       : chunk { 
                $$ = $1;
                root = $$; 
            }
            ;

chunk       : chunkrep laststatement { 
                $$ = $1;
				$$->statements.push_back($2);
            }
            | chunkrep {
                $$ = $1;
            }
            | laststatement {
                $$ = new Sequence();
				$$->statements.push_back($1);
            }
            ;

chunkrep    : statement optsemi {
				$$ = new Sequence();
                $$->statements.push_back($1);
            }
            | chunk statement optsemi {
                $$ = $1;
                $$->statements.push_back($2);
            }
            ;
            

statement   : varlist ASSIGN explist {
                $$ = new Assignment($1, $3);
            }
            | functioncall {
                $$ = new CallStatement($1);
            }
            | DO block END {
                $$ = $2;
            }
            | WHILE exp DO block END {
                
            }
            | REPEAT block UNTIL exp {
                $$ = new Repeat($4, $2);
            }
            | if {
                $$ = $1; 
            }
            | FOR NAME ASSIGN exp COMMA exp optexpc DO block END {
                auto assignment = new Assignment(new Variable($2), $4);
				$$ = new ForLoop(assignment, $6, $9, $7);
            }
            | FOR namelist IN explist DO block END {
                
            }
            | FUNCTION funcname funcbody {
                $$ = $3;
				$$->name = $2;
            }
            | LOCAL FUNCTION NAME funcbody {
                $$ = $4;
				$$->name = $3;
            }
            | LOCAL namelist optexpliste {
                
            }
            ;

if          : IF exp THEN block optelseifs optelse END {
                $$ = new If($2, $4, $6);
            }
            ;

elseifs     : ELSEIF exp THEN block {
                
            }
            | elseifs ELSEIF exp THEN block {
                
            }
            ;

optelseifs  : {
                
            }
            | elseifs {
                $$ = $1;
            }
            ;

optelse     : {
				$$ = nullptr;              
            }
            | ELSE block {
                $$ = $2;
            }

laststatement: RETURN optexplist optsemi {
				$$ = new Return($2);
            }
            | BREAK optsemi {
                
            }
            ;

funcname    : NAME repeatname1 optname {
                $$ = $1 + $2 + $3;
            }
            ;

optname     : {
                $$ = "";   
            }
            | COLON NAME {
                $$ = $1+$2;
            }
            ;

repeatname1 : {
                $$ = "";            
            }
            | NAME {
                $$ = $1;
            }
            | repeatname1 DOT NAME {
                $$ += $2 + $3;
            }
            ;

varlist     : var {
				$$ = new ExpressionList();
				$$->expressions.push_back($1);
            }
            | varlist COMMA var {
                $$ = $1;
				$$->expressions.push_back($3);
            }
            ;

var         : NAME {
                $$ = new Variable($1);            
            }
            | prefixexp SQUARE_L exp SQUARE_R {
				$$ = new ArrayAccess($1, $3);
            }
            | prefixexp DOT NAME {
				$$ = new Subaccess($1, new Variable($3));
            }
            ;

explist     : exp {
				ExpressionList* expList = dynamic_cast<ExpressionList*>($1);
				if(expList != nullptr) {
					$$ = expList;
				}
				else {
					$$ = new ExpressionList();
					$$->expressions.push_back($1);
				}

            }
            | explist COMMA exp {
                $$ = $1;
				$$->expressions.push_back($3);
            }

exp         : STRING  { 
                $$ = new Constant("string", $1);
            }
            | NUMBER {
                $$ = new Constant("number", $1);
            }
            | FALSE {
                $$ = new Constant("bool", $1);
            }
            | TRUE {
                $$ = new Constant("bool", $1);
            } 
            | NIL {
                $$ = new Constant("nil", $1);
            }
            | VARARGS {
                
            }
            | function {
                
            }
            | prefixexp {
                $$ = $1;
            }
            | tableconstructor {
                $$ = $1;
            }
            | operator {
                $$ = $1;
            }
            ;

optparlist  : { 
                $$ = new ExpressionList();
            }
            | parlist {
                $$ = $1;
            }
            ;

parlist     : namelist optvarargs {
                $$ = new ExpressionList();
				for (auto &name : $1)
				{
					$$->expressions.push_back(new Variable(name));
				}
            }
            | VARARGS {

            }
            ;

namelist    : NAME {
                $$ = std::list<std::string>();
                $$.push_back($1);            
            }
            | namelist COMMA NAME {
                $$ = $1;
                $$.push_back($3);
            }
            ;


optexpliste : {
                $$ = new ExpressionList();
            }
            | ASSIGN explist {
                $$ = $2;
            }
            ;

optexpc     : {
                $$ = nullptr;
            }
            | COMMA exp {
                $$ = $2;
            }
            ;

functioncall: prefixexp args {
                $$ = new Call();
                $$->function = $1;
                $$->args = $2;
            }
            | prefixexp COLON NAME args {
				
            } 
            ;

args        : PARANTHESIS_L optexplist PARANTHESIS_R {

				$$ = $2;

            }
            | STRING {

				$$ = new Constant("string", $1);

            }
            ;

function    : FUNCTION funcbody {

				$$ = $2;

            }
            ;

funcbody    : PARANTHESIS_L optparlist PARANTHESIS_R block END {

				$$ = new Function($4, $2);

            }
            ;

prefixexp   : var {
                $$ = $1;            
            }
            | functioncall {
                $$ = $1;
            }
            | PARANTHESIS_L exp PARANTHESIS_R {
                $$ = $2;
            }
            ;

optexplist  : {
               $$ = new ExpressionList();           
            }
            | explist {
                $$ = $1;
            }
            ;

optsemi     : 
            | SEMICOLON
            ;

optvarargs  : {
                $$ = "";   
            }
            | COMMA VARARGS {
                $$ = $2;
            }
            ;

tableconstructor: BRACES_L optfieldlist BRACES_R {
                $$ = $2;
            }
            ;

optfieldlist: {
				$$ = new ExpressionList();            
            }
            | fieldlist {
                $$ = $1;
            }

fieldlist   : field fieldrep optfieldsep {
               $$ = $2;
			   $$->expressions.push_back($1);
            }
            ;

field       : NAME ASSIGN exp {
				
            }
            | exp {
                $$ = $1;
            }
            | SQUARE_L exp SQUARE_R ASSIGN exp {
                
            }
            ;

fieldrep    : {
              $$ = new ExpressionList();   
            }
            | fieldsep field {
              $$ = new ExpressionList();
			  $$->expressions.push_back($2);
            }
            | fieldrep fieldsep field {
              $$ = $1;
			  $$->expressions.push_back($3);
            }
            ;

fieldsep    : COMMA
            | SEMICOLON
            ;

optfieldsep :
            | fieldsep
            ;

operator    : exp PLUS exp { $$ = BinaryOperator::createAdd($1, $3); }
            | exp MINUS exp { $$ = BinaryOperator::createSub($1, $3); }
            | exp MULTI exp { $$ = BinaryOperator::createMul($1, $3); }
            | exp DIVISION exp { $$ = BinaryOperator::createDiv($1, $3); }
            | exp POWER exp { $$ = BinaryOperator::createPow($1, $3); }
            | exp MODULUS exp { $$ = BinaryOperator::createMod($1, $3); }
            | exp CONCAT exp { $$ = BinaryOperator::createConcat($1, $3); }
            | exp GREATER exp { $$ = BinaryOperator::createGreater($1, $3); }
            | exp GREATERTHANEQUAL exp { $$ = BinaryOperator::createGreaterEquals($1, $3); }
            | exp LESSER exp { $$ = BinaryOperator::createLesser($1, $3); }
            | exp LESSERTHANEQUAL exp { $$ = BinaryOperator::createLesserEquals($1, $3); }
            | exp EQUALS exp { $$ = BinaryOperator::createEquals($1, $3); }
            | exp NOTEQUALS exp { $$ = BinaryOperator::createNotEquals($1, $3); }
            | exp AND exp { $$ = BinaryOperator::createAnd($1, $3); }
            | exp OR exp { $$ = BinaryOperator::createOr($1, $3); }
            | MINUS exp { $$ = UnaryOperator::createNeg($2);}
            | NOT exp { $$ = UnaryOperator::createNot($2);}
            | HASH exp { $$ = UnaryOperator::createCount($2);}
            ;


