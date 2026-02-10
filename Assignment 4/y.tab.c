/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "22101848_22101069.y"


#include "symbol_table.h"
#include "ast.h"
#include "three_addr_code.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

/* Type definition for all grammar symbols */
#define YYSTYPE symbol_info*

extern FILE *yyin;
int yyparse(void);
int yylex(void);
extern YYSTYPE yylval;

symbol_table *sym_tbl = new symbol_table();
ProgramNode* program_root = new ProgramNode();

int line_count = 1;
int error_count = 0;
ofstream log_file, error_file, code_file;

string variable_list=""; //for variable declaration tracking
vector<string>parameter_types; //for parameter types in func dec and def
vector<string>parameter_names; //for func def parameter names	
vector<string>argument_types; //to store types of function arguments

int inside_function = 0; //is compound statement inside function definition

string return_data_type, function_name, function_return_type;

void yyerror(char *s)
{
	log_file<<"At line "<<line_count<<" "<<s<<endl<<endl;
	error_file<<"At line "<<line_count<<" "<<s<<endl<<endl;
	error_count++;
	
	variable_list = "";
	parameter_types.clear();
	parameter_names.clear();
	argument_types.clear();
	inside_function = 0;
	return_data_type = "";
	function_name = "";
	function_return_type = "";
}


#line 124 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IF = 258,                      /* IF  */
    ELSE = 259,                    /* ELSE  */
    FOR = 260,                     /* FOR  */
    WHILE = 261,                   /* WHILE  */
    DO = 262,                      /* DO  */
    BREAK = 263,                   /* BREAK  */
    INT = 264,                     /* INT  */
    CHAR = 265,                    /* CHAR  */
    FLOAT = 266,                   /* FLOAT  */
    DOUBLE = 267,                  /* DOUBLE  */
    VOID = 268,                    /* VOID  */
    RETURN = 269,                  /* RETURN  */
    SWITCH = 270,                  /* SWITCH  */
    CASE = 271,                    /* CASE  */
    DEFAULT = 272,                 /* DEFAULT  */
    CONTINUE = 273,                /* CONTINUE  */
    PRINTLN = 274,                 /* PRINTLN  */
    ADDOP = 275,                   /* ADDOP  */
    MULOP = 276,                   /* MULOP  */
    INCOP = 277,                   /* INCOP  */
    DECOP = 278,                   /* DECOP  */
    RELOP = 279,                   /* RELOP  */
    ASSIGNOP = 280,                /* ASSIGNOP  */
    LOGICOP = 281,                 /* LOGICOP  */
    NOT = 282,                     /* NOT  */
    LPAREN = 283,                  /* LPAREN  */
    RPAREN = 284,                  /* RPAREN  */
    LCURL = 285,                   /* LCURL  */
    RCURL = 286,                   /* RCURL  */
    LTHIRD = 287,                  /* LTHIRD  */
    RTHIRD = 288,                  /* RTHIRD  */
    COMMA = 289,                   /* COMMA  */
    SEMICOLON = 290,               /* SEMICOLON  */
    CONST_INT = 291,               /* CONST_INT  */
    CONST_FLOAT = 292,             /* CONST_FLOAT  */
    ID = 293,                      /* ID  */
    LOWER_THAN_ELSE = 294          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define DO 262
#define BREAK 263
#define INT 264
#define CHAR 265
#define FLOAT 266
#define DOUBLE 267
#define VOID 268
#define RETURN 269
#define SWITCH 270
#define CASE 271
#define DEFAULT 272
#define CONTINUE 273
#define PRINTLN 274
#define ADDOP 275
#define MULOP 276
#define INCOP 277
#define DECOP 278
#define RELOP 279
#define ASSIGNOP 280
#define LOGICOP 281
#define NOT 282
#define LPAREN 283
#define RPAREN 284
#define LCURL 285
#define RCURL 286
#define LTHIRD 287
#define RTHIRD 288
#define COMMA 289
#define SEMICOLON 290
#define CONST_INT 291
#define CONST_FLOAT 292
#define ID 293
#define LOWER_THAN_ELSE 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_FOR = 5,                        /* FOR  */
  YYSYMBOL_WHILE = 6,                      /* WHILE  */
  YYSYMBOL_DO = 7,                         /* DO  */
  YYSYMBOL_BREAK = 8,                      /* BREAK  */
  YYSYMBOL_INT = 9,                        /* INT  */
  YYSYMBOL_CHAR = 10,                      /* CHAR  */
  YYSYMBOL_FLOAT = 11,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 12,                    /* DOUBLE  */
  YYSYMBOL_VOID = 13,                      /* VOID  */
  YYSYMBOL_RETURN = 14,                    /* RETURN  */
  YYSYMBOL_SWITCH = 15,                    /* SWITCH  */
  YYSYMBOL_CASE = 16,                      /* CASE  */
  YYSYMBOL_DEFAULT = 17,                   /* DEFAULT  */
  YYSYMBOL_CONTINUE = 18,                  /* CONTINUE  */
  YYSYMBOL_PRINTLN = 19,                   /* PRINTLN  */
  YYSYMBOL_ADDOP = 20,                     /* ADDOP  */
  YYSYMBOL_MULOP = 21,                     /* MULOP  */
  YYSYMBOL_INCOP = 22,                     /* INCOP  */
  YYSYMBOL_DECOP = 23,                     /* DECOP  */
  YYSYMBOL_RELOP = 24,                     /* RELOP  */
  YYSYMBOL_ASSIGNOP = 25,                  /* ASSIGNOP  */
  YYSYMBOL_LOGICOP = 26,                   /* LOGICOP  */
  YYSYMBOL_NOT = 27,                       /* NOT  */
  YYSYMBOL_LPAREN = 28,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 29,                    /* RPAREN  */
  YYSYMBOL_LCURL = 30,                     /* LCURL  */
  YYSYMBOL_RCURL = 31,                     /* RCURL  */
  YYSYMBOL_LTHIRD = 32,                    /* LTHIRD  */
  YYSYMBOL_RTHIRD = 33,                    /* RTHIRD  */
  YYSYMBOL_COMMA = 34,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 35,                 /* SEMICOLON  */
  YYSYMBOL_CONST_INT = 36,                 /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 37,               /* CONST_FLOAT  */
  YYSYMBOL_ID = 38,                        /* ID  */
  YYSYMBOL_LOWER_THAN_ELSE = 39,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_start = 41,                     /* start  */
  YYSYMBOL_program = 42,                   /* program  */
  YYSYMBOL_unit = 43,                      /* unit  */
  YYSYMBOL_func_definition = 44,           /* func_definition  */
  YYSYMBOL_enter_func = 45,                /* enter_func  */
  YYSYMBOL_parameter_list = 46,            /* parameter_list  */
  YYSYMBOL_compound_statement = 47,        /* compound_statement  */
  YYSYMBOL_enter_scope_variables = 48,     /* enter_scope_variables  */
  YYSYMBOL_var_declaration = 49,           /* var_declaration  */
  YYSYMBOL_type_specifier = 50,            /* type_specifier  */
  YYSYMBOL_declaration_list = 51,          /* declaration_list  */
  YYSYMBOL_id_name = 52,                   /* id_name  */
  YYSYMBOL_statements = 53,                /* statements  */
  YYSYMBOL_statement = 54,                 /* statement  */
  YYSYMBOL_expression_statement = 55,      /* expression_statement  */
  YYSYMBOL_variable = 56,                  /* variable  */
  YYSYMBOL_expression = 57,                /* expression  */
  YYSYMBOL_logic_expression = 58,          /* logic_expression  */
  YYSYMBOL_rel_expression = 59,            /* rel_expression  */
  YYSYMBOL_simple_expression = 60,         /* simple_expression  */
  YYSYMBOL_term = 61,                      /* term  */
  YYSYMBOL_unary_expression = 62,          /* unary_expression  */
  YYSYMBOL_factor = 63,                    /* factor  */
  YYSYMBOL_argument_list = 64,             /* argument_list  */
  YYSYMBOL_arguments = 65                  /* arguments  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   178

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  121

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    62,    62,    75,    97,   113,   121,   129,   135,   167,
     195,   237,   254,   264,   274,   286,   299,   315,   339,   409,
     417,   425,   435,   445,   456,   464,   474,   482,   496,   510,
     516,   523,   531,   539,   547,   555,   571,   585,   600,   614,
     635,   648,   659,   672,   717,   759,   768,   808,   817,   852,
     861,   896,   906,   946,   956,  1031,  1056,  1081,  1092,  1101,
    1175,  1184,  1196,  1208,  1224,  1242,  1250,  1261,  1284
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "FOR",
  "WHILE", "DO", "BREAK", "INT", "CHAR", "FLOAT", "DOUBLE", "VOID",
  "RETURN", "SWITCH", "CASE", "DEFAULT", "CONTINUE", "PRINTLN", "ADDOP",
  "MULOP", "INCOP", "DECOP", "RELOP", "ASSIGNOP", "LOGICOP", "NOT",
  "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "COMMA",
  "SEMICOLON", "CONST_INT", "CONST_FLOAT", "ID", "LOWER_THAN_ELSE",
  "$accept", "start", "program", "unit", "func_definition", "enter_func",
  "parameter_list", "compound_statement", "enter_scope_variables",
  "var_declaration", "type_specifier", "declaration_list", "id_name",
  "statements", "statement", "expression_statement", "variable",
  "expression", "logic_expression", "rel_expression", "simple_expression",
  "term", "unary_expression", "factor", "argument_list", "arguments", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-72)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      45,   -72,   -72,   -72,   -72,    28,    44,   -72,   -72,   -72,
      11,   -72,   -72,   -72,   -14,    55,    11,   -72,     3,    23,
      29,   -72,   -10,    22,    35,    37,    48,   -72,   103,   -72,
     -72,    65,   -72,   -72,    48,    62,   -72,    66,   -72,   -72,
     -72,    78,    80,    83,    -2,    93,    -2,    -2,    -2,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,    56,   104,   -72,   -72,
      97,    90,   -72,   100,    75,   106,   -72,   -72,    -2,    54,
      -2,    94,    11,    25,   -72,   -72,    99,    -2,    -2,   -72,
     -72,   -72,   -72,   -72,    -2,   -72,    -2,    -2,    -2,    -2,
     101,    54,   107,   -72,   108,   -72,   -72,   109,   110,   114,
     -72,   -72,   106,   113,   -72,   140,    -2,   140,   115,   -72,
      -2,   -72,   144,   123,   -72,   -72,   -72,   140,   140,   -72,
     -72
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     7,    19,    20,    21,     0,     0,     4,     6,     5,
       0,     1,     3,    26,     0,    24,     0,    18,     0,     0,
      22,    10,     0,    14,     0,     0,     0,    10,     0,    13,
      25,     0,    17,     9,     0,    12,    23,     0,     8,    11,
      29,     0,     0,     0,     0,     0,     0,     0,     0,    16,
      41,    61,    62,    32,    34,    31,    43,     0,    27,    33,
      58,     0,    45,    47,    49,    51,    53,    57,     0,     0,
       0,     0,     0,    58,    55,    56,     0,    66,     0,    30,
      15,    28,    63,    64,     0,    42,     0,     0,     0,     0,
       0,     0,     0,    40,     0,    60,    68,     0,    65,     0,
      46,    48,    52,    50,    54,     0,     0,     0,     0,    59,
       0,    44,    36,     0,    38,    39,    67,     0,     0,    37,
      35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -72,   -72,   -72,   149,    17,   129,   -72,    -4,   -72,    70,
     -13,   -72,    -6,   -72,   -55,   -58,   -46,   -41,   -71,    71,
      73,    76,   -38,   -72,   -72,   -72
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,     7,    53,    26,    22,    54,    37,    55,
      10,    14,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    97,    98
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      73,    73,    81,    71,    15,    23,    96,    76,    74,    75,
      20,    91,     2,   100,     3,    35,     4,     8,    46,    27,
      16,    17,    33,     8,    28,    47,    48,    90,    11,    92,
      38,    73,    21,   106,    51,    52,    13,    99,    73,   116,
      73,    73,    73,    73,    -2,     1,     1,    82,    83,    13,
     112,   104,   114,     2,     2,     3,     3,     4,     4,    24,
      29,    25,   119,   120,    73,   113,    94,    40,    30,    41,
       9,    42,    43,    31,    46,     2,     9,     3,    32,     4,
      44,    47,    48,    18,    77,    45,    46,    19,    78,    50,
      51,    52,    13,    47,    48,    87,    32,    49,    36,    88,
      39,    50,    51,    52,    13,    79,    68,    41,    69,    42,
      43,    70,     2,     2,     3,     3,     4,     4,    44,    82,
      83,    72,    84,    45,    46,    85,    86,    89,    95,    93,
     105,    47,    48,    87,    32,    80,   107,   108,   109,    50,
      51,    52,    13,    41,   110,    42,    43,   111,   117,     2,
     115,     3,   118,     4,    44,    12,    34,   101,     0,    45,
      46,   103,     0,   102,     0,     0,     0,    47,    48,     0,
      32,     0,     0,     0,     0,    50,    51,    52,    13
};

static const yytype_int8 yycheck[] =
{
      46,    47,    57,    44,    10,    18,    77,    48,    46,    47,
      16,    69,     9,    84,    11,    28,    13,     0,    20,    29,
      34,    35,    26,     6,    34,    27,    28,    68,     0,    70,
      34,    77,    29,    91,    36,    37,    38,    78,    84,   110,
      86,    87,    88,    89,     0,     1,     1,    22,    23,    38,
     105,    89,   107,     9,     9,    11,    11,    13,    13,    36,
      38,    32,   117,   118,   110,   106,    72,     1,    33,     3,
       0,     5,     6,    36,    20,     9,     6,    11,    30,    13,
      14,    27,    28,    28,    28,    19,    20,    32,    32,    35,
      36,    37,    38,    27,    28,    20,    30,    31,    33,    24,
      38,    35,    36,    37,    38,     1,    28,     3,    28,     5,
       6,    28,     9,     9,    11,    11,    13,    13,    14,    22,
      23,    28,    25,    19,    20,    35,    26,    21,    29,    35,
      29,    27,    28,    20,    30,    31,    29,    29,    29,    35,
      36,    37,    38,     3,    34,     5,     6,    33,     4,     9,
      35,    11,    29,    13,    14,     6,    27,    86,    -1,    19,
      20,    88,    -1,    87,    -1,    -1,    -1,    27,    28,    -1,
      30,    -1,    -1,    -1,    -1,    35,    36,    37,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     9,    11,    13,    41,    42,    43,    44,    49,
      50,     0,    43,    38,    51,    52,    34,    35,    28,    32,
      52,    29,    46,    50,    36,    32,    45,    29,    34,    38,
      33,    36,    30,    47,    45,    50,    33,    48,    47,    38,
       1,     3,     5,     6,    14,    19,    20,    27,    28,    31,
      35,    36,    37,    44,    47,    49,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    28,    28,
      28,    57,    28,    56,    62,    62,    57,    28,    32,     1,
      31,    54,    22,    23,    25,    35,    26,    20,    24,    21,
      57,    55,    57,    35,    52,    29,    58,    64,    65,    57,
      58,    59,    61,    60,    62,    29,    55,    29,    29,    29,
      34,    33,    54,    57,    54,    35,    58,     4,    29,    54,
      54
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    44,    44,
      45,    46,    46,    46,    46,    47,    47,    48,    49,    50,
      50,    50,    51,    51,    51,    51,    52,    53,    53,    53,
      53,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    55,    55,    56,    56,    57,    57,    58,    58,    59,
      59,    60,    60,    61,    61,    62,    62,    62,    63,    63,
      63,    63,    63,    63,    63,    64,    64,    65,    65
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     7,     6,
       0,     4,     3,     2,     1,     4,     3,     0,     3,     1,
       1,     1,     3,     6,     1,     4,     1,     1,     2,     1,
       2,     1,     1,     1,     1,     7,     5,     7,     5,     5,
       3,     1,     2,     1,     4,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     2,     2,     1,     1,     4,
       3,     1,     1,     2,     2,     1,     0,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* start: program  */
