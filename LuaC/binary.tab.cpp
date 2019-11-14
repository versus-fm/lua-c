// A Bison parser, made by GNU Bison 3.0.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "binary.tab.cpp" // lalr1.cc:398

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

#include "binary.tab.hh"

// User implementation prologue.

#line 51 "binary.tab.cpp" // lalr1.cc:406
// Unqualified %code blocks.
#line 25 "binary.y" // lalr1.cc:407

    #include <string>
    #include <iostream>
    #define YY_DECL yy::parser::symbol_type yylex()
    YY_DECL;
    Sequence* root = new Sequence();        

#line 61 "binary.tab.cpp" // lalr1.cc:407


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyempty = true)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 128 "binary.tab.cpp" // lalr1.cc:473

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
     :yydebug_ (false),
      yycdebug_ (&std::cerr)
#endif
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s)
  {
      switch (that.type_get ())
    {
      case 75: // functioncall
        value.move< Call* > (that.value);
        break;

      case 67: // var
      case 69: // exp
      case 74: // optexpc
      case 76: // args
      case 79: // prefixexp
      case 86: // field
      case 90: // operator
        value.move< Expression* > (that.value);
        break;

      case 66: // varlist
      case 68: // explist
      case 70: // optparlist
      case 71: // parlist
      case 73: // optexpliste
      case 80: // optexplist
      case 83: // tableconstructor
      case 84: // optfieldlist
      case 85: // fieldlist
      case 87: // fieldrep
        value.move< ExpressionList* > (that.value);
        break;

      case 78: // funcbody
        value.move< Function* > (that.value);
        break;

      case 54: // block
      case 55: // chunk
      case 56: // chunkrep
        value.move< Sequence* > (that.value);
        break;

      case 57: // statement
      case 58: // if
      case 61: // optelse
      case 62: // laststatement
      case 77: // function
        value.move< Statement* > (that.value);
        break;

      case 59: // elseifs
      case 60: // optelseifs
        value.move< std::list<Statement*> > (that.value);
        break;

      case 72: // namelist
        value.move< std::list<std::string> > (that.value);
        break;

      case 3: // NAME
      case 4: // STRING
      case 5: // NUMBER
      case 6: // AND
      case 7: // BREAK
      case 8: // DO
      case 9: // ELSE
      case 10: // ELSEIF
      case 11: // END
      case 12: // FALSE
      case 13: // FOR
      case 14: // FUNCTION
      case 15: // IF
      case 16: // IN
      case 17: // LOCAL
      case 18: // NIL
      case 19: // NOT
      case 20: // OR
      case 21: // REPEAT
      case 22: // RETURN
      case 23: // THEN
      case 24: // TRUE
      case 25: // UNTIL
      case 26: // WHILE
      case 27: // PARANTHESIS_L
      case 28: // PARANTHESIS_R
      case 29: // SQUARE_R
      case 30: // SQUARE_L
      case 31: // BRACES_R
      case 32: // BRACES_L
      case 33: // PLUS
      case 34: // MINUS
      case 35: // MULTI
      case 36: // DIVISION
      case 37: // MODULUS
      case 38: // POWER
      case 39: // HASH
      case 40: // LESSER
      case 41: // GREATER
      case 42: // COLON
      case 43: // DOT
      case 44: // ASSIGN
      case 45: // COMMA
      case 46: // SEMICOLON
      case 47: // EQUALS
      case 48: // NOTEQUALS
      case 49: // GREATERTHANEQUAL
      case 50: // LESSERTHANEQUAL
      case 51: // CONCAT
      case 52: // VARARGS
      case 63: // funcname
      case 64: // optname
      case 65: // repeatname1
      case 82: // optvarargs
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 75: // functioncall
        value.copy< Call* > (that.value);
        break;

      case 67: // var
      case 69: // exp
      case 74: // optexpc
      case 76: // args
      case 79: // prefixexp
      case 86: // field
      case 90: // operator
        value.copy< Expression* > (that.value);
        break;

      case 66: // varlist
      case 68: // explist
      case 70: // optparlist
      case 71: // parlist
      case 73: // optexpliste
      case 80: // optexplist
      case 83: // tableconstructor
      case 84: // optfieldlist
      case 85: // fieldlist
      case 87: // fieldrep
        value.copy< ExpressionList* > (that.value);
        break;

      case 78: // funcbody
        value.copy< Function* > (that.value);
        break;

      case 54: // block
      case 55: // chunk
      case 56: // chunkrep
        value.copy< Sequence* > (that.value);
        break;

      case 57: // statement
      case 58: // if
      case 61: // optelse
      case 62: // laststatement
      case 77: // function
        value.copy< Statement* > (that.value);
        break;

      case 59: // elseifs
      case 60: // optelseifs
        value.copy< std::list<Statement*> > (that.value);
        break;

      case 72: // namelist
        value.copy< std::list<std::string> > (that.value);
        break;

      case 3: // NAME
      case 4: // STRING
      case 5: // NUMBER
      case 6: // AND
      case 7: // BREAK
      case 8: // DO
      case 9: // ELSE
      case 10: // ELSEIF
      case 11: // END
      case 12: // FALSE
      case 13: // FOR
      case 14: // FUNCTION
      case 15: // IF
      case 16: // IN
      case 17: // LOCAL
      case 18: // NIL
      case 19: // NOT
      case 20: // OR
      case 21: // REPEAT
      case 22: // RETURN
      case 23: // THEN
      case 24: // TRUE
      case 25: // UNTIL
      case 26: // WHILE
      case 27: // PARANTHESIS_L
      case 28: // PARANTHESIS_R
      case 29: // SQUARE_R
      case 30: // SQUARE_L
      case 31: // BRACES_R
      case 32: // BRACES_L
      case 33: // PLUS
      case 34: // MINUS
      case 35: // MULTI
      case 36: // DIVISION
      case 37: // MODULUS
      case 38: // POWER
      case 39: // HASH
      case 40: // LESSER
      case 41: // GREATER
      case 42: // COLON
      case 43: // DOT
      case 44: // ASSIGN
      case 45: // COMMA
      case 46: // SEMICOLON
      case 47: // EQUALS
      case 48: // NOTEQUALS
      case 49: // GREATERTHANEQUAL
      case 50: // LESSERTHANEQUAL
      case 51: // CONCAT
      case 52: // VARARGS
      case 63: // funcname
      case 64: // optname
      case 65: // repeatname1
      case 82: // optvarargs
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }


  template <typename Base>
  inline
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yylhs)
  {
    int yyr = yypgoto_[yylhs - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yylhs - yyntokens_];
  }

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    /// Whether yyla contains a lookahead.
    bool yyempty = true;

    // State.
    int yyn;
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// $$ and @$.
    stack_symbol_type yylhs;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULL, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyempty)
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
        yyempty = false;
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Discard the token being shifted.
    yyempty = true;

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
    /* Variants are always initialized to an empty instance of the
       correct type. The default $$=$1 action is NOT applied when using
       variants.  */
      switch (yyr1_[yyn])
    {
      case 75: // functioncall
        yylhs.value.build< Call* > ();
        break;

      case 67: // var
      case 69: // exp
      case 74: // optexpc
      case 76: // args
      case 79: // prefixexp
      case 86: // field
      case 90: // operator
        yylhs.value.build< Expression* > ();
        break;

      case 66: // varlist
      case 68: // explist
      case 70: // optparlist
      case 71: // parlist
      case 73: // optexpliste
      case 80: // optexplist
      case 83: // tableconstructor
      case 84: // optfieldlist
      case 85: // fieldlist
      case 87: // fieldrep
        yylhs.value.build< ExpressionList* > ();
        break;

      case 78: // funcbody
        yylhs.value.build< Function* > ();
        break;

      case 54: // block
      case 55: // chunk
      case 56: // chunkrep
        yylhs.value.build< Sequence* > ();
        break;

      case 57: // statement
      case 58: // if
      case 61: // optelse
      case 62: // laststatement
      case 77: // function
        yylhs.value.build< Statement* > ();
        break;

      case 59: // elseifs
      case 60: // optelseifs
        yylhs.value.build< std::list<Statement*> > ();
        break;

      case 72: // namelist
        yylhs.value.build< std::list<std::string> > ();
        break;

      case 3: // NAME
      case 4: // STRING
      case 5: // NUMBER
      case 6: // AND
      case 7: // BREAK
      case 8: // DO
      case 9: // ELSE
      case 10: // ELSEIF
      case 11: // END
      case 12: // FALSE
      case 13: // FOR
      case 14: // FUNCTION
      case 15: // IF
      case 16: // IN
      case 17: // LOCAL
      case 18: // NIL
      case 19: // NOT
      case 20: // OR
      case 21: // REPEAT
      case 22: // RETURN
      case 23: // THEN
      case 24: // TRUE
      case 25: // UNTIL
      case 26: // WHILE
      case 27: // PARANTHESIS_L
      case 28: // PARANTHESIS_R
      case 29: // SQUARE_R
      case 30: // SQUARE_L
      case 31: // BRACES_R
      case 32: // BRACES_L
      case 33: // PLUS
      case 34: // MINUS
      case 35: // MULTI
      case 36: // DIVISION
      case 37: // MODULUS
      case 38: // POWER
      case 39: // HASH
      case 40: // LESSER
      case 41: // GREATER
      case 42: // COLON
      case 43: // DOT
      case 44: // ASSIGN
      case 45: // COMMA
      case 46: // SEMICOLON
      case 47: // EQUALS
      case 48: // NOTEQUALS
      case 49: // GREATERTHANEQUAL
      case 50: // LESSERTHANEQUAL
      case 51: // CONCAT
      case 52: // VARARGS
      case 63: // funcname
      case 64: // optname
      case 65: // repeatname1
      case 82: // optvarargs
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }



    // Perform the reduction.
    YY_REDUCE_PRINT (yyn);
    try
      {
        switch (yyn)
          {
  case 2:
#line 141 "binary.y" // lalr1.cc:846
    { 
                yylhs.value.as< Sequence* > () = yystack_[0].value.as< Sequence* > ();
                root = yylhs.value.as< Sequence* > (); 
            }
#line 820 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 3:
#line 147 "binary.y" // lalr1.cc:846
    { 
                yylhs.value.as< Sequence* > () = yystack_[1].value.as< Sequence* > ();
				yylhs.value.as< Sequence* > ()->statements.push_back(yystack_[0].value.as< Statement* > ());
            }
#line 829 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 4:
#line 151 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< Sequence* > () = yystack_[0].value.as< Sequence* > ();
            }
#line 837 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 5:
#line 154 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< Sequence* > () = new Sequence();
				yylhs.value.as< Sequence* > ()->statements.push_back(yystack_[0].value.as< Statement* > ());
            }
