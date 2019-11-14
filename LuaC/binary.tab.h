// A Bison parser, made by GNU Bison 3.0.

// Skeleton interface for Bison LALR(1) parsers in C++

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

/**
 ** \file binary.tab.h
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

#ifndef YY_YY_BINARY_TAB_H_INCLUDED
# define YY_YY_BINARY_TAB_H_INCLUDED
// //                    "%code requires" blocks.
#line 6 "binary.y" // lalr1.cc:371

    #include "Node.hh"

#line 48 "binary.tab.h" // lalr1.cc:371


# include <vector>
# include <iostream>
# include <stdexcept>
# include <string>
# include "stack.hh"


#ifndef YYASSERT
# include <cassert>
# define YYASSERT assert
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif


namespace yy {
#line 71 "binary.tab.h" // lalr1.cc:371



  /// A char[S] buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current state.
  template <size_t S>
  struct variant
  {
    /// Type of *this.
    typedef variant<S> self_type;

    /// Empty construction.
    variant ()
    {}

    /// Construct and fill.
    template <typename T>
    variant (const T& t)
    {
      YYASSERT (sizeof (T) <= S);
      new (yyas_<T> ()) T (t);
    }

    /// Destruction, allowed only if empty.
    ~variant ()
    {}

    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    build ()
    {
      return *new (yyas_<T> ()) T;
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    build (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as ()
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a other, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsability.
    /// Swapping between built and (possibly) non-built is done with
    /// variant::move ().
    template <typename T>
    void
    swap (self_type& other)
    {
      std::swap (as<T> (), other.as<T> ());
    }

    /// Move the content of \a other to this.
    ///
    /// Destroys \a other.
    template <typename T>
    void
    move (self_type& other)
    {
      build<T> ();
      swap<T> (other);
      other.destroy<T> ();
    }

    /// Copy the content of \a other to this.
    template <typename T>
    void
    copy (const self_type& other)
    {
      build<T> (other.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
    /// Prohibit blind copies.
    self_type& operator=(const self_type&);
    variant (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ ()
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[S];
    } yybuffer_;
  };


  /// A Bison parser.
  class parser
  {
  public:
#ifndef YYSTYPE
    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // block
      // chunk
      // chunkrep
      // statement
      // if
      // optelse
      // laststatement
      // var
      // exp
      // optexpc
      // functioncall
      // args
      // function
      // funcbody
      // prefixexp
      // tableconstructor
      // optfieldlist
      // fieldlist
      // field
      // operator
      char dummy1[sizeof(Node*)];

      // elseifs
      // optelseifs
      // varlist
      // explist
      // optexpliste
      // optexplist
      // fieldrep
      char dummy2[sizeof(std::list<Node*>)];

      // optparlist
      // parlist
      // namelist
      char dummy3[sizeof(std::list<std::string>)];

      // NAME
      // STRING
      // NUMBER
      // AND
      // BREAK
      // DO
      // ELSE
      // ELSEIF
      // END
      // FALSE
      // FOR
      // FUNCTION
      // IF
      // IN
      // LOCAL
      // NIL
      // NOT
      // OR
      // REPEAT
      // RETURN
      // THEN
      // TRUE
      // UNTIL
      // WHILE
      // PARANTHESIS_L
      // PARANTHESIS_R
      // SQUARE_R
      // SQUARE_L
      // BRACES_R
      // BRACES_L
      // PLUS
      // MINUS
      // MULTI
      // DIVISION
      // MODULUS
      // POWER
      // HASH
      // LESSER
      // GREATER
      // COLON
      // DOT
      // ASSIGN
      // COMMA
      // SEMICOLON
      // EQUALS
      // NOTEQUALS
      // GREATERTHANEQUAL
      // LESSERTHANEQUAL
      // CONCAT
      // VARARGS
      // funcname
      // optname
      // repeatname1
      // optvarargs
      char dummy4[sizeof(std::string)];
};

    /// Symbol semantic values.
    typedef variant<sizeof(union_type)> semantic_type;
#else
    typedef YYSTYPE semantic_type;
#endif

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const std::string& m);
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        EOFFF = 0,
        NAME = 258,
        STRING = 259,
        NUMBER = 260,
        AND = 261,
        BREAK = 262,
        DO = 263,
        ELSE = 264,
        ELSEIF = 265,
        END = 266,
        FALSE = 267,
        FOR = 268,
        FUNCTION = 269,
        IF = 270,
        IN = 271,
        LOCAL = 272,
        NIL = 273,
        NOT = 274,
        OR = 275,
        REPEAT = 276,
        RETURN = 277,
        THEN = 278,
        TRUE = 279,
        UNTIL = 280,
        WHILE = 281,
        PARANTHESIS_L = 282,
        PARANTHESIS_R = 283,
        SQUARE_R = 284,
        SQUARE_L = 285,
        BRACES_R = 286,
        BRACES_L = 287,
        PLUS = 288,
        MINUS = 289,
        MULTI = 290,
        DIVISION = 291,
        MODULUS = 292,
        POWER = 293,
        HASH = 294,
        LESSER = 295,
        GREATER = 296,
        COLON = 297,
        DOT = 298,
        ASSIGN = 299,
        COMMA = 300,
        SEMICOLON = 301,
        EQUALS = 302,
        NOTEQUALS = 303,
        GREATERTHANEQUAL = 304,
        LESSERTHANEQUAL = 305,
        CONCAT = 306,
        VARARGS = 307
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Internal symbol number.
    typedef int symbol_number_type;

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get().
    ///
    /// Provide access to semantic value.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ();

      /// Copy constructor.
      basic_symbol (const basic_symbol& other);

      /// Constructor for valueless symbols, and symbols from each type.

  basic_symbol (typename Base::kind_type t);

  basic_symbol (typename Base::kind_type t, const Node* v);

  basic_symbol (typename Base::kind_type t, const std::list<Node*> v);

  basic_symbol (typename Base::kind_type t, const std::list<std::string> v);

  basic_symbol (typename Base::kind_type t, const std::string v);


      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    const semantic_type& v);

      ~basic_symbol ();

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

    private:
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& other);
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

      /// Copy constructor.
      by_type (const by_type& other);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// -1 when this symbol is empty.
      symbol_number_type type_get () const;

      /// The token.
      token_type token () const;

      enum { empty = 0 };

      /// The symbol type.
      /// -1 when this symbol is empty.
      token_number_type type;
    };

    /// "External" symbols: returned by the scanner.
    typedef basic_symbol<by_type> symbol_type;

    // Symbol constructors declarations.
    static inline
    symbol_type
    make_EOFFF ();

    static inline
    symbol_type
    make_NAME (const std::string& v);

    static inline
    symbol_type
    make_STRING (const std::string& v);

    static inline
    symbol_type
    make_NUMBER (const std::string& v);

    static inline
    symbol_type
    make_AND (const std::string& v);

    static inline
    symbol_type
    make_BREAK (const std::string& v);

    static inline
    symbol_type
    make_DO (const std::string& v);

    static inline
    symbol_type
    make_ELSE (const std::string& v);

    static inline
    symbol_type
    make_ELSEIF (const std::string& v);

    static inline
    symbol_type
    make_END (const std::string& v);

    static inline
    symbol_type
    make_FALSE (const std::string& v);

    static inline
    symbol_type
    make_FOR (const std::string& v);

    static inline
    symbol_type
    make_FUNCTION (const std::string& v);

    static inline
    symbol_type
    make_IF (const std::string& v);

    static inline
    symbol_type
    make_IN (const std::string& v);

    static inline
    symbol_type
    make_LOCAL (const std::string& v);

    static inline
    symbol_type
    make_NIL (const std::string& v);

    static inline
    symbol_type
    make_NOT (const std::string& v);

    static inline
    symbol_type
    make_OR (const std::string& v);

    static inline
    symbol_type
    make_REPEAT (const std::string& v);

    static inline
    symbol_type
    make_RETURN (const std::string& v);

    static inline
    symbol_type
    make_THEN (const std::string& v);

    static inline
    symbol_type
    make_TRUE (const std::string& v);

    static inline
    symbol_type
    make_UNTIL (const std::string& v);

    static inline
    symbol_type
    make_WHILE (const std::string& v);

    static inline
    symbol_type
    make_PARANTHESIS_L (const std::string& v);

    static inline
    symbol_type
    make_PARANTHESIS_R (const std::string& v);

    static inline
    symbol_type
    make_SQUARE_R (const std::string& v);

    static inline
    symbol_type
    make_SQUARE_L (const std::string& v);

    static inline
    symbol_type
    make_BRACES_R (const std::string& v);

    static inline
    symbol_type
    make_BRACES_L (const std::string& v);

    static inline
    symbol_type
    make_PLUS (const std::string& v);

    static inline
    symbol_type
    make_MINUS (const std::string& v);

    static inline
    symbol_type
    make_MULTI (const std::string& v);

    static inline
    symbol_type
    make_DIVISION (const std::string& v);

    static inline
    symbol_type
    make_MODULUS (const std::string& v);

    static inline
    symbol_type
    make_POWER (const std::string& v);

    static inline
    symbol_type
    make_HASH (const std::string& v);

    static inline
    symbol_type
    make_LESSER (const std::string& v);

    static inline
    symbol_type
    make_GREATER (const std::string& v);

    static inline
    symbol_type
    make_COLON (const std::string& v);

    static inline
    symbol_type
    make_DOT (const std::string& v);

    static inline
    symbol_type
    make_ASSIGN (const std::string& v);

    static inline
    symbol_type
    make_COMMA (const std::string& v);

    static inline
    symbol_type
    make_SEMICOLON (const std::string& v);

    static inline
    symbol_type
    make_EQUALS (const std::string& v);

    static inline
    symbol_type
    make_NOTEQUALS (const std::string& v);

    static inline
    symbol_type
    make_GREATERTHANEQUAL (const std::string& v);

    static inline
    symbol_type
    make_LESSERTHANEQUAL (const std::string& v);

    static inline
    symbol_type
    make_CONCAT (const std::string& v);

    static inline
    symbol_type
    make_VARARGS (const std::string& v);


    /// Build a parser object.
    parser ();
    virtual ~parser ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param msg    a description of the syntax error.
    virtual void error (const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

  private:
    /// This class is not copyable.
    parser (const parser&);
    parser& operator= (const parser&);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yytoken   the lookahead token type, or yyempty_.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         symbol_number_type yytoken) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yylhs     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yylhs);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (token_type t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const short int yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned char yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const short int yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const short int yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const short int yytable_[];

  static const short int yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned short int yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    // Debugging.
    int yydebug_;
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param s         The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state ();

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s);

      /// Copy constructor.
      by_state (const by_state& other);

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// "empty" when empty.
      symbol_number_type type_get () const;

      enum { empty = 0 };

      /// The state.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, symbol_type& sym);
      /// Assignment, needed by push_back.
      stack_symbol_type& operator= (const stack_symbol_type& that);
    };

    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, stack_symbol_type& s);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, state_type s, symbol_type& sym);

    /// Pop \a n symbols the three stacks.
    void yypop_ (unsigned int n = 1);

    // Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 568,           //< Last index in yytable_.
      yynnts_ = 38,  //< Number of nonterminal symbols.
      yyempty_ = -2,
      yyfinal_ = 56, //< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 53    //< Number of tokens.
    };


  };

  // Symbol number corresponding to token number t.
  inline
  parser::token_number_type
  parser::yytranslate_ (token_type t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
    };
    const unsigned int user_token_number_max_ = 307;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

  inline
  parser::syntax_error::syntax_error (const std::string& m)
    : std::runtime_error (m)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
  {
      switch (other.type_get ())
    {
      case 54: // block
      case 55: // chunk
      case 56: // chunkrep
      case 57: // statement
      case 58: // if
      case 61: // optelse
      case 62: // laststatement
      case 67: // var
      case 69: // exp
      case 74: // optexpc
      case 75: // functioncall
      case 76: // args
      case 77: // function
      case 78: // funcbody
      case 79: // prefixexp
      case 83: // tableconstructor
      case 84: // optfieldlist
      case 85: // fieldlist
      case 86: // field
      case 90: // operator
        value.copy< Node* > (other.value);
        break;

      case 59: // elseifs
      case 60: // optelseifs
      case 66: // varlist
      case 68: // explist
      case 73: // optexpliste
      case 80: // optexplist
      case 87: // fieldrep
        value.copy< std::list<Node*> > (other.value);
        break;

      case 70: // optparlist
      case 71: // parlist
      case 72: // namelist
        value.copy< std::list<std::string> > (other.value);
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
        value.copy< std::string > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v)
    : Base (t)
    , value ()
  {
    (void) v;
      switch (this->type_get ())
    {
      case 54: // block
      case 55: // chunk
      case 56: // chunkrep
      case 57: // statement
      case 58: // if
      case 61: // optelse
      case 62: // laststatement
      case 67: // var
      case 69: // exp
      case 74: // optexpc
      case 75: // functioncall
      case 76: // args
      case 77: // function
      case 78: // funcbody
      case 79: // prefixexp
      case 83: // tableconstructor
      case 84: // optfieldlist
      case 85: // fieldlist
      case 86: // field
      case 90: // operator
        value.copy< Node* > (v);
        break;

      case 59: // elseifs
      case 60: // optelseifs
      case 66: // varlist
      case 68: // explist
      case 73: // optexpliste
      case 80: // optexplist
      case 87: // fieldrep
        value.copy< std::list<Node*> > (v);
        break;

      case 70: // optparlist
      case 71: // parlist
      case 72: // namelist
        value.copy< std::list<std::string> > (v);
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
        value.copy< std::string > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const Node* v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::list<Node*> v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::list<std::string> v)
    : Base (t)
    , value (v)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::string v)
    : Base (t)
    , value (v)
  {}


  template <typename Base>
  inline
  parser::basic_symbol<Base>::~basic_symbol ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      case 54: // block
      case 55: // chunk
      case 56: // chunkrep
      case 57: // statement
      case 58: // if
      case 61: // optelse
      case 62: // laststatement
      case 67: // var
      case 69: // exp
      case 74: // optexpc
      case 75: // functioncall
      case 76: // args
      case 77: // function
      case 78: // funcbody
      case 79: // prefixexp
      case 83: // tableconstructor
      case 84: // optfieldlist
      case 85: // fieldlist
      case 86: // field
      case 90: // operator
        value.template destroy< Node* > ();
        break;

      case 59: // elseifs
      case 60: // optelseifs
      case 66: // varlist
      case 68: // explist
      case 73: // optexpliste
      case 80: // optexplist
      case 87: // fieldrep
        value.template destroy< std::list<Node*> > ();
        break;

      case 70: // optparlist
      case 71: // parlist
      case 72: // namelist
        value.template destroy< std::list<std::string> > ();
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
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 54: // block
      case 55: // chunk
      case 56: // chunkrep
      case 57: // statement
      case 58: // if
      case 61: // optelse
      case 62: // laststatement
      case 67: // var
      case 69: // exp
      case 74: // optexpc
      case 75: // functioncall
      case 76: // args
      case 77: // function
      case 78: // funcbody
      case 79: // prefixexp
      case 83: // tableconstructor
      case 84: // optfieldlist
      case 85: // fieldlist
      case 86: // field
      case 90: // operator
        value.move< Node* > (s.value);
        break;

      case 59: // elseifs
      case 60: // optelseifs
      case 66: // varlist
      case 68: // explist
      case 73: // optexpliste
      case 80: // optexplist
      case 87: // fieldrep
        value.move< std::list<Node*> > (s.value);
        break;

      case 70: // optparlist
      case 71: // parlist
      case 72: // namelist
        value.move< std::list<std::string> > (s.value);
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
        value.move< std::string > (s.value);
        break;

      default:
        break;
    }

  }

  // by_type.
  inline
  parser::by_type::by_type ()
     : type (empty)
  {}

  inline
  parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.type = empty;
  }

  inline
  int
  parser::by_type::type_get () const
  {
    return type;
  }

  inline
  parser::token_type
  parser::by_type::token () const
  {
    // YYTOKNUM[NUM] -- (External) token number corresponding to the
    // (internal) symbol number NUM (which must be that of a token).  */
    static
    const unsigned short int
    yytoken_number_[] =
    {
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
    };
    return static_cast<token_type> (yytoken_number_[type]);
  }
  // Implementation of make_symbol for each symbol type.
  parser::symbol_type
  parser::make_EOFFF ()
  {
    return symbol_type (token::EOFFF);

  }

  parser::symbol_type
  parser::make_NAME (const std::string& v)
  {
    return symbol_type (token::NAME, v);

  }

  parser::symbol_type
  parser::make_STRING (const std::string& v)
  {
    return symbol_type (token::STRING, v);

  }

  parser::symbol_type
  parser::make_NUMBER (const std::string& v)
  {
    return symbol_type (token::NUMBER, v);

  }

  parser::symbol_type
  parser::make_AND (const std::string& v)
  {
    return symbol_type (token::AND, v);

  }

  parser::symbol_type
  parser::make_BREAK (const std::string& v)
  {
    return symbol_type (token::BREAK, v);

  }

  parser::symbol_type
  parser::make_DO (const std::string& v)
  {
    return symbol_type (token::DO, v);

  }

  parser::symbol_type
  parser::make_ELSE (const std::string& v)
  {
    return symbol_type (token::ELSE, v);

  }

  parser::symbol_type
  parser::make_ELSEIF (const std::string& v)
  {
    return symbol_type (token::ELSEIF, v);

  }

  parser::symbol_type
  parser::make_END (const std::string& v)
  {
    return symbol_type (token::END, v);

  }

  parser::symbol_type
  parser::make_FALSE (const std::string& v)
  {
    return symbol_type (token::FALSE, v);

  }

  parser::symbol_type
  parser::make_FOR (const std::string& v)
  {
    return symbol_type (token::FOR, v);

  }

  parser::symbol_type
  parser::make_FUNCTION (const std::string& v)
  {
    return symbol_type (token::FUNCTION, v);

  }

  parser::symbol_type
  parser::make_IF (const std::string& v)
  {
    return symbol_type (token::IF, v);

  }

  parser::symbol_type
  parser::make_IN (const std::string& v)
  {
    return symbol_type (token::IN, v);

  }

  parser::symbol_type
  parser::make_LOCAL (const std::string& v)
  {
    return symbol_type (token::LOCAL, v);

  }

  parser::symbol_type
  parser::make_NIL (const std::string& v)
  {
    return symbol_type (token::NIL, v);

  }

  parser::symbol_type
  parser::make_NOT (const std::string& v)
  {
    return symbol_type (token::NOT, v);

  }

  parser::symbol_type
  parser::make_OR (const std::string& v)
  {
    return symbol_type (token::OR, v);

  }

  parser::symbol_type
  parser::make_REPEAT (const std::string& v)
  {
    return symbol_type (token::REPEAT, v);

  }

  parser::symbol_type
  parser::make_RETURN (const std::string& v)
  {
    return symbol_type (token::RETURN, v);

  }

  parser::symbol_type
  parser::make_THEN (const std::string& v)
  {
    return symbol_type (token::THEN, v);

  }

  parser::symbol_type
  parser::make_TRUE (const std::string& v)
  {
    return symbol_type (token::TRUE, v);

  }

  parser::symbol_type
  parser::make_UNTIL (const std::string& v)
  {
    return symbol_type (token::UNTIL, v);

  }

  parser::symbol_type
  parser::make_WHILE (const std::string& v)
  {
    return symbol_type (token::WHILE, v);

  }

  parser::symbol_type
  parser::make_PARANTHESIS_L (const std::string& v)
  {
    return symbol_type (token::PARANTHESIS_L, v);

  }

  parser::symbol_type
  parser::make_PARANTHESIS_R (const std::string& v)
  {
    return symbol_type (token::PARANTHESIS_R, v);

  }

  parser::symbol_type
  parser::make_SQUARE_R (const std::string& v)
  {
    return symbol_type (token::SQUARE_R, v);

  }

  parser::symbol_type
  parser::make_SQUARE_L (const std::string& v)
  {
    return symbol_type (token::SQUARE_L, v);

  }

  parser::symbol_type
  parser::make_BRACES_R (const std::string& v)
  {
    return symbol_type (token::BRACES_R, v);

  }

  parser::symbol_type
  parser::make_BRACES_L (const std::string& v)
  {
    return symbol_type (token::BRACES_L, v);

  }

  parser::symbol_type
  parser::make_PLUS (const std::string& v)
  {
    return symbol_type (token::PLUS, v);

  }

  parser::symbol_type
  parser::make_MINUS (const std::string& v)
  {
    return symbol_type (token::MINUS, v);

  }

  parser::symbol_type
  parser::make_MULTI (const std::string& v)
  {
    return symbol_type (token::MULTI, v);

  }

  parser::symbol_type
  parser::make_DIVISION (const std::string& v)
  {
    return symbol_type (token::DIVISION, v);

  }

  parser::symbol_type
  parser::make_MODULUS (const std::string& v)
  {
    return symbol_type (token::MODULUS, v);

  }

  parser::symbol_type
  parser::make_POWER (const std::string& v)
  {
    return symbol_type (token::POWER, v);

  }

  parser::symbol_type
  parser::make_HASH (const std::string& v)
  {
    return symbol_type (token::HASH, v);

  }

  parser::symbol_type
  parser::make_LESSER (const std::string& v)
  {
    return symbol_type (token::LESSER, v);

  }

  parser::symbol_type
  parser::make_GREATER (const std::string& v)
  {
    return symbol_type (token::GREATER, v);

  }

  parser::symbol_type
  parser::make_COLON (const std::string& v)
  {
    return symbol_type (token::COLON, v);

  }

  parser::symbol_type
  parser::make_DOT (const std::string& v)
  {
    return symbol_type (token::DOT, v);

  }

  parser::symbol_type
  parser::make_ASSIGN (const std::string& v)
  {
    return symbol_type (token::ASSIGN, v);

  }

  parser::symbol_type
  parser::make_COMMA (const std::string& v)
  {
    return symbol_type (token::COMMA, v);

  }

  parser::symbol_type
  parser::make_SEMICOLON (const std::string& v)
  {
    return symbol_type (token::SEMICOLON, v);

  }

  parser::symbol_type
  parser::make_EQUALS (const std::string& v)
  {
    return symbol_type (token::EQUALS, v);

  }

  parser::symbol_type
  parser::make_NOTEQUALS (const std::string& v)
  {
    return symbol_type (token::NOTEQUALS, v);

  }

  parser::symbol_type
  parser::make_GREATERTHANEQUAL (const std::string& v)
  {
    return symbol_type (token::GREATERTHANEQUAL, v);

  }

  parser::symbol_type
  parser::make_LESSERTHANEQUAL (const std::string& v)
  {
    return symbol_type (token::LESSERTHANEQUAL, v);

  }

  parser::symbol_type
  parser::make_CONCAT (const std::string& v)
  {
    return symbol_type (token::CONCAT, v);

  }

  parser::symbol_type
  parser::make_VARARGS (const std::string& v)
  {
    return symbol_type (token::VARARGS, v);

  }



} // yy
#line 1847 "binary.tab.h" // lalr1.cc:371




#endif // !YY_YY_BINARY_TAB_H_INCLUDED