#line 63 "22101848_22101069.y"
        {
		log_file<<"At line no: "<<line_count<<" start : program "<<endl<<endl;
		log_file<<"Symbol Table"<<endl<<endl;
		
		sym_tbl->Print_all_scope(log_file);
		
		yyval = yyvsp[0];
		// Set root of AST to the program node
		program_root = (ProgramNode*)yyvsp[0]->get_ast_node();
	}
#line 1395 "y.tab.c"
    break;

  case 3: /* program: program unit  */
#line 76 "22101848_22101069.y"
        {
		log_file<<"At line no: "<<line_count<<" program : program unit "<<endl<<endl;
		log_file<<yyvsp[-1]->getname()+"\n"+yyvsp[0]->getname()<<endl<<endl;
		
		yyval = new symbol_info(yyvsp[-1]->getname()+"\n"+yyvsp[0]->getname(),"program");
		
		// Build/update AST node for program
		ProgramNode* prog_node;
		if(yyvsp[-1]->get_ast_node()) {
			prog_node = (ProgramNode*)yyvsp[-1]->get_ast_node();
		} else {
			prog_node = new ProgramNode();
		}
		
		// Append the unit to the program
		if(yyvsp[0]->get_ast_node()) {
			prog_node->add_unit(yyvsp[0]->get_ast_node());
		}
		
		yyval->set_ast_node(prog_node);
	}
#line 1421 "y.tab.c"
    break;

  case 4: /* program: unit  */
#line 98 "22101848_22101069.y"
        {
		log_file<<"At line no: "<<line_count<<" program : unit "<<endl<<endl;
		log_file<<yyvsp[0]->getname()<<endl<<endl;
		
		yyval = new symbol_info(yyvsp[0]->getname(),"program");
		
		// Build AST node for program with a single unit
		ProgramNode* prog_node = new ProgramNode();
		if(yyvsp[0]->get_ast_node()) {
			prog_node->add_unit(yyvsp[0]->get_ast_node());
		}
		yyval->set_ast_node(prog_node);
	}
#line 1439 "y.tab.c"
    break;

  case 5: /* unit: var_declaration  */
#line 114 "22101848_22101069.y"
         {
		log_file<<"At line no: "<<line_count<<" unit : var_declaration "<<endl<<endl;
		log_file<<yyvsp[0]->getname()<<endl<<endl;
		
		yyval = new symbol_info(yyvsp[0]->getname(),"unit");
		yyval->set_ast_node(yyvsp[0]->get_ast_node());
	 }
#line 1451 "y.tab.c"
    break;

  case 6: /* unit: func_definition  */
#line 122 "22101848_22101069.y"
     {
		log_file<<"At line no: "<<line_count<<" unit : func_definition "<<endl<<endl;
		log_file<<yyvsp[0]->getname()<<endl<<endl;
		
		yyval = new symbol_info(yyvsp[0]->getname(),"unit");
		yyval->set_ast_node(yyvsp[0]->get_ast_node());
	 }
#line 1463 "y.tab.c"
    break;

  case 7: /* unit: error  */
#line 130 "22101848_22101069.y"
         {
	 	yyval = new symbol_info("","unit");
	 }
#line 1471 "y.tab.c"
    break;

  case 8: /* func_definition: type_specifier id_name LPAREN parameter_list RPAREN enter_func compound_statement  */