#line 846 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 6:
#line 160 "binary.y" // lalr1.cc:846
    {
				yylhs.value.as< Sequence* > () = new Sequence();
                yylhs.value.as< Sequence* > ()->statements.push_back(yystack_[1].value.as< Statement* > ());
            }
#line 855 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 7:
#line 164 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< Sequence* > () = yystack_[2].value.as< Sequence* > ();
                yylhs.value.as< Sequence* > ()->statements.push_back(yystack_[1].value.as< Statement* > ());
            }
#line 864 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 8:
#line 171 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< Statement* > () = new Assignment(yystack_[2].value.as< ExpressionList* > (), yystack_[0].value.as< ExpressionList* > ());
            }
#line 872 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 9:
#line 174 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< Statement* > () = new CallStatement(yystack_[0].value.as< Call* > ());
            }
#line 880 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 10:
#line 177 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< Statement* > () = yystack_[1].value.as< Sequence* > ();
            }
#line 888 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 11:
#line 180 "binary.y" // lalr1.cc:846
    {
                
            }
#line 896 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 12:
#line 183 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< Statement* > () = new Repeat(yystack_[0].value.as< Expression* > (), yystack_[2].value.as< Sequence* > ());
            }
#line 904 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 13:
#line 186 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< Statement* > () = yystack_[0].value.as< Statement* > (); 
            }