#line 136 "22101848_22101069.y"
                {	
			log_file<<"At line no: "<<line_count<<" func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement "<<endl<<endl;
			log_file<<yyvsp[-6]->getname()<<" "<<yyvsp[-5]->getname()<<"("+yyvsp[-3]->getname()+")\n"<<yyvsp[0]->getname()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-6]->getname()+" "+yyvsp[-5]->getname()+"("+yyvsp[-3]->getname()+")\n"+yyvsp[0]->getname(),"func_def");	
			
			// Build AST node for function definition
			FuncDeclNode* func_node = new FuncDeclNode(yyvsp[-6]->getname(), yyvsp[-5]->getname());
			
			// Add function parameters
			for(int i = 0; i < parameter_types.size(); i++) {
				if(parameter_names[i] != "_null_") {
					func_node->add_param(parameter_types[i], parameter_names[i]);
				}
			}
			
			// Set function body
			if(yyvsp[0]->get_ast_node()) {
				func_node->set_body((BlockNode*)yyvsp[0]->get_ast_node());
			}
			
			yyval->set_ast_node(func_node);
			
			if(sym_tbl->getID()!=1)
			{
				sym_tbl->Remove_from_table(yyvsp[-5]->getname());
			}
			
			parameter_types.clear();
			parameter_names.clear();	
		}
#line 1507 "y.tab.c"
    break;

  case 9: /* func_definition: type_specifier id_name LPAREN RPAREN enter_func compound_statement  */
#line 168 "22101848_22101069.y"
                {
			
			log_file<<"At line no: "<<line_count<<" func_definition : type_specifier ID LPAREN RPAREN compound_statement "<<endl<<endl;
			log_file<<yyvsp[-5]->getname()<<" "<<yyvsp[-4]->getname()<<"()\n"<<yyvsp[0]->getname()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-5]->getname()+" "+yyvsp[-4]->getname()+"()\n"+yyvsp[0]->getname(),"func_def");	
			
			// Build AST node for function definition
			FuncDeclNode* func_node = new FuncDeclNode(yyvsp[-5]->getname(), yyvsp[-4]->getname());
			
			// Set function body
			if(yyvsp[0]->get_ast_node()) {
				func_node->set_body((BlockNode*)yyvsp[0]->get_ast_node());
			}
			
			yyval->set_ast_node(func_node);
			
			if(sym_tbl->getID()!=1)
			{
				sym_tbl->Remove_from_table(yyvsp[-4]->getname());
			}
			
			parameter_types.clear();
			parameter_names.clear();	
		}
#line 1537 "y.tab.c"
    break;

  case 10: /* enter_func: %empty  */
#line 195 "22101848_22101069.y"
             {
				//not in global scope check
				
				inside_function=1;//compound statement is coming in function definition. enter parameter variables.
				
				if(parameter_types.size()!=0) //validate parameters
				{
					for(int i = 0; i < parameter_types.size();i++)
					{
						if(parameter_names[i]=="_null_")
						{
							error_file<<"At line no: "<<line_count<<" Parameter "<<i+1<<"'s name not given in function definition of "<<function_name<<endl<<endl;
							log_file<<"At line no: "<<line_count<<" Parameter "<<i+1<<"'s name not given in function definition of "<<function_name<<endl<<endl;
							error_count++;
						}
					}
				}
				
				//check if function already exists and perform error checking
				if(sym_tbl->Insert_in_table(function_name,"ID"))
				{
					(sym_tbl->Lookup_in_table(function_name))->setvartype(function_return_type);
					(sym_tbl->Lookup_in_table(function_name))->setidtype("func_def");
					(sym_tbl->Lookup_in_table(function_name))->setparamlist(parameter_types);//set parameters
					(sym_tbl->Lookup_in_table(function_name))->setparamname(parameter_names);
				}
				else
				{
					error_file<<"At line no: "<<line_count<<" Multiple declaration of function "<<function_name<<endl<<endl;
					log_file<<"At line no: "<<line_count<<" Multiple declaration of function "<<function_name<<endl<<endl;
					error_count++;
				}
					
				if((sym_tbl->Lookup_in_table(function_name))->getvartype() != function_return_type)
				{
					error_file<<"At line no: "<<line_count<<" Return type mismatch of function "<<function_name<<endl<<endl;
					log_file<<"At line no: "<<line_count<<" Return type mismatch of function "<<function_name<<endl<<endl;
					error_count++;
				}
            }
#line 1582 "y.tab.c"
    break;

  case 11: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 238 "22101848_22101069.y"
                {
			log_file<<"At line no: "<<line_count<<" parameter_list : parameter_list COMMA type_specifier ID "<<endl<<endl;
			log_file<<yyvsp[-3]->getname()+","+yyvsp[-1]->getname()+" "+yyvsp[0]->getname()<<endl<<endl;
					
			yyval = new symbol_info(yyvsp[-3]->getname()+","+yyvsp[-1]->getname()+" "+yyvsp[0]->getname(),"param_list");
			
			if(count(parameter_names.begin(),parameter_names.end(),yyvsp[0]->getname()))
			{
				error_file<<"At line no: "<<line_count<<" Multiple declaration of variable "<<yyvsp[0]->getname()<<" in parameter of "<<function_name<<endl<<endl;
				log_file<<"At line no: "<<line_count<<" Multiple declaration of variable "<<yyvsp[0]->getname()<<" in parameter of "<<function_name<<endl<<endl;
				error_count++;
			}
			
			parameter_types.push_back(yyvsp[-1]->getname());
			parameter_names.push_back(yyvsp[0]->getname());
		}
#line 1603 "y.tab.c"
    break;

  case 12: /* parameter_list: parameter_list COMMA type_specifier  */
#line 255 "22101848_22101069.y"
                {
			log_file<<"At line no: "<<line_count<<" parameter_list : parameter_list COMMA type_specifier "<<endl<<endl;
			log_file<<yyvsp[-2]->getname()+","+yyvsp[0]->getname()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-2]->getname()+","+yyvsp[0]->getname(),"param_list");
			
			parameter_types.push_back(yyvsp[0]->getname());
			parameter_names.push_back("_null_");
		}
#line 1617 "y.tab.c"
    break;

  case 13: /* parameter_list: type_specifier ID  */
#line 265 "22101848_22101069.y"
                {
			log_file<<"At line no: "<<line_count<<" parameter_list : type_specifier ID "<<endl<<endl;
			log_file<<yyvsp[-1]->getname()<<" "<<yyvsp[0]->getname()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-1]->getname()+" "+yyvsp[0]->getname(),"param_list");
			
			parameter_types.push_back(yyvsp[-1]->getname());
			parameter_names.push_back(yyvsp[0]->getname());
		}
#line 1631 "y.tab.c"
    break;

  case 14: /* parameter_list: type_specifier  */
#line 275 "22101848_22101069.y"
                {
			log_file<<"At line no: "<<line_count<<" parameter_list : type_specifier "<<endl<<endl;
			log_file<<yyvsp[0]->getname()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->getname(),"param_list");
			
			parameter_types.push_back(yyvsp[0]->getname());
			parameter_names.push_back("_null_");
		}
#line 1645 "y.tab.c"
    break;

  case 15: /* compound_statement: LCURL enter_scope_variables statements RCURL  */
#line 287 "22101848_22101069.y"
                        { 
 		    	log_file<<"At line no: "<<line_count<<" compound_statement : LCURL statements RCURL "<<endl<<endl;
				log_file<<"{\n"+yyvsp[-1]->getname()+"\n}"<<endl<<endl;
				
				yyval = new symbol_info("{\n"+yyvsp[-1]->getname()+"\n}","comp_stmnt");
				
				// Set AST node for compound statement
				yyval->set_ast_node(yyvsp[-1]->get_ast_node());
				
				sym_tbl->Print_all_scope(log_file);
			    sym_tbl->exit_scope(log_file);
 		    }
#line 1662 "y.tab.c"
    break;

  case 16: /* compound_statement: LCURL enter_scope_variables RCURL  */
#line 300 "22101848_22101069.y"
                    { 
 		    	log_file<<"At line no: "<<line_count<<" compound_statement : LCURL RCURL "<<endl<<endl;
				log_file<<"{\n}"<<endl<<endl;
				
				yyval = new symbol_info("{\n}","comp_stmnt");
				
				// Build empty block node
				BlockNode* empty_block = new BlockNode();
				yyval->set_ast_node(empty_block);
				
				sym_tbl->Print_all_scope(log_file);
			    sym_tbl->exit_scope(log_file);
 		    }
#line 1680 "y.tab.c"
    break;

  case 17: /* enter_scope_variables: %empty  */
#line 315 "22101848_22101069.y"
                        {
				sym_tbl->enter_scope(log_file);
				
				if(inside_function == 1)
				{
					if(parameter_names.size()!=0)
					{
						for(int i = 0; i < parameter_names.size(); i++)
						{
							if(parameter_names[i]!="_null_")
							{
								sym_tbl->Insert_in_table(parameter_names[i],"ID");
								(sym_tbl->Lookup_in_table(parameter_names[i]))->setidtype("var");
								(sym_tbl->Lookup_in_table(parameter_names[i]))->setvartype(parameter_types[i]);
							}
							
						}
					}
					inside_function=0; //variables entered. if more compound statements come in func definitions, don't re-enter.
				}
				
			}
#line 1707 "y.tab.c"
    break;

  case 18: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 340 "22101848_22101069.y"
                 {
			log_file<<"At line no: "<<line_count<<" var_declaration : type_specifier declaration_list SEMICOLON "<<endl<<endl;
			log_file<<yyvsp[-2]->getname()<<" "<<variable_list<<";"<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-2]->getname()+" "+variable_list+";","var_dec");
			
			if(yyvsp[-2]->getname()=="void")
			{
				error_file<<"At line no: "<<line_count<<" variable type can not be void "<<endl<<endl;
				log_file<<"At line no: "<<line_count<<" variable type can not be void "<<endl<<endl;
				error_count++;
				yyvsp[-2] = new symbol_info("error","type"); //variable declared void so pass error instead
			}
			
			// Build AST node for variable declaration
			DeclNode* declaration_node = new DeclNode(yyvsp[-2]->getname());
			
			// Parse variable_list to add variables to the declaration node
			stringstream var_stream(variable_list);
			string var_identifier;
			
			while(getline(var_stream,var_identifier,','))
			{
				if(var_identifier.find("[") == string::npos) // regular variable
				{
					declaration_node->add_var(var_identifier, 0);
					
					if(sym_tbl->Insert_in_table(var_identifier,"ID"))
					{
						(sym_tbl->Lookup_in_table(var_identifier))->setvartype(yyvsp[-2]->getname());
						(sym_tbl->Lookup_in_table(var_identifier))->setidtype("var");
					}
					else
					{
						error_file<<"At line no: "<<line_count<<" Multiple declaration of variable "<<var_identifier<<endl<<endl;
						log_file<<"At line no: "<<line_count<<" Multiple declaration of variable "<<var_identifier<<endl<<endl;
						error_count++;
					}
				}
				else // array variable
				{
					stringstream array_stream(var_identifier);
					string array_name, array_dimension;
					
					getline(array_stream,array_name,'['); // extract array name
					getline(array_stream,array_dimension,']'); // extract array size
					
					declaration_node->add_var(array_name, stoi(array_dimension));
					
					if(sym_tbl->Insert_in_table(array_name,"ID"))
					{
						(sym_tbl->Lookup_in_table(array_name))->setvartype(yyvsp[-2]->getname());
						(sym_tbl->Lookup_in_table(array_name))->setidtype("array");
						(sym_tbl->Lookup_in_table(array_name))->setarraysize(stoi(array_dimension));
					}
					else
					{
						error_file<<"At line no: "<<line_count<<" Multiple declaration of variable "<<array_name<<endl<<endl;
						log_file<<"At line no: "<<line_count<<" Multiple declaration of variable "<<array_name<<endl<<endl;
						error_count++;
					}
				}
			}
			
			yyval->set_ast_node(declaration_node);
			variable_list = "";
		 }
#line 1779 "y.tab.c"
    break;

  case 19: /* type_specifier: INT  */
#line 410 "22101848_22101069.y"
                {
			log_file<<"At line no: "<<line_count<<" type_specifier : INT "<<endl<<endl;
			log_file<<"int"<<endl<<endl;
			
			yyval = new symbol_info("int","type");
			return_data_type = "int";
	    }
#line 1791 "y.tab.c"
    break;

  case 20: /* type_specifier: FLOAT  */
#line 418 "22101848_22101069.y"
                {
			log_file<<"At line no: "<<line_count<<" type_specifier : FLOAT "<<endl<<endl;
			log_file<<"float"<<endl<<endl;
			
			yyval = new symbol_info("float","type");
			return_data_type = "float";
	    }
#line 1803 "y.tab.c"
    break;

  case 21: /* type_specifier: VOID  */
#line 426 "22101848_22101069.y"
                {
			log_file<<"At line no: "<<line_count<<" type_specifier : VOID "<<endl<<endl;
			log_file<<"void"<<endl<<endl;
			
			yyval = new symbol_info("void","type");
			return_data_type = "void";
	    }
#line 1815 "y.tab.c"
    break;

  case 22: /* declaration_list: declaration_list COMMA id_name  */
#line 436 "22101848_22101069.y"
                  {
 		  	string var_name = yyvsp[0]->getname();
 		  	log_file<<"At line no: "<<line_count<<" declaration_list : declaration_list COMMA ID "<<endl<<endl;
 		  	
 		  	variable_list=variable_list+","+var_name;
 		  	
			log_file<<variable_list<<endl<<endl;
			
 		  }
#line 1829 "y.tab.c"
    break;

  case 23: /* declaration_list: declaration_list COMMA id_name LTHIRD CONST_INT RTHIRD  */
#line 446 "22101848_22101069.y"
                  {
 		  	string var_name = yyvsp[-3]->getname();
 		  	string array_size = yyvsp[-1]->getname();
 		  	log_file<<"At line no: "<<line_count<<" declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD "<<endl<<endl;
 		  	
 		  	variable_list=variable_list+","+var_name+"["+array_size+"]";
 		  	
			log_file<<variable_list<<endl<<endl;
			
 		  }
#line 1844 "y.tab.c"
    break;

  case 24: /* declaration_list: id_name  */
#line 457 "22101848_22101069.y"
                  {
 		  	string var_name = yyvsp[0]->getname();
 		  	log_file<<"At line no: "<<line_count<<" declaration_list : ID "<<endl<<endl;
			log_file<<var_name<<endl<<endl;
			
			variable_list+=var_name;
 		  }
#line 1856 "y.tab.c"
    break;

  case 25: /* declaration_list: id_name LTHIRD CONST_INT RTHIRD  */
#line 465 "22101848_22101069.y"
                  {
 		  	string var_name = yyvsp[-3]->getname();
 		  	string array_size = yyvsp[-1]->getname();
 		  	log_file<<"At line no: "<<line_count<<" declaration_list : ID LTHIRD CONST_INT RTHIRD "<<endl<<endl;
			log_file<<var_name+"["+array_size+"]"<<endl<<endl;
			
			variable_list=variable_list+var_name+"["+array_size+"]";
 		  }
#line 1869 "y.tab.c"
    break;

  case 26: /* id_name: ID  */
#line 475 "22101848_22101069.y"
                  {
		   	yyval = new symbol_info(yyvsp[0]->getname(),"ID");
		   	function_name = yyvsp[0]->getname();
		   	function_return_type = return_data_type;
		  }
#line 1879 "y.tab.c"
    break;

  case 27: /* statements: statement  */
#line 483 "22101848_22101069.y"
           {
	    	log_file<<"At line no: "<<line_count<<" statements : statement "<<endl<<endl;
			log_file<<yyvsp[0]->getname()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->getname(),"stmnts");
			
			// Build block for statements
			BlockNode* statement_block = new BlockNode();
			if(yyvsp[0]->get_ast_node()) {
				statement_block->add_statement((StmtNode*)yyvsp[0]->get_ast_node());
			}
			yyval->set_ast_node(statement_block);
	   }
#line 1897 "y.tab.c"
    break;

  case 28: /* statements: statements statement  */
#line 497 "22101848_22101069.y"
           {
	    	log_file<<"At line no: "<<line_count<<" statements : statements statement "<<endl<<endl;
			log_file<<yyvsp[-1]->getname()<<"\n"<<yyvsp[0]->getname()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-1]->getname()+"\n"+yyvsp[0]->getname(),"stmnts");
			
			// Append statement to block
			BlockNode* statement_block = (BlockNode*)yyvsp[-1]->get_ast_node();
			if(yyvsp[0]->get_ast_node()) {
				statement_block->add_statement((StmtNode*)yyvsp[0]->get_ast_node());
			}
			yyval->set_ast_node(statement_block);
	   }
#line 1915 "y.tab.c"
    break;

  case 29: /* statements: error  */
#line 511 "22101848_22101069.y"
           {
	  		yyval = new symbol_info("","stmnts");
			BlockNode* error_block = new BlockNode();
			yyval->set_ast_node(error_block);
	   }
#line 1925 "y.tab.c"
    break;

  case 30: /* statements: statements error  */
#line 517 "22101848_22101069.y"
           {
	   		yyval = new symbol_info(yyvsp[-1]->getname(),"stmnts");
			yyval->set_ast_node(yyvsp[-1]->get_ast_node());
	   }
#line 1934 "y.tab.c"
    break;

  case 31: /* statement: var_declaration  */
#line 524 "22101848_22101069.y"
          {
	    	log_file<<"At line no: "<<line_count<<" statement : var_declaration "<<endl<<endl;
			log_file<<yyvsp[0]->getname()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->getname(),"stmnt");
			yyval->set_ast_node(yyvsp[0]->get_ast_node());
	  }
#line 1946 "y.tab.c"
    break;

  case 32: /* statement: func_definition  */
#line 532 "22101848_22101069.y"
          {
	  		log_file<<"At line no: "<<line_count<<" Function definition must be in the global scope "<<endl<<endl;
	  		error_file<<"At line no: "<<line_count<<" Function definition must be in the global scope "<<endl<<endl;
	  		error_count++;
	  		yyval = new symbol_info("","stmnt");
	  		
	  }
#line 1958 "y.tab.c"
    break;

  case 33: /* statement: expression_statement  */
#line 540 "22101848_22101069.y"
          {
	    	log_file<<"At line no: "<<line_count<<" statement : expression_statement "<<endl<<endl;
			log_file<<yyvsp[0]->getname()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->getname(),"stmnt");
			yyval->set_ast_node(yyvsp[0]->get_ast_node());
	  }
#line 1970 "y.tab.c"
    break;

  case 34: /* statement: compound_statement  */
#line 548 "22101848_22101069.y"
          {
	    	log_file<<"At line no: "<<line_count<<" statement : compound_statement "<<endl<<endl;
			log_file<<yyvsp[0]->getname()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->getname(),"stmnt");
			yyval->set_ast_node(yyvsp[0]->get_ast_node());
	  }
#line 1982 "y.tab.c"
    break;

  case 35: /* statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement  */
#line 556 "22101848_22101069.y"
          {
	    	log_file<<"At line no: "<<line_count<<" statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement "<<endl<<endl;
			log_file<<"for("<<yyvsp[-4]->getname()<<yyvsp[-3]->getname()<<yyvsp[-2]->getname()<<")\n"<<yyvsp[0]->getname()<<endl<<endl;
			
			yyval = new symbol_info("for("+yyvsp[-4]->getname()+yyvsp[-3]->getname()+yyvsp[-2]->getname()+")\n"+yyvsp[0]->getname(),"stmnt");
			
			// Build AST node for for loop
			ForNode* for_loop_node = new ForNode(
				(ExprNode*)yyvsp[-4]->get_ast_node(),
				(ExprNode*)yyvsp[-3]->get_ast_node(),
				(ExprNode*)yyvsp[-2]->get_ast_node(),
				(StmtNode*)yyvsp[0]->get_ast_node()
			);
			yyval->set_ast_node(for_loop_node);
	  }