#line 912 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 14:
#line 189 "binary.y" // lalr1.cc:846
    {
                auto assignment = new Assignment(new Variable(yystack_[8].value.as< std::string > ()), yystack_[6].value.as< Expression* > ());
				yylhs.value.as< Statement* > () = new ForLoop(assignment, yystack_[4].value.as< Expression* > (), yystack_[1].value.as< Sequence* > (), yystack_[3].value.as< Expression* > ());
            }
#line 921 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 15:
#line 193 "binary.y" // lalr1.cc:846
    {
                
            }
#line 929 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 16:
#line 196 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< Statement* > () = yystack_[0].value.as< Function* > ();
				yylhs.value.as< Statement* > ()->name = yystack_[1].value.as< std::string > ();
            }
#line 938 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 17:
#line 200 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< Statement* > () = yystack_[0].value.as< Function* > ();
				yylhs.value.as< Statement* > ()->name = yystack_[1].value.as< std::string > ();
            }
#line 947 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 18:
#line 204 "binary.y" // lalr1.cc:846
    {
                
            }
#line 955 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 19:
#line 209 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< Statement* > () = new If(yystack_[5].value.as< Expression* > (), yystack_[3].value.as< Sequence* > (), yystack_[1].value.as< Statement* > ());
            }
#line 963 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 20:
#line 214 "binary.y" // lalr1.cc:846
    {
                
            }
#line 971 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 21:
#line 217 "binary.y" // lalr1.cc:846
    {
                
            }
#line 979 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 22:
#line 222 "binary.y" // lalr1.cc:846
    {
                
            }
#line 987 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 23:
#line 225 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< std::list<Statement*> > () = yystack_[0].value.as< std::list<Statement*> > ();
            }
#line 995 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 24:
#line 230 "binary.y" // lalr1.cc:846
    {
				yylhs.value.as< Statement* > () = nullptr;              
            }
#line 1003 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 25:
#line 233 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< Statement* > () = yystack_[0].value.as< Sequence* > ();
            }
#line 1011 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 26:
#line 237 "binary.y" // lalr1.cc:846
    {
				yylhs.value.as< Statement* > () = new Return(yystack_[1].value.as< ExpressionList* > ());
            }
#line 1019 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 27:
#line 240 "binary.y" // lalr1.cc:846
    {
                
            }
#line 1027 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 28:
#line 245 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< std::string > () = yystack_[2].value.as< std::string > () + yystack_[1].value.as< std::string > () + yystack_[0].value.as< std::string > ();
            }
#line 1035 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 29:
#line 250 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< std::string > () = "";   
            }
#line 1043 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 30:
#line 253 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< std::string > () = yystack_[1].value.as< std::string > ()+yystack_[0].value.as< std::string > ();
            }
#line 1051 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 31:
#line 258 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< std::string > () = "";            
            }
#line 1059 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 32:
#line 261 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();
            }
#line 1067 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 33:
#line 264 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< std::string > () += yystack_[1].value.as< std::string > () + yystack_[0].value.as< std::string > ();
            }
#line 1075 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 34:
#line 269 "binary.y" // lalr1.cc:846
    {
				yylhs.value.as< ExpressionList* > () = new ExpressionList();
				yylhs.value.as< ExpressionList* > ()->expressions.push_back(yystack_[0].value.as< Expression* > ());
            }
#line 1084 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 35:
#line 273 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< ExpressionList* > () = yystack_[2].value.as< ExpressionList* > ();
				yylhs.value.as< ExpressionList* > ()->expressions.push_back(yystack_[0].value.as< Expression* > ());
            }
#line 1093 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 36:
#line 279 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< Expression* > () = new Variable(yystack_[0].value.as< std::string > ());            
            }
#line 1101 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 37:
#line 282 "binary.y" // lalr1.cc:846
    {
				yylhs.value.as< Expression* > () = new ArrayAccess(yystack_[3].value.as< Expression* > (), yystack_[1].value.as< Expression* > ());
            }
#line 1109 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 38:
#line 285 "binary.y" // lalr1.cc:846
    {
				yylhs.value.as< Expression* > () = new Subaccess(yystack_[2].value.as< Expression* > (), new Variable(yystack_[0].value.as< std::string > ()));
            }
#line 1117 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 39:
#line 290 "binary.y" // lalr1.cc:846
    {
				ExpressionList* expList = dynamic_cast<ExpressionList*>(yystack_[0].value.as< Expression* > ());
				if(expList != nullptr) {
					yylhs.value.as< ExpressionList* > () = expList;
				}
				else {
					yylhs.value.as< ExpressionList* > () = new ExpressionList();
					yylhs.value.as< ExpressionList* > ()->expressions.push_back(yystack_[0].value.as< Expression* > ());
				}

            }
#line 1133 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 40:
#line 301 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< ExpressionList* > () = yystack_[2].value.as< ExpressionList* > ();
				yylhs.value.as< ExpressionList* > ()->expressions.push_back(yystack_[0].value.as< Expression* > ());
            }
#line 1142 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 41:
#line 306 "binary.y" // lalr1.cc:846
    { 
                yylhs.value.as< Expression* > () = new Constant("string", yystack_[0].value.as< std::string > ());
            }