#line 2002 "y.tab.c"
    break;

  case 36: /* statement: IF LPAREN expression RPAREN statement  */
#line 572 "22101848_22101069.y"
          {
	    	log_file<<"At line no: "<<line_count<<" statement : IF LPAREN expression RPAREN statement "<<endl<<endl;
			log_file<<"if("<<yyvsp[-2]->getname()<<")\n"<<yyvsp[0]->getname()<<endl<<endl;
			
			yyval = new symbol_info("if("+yyvsp[-2]->getname()+")\n"+yyvsp[0]->getname(),"stmnt");
			
			// Build AST node for if statement (no else)
			IfNode* if_stmt_node = new IfNode(
				(ExprNode*)yyvsp[-2]->get_ast_node(),
				(StmtNode*)yyvsp[0]->get_ast_node()
			);
			yyval->set_ast_node(if_stmt_node);
	  }
#line 2020 "y.tab.c"
    break;

  case 37: /* statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 586 "22101848_22101069.y"
          {
	    	log_file<<"At line no: "<<line_count<<" statement : IF LPAREN expression RPAREN statement ELSE statement "<<endl<<endl;
			log_file<<"if("<<yyvsp[-4]->getname()<<")\n"<<yyvsp[-2]->getname()<<"\nelse\n"<<yyvsp[0]->getname()<<endl<<endl;
			
			yyval = new symbol_info("if("+yyvsp[-4]->getname()+")\n"+yyvsp[-2]->getname()+"\nelse\n"+yyvsp[0]->getname(),"stmnt");
			
			// Build AST node for if-else statement
			IfNode* if_else_node = new IfNode(
				(ExprNode*)yyvsp[-4]->get_ast_node(),
				(StmtNode*)yyvsp[-2]->get_ast_node(),
				(StmtNode*)yyvsp[0]->get_ast_node()
			);
			yyval->set_ast_node(if_else_node);
	  }
#line 2039 "y.tab.c"
    break;

  case 38: /* statement: WHILE LPAREN expression RPAREN statement  */
#line 601 "22101848_22101069.y"
          {
	    	log_file<<"At line no: "<<line_count<<" statement : WHILE LPAREN expression RPAREN statement "<<endl<<endl;
			log_file<<"while("<<yyvsp[-2]->getname()<<")\n"<<yyvsp[0]->getname()<<endl<<endl;
			
			yyval = new symbol_info("while("+yyvsp[-2]->getname()+")\n"+yyvsp[0]->getname(),"stmnt");
			
			// Build AST node for while loop
			WhileNode* while_loop_node = new WhileNode(
				(ExprNode*)yyvsp[-2]->get_ast_node(),
				(StmtNode*)yyvsp[0]->get_ast_node()
			);
			yyval->set_ast_node(while_loop_node);
	  }
#line 2057 "y.tab.c"
    break;

  case 39: /* statement: PRINTLN LPAREN id_name RPAREN SEMICOLON  */
#line 615 "22101848_22101069.y"
          {
	    	log_file<<"At line no: "<<line_count<<" statement : PRINTLN LPAREN ID RPAREN SEMICOLON "<<endl<<endl;
			log_file<<"printf("<<yyvsp[-2]->getname()<<");"<<endl<<endl; 
			
			if(sym_tbl->Lookup_in_table(yyvsp[-2]->getname()) == NULL)
			{
				error_file<<"At line no: "<<line_count<<" Undeclared variable "<<yyvsp[-2]->getname()<<endl<<endl;
				log_file<<"At line no: "<<line_count<<" Undeclared variable "<<yyvsp[-2]->getname()<<endl<<endl;
				error_count++;
			}
			
			yyval = new symbol_info("printf("+yyvsp[-2]->getname()+");","stmnt");
			
			// Build a basic expression statement for printf
			VarNode* print_var = new VarNode(yyvsp[-2]->getname(), 
			                         sym_tbl->Lookup_in_table(yyvsp[-2]->getname()) ? 
			                         sym_tbl->Lookup_in_table(yyvsp[-2]->getname())->getvartype() : "error");
			ExprStmtNode* printf_node = new ExprStmtNode(print_var);
			yyval->set_ast_node(printf_node);
	  }
#line 2082 "y.tab.c"
    break;

  case 40: /* statement: RETURN expression SEMICOLON  */
#line 636 "22101848_22101069.y"
          {
	    	log_file<<"At line no: "<<line_count<<" statement : RETURN expression SEMICOLON "<<endl<<endl;
			log_file<<"return "<<yyvsp[-1]->getname()<<";"<<endl<<endl;
			
			yyval = new symbol_info("return "+yyvsp[-1]->getname()+";","stmnt");
			
			// Build AST node for return statement
			ReturnNode* return_stmt_node = new ReturnNode((ExprNode*)yyvsp[-1]->get_ast_node());
			yyval->set_ast_node(return_stmt_node);
	  }
#line 2097 "y.tab.c"
    break;

  case 41: /* expression_statement: SEMICOLON  */
#line 649 "22101848_22101069.y"
                        {
				log_file<<"At line no: "<<line_count<<" expression_statement : SEMICOLON "<<endl<<endl;
				log_file<<";"<<endl<<endl;
				
				yyval = new symbol_info(";","expr_stmt");
				
				// Build empty expression statement
				ExprStmtNode* empty_expr_stmt = new ExprStmtNode(nullptr);
				yyval->set_ast_node(empty_expr_stmt);
	        }
#line 2112 "y.tab.c"
    break;

  case 42: /* expression_statement: expression SEMICOLON  */
#line 660 "22101848_22101069.y"
                        {
				log_file<<"At line no: "<<line_count<<" expression_statement : expression SEMICOLON "<<endl<<endl;
				log_file<<yyvsp[-1]->getname()<<";"<<endl<<endl;
				
				yyval = new symbol_info(yyvsp[-1]->getname()+";","expr_stmt");
				
				// Build expression statement from expression
				ExprStmtNode* expr_stmt_node = new ExprStmtNode((ExprNode*)yyvsp[-1]->get_ast_node());
				yyval->set_ast_node(expr_stmt_node);
	        }
#line 2127 "y.tab.c"
    break;

  case 43: /* variable: id_name  */
#line 673 "22101848_22101069.y"
      {
	    log_file<<"At line no: "<<line_count<<" variable : ID "<<endl<<endl;
		log_file<<yyvsp[0]->getname()<<endl<<endl;
			
		yyval = new symbol_info(yyvsp[0]->getname(),"varbl");
		
		if(sym_tbl->Lookup_in_table(yyvsp[0]->getname()) == NULL)
		{
			error_file<<"At line no: "<<line_count<<" Undeclared variable "<<yyvsp[0]->getname()<<endl<<endl;
			log_file<<"At line no: "<<line_count<<" Undeclared variable "<<yyvsp[0]->getname()<<endl<<endl;
			error_count++;
			
			yyval->setvartype("error");; //not found set error type
		}
		else if((sym_tbl->Lookup_in_table(yyvsp[0]->getname()))->getidtype() != "var") //variable is not a normal variable
		{
			if((sym_tbl->Lookup_in_table(yyvsp[0]->getname()))->getidtype() == "array")
			{
				error_file<<"At line no: "<<line_count<<" variable is of array type : "<<yyvsp[0]->getname()<<endl<<endl;
				log_file<<"At line no: "<<line_count<<" variable is of array type : "<<yyvsp[0]->getname()<<endl<<endl;
				error_count++;
			}
			else if((sym_tbl->Lookup_in_table(yyvsp[0]->getname()))->getidtype() == "func_def") 
			{
				error_file<<"At line no: "<<line_count<<" variable is of function type : "<<yyvsp[0]->getname()<<endl<<endl;
				log_file<<"At line no: "<<line_count<<" variable is of function type : "<<yyvsp[0]->getname()<<endl<<endl;
				error_count++;
			}
			else if((sym_tbl->Lookup_in_table(yyvsp[0]->getname()))->getidtype() == "func_dec") 
			{
				error_file<<"At line no: "<<line_count<<" variable is of function type : "<<yyvsp[0]->getname()<<endl<<endl;
				log_file<<"At line no: "<<line_count<<" variable is of function type : "<<yyvsp[0]->getname()<<endl<<endl;
				error_count++;
			}
			
			
			yyval->setvartype("error");; //doesn't match set error type
		}
		else yyval->setvartype((sym_tbl->Lookup_in_table(yyvsp[0]->getname()))->getvartype());  //set variable type as id type
		
		// Build AST node for variable
		VarNode* variable_node = new VarNode(yyvsp[0]->getname(), yyval->getvartype());
		yyval->set_ast_node(variable_node);
	 }
#line 2176 "y.tab.c"
    break;

  case 44: /* variable: id_name LTHIRD expression RTHIRD  */