#line 1150 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 42:
#line 309 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< Expression* > () = new Constant("number", yystack_[0].value.as< std::string > ());
            }
#line 1158 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 43:
#line 312 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< Expression* > () = new Constant("bool", yystack_[0].value.as< std::string > ());
            }
#line 1166 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 44:
#line 315 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< Expression* > () = new Constant("bool", yystack_[0].value.as< std::string > ());
            }
#line 1174 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 45:
#line 318 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< Expression* > () = new Constant("nil", yystack_[0].value.as< std::string > ());
            }
#line 1182 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 46:
#line 321 "binary.y" // lalr1.cc:846
    {
                
            }
#line 1190 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 47:
#line 324 "binary.y" // lalr1.cc:846
    {
                
            }
#line 1198 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 48:
#line 327 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< Expression* > () = yystack_[0].value.as< Expression* > ();
            }
#line 1206 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 49:
#line 330 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< Expression* > () = yystack_[0].value.as< ExpressionList* > ();
            }
#line 1214 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 50:
#line 333 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< Expression* > () = yystack_[0].value.as< Expression* > ();
            }
#line 1222 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 51:
#line 338 "binary.y" // lalr1.cc:846
    { 
                yylhs.value.as< ExpressionList* > () = new ExpressionList();
            }
#line 1230 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 52:
#line 341 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< ExpressionList* > () = yystack_[0].value.as< ExpressionList* > ();
            }
#line 1238 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 53:
#line 346 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< ExpressionList* > () = new ExpressionList();
				for (auto &name : yystack_[1].value.as< std::list<std::string> > ())
				{
					yylhs.value.as< ExpressionList* > ()->expressions.push_back(new Variable(name));
				}
            }
#line 1250 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 54:
#line 353 "binary.y" // lalr1.cc:846
    {

            }
#line 1258 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 55:
#line 358 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< std::list<std::string> > () = std::list<std::string>();
                yylhs.value.as< std::list<std::string> > ().push_back(yystack_[0].value.as< std::string > ());            
            }
#line 1267 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 56:
#line 362 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< std::list<std::string> > () = yystack_[2].value.as< std::list<std::string> > ();
                yylhs.value.as< std::list<std::string> > ().push_back(yystack_[0].value.as< std::string > ());
            }
#line 1276 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 57:
#line 369 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< ExpressionList* > () = new ExpressionList();
            }
#line 1284 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 58:
#line 372 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< ExpressionList* > () = yystack_[0].value.as< ExpressionList* > ();
            }
#line 1292 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 59:
#line 377 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< Expression* > () = nullptr;
            }
#line 1300 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 60:
#line 380 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< Expression* > () = yystack_[0].value.as< Expression* > ();
            }
#line 1308 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 61:
#line 385 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< Call* > () = new Call();
                yylhs.value.as< Call* > ()->function = yystack_[1].value.as< Expression* > ();
                yylhs.value.as< Call* > ()->args = yystack_[0].value.as< Expression* > ();
            }
#line 1318 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 62:
#line 390 "binary.y" // lalr1.cc:846
    {
				
            }
#line 1326 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 63:
#line 395 "binary.y" // lalr1.cc:846
    {

				yylhs.value.as< Expression* > () = yystack_[1].value.as< ExpressionList* > ();

            }
#line 1336 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 64:
#line 400 "binary.y" // lalr1.cc:846
    {

				yylhs.value.as< Expression* > () = new Constant("string", yystack_[0].value.as< std::string > ());

            }
#line 1346 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 65:
#line 407 "binary.y" // lalr1.cc:846
    {

				yylhs.value.as< Statement* > () = yystack_[0].value.as< Function* > ();

            }
#line 1356 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 66:
#line 414 "binary.y" // lalr1.cc:846
    {

				yylhs.value.as< Function* > () = new Function(yystack_[1].value.as< Sequence* > (), yystack_[3].value.as< ExpressionList* > ());

            }
#line 1366 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 67:
#line 421 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< Expression* > () = yystack_[0].value.as< Expression* > ();            
            }
#line 1374 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 68:
#line 424 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< Expression* > () = yystack_[0].value.as< Call* > ();
            }
#line 1382 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 69:
#line 427 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< Expression* > () = yystack_[1].value.as< Expression* > ();
            }
#line 1390 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 70:
#line 432 "binary.y" // lalr1.cc:846
    {
               yylhs.value.as< ExpressionList* > () = new ExpressionList();           
            }
#line 1398 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 71:
#line 435 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< ExpressionList* > () = yystack_[0].value.as< ExpressionList* > ();
            }
#line 1406 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 74:
#line 444 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< std::string > () = "";   
            }
#line 1414 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 75:
#line 447 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();
            }
#line 1422 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 76:
#line 452 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< ExpressionList* > () = yystack_[1].value.as< ExpressionList* > ();
            }
#line 1430 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 77:
#line 457 "binary.y" // lalr1.cc:846
    {
				yylhs.value.as< ExpressionList* > () = new ExpressionList();            
            }
#line 1438 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 78:
#line 460 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< ExpressionList* > () = yystack_[0].value.as< ExpressionList* > ();
            }
#line 1446 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 79:
#line 464 "binary.y" // lalr1.cc:846
    {
               yylhs.value.as< ExpressionList* > () = yystack_[1].value.as< ExpressionList* > ();
			   yylhs.value.as< ExpressionList* > ()->expressions.push_back(yystack_[2].value.as< Expression* > ());
            }
#line 1455 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 80:
#line 470 "binary.y" // lalr1.cc:846
    {
				
            }
#line 1463 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 81:
#line 473 "binary.y" // lalr1.cc:846
    {
                yylhs.value.as< Expression* > () = yystack_[0].value.as< Expression* > ();
            }
#line 1471 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 82:
#line 476 "binary.y" // lalr1.cc:846
    {
                
            }
#line 1479 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 83:
#line 481 "binary.y" // lalr1.cc:846
    {
              yylhs.value.as< ExpressionList* > () = new ExpressionList();   
            }
#line 1487 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 84:
#line 484 "binary.y" // lalr1.cc:846
    {
              yylhs.value.as< ExpressionList* > () = new ExpressionList();
			  yylhs.value.as< ExpressionList* > ()->expressions.push_back(yystack_[0].value.as< Expression* > ());
            }
#line 1496 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 85:
#line 488 "binary.y" // lalr1.cc:846
    {
              yylhs.value.as< ExpressionList* > () = yystack_[2].value.as< ExpressionList* > ();
			  yylhs.value.as< ExpressionList* > ()->expressions.push_back(yystack_[0].value.as< Expression* > ());
            }
#line 1505 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 90:
#line 502 "binary.y" // lalr1.cc:846
    { yylhs.value.as< Expression* > () = BinaryOperator::createAdd(yystack_[2].value.as< Expression* > (), yystack_[0].value.as< Expression* > ()); }
#line 1511 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 91:
#line 503 "binary.y" // lalr1.cc:846
    { yylhs.value.as< Expression* > () = BinaryOperator::createSub(yystack_[2].value.as< Expression* > (), yystack_[0].value.as< Expression* > ()); }
#line 1517 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 92:
#line 504 "binary.y" // lalr1.cc:846
    { yylhs.value.as< Expression* > () = BinaryOperator::createMul(yystack_[2].value.as< Expression* > (), yystack_[0].value.as< Expression* > ()); }
#line 1523 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 93:
#line 505 "binary.y" // lalr1.cc:846
    { yylhs.value.as< Expression* > () = BinaryOperator::createDiv(yystack_[2].value.as< Expression* > (), yystack_[0].value.as< Expression* > ()); }
#line 1529 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 94:
#line 506 "binary.y" // lalr1.cc:846
    { yylhs.value.as< Expression* > () = BinaryOperator::createPow(yystack_[2].value.as< Expression* > (), yystack_[0].value.as< Expression* > ()); }
#line 1535 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 95:
#line 507 "binary.y" // lalr1.cc:846
    { yylhs.value.as< Expression* > () = BinaryOperator::createMod(yystack_[2].value.as< Expression* > (), yystack_[0].value.as< Expression* > ()); }
#line 1541 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 96:
#line 508 "binary.y" // lalr1.cc:846
    { yylhs.value.as< Expression* > () = BinaryOperator::createConcat(yystack_[2].value.as< Expression* > (), yystack_[0].value.as< Expression* > ()); }
#line 1547 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 97:
#line 509 "binary.y" // lalr1.cc:846
    { yylhs.value.as< Expression* > () = BinaryOperator::createGreater(yystack_[2].value.as< Expression* > (), yystack_[0].value.as< Expression* > ()); }
#line 1553 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 98:
#line 510 "binary.y" // lalr1.cc:846
    { yylhs.value.as< Expression* > () = BinaryOperator::createGreaterEquals(yystack_[2].value.as< Expression* > (), yystack_[0].value.as< Expression* > ()); }
#line 1559 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 99:
#line 511 "binary.y" // lalr1.cc:846
    { yylhs.value.as< Expression* > () = BinaryOperator::createLesser(yystack_[2].value.as< Expression* > (), yystack_[0].value.as< Expression* > ()); }
#line 1565 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 100:
#line 512 "binary.y" // lalr1.cc:846
    { yylhs.value.as< Expression* > () = BinaryOperator::createLesserEquals(yystack_[2].value.as< Expression* > (), yystack_[0].value.as< Expression* > ()); }
#line 1571 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 101:
#line 513 "binary.y" // lalr1.cc:846
    { yylhs.value.as< Expression* > () = BinaryOperator::createEquals(yystack_[2].value.as< Expression* > (), yystack_[0].value.as< Expression* > ()); }
#line 1577 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 102:
#line 514 "binary.y" // lalr1.cc:846
    { yylhs.value.as< Expression* > () = BinaryOperator::createNotEquals(yystack_[2].value.as< Expression* > (), yystack_[0].value.as< Expression* > ()); }
#line 1583 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 103:
#line 515 "binary.y" // lalr1.cc:846
    { yylhs.value.as< Expression* > () = BinaryOperator::createAnd(yystack_[2].value.as< Expression* > (), yystack_[0].value.as< Expression* > ()); }
#line 1589 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 104:
#line 516 "binary.y" // lalr1.cc:846
    { yylhs.value.as< Expression* > () = BinaryOperator::createOr(yystack_[2].value.as< Expression* > (), yystack_[0].value.as< Expression* > ()); }
#line 1595 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 105:
#line 517 "binary.y" // lalr1.cc:846
    { yylhs.value.as< Expression* > () = UnaryOperator::createNeg(yystack_[0].value.as< Expression* > ());}
#line 1601 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 106:
#line 518 "binary.y" // lalr1.cc:846
    { yylhs.value.as< Expression* > () = UnaryOperator::createNot(yystack_[0].value.as< Expression* > ());}
#line 1607 "binary.tab.cpp" // lalr1.cc:846
    break;

  case 107:
#line 519 "binary.y" // lalr1.cc:846
    { yylhs.value.as< Expression* > () = UnaryOperator::createCount(yystack_[0].value.as< Expression* > ());}
#line 1613 "binary.tab.cpp" // lalr1.cc:846
    break;