#line 718 "22101848_22101069.y"
         {
	 	log_file<<"At line no: "<<line_count<<" variable : ID LTHIRD expression RTHIRD "<<endl<<endl;
		log_file<<yyvsp[-3]->getname()<<"["<<yyvsp[-1]->getname()<<"]"<<endl<<endl;
		
		yyval = new symbol_info(yyvsp[-3]->getname()+"["+yyvsp[-1]->getname()+"]","varbl");
		
		if(sym_tbl->Lookup_in_table(yyvsp[-3]->getname()) == NULL)
		{
			error_file<<"At line no: "<<line_count<<" Undeclared variable "<<yyvsp[-3]->getname()<<endl<<endl;
			log_file<<"At line no: "<<line_count<<" Undeclared variable "<<yyvsp[-3]->getname()<<endl<<endl;
			error_count++;
			
			yyval->setvartype("error");; //not found set error type
		}
		else if((sym_tbl->Lookup_in_table(yyvsp[-3]->getname()))->getidtype() != "array") //variable is not an array
		{
			error_file<<"At line no: "<<line_count<<" variable is not of array type : "<<yyvsp[-3]->getname()<<endl<<endl;
			log_file<<"At line no: "<<line_count<<" variable is not of array type : "<<yyvsp[-3]->getname()<<endl<<endl;
			error_count++;
			
			yyval->setvartype("error");; //doesn't match set error type
		}
		else if(yyvsp[-1]->getvartype()!="int") // get type of expression for array index
		{
			error_file<<"At line no: "<<line_count<<" array index is not of integer type : "<<yyvsp[-3]->getname()<<endl<<endl;
			log_file<<"At line no: "<<line_count<<" array index is not of integer type : "<<yyvsp[-3]->getname()<<endl<<endl;
			error_count++;
			
			yyval->setvartype("error");
		}
		else
		{
			yyval->setvartype((sym_tbl->Lookup_in_table(yyvsp[-3]->getname()))->getvartype());
		}
		
		// Build AST node for array access
		VarNode* array_access_node = new VarNode(yyvsp[-3]->getname(), yyval->getvartype(), (ExprNode*)yyvsp[-1]->get_ast_node());
		yyval->set_ast_node(array_access_node);
	 }
#line 2220 "y.tab.c"
    break;

  case 45: /* expression: logic_expression  */
#line 760 "22101848_22101069.y"
           {
	    	log_file<<"At line no: "<<line_count<<" expression : logic_expression "<<endl<<endl;
			log_file<<yyvsp[0]->getname()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->getname(),"expr");
			yyval->setvartype(yyvsp[0]->getvartype());
			yyval->set_ast_node(yyvsp[0]->get_ast_node());
	   }
#line 2233 "y.tab.c"
    break;

  case 46: /* expression: variable ASSIGNOP logic_expression  */
#line 769 "22101848_22101069.y"
           {
	    	log_file<<"At line no: "<<line_count<<" expression : variable ASSIGNOP logic_expression "<<endl<<endl;
			log_file<<yyvsp[-2]->getname()<<"="<<yyvsp[0]->getname()<<endl<<endl;

			yyval = new symbol_info(yyvsp[-2]->getname()+"="+yyvsp[0]->getname(),"expr");
			yyval->setvartype(yyvsp[-2]->getvartype());
			
			if(yyvsp[-2]->getvartype() == "void" || yyvsp[0]->getvartype() == "void") //if any operand is void
			{
				error_file<<"At line no: "<<line_count<<" operation on void type "<<endl<<endl;
				log_file<<"At line no: "<<line_count<<" operation on void type "<<endl<<endl;
				error_count++;
				
				yyval->setvartype("error");
			}
			else if(yyvsp[-2]->getvartype() == "int" && yyvsp[0]->getvartype() == "float") // assigning float into int
			{
				error_file<<"At line no: "<<line_count<<" Warning: Assignment of float value into variable of integer type "<<endl<<endl;
				log_file<<"At line no: "<<line_count<<" Warning: Assignment of float value into variable of integer type "<<endl<<endl;
				error_count++;
				
				yyval->setvartype("int");
			}
			
			if(yyvsp[-2]->getvartype() == "error" || yyvsp[0]->getvartype() == "error") //if any operand is error
			{
				yyval->setvartype("error");
			}
			
			// Build AST node for assignment
			AssignNode* assignment_node = new AssignNode(
				(VarNode*)yyvsp[-2]->get_ast_node(),
				(ExprNode*)yyvsp[0]->get_ast_node(),
				yyval->getvartype()
			);
			yyval->set_ast_node(assignment_node);
	   }
#line 2275 "y.tab.c"
    break;

  case 47: /* logic_expression: rel_expression  */
#line 809 "22101848_22101069.y"
             {
	    	log_file<<"At line no: "<<line_count<<" logic_expression : rel_expression "<<endl<<endl;
			log_file<<yyvsp[0]->getname()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->getname(),"lgc_expr");
			yyval->setvartype(yyvsp[0]->getvartype());
			yyval->set_ast_node(yyvsp[0]->get_ast_node());
	     }
#line 2288 "y.tab.c"
    break;

  case 48: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 818 "22101848_22101069.y"
                 {
	    	log_file<<"At line no: "<<line_count<<" logic_expression : rel_expression LOGICOP rel_expression "<<endl<<endl;
			log_file<<yyvsp[-2]->getname()<<yyvsp[-1]->getname()<<yyvsp[0]->getname()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-2]->getname()+yyvsp[-1]->getname()+yyvsp[0]->getname(),"lgc_expr");
			yyval->setvartype("int");
			
			//perform type checking on both sides of logicop
			
			if(yyvsp[-2]->getvartype() == "void" || yyvsp[0]->getvartype() == "void") //if any operand is void
			{
				error_file<<"At line no: "<<line_count<<" operation on void type "<<endl<<endl;
				log_file<<"At line no: "<<line_count<<" operation on void type "<<endl<<endl;
				error_count++;
				
				yyval->setvartype("error");
			}
			
			if(yyvsp[-2]->getvartype() == "error" || yyvsp[0]->getvartype() == "error") //if any operand is error
			{
				yyval->setvartype("error");
			}
			
			// Build AST node for logical operation
			BinaryOpNode* logic_operation_node = new BinaryOpNode(
				yyvsp[-1]->getname(),
				(ExprNode*)yyvsp[-2]->get_ast_node(),
				(ExprNode*)yyvsp[0]->get_ast_node(),
				yyval->getvartype()
			);
			yyval->set_ast_node(logic_operation_node);
	     }
#line 2325 "y.tab.c"
    break;

  case 49: /* rel_expression: simple_expression  */
#line 853 "22101848_22101069.y"
                {
	    	log_file<<"At line no: "<<line_count<<" rel_expression : simple_expression "<<endl<<endl;
			log_file<<yyvsp[0]->getname()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->getname(),"rel_expr");
			yyval->setvartype(yyvsp[0]->getvartype());
			yyval->set_ast_node(yyvsp[0]->get_ast_node());
	    }
#line 2338 "y.tab.c"
    break;

  case 50: /* rel_expression: simple_expression RELOP simple_expression  */
#line 862 "22101848_22101069.y"
                {
	    	log_file<<"At line no: "<<line_count<<" rel_expression : simple_expression RELOP simple_expression "<<endl<<endl;
			log_file<<yyvsp[-2]->getname()<<yyvsp[-1]->getname()<<yyvsp[0]->getname()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-2]->getname()+yyvsp[-1]->getname()+yyvsp[0]->getname(),"rel_expr");
			yyval->setvartype("int");
			
			//perform type checking on both sides of relop
			
			if(yyvsp[-2]->getvartype() == "void" || yyvsp[0]->getvartype() == "void") //if any operand is void
			{
				error_file<<"At line no: "<<line_count<<" operation on void type "<<endl<<endl;
				log_file<<"At line no: "<<line_count<<" operation on void type "<<endl<<endl;
				error_count++;
				
				yyval->setvartype("error");
			}
			
			if(yyvsp[-2]->getvartype() == "error" || yyvsp[0]->getvartype() == "error") //if any operand is error
			{
				yyval->setvartype("error");
			}
			
			// Build AST node for relational operation
			BinaryOpNode* relational_operation_node = new BinaryOpNode(
				yyvsp[-1]->getname(),
				(ExprNode*)yyvsp[-2]->get_ast_node(),
				(ExprNode*)yyvsp[0]->get_ast_node(),
				yyval->getvartype()
			);
			yyval->set_ast_node(relational_operation_node);
	    }
#line 2375 "y.tab.c"
    break;

  case 51: /* simple_expression: term  */
#line 897 "22101848_22101069.y"
          {
	    	log_file<<"At line no: "<<line_count<<" simple_expression : term "<<endl<<endl;
			log_file<<yyvsp[0]->getname()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->getname(),"simp_expr");
			yyval->setvartype(yyvsp[0]->getvartype());
			yyval->set_ast_node(yyvsp[0]->get_ast_node());
			
	      }
#line 2389 "y.tab.c"
    break;

  case 52: /* simple_expression: simple_expression ADDOP term  */
#line 907 "22101848_22101069.y"
                  {
	    	log_file<<"At line no: "<<line_count<<" simple_expression : simple_expression ADDOP term "<<endl<<endl;
			log_file<<yyvsp[-2]->getname()<<yyvsp[-1]->getname()<<yyvsp[0]->getname()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-2]->getname()+yyvsp[-1]->getname()+yyvsp[0]->getname(),"simp_expr");
			yyval->setvartype(yyvsp[-2]->getvartype());
			
			//perform type checking on both sides of addop
			
			if(yyvsp[-2]->getvartype() == "void" || yyvsp[0]->getvartype() == "void") //if any operand is void
			{
				error_file<<"At line no: "<<line_count<<" operation on void type "<<endl<<endl;
				log_file<<"At line no: "<<line_count<<" operation on void type "<<endl<<endl;
				error_count++;
				
				yyval->setvartype("error");
			}
			else if(yyvsp[-2]->getvartype() == "float" || yyvsp[0]->getvartype() == "float") //if any operand is float
			{
				yyval->setvartype("float");
			}
			else yyval->setvartype("int");
			
			if(yyvsp[-2]->getvartype() == "error" || yyvsp[0]->getvartype() == "error") //if any operand is error
			{
				yyval->setvartype("error");
			}
			
			// Build AST node for addition/subtraction
			BinaryOpNode* addop_node = new BinaryOpNode(
				yyvsp[-1]->getname(),
				(ExprNode*)yyvsp[-2]->get_ast_node(),
				(ExprNode*)yyvsp[0]->get_ast_node(),
				yyval->getvartype()
			);
			yyval->set_ast_node(addop_node);
	      }
#line 2431 "y.tab.c"
    break;

  case 53: /* term: unary_expression  */
#line 947 "22101848_22101069.y"
     {
	    	log_file<<"At line no: "<<line_count<<" term : unary_expression "<<endl<<endl;
			log_file<<yyvsp[0]->getname()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->getname(),"term");
			yyval->setvartype(yyvsp[0]->getvartype());
			yyval->set_ast_node(yyvsp[0]->get_ast_node());
			
	 }
#line 2445 "y.tab.c"
    break;

  case 54: /* term: term MULOP unary_expression  */
#line 957 "22101848_22101069.y"
     {
	    	log_file<<"At line no: "<<line_count<<" term : term MULOP unary_expression "<<endl<<endl;
			log_file<<yyvsp[-2]->getname()<<yyvsp[-1]->getname()<<yyvsp[0]->getname()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-2]->getname()+yyvsp[-1]->getname()+yyvsp[0]->getname(),"term");
			yyval->setvartype(yyvsp[-2]->getvartype());
			
			//perform type checking on both sides of mulop
			if(yyvsp[-2]->getvartype() == "void" || yyvsp[0]->getvartype() == "void") //if any operand is void
			{
				error_file<<"At line no: "<<line_count<<" operation on void type "<<endl<<endl;
				log_file<<"At line no: "<<line_count<<" operation on void type "<<endl<<endl;
				error_count++;
				
				yyval->setvartype("error");
			}
			else if(yyvsp[-2]->getvartype() == "float" || yyvsp[0]->getvartype() == "float") //if any operand is float
			{
				yyval->setvartype("float");
			}
			else yyval->setvartype("int");
			
			//check if both operands are int for modulus
			if(yyvsp[-1]->getname() == "%")
			{
				if(yyvsp[-2]->getvartype() == "int" && yyvsp[0]->getvartype() == "int")
				{
					if(yyvsp[0]->getname()=="0")
					{
						error_file<<"At line no: "<<line_count<<" Modulus by 0 "<<endl<<endl;
						log_file<<"At line no: "<<line_count<<" Modulus by 0 "<<endl<<endl;
						error_count++;
						
						yyval->setvartype("error");
					}
					else yyval->setvartype("int");
				}
				else if(yyvsp[-2]->getvartype() == "float" || yyvsp[0]->getvartype() == "float")
				{
					error_file<<"At line no: "<<line_count<<" Modulus operator on non integer type "<<endl<<endl;
					log_file<<"At line no: "<<line_count<<" Modulus operator on non integer type "<<endl<<endl;
					error_count++;
					
					yyval->setvartype("error");
				}
			}
			
			if(yyvsp[-1]->getname() == "/") //division by zero
			{
				if(yyvsp[0]->getname()=="0")
				{
					error_file<<"At line no: "<<line_count<<" Divide by 0 "<<endl<<endl;
					log_file<<"At line no: "<<line_count<<" Divide by 0 "<<endl<<endl;
					error_count++;
					
					yyval->setvartype("error");
				}
			}
			if(yyvsp[-2]->getvartype() == "error" || yyvsp[0]->getvartype() == "error") //if any operand is error
			{
				yyval->setvartype("error");
			}
			
			// Build AST node for multiplication/division/modulus
			BinaryOpNode* mulop_node = new BinaryOpNode(
				yyvsp[-1]->getname(),
				(ExprNode*)yyvsp[-2]->get_ast_node(),
				(ExprNode*)yyvsp[0]->get_ast_node(),
				yyval->getvartype()
			);
			yyval->set_ast_node(mulop_node);
	 }
#line 2522 "y.tab.c"
    break;

  case 55: /* unary_expression: ADDOP unary_expression  */
#line 1032 "22101848_22101069.y"
                 {
	    	log_file<<"At line no: "<<line_count<<" unary_expression : ADDOP unary_expression "<<endl<<endl;
			log_file<<yyvsp[-1]->getname()<<yyvsp[0]->getname()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-1]->getname()+yyvsp[0]->getname(),"un_expr");
			yyval->setvartype(yyvsp[0]->getvartype());
			
			if(yyvsp[0]->getvartype()=="void")
			{
				error_file<<"At line no: "<<line_count<<" operation on void type : "<<yyvsp[0]->getname()<<endl<<endl;
				log_file<<"At line no: "<<line_count<<" operation on void type : "<<yyvsp[0]->getname()<<endl<<endl;
				error_count++;
				
				yyval->setvartype("error");
			}
			
			// Build AST node for unary plus/minus
			UnaryOpNode* unary_addop_node = new UnaryOpNode(
				yyvsp[-1]->getname(),
				(ExprNode*)yyvsp[0]->get_ast_node(),
				yyval->getvartype()
			);
			yyval->set_ast_node(unary_addop_node);
	     }
#line 2551 "y.tab.c"
    break;

  case 56: /* unary_expression: NOT unary_expression  */
#line 1057 "22101848_22101069.y"
                 {
	    	log_file<<"At line no: "<<line_count<<" unary_expression : NOT unary_expression "<<endl<<endl;
			log_file<<"!"<<yyvsp[0]->getname()<<endl<<endl;
			
			yyval = new symbol_info("!"+yyvsp[0]->getname(),"un_expr");
			yyval->setvartype("int");
			
			if(yyvsp[0]->getvartype()=="void")
			{
				error_file<<"At line no: "<<line_count<<" operation on void type : "<<yyvsp[0]->getname()<<endl<<endl;
				log_file<<"At line no: "<<line_count<<" operation on void type : "<<yyvsp[0]->getname()<<endl<<endl;
				error_count++;
				
				yyval->setvartype("error");
			}
			
			// Build AST node for logical NOT
			UnaryOpNode* not_operation_node = new UnaryOpNode(
				"!",
				(ExprNode*)yyvsp[0]->get_ast_node(),
				yyval->getvartype()
			);
			yyval->set_ast_node(not_operation_node);
	     }
#line 2580 "y.tab.c"
    break;

  case 57: /* unary_expression: factor  */
#line 1082 "22101848_22101069.y"
                 {
	    	log_file<<"At line no: "<<line_count<<" unary_expression : factor "<<endl<<endl;
			log_file<<yyvsp[0]->getname()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->getname(),"un_expr");
			yyval->setvartype(yyvsp[0]->getvartype());
			yyval->set_ast_node(yyvsp[0]->get_ast_node());
	     }
#line 2593 "y.tab.c"
    break;

  case 58: /* factor: variable  */
#line 1093 "22101848_22101069.y"
    {
	    log_file<<"At line no: "<<line_count<<" factor : variable "<<endl<<endl;
		log_file<<yyvsp[0]->getname()<<endl<<endl;
			
		yyval = new symbol_info(yyvsp[0]->getname(),"fctr");
		yyval->setvartype(yyvsp[0]->getvartype());
		yyval->set_ast_node(yyvsp[0]->get_ast_node());
	}
#line 2606 "y.tab.c"
    break;

  case 59: /* factor: id_name LPAREN argument_list RPAREN  */
#line 1102 "22101848_22101069.y"
        {
	    log_file<<"At line no: "<<line_count<<" factor : ID LPAREN argument_list RPAREN "<<endl<<endl;
	    log_file<<yyvsp[-3]->getname()<<"("<<yyvsp[-1]->getname()<<")"<<endl<<endl;
	
	    yyval = new symbol_info(yyvsp[-3]->getname()+"("+yyvsp[-1]->getname()+")","fctr");
	    yyval->setvartype("error");
	
	    int type_match_flag = 0;
	
	    // Perform type checking (existing code)
	    if(sym_tbl->Lookup_in_table(yyvsp[-3]->getname())==NULL) //undeclared function
	    {
	        error_file<<"At line no: "<<line_count<<" Undeclared function: "<<yyvsp[-3]->getname()<<endl<<endl;
	        log_file<<"At line no: "<<line_count<<" Undeclared function: "<<yyvsp[-3]->getname()<<endl<<endl;
	        error_count++;
	    }
	    else
	    {
	        if((sym_tbl->Lookup_in_table(yyvsp[-3]->getname()))->getidtype()=="func_dec") //declared but not defined
	        {
	            error_file<<"At line no: "<<line_count<<" Undefined function: "<<yyvsp[-3]->getname()<<endl<<endl;
	            log_file<<"At line no: "<<line_count<<" Undefined function: "<<yyvsp[-3]->getname()<<endl<<endl;
	            error_count++;
	        }
	        else if((sym_tbl->Lookup_in_table(yyvsp[-3]->getname()))->getidtype()=="func_def")
	        {
	            vector<string> param_type_list = (sym_tbl->Lookup_in_table(yyvsp[-3]->getname()))->getparamlist();
	
	            if(argument_types.size()!=param_type_list.size()) //number of parameters don't match
	            {
	                error_file<<"At line no: "<<line_count<<" Inconsistencies in number of arguments in function call: "<<yyvsp[-3]->getname()<<endl<<endl;
	                log_file<<"At line no: "<<line_count<<" Inconsistencies in number of arguments in function call: "<<yyvsp[-3]->getname()<<endl<<endl;
	                error_count++;
	            }
	            else if(param_type_list.size()!=0)
	            {
	                for(int i = 0; i < param_type_list.size(); i++)
	                {
	                    if(argument_types[i]!=param_type_list[i])
	                    {
	                        if(argument_types[i] == "int" && param_type_list[i] == "float") {}
	                        else if(argument_types[i]!="error")
	                        {
	                            type_match_flag = 1;
	                            error_file<<"At line no: "<<line_count<<" "<<"argument "<<i+1<<" type mismatch in function call: "<<yyvsp[-3]->getname()<<endl<<endl;
	                            log_file<<"At line no: "<<line_count<<" "<<"argument "<<i+1<<" type mismatch in function call: "<<yyvsp[-3]->getname()<<endl<<endl;
	                            error_count++;
	                        }
	                    }
	                }                   
	            }
	            if(!type_match_flag) yyval->setvartype((sym_tbl->Lookup_in_table(yyvsp[-3]->getname()))->getvartype());
	        }
	    }
	
	    // Build function call node
	    FuncCallNode* func_call_node = new FuncCallNode(yyvsp[-3]->getname(), yyval->getvartype());
	
	    // Get arguments from the ArgumentsNode if exists
	    if (yyvsp[-1]->get_ast_node()) {
	        ArgumentsNode* args_node = dynamic_cast<ArgumentsNode*>(yyvsp[-1]->get_ast_node());
	        if (args_node) {
	            // Add each argument to function call
	            for (auto arg : args_node->get_arguments()) {
	                func_call_node->add_argument(arg);
	            }
	        }
	    }
	
	    yyval->set_ast_node(func_call_node);
	
	    argument_types.clear();
	}