#line 1617 "binary.tab.cpp" // lalr1.cc:846
          default:
            break;
          }
      }
    catch (const syntax_error& yyexc)
      {
        error (yyexc);
        YYERROR;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yylhs);
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    // Shift the result of the reduction.
    yypush_ (YY_NULL, yylhs);
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state,
                                           yyempty ? yyempty_ : yyla.type_get ()));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyempty)
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyempty = true;
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* $$ was initialized before running the user action.  */
    YY_SYMBOL_PRINT ("Error: discarding", yylhs);
    yylhs.~stack_symbol_type();
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyempty)
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyempty)
          yy_destroy_ (YY_NULL, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULL, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, symbol_number_type yytoken) const
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULL;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -124;

  const signed char parser::yytable_ninf_ = -69;

  const short int
  parser::yypact_[] =
  {
     522,  -124,   -34,   522,    23,    28,    63,    60,   522,    63,
      63,    63,    38,   238,    36,   -34,  -124,  -124,   -11,    34,
     106,    76,  -124,  -124,    35,     3,    19,    56,    42,  -124,
    -124,  -124,    42,  -124,    63,  -124,    18,    63,    63,  -124,
    -124,    93,  -124,  -124,    76,  -124,  -124,  -124,    62,    47,
      46,    31,   450,   -34,   282,   117,  -124,   -34,  -124,  -124,
      63,    12,  -124,    63,    63,    95,   104,  -124,  -124,    63,
      63,   108,  -124,    -2,     2,  -124,  -124,    58,    68,    63,
     450,    83,  -124,    55,    48,   450,    63,    63,   522,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    42,    63,  -124,    63,    63,  -124,   522,  -124,
    -124,    31,    49,    89,   187,    24,  -124,   334,    10,  -124,
     118,   119,  -124,  -124,    92,  -124,    87,    63,   357,  -124,
    -124,  -124,    55,    18,   517,   473,   125,    48,    48,    58,
      58,    58,    58,   258,   258,   258,   258,   258,   258,   258,
    -124,    31,   450,   450,   127,  -124,  -124,  -124,    63,   522,
    -124,  -124,   522,     4,  -124,   450,   102,    18,  -124,  -124,
      63,   129,   138,  -124,   381,   145,   150,  -124,    63,  -124,
     404,    63,   522,   158,    63,   162,  -124,  -124,   450,   522,
     427,  -124,  -124,   450,   522,  -124,   522,   160,  -124,  -124
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,    36,    72,     0,     0,     0,     0,     0,     0,    70,
       0,     0,     0,     2,     4,    72,    13,     5,     0,    67,
       9,     0,    73,    27,     0,    55,     0,    31,     0,    41,
      42,    43,     0,    45,     0,    44,    77,     0,     0,    46,
      67,     0,    68,    47,    48,    49,    50,    55,     0,    57,
       0,    71,    39,    72,     0,     0,     1,    72,     3,     6,
       0,     0,    64,    70,     0,     0,     0,    61,    10,     0,
       0,     0,    32,    29,    51,    16,    65,   106,    36,     0,
      81,     0,    78,    83,   105,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,     0,     0,    26,     0,    69,
       7,     8,    67,     0,     0,     0,    38,     0,     0,    56,
       0,     0,    28,    54,     0,    52,    74,     0,     0,    76,
      86,    87,    88,     0,   103,   104,    22,    90,    91,    92,
      93,    95,    94,    99,    97,   101,   102,    98,   100,    96,
      17,    58,    12,    40,     0,    63,    37,    62,     0,     0,
      30,    33,     0,     0,    53,    80,     0,    89,    79,    84,
       0,    23,    24,    11,    59,     0,     0,    75,     0,    85,
       0,     0,     0,     0,     0,     0,    15,    66,    82,     0,
       0,    25,    19,    60,     0,    20,     0,     0,    21,    14
  };

  const short int
  parser::yypgoto_[] =
  {
    -124,    17,  -124,  -124,   159,  -124,  -124,  -124,  -124,   163,
    -124,  -124,  -124,  -124,     0,   -43,   181,  -124,  -124,    -1,
    -124,  -124,    16,    59,  -124,   -30,     1,   110,    -4,  -124,
    -124,  -124,  -124,  -123,  -124,    52,  -124,  -124
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,    12,    13,    14,    15,    16,   171,   172,   183,    17,
      28,   122,    73,    18,    40,    51,    52,   124,   125,    26,
     104,   185,    42,    67,    43,    75,    44,    53,    23,   164,
      45,    81,    82,    83,   132,   133,   168,    46
  };

  const short int
  parser::yytable_[] =
  {
      19,    21,    76,    19,    21,    47,    49,   119,    19,    21,
     169,    59,    22,    19,    21,     1,    20,   111,   159,    20,
      24,    78,    29,    30,    20,    50,    25,   118,    62,    20,
      31,    27,    32,    60,    61,    70,    33,    34,    56,    11,
     120,   121,    35,     2,   179,    11,    68,    69,    79,   107,
      36,    63,    37,   110,   123,   106,   177,    38,     9,    72,
     151,   112,    21,    47,    71,   102,     1,    29,    30,    74,
      39,   105,   150,   126,    48,    31,   106,    32,   -34,   -34,
      62,    33,    34,    91,    92,    93,    94,    35,    19,    21,
      11,   103,    71,   -35,   -35,    36,    94,    37,   115,    86,
     130,   131,    38,    63,    20,   136,    64,   116,    19,    21,
     -68,   119,   127,    87,   129,    39,    88,   155,    65,    66,
     162,   160,   161,    86,    20,   154,    89,    90,    91,    92,
      93,    94,   163,    95,    96,   170,   -68,    87,   173,   181,
      97,    98,    99,   100,   101,   109,   178,   182,   -68,   -68,
      89,    90,    91,    92,    93,    94,   186,    95,    96,    19,
      21,   187,    19,    21,    97,    98,    99,   100,   101,   192,
     194,   199,    57,   113,   157,    20,   175,    58,    20,   176,
       0,     0,    19,    21,   167,     0,     0,    41,     0,    19,
      21,    54,    55,    86,    19,    21,    19,    21,    20,   191,
       0,     0,     0,     0,     0,    20,   195,    87,     0,     0,
      20,   197,    20,   198,     0,    77,   156,    80,    84,    85,
      89,    90,    91,    92,    93,    94,     0,    95,    96,     0,
       0,     0,     0,     0,    97,    98,    99,   100,   101,     0,
       0,     1,     0,     0,     0,   114,     3,     0,     0,     0,
     117,     4,     5,     6,     0,     7,     0,     0,     0,     8,
     128,     0,     0,     0,    10,    11,     0,   134,   135,     0,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,     0,     0,     0,   152,   153,    86,     0,
     108,    89,    90,    91,    92,    93,    94,     0,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     0,   165,   101,
       0,     0,     0,     0,    80,    89,    90,    91,    92,    93,
      94,     0,    95,    96,     0,     0,     0,     0,     0,    97,
      98,    99,   100,   101,     0,     0,     0,     0,     0,   174,
      86,     0,     0,     0,     0,     0,     0,     0,    80,     0,
       0,   180,     0,     0,    87,     0,     0,     0,     0,   188,
       0,     0,   190,    86,     0,   193,     0,    89,    90,    91,
      92,    93,    94,     0,    95,    96,     0,    87,     0,   158,
       0,    97,    98,    99,   100,   101,   166,    86,     0,     0,
      89,    90,    91,    92,    93,    94,     0,    95,    96,     0,
       0,    87,     0,     0,    97,    98,    99,   100,   101,     0,
      86,     0,     0,     0,    89,    90,    91,    92,    93,    94,
       0,    95,    96,     0,    87,     0,   184,   189,    97,    98,
      99,   100,   101,    86,     0,     0,     0,    89,    90,    91,
      92,    93,    94,     0,    95,    96,     0,    87,     0,     0,
     196,    97,    98,    99,   100,   101,    86,     0,     0,     0,
      89,    90,    91,    92,    93,    94,     0,    95,    96,     0,
      87,     0,     0,     0,    97,    98,    99,   100,   101,    86,
       0,     0,     0,    89,    90,    91,    92,    93,    94,     0,
      95,    96,     0,     0,     0,     0,     0,    97,    98,    99,
     100,   101,     0,     0,     0,     0,    89,    90,    91,    92,
      93,    94,     0,    95,    96,     0,     0,     0,     0,     0,
      97,    98,    99,   100,   101,     1,     0,     0,     0,     2,
       3,     0,     0,     0,     0,     4,     5,     6,     0,     7,
       0,     0,     0,     8,     9,     0,     0,     0,    10,    11,
      89,    90,    91,    92,    93,    94,     0,    95,    96,     0,
       0,     0,     0,     0,    97,    98,    99,   100,   101
  };

  const short int
  parser::yycheck_[] =
  {
       0,     0,    32,     3,     3,     3,     7,     3,     8,     8,
     133,    15,    46,    13,    13,     3,     0,    60,     8,     3,
       3,     3,     4,     5,     8,     8,     3,    70,     4,    13,
      12,     3,    14,    44,    45,    16,    18,    19,     0,    27,
      42,    43,    24,     7,   167,    27,    11,    44,    30,    53,
      32,    27,    34,    57,    52,    45,    52,    39,    22,     3,
     103,    61,    61,     3,    45,     3,     3,     4,     5,    27,
      52,    25,   102,    74,    14,    12,    45,    14,    44,    45,
       4,    18,    19,    35,    36,    37,    38,    24,    88,    88,
      27,    44,    45,    44,    45,    32,    38,    34,     3,     6,
      45,    46,    39,    27,    88,    88,    30,     3,   108,   108,
       4,     3,    44,    20,    31,    52,    23,    28,    42,    43,
      28,     3,     3,     6,   108,   108,    33,    34,    35,    36,
      37,    38,    45,    40,    41,    10,    30,    20,    11,    10,
      47,    48,    49,    50,    51,    28,    44,     9,    42,    43,
      33,    34,    35,    36,    37,    38,    11,    40,    41,   159,
     159,    11,   162,   162,    47,    48,    49,    50,    51,    11,
       8,    11,    13,    63,   115,   159,   159,    14,   162,   162,
      -1,    -1,   182,   182,   132,    -1,    -1,     6,    -1,   189,
     189,    10,    11,     6,   194,   194,   196,   196,   182,   182,
      -1,    -1,    -1,    -1,    -1,   189,   189,    20,    -1,    -1,
     194,   194,   196,   196,    -1,    34,    29,    36,    37,    38,
      33,    34,    35,    36,    37,    38,    -1,    40,    41,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,    -1,
      -1,     3,    -1,    -1,    -1,    64,     8,    -1,    -1,    -1,
      69,    13,    14,    15,    -1,    17,    -1,    -1,    -1,    21,
      79,    -1,    -1,    -1,    26,    27,    -1,    86,    87,    -1,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,    -1,    -1,    -1,   105,   106,     6,    -1,
       8,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,   127,    51,
      -1,    -1,    -1,    -1,   133,    33,    34,    35,    36,    37,
      38,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    47,
      48,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,   158,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,    -1,
      -1,   170,    -1,    -1,    20,    -1,    -1,    -1,    -1,   178,
      -1,    -1,   181,     6,    -1,   184,    -1,    33,    34,    35,
      36,    37,    38,    -1,    40,    41,    -1,    20,    -1,    45,
      -1,    47,    48,    49,    50,    51,    29,     6,    -1,    -1,
      33,    34,    35,    36,    37,    38,    -1,    40,    41,    -1,
      -1,    20,    -1,    -1,    47,    48,    49,    50,    51,    -1,
       6,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      -1,    40,    41,    -1,    20,    -1,    45,    23,    47,    48,
      49,    50,    51,     6,    -1,    -1,    -1,    33,    34,    35,
      36,    37,    38,    -1,    40,    41,    -1,    20,    -1,    -1,
      23,    47,    48,    49,    50,    51,     6,    -1,    -1,    -1,
      33,    34,    35,    36,    37,    38,    -1,    40,    41,    -1,
      20,    -1,    -1,    -1,    47,    48,    49,    50,    51,     6,
      -1,    -1,    -1,    33,    34,    35,    36,    37,    38,    -1,
      40,    41,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      50,    51,    -1,    -1,    -1,    -1,    33,    34,    35,    36,
      37,    38,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,
      47,    48,    49,    50,    51,     3,    -1,    -1,    -1,     7,
       8,    -1,    -1,    -1,    -1,    13,    14,    15,    -1,    17,
      -1,    -1,    -1,    21,    22,    -1,    -1,    -1,    26,    27,
      33,    34,    35,    36,    37,    38,    -1,    40,    41,    -1,
      -1,    -1,    -1,    -1,    47,    48,    49,    50,    51
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,     7,     8,    13,    14,    15,    17,    21,    22,
      26,    27,    54,    55,    56,    57,    58,    62,    66,    67,
      75,    79,    46,    81,    54,     3,    72,     3,    63,     4,
       5,    12,    14,    18,    19,    24,    32,    34,    39,    52,
      67,    69,    75,    77,    79,    83,    90,     3,    14,    72,
      54,    68,    69,    80,    69,    69,     0,    57,    62,    81,
      44,    45,     4,    27,    30,    42,    43,    76,    11,    44,
      16,    45,     3,    65,    27,    78,    78,    69,     3,    30,
      69,    84,    85,    86,    69,    69,     6,    20,    23,    33,
      34,    35,    36,    37,    38,    40,    41,    47,    48,    49,
      50,    51,     3,    44,    73,    25,    45,    81,     8,    28,
      81,    68,    67,    80,    69,     3,     3,    69,    68,     3,
      42,    43,    64,    52,    70,    71,    72,    44,    69,    31,
      45,    46,    87,    88,    69,    69,    54,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      78,    68,    69,    69,    54,    28,    29,    76,    45,     8,
       3,     3,    28,    45,    82,    69,    29,    88,    89,    86,
      10,    59,    60,    11,    69,    54,    54,    52,    44,    86,
      69,    10,     9,    61,    45,    74,    11,    11,    69,    23,
      69,    54,    11,    69,     8,    54,    23,    54,    54,    11
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    53,    54,    55,    55,    55,    56,    56,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    58,
      59,    59,    60,    60,    61,    61,    62,    62,    63,    64,
      64,    65,    65,    65,    66,    66,    67,    67,    67,    68,
      68,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    70,    70,    71,    71,    72,    72,    73,    73,    74,
      74,    75,    75,    76,    76,    77,    78,    79,    79,    79,
      80,    80,    81,    81,    82,    82,    83,    84,    84,    85,
      86,    86,    86,    87,    87,    87,    88,    88,    89,    89,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     2,     3,     3,     1,
       3,     5,     4,     1,    10,     7,     3,     4,     3,     7,
       4,     5,     0,     1,     0,     2,     3,     2,     3,     0,
       2,     0,     1,     3,     1,     3,     1,     4,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     2,     1,     1,     3,     0,     2,     0,
       2,     2,     4,     3,     1,     2,     5,     1,     1,     3,
       0,     1,     0,     1,     0,     2,     3,     0,     1,     3,
       3,     1,     5,     0,     2,     3,     1,     1,     0,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "NAME", "STRING", "NUMBER",
  "AND", "BREAK", "DO", "ELSE", "ELSEIF", "END", "FALSE", "FOR",
  "FUNCTION", "IF", "IN", "LOCAL", "NIL", "NOT", "OR", "REPEAT", "RETURN",
  "THEN", "TRUE", "UNTIL", "WHILE", "PARANTHESIS_L", "PARANTHESIS_R",
  "SQUARE_R", "SQUARE_L", "BRACES_R", "BRACES_L", "PLUS", "MINUS", "MULTI",
  "DIVISION", "MODULUS", "POWER", "HASH", "LESSER", "GREATER", "COLON",
  "DOT", "ASSIGN", "COMMA", "SEMICOLON", "EQUALS", "NOTEQUALS",
  "GREATERTHANEQUAL", "LESSERTHANEQUAL", "CONCAT", "VARARGS", "$accept",
  "block", "chunk", "chunkrep", "statement", "if", "elseifs", "optelseifs",
  "optelse", "laststatement", "funcname", "optname", "repeatname1",
  "varlist", "var", "explist", "exp", "optparlist", "parlist", "namelist",
  "optexpliste", "optexpc", "functioncall", "args", "function", "funcbody",
  "prefixexp", "optexplist", "optsemi", "optvarargs", "tableconstructor",
  "optfieldlist", "fieldlist", "field", "fieldrep", "fieldsep",
  "optfieldsep", "operator", YY_NULL
  };

#if YYDEBUG
  const unsigned short int
  parser::yyrline_[] =
  {
       0,   141,   141,   147,   151,   154,   160,   164,   171,   174,
     177,   180,   183,   186,   189,   193,   196,   200,   204,   209,
     214,   217,   222,   225,   230,   233,   237,   240,   245,   250,
     253,   258,   261,   264,   269,   273,   279,   282,   285,   290,
     301,   306,   309,   312,   315,   318,   321,   324,   327,   330,
     333,   338,   341,   346,   353,   358,   362,   369,   372,   377,
     380,   385,   390,   395,   400,   407,   414,   421,   424,   427,
     432,   435,   440,   441,   444,   447,   452,   457,   460,   464,
     470,   473,   476,   481,   484,   488,   494,   495,   498,   499,
     502,   503,   504,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 2195 "binary.tab.cpp" // lalr1.cc:1156