#line 2684 "y.tab.c"
    break;

  case 60: /* factor: LPAREN expression RPAREN  */
#line 1176 "22101848_22101069.y"
        {
	   	log_file<<"At line no: "<<line_count<<" factor : LPAREN expression RPAREN "<<endl<<endl;
		log_file<<"("<<yyvsp[-1]->getname()<<")"<<endl<<endl;
		
		yyval = new symbol_info("("+yyvsp[-1]->getname()+")","fctr");
		yyval->setvartype(yyvsp[-1]->getvartype());
		yyval->set_ast_node(yyvsp[-1]->get_ast_node()); // Pass through expression AST
	}
#line 2697 "y.tab.c"
    break;

  case 61: /* factor: CONST_INT  */
#line 1185 "22101848_22101069.y"
        {
	    log_file<<"At line no: "<<line_count<<" factor : CONST_INT "<<endl<<endl;
		log_file<<yyvsp[0]->getname()<<endl<<endl;
			
		yyval = new symbol_info(yyvsp[0]->getname(),"fctr");
		yyval->setvartype("int");
		
		// Build AST node for integer constant
		ConstNode* int_const_node = new ConstNode(yyvsp[0]->getname(), "int");
		yyval->set_ast_node(int_const_node);
	}
#line 2713 "y.tab.c"
    break;

  case 62: /* factor: CONST_FLOAT  */
#line 1197 "22101848_22101069.y"
        {
	    log_file<<"At line no: "<<line_count<<" factor : CONST_FLOAT "<<endl<<endl;
		log_file<<yyvsp[0]->getname()<<endl<<endl;
			
		yyval = new symbol_info(yyvsp[0]->getname(),"fctr");
		yyval->setvartype("float");
		
		// Build AST node for float constant
		ConstNode* float_const_node = new ConstNode(yyvsp[0]->getname(), "float");
		yyval->set_ast_node(float_const_node);
	}
#line 2729 "y.tab.c"
    break;

  case 63: /* factor: variable INCOP  */
#line 1209 "22101848_22101069.y"
        {
	    log_file<<"At line no: "<<line_count<<" factor : variable INCOP "<<endl<<endl;
		log_file<<yyvsp[-1]->getname()<<"++"<<endl<<endl;
			
		yyval = new symbol_info(yyvsp[-1]->getname()+"++","fctr");
		yyval->setvartype(yyvsp[-1]->getvartype());
		
		// Build AST nodes for increment
		// For x++, represented as (x = x + 1)
		VarNode* inc_var_node = (VarNode*)yyvsp[-1]->get_ast_node();
		ConstNode* one_const_node = new ConstNode("1", "int");
		BinaryOpNode* add_one_node = new BinaryOpNode("+", inc_var_node, one_const_node, yyvsp[-1]->getvartype());
		AssignNode* inc_assign_node = new AssignNode(inc_var_node, add_one_node, yyvsp[-1]->getvartype());
		yyval->set_ast_node(inc_assign_node);
	}
#line 2749 "y.tab.c"
    break;

  case 64: /* factor: variable DECOP  */
#line 1225 "22101848_22101069.y"
        {
	    log_file<<"At line no: "<<line_count<<" factor : variable DECOP "<<endl<<endl;
		log_file<<yyvsp[-1]->getname()<<"--"<<endl<<endl;
			
		yyval = new symbol_info(yyvsp[-1]->getname()+"--","fctr");
		yyval->setvartype(yyvsp[-1]->getvartype());
		
		// Build AST nodes for decrement
		// For x--, represented as (x = x - 1)
		VarNode* dec_var_node = (VarNode*)yyvsp[-1]->get_ast_node();
		ConstNode* one_const_node = new ConstNode("1", "int");
		BinaryOpNode* sub_one_node = new BinaryOpNode("-", dec_var_node, one_const_node, yyvsp[-1]->getvartype());
		AssignNode* dec_assign_node = new AssignNode(dec_var_node, sub_one_node, yyvsp[-1]->getvartype());
		yyval->set_ast_node(dec_assign_node);
	}
#line 2769 "y.tab.c"
    break;

  case 65: /* argument_list: arguments  */
#line 1243 "22101848_22101069.y"
              {
                    log_file<<"At line no: "<<line_count<<" argument_list : arguments "<<endl<<endl;
                    log_file<<yyvsp[0]->getname()<<endl<<endl;
                        
                    yyval = yyvsp[0]; // Pass through arguments node
              }
#line 2780 "y.tab.c"
    break;

  case 66: /* argument_list: %empty  */
#line 1250 "22101848_22101069.y"
              {
                    log_file<<"At line no: "<<line_count<<" argument_list :  "<<endl<<endl;
                    log_file<<""<<endl<<endl;
                        
                    yyval = new symbol_info("","arg_list");
                    // Build empty arguments node
                    ArgumentsNode* empty_args = new ArgumentsNode();
                    yyval->set_ast_node(empty_args);
              }
#line 2794 "y.tab.c"
    break;

  case 67: /* arguments: arguments COMMA logic_expression  */
#line 1262 "22101848_22101069.y"
          {
                log_file<<"At line no: "<<line_count<<" arguments : arguments COMMA logic_expression "<<endl<<endl;
                log_file<<yyvsp[-2]->getname()<<","<<yyvsp[0]->getname()<<endl<<endl;
                        
                yyval = new symbol_info(yyvsp[-2]->getname()+","+yyvsp[0]->getname(),"arg");
                
                // Get existing arguments node or create new
                ArgumentsNode* args_list;
                if (yyvsp[-2]->get_ast_node()) {
                    args_list = dynamic_cast<ArgumentsNode*>(yyvsp[-2]->get_ast_node());
                } else {
                    args_list = new ArgumentsNode();
                }
                
                // Add new argument
                if (yyvsp[0]->get_ast_node()) {
                    args_list->add_argument(dynamic_cast<ExprNode*>(yyvsp[0]->get_ast_node()));
                }
                
                yyval->set_ast_node(args_list);
                argument_types.push_back(yyvsp[0]->getvartype());
          }
#line 2821 "y.tab.c"
    break;

  case 68: /* arguments: logic_expression  */
#line 1285 "22101848_22101069.y"
          {
                log_file<<"At line no: "<<line_count<<" arguments : logic_expression "<<endl<<endl;
                log_file<<yyvsp[0]->getname()<<endl<<endl;
                        
                yyval = new symbol_info(yyvsp[0]->getname(),"arg");
                
                // Build new arguments node with single argument
                ArgumentsNode* args_list = new ArgumentsNode();
                if (yyvsp[0]->get_ast_node()) {
                    args_list->add_argument(dynamic_cast<ExprNode*>(yyvsp[0]->get_ast_node()));
                }
                
                yyval->set_ast_node(args_list);
                argument_types.push_back(yyvsp[0]->getvartype());
          }
#line 2841 "y.tab.c"
    break;


#line 2845 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1303 "22101848_22101069.y"


int main(int argc, char *argv[])
{
	if(argc != 2) 
	{
		cout<<"Please input file name"<<endl;
		return 0;
	}
	yyin = fopen(argv[1], "r");
	log_file.open("log.txt", ios::trunc);
	error_file.open("error.txt", ios::trunc);
	code_file.open("code.txt", ios::trunc);

	if(yyin == NULL)
	{
		cout<<"Couldn't open file"<<endl;
		return 0;
	}
	
	// First pass: Parse input and build AST
	cout << "==== Pass 1: Parsing and constructing AST ====" << endl;
	log_file << "==== Pass 1: Parsing and constructing AST ====" << endl;
	
	sym_tbl->enter_scope(log_file);
	yyparse();
	
	log_file << endl << "Symbol Table after first pass:" << endl;
	sym_tbl->Print_all_scope(log_file);
	
	// Only proceed to second pass if no errors occurred
	if (error_count == 0 && program_root) {
		cout << "==== Pass 2: Generating Three-Address Code ====" << endl;
		log_file << endl << "==== Pass 2: Generating Three-Address Code ====" << endl;
		
		// Generate three-address code (second pass)
		log_file << "Initiating Three-Address Code generation..." << endl;
		ThreeAddrCodeGenerator tac_generator(program_root, code_file);
		tac_generator.generate();
		
		log_file << "Three-Address Code generation completed successfully" << endl;
		cout << "Three-Address Code generated successfully. Output in code.txt" << endl;
	} else {
		cout << "Three-Address Code generation skipped due to compilation errors" << endl;
		log_file << endl << "Three-Address Code generation skipped due to errors" << endl;
		code_file << "// Three-Address Code generation aborted due to compilation errors" << endl;
	}
	
	log_file<<endl<<"Total lines: "<<line_count<<endl;
	log_file<<"Total errors: "<<error_count<<endl;
	error_file<<"Total errors: "<<error_count<<endl;
	
	log_file.close();
	error_file.close();
	code_file.close();

	
	fclose(yyin);
	
	return 0;
}
