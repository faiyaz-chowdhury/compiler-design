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

#include <cstring>

#define YYSTYPE symbol_info*

extern FILE *yyin;
int yyparse(void);
int yylex(void);
extern YYSTYPE yylval;

symbol_table *table;
string current_type;
string current_func_name;
string current_func_return_type;
vector<pair<string, string> > current_func_params;
bool is_function_definition = false;
bool error_found = false;

int lines = 1;
ofstream outlog;
ofstream error_log;

int error_count = 0;

void yyerror(const char *s)
{
    outlog << "Error at line " << lines << " " << s << endl << endl;
    error_found = true;
}

bool check_function_declaration(string name) {
    symbol_info* temp = new symbol_info(name, "ID");
    symbol_info* found = table->lookup(temp);
    delete temp;
    return found != NULL && found->get_is_function();
}

bool check_current_scope_variables(string name) {
    symbol_info* temp = new symbol_info(name, "ID");
    symbol_info* found = table->lookup_current_scope(temp);
    delete temp;
    return found != NULL;
}

symbol_info* get_variable_info(string name) {
	symbol_info* temp = new symbol_info(name, "ID");
	symbol_info* found = table->lookup(temp);
	delete temp;
	return found;
}


#line 127 "y.tab.c"

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
  YYSYMBOL_45_1 = 45,                      /* $@1  */
  YYSYMBOL_46_2 = 46,                      /* $@2  */
  YYSYMBOL_47_3 = 47,                      /* $@3  */
  YYSYMBOL_parameter_list = 48,            /* parameter_list  */
  YYSYMBOL_compound_statement = 49,        /* compound_statement  */
  YYSYMBOL_50_4 = 50,                      /* $@4  */
  YYSYMBOL_51_5 = 51,                      /* $@5  */
  YYSYMBOL_var_declaration = 52,           /* var_declaration  */
  YYSYMBOL_type_specifier = 53,            /* type_specifier  */
  YYSYMBOL_declaration_list = 54,          /* declaration_list  */
  YYSYMBOL_statements = 55,                /* statements  */
  YYSYMBOL_statement = 56,                 /* statement  */
  YYSYMBOL_expression_statement = 57,      /* expression_statement  */
  YYSYMBOL_variable = 58,                  /* variable  */
  YYSYMBOL_expression = 59,                /* expression  */
  YYSYMBOL_logic_expression = 60,          /* logic_expression  */
  YYSYMBOL_rel_expression = 61,            /* rel_expression  */
  YYSYMBOL_simple_expression = 62,         /* simple_expression  */
  YYSYMBOL_term = 63,                      /* term  */
  YYSYMBOL_unary_expression = 64,          /* unary_expression  */
  YYSYMBOL_factor = 65,                    /* factor  */
  YYSYMBOL_argument_list = 66,             /* argument_list  */
  YYSYMBOL_arguments = 67                  /* arguments  */
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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   142

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  120

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
       0,    64,    64,    71,    77,    85,    91,    99,    99,    99,
     124,   124,   141,   161,   171,   182,   194,   194,   216,   216,
     231,   248,   255,   262,   271,   288,   306,   323,   343,   350,
     359,   366,   373,   380,   387,   394,   401,   408,   422,   431,
     438,   447,   473,   506,   518,   552,   567,   589,   604,   626,
     641,   677,   692,   744,   758,   766,   784,   796,   842,   850,
     858,   866,   874,   884,   892,   900,   910
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
  "$accept", "start", "program", "unit", "func_definition", "$@1", "$@2",
  "$@3", "parameter_list", "compound_statement", "$@4", "$@5",
  "var_declaration", "type_specifier", "declaration_list", "statements",
  "statement", "expression_statement", "variable", "expression",
  "logic_expression", "rel_expression", "simple_expression", "term",
  "unary_expression", "factor", "argument_list", "arguments", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-73)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-19)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      21,   -73,   -73,   -73,    14,    21,   -73,   -73,   -73,    11,
     -73,   -73,    20,   -22,     9,    15,    12,   -73,   -73,    21,
      41,    45,    49,   -14,    44,   -73,    47,    53,   -73,   -73,
      21,   -73,    52,   103,    57,    49,    54,   -73,    61,    62,
      63,    27,    65,    27,    27,    27,   -73,   -73,   -73,    29,
     -73,   -73,    58,    67,   -73,   -73,    37,    64,   -73,    74,
      51,    80,   -73,   -73,   -73,   -73,   -73,    27,   -10,    27,
      72,    73,     0,   -73,   -73,    81,    27,    27,    83,   -73,
     -73,   -73,   -73,    27,   -73,    27,    27,    27,    27,    84,
     -10,    89,   -73,    90,   -73,   -73,    91,    87,    92,   -73,
     -73,    80,   104,   -73,   103,    27,   103,    93,   -73,    27,
     -73,   122,    98,   -73,   -73,   -73,   103,   103,   -73,   -73
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    21,    22,    23,     0,     2,     4,     6,     5,     0,
       1,     3,    26,     0,     7,     0,     0,    20,    10,     0,
       0,    24,     0,     0,    15,    27,     0,    16,    11,     8,
       0,    14,     0,     0,     0,     0,    13,    25,     0,     0,
       0,     0,     0,     0,     0,     0,    39,    59,    60,    41,
      32,    30,     0,     0,    28,    31,    56,     0,    43,    45,
      47,    49,    51,    55,    19,     9,    12,     0,     0,     0,
       0,     0,    56,    53,    54,     0,    64,     0,    26,    17,
      29,    61,    62,     0,    40,     0,     0,     0,     0,     0,
       0,     0,    38,     0,    58,    66,     0,    63,     0,    44,
      46,    50,    48,    52,     0,     0,     0,     0,    57,     0,
      42,    34,     0,    36,    37,    65,     0,     0,    35,    33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -73,   -73,   -73,   124,   -73,   -73,   -73,   -73,   -73,   -16,
     -73,   -73,    36,    16,   -73,   -73,   -48,   -66,   -43,   -38,
     -72,    50,    55,    46,   -35,   -73,   -73,   -73
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,    19,    35,    22,    23,    50,
      33,    34,    51,    52,    13,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    96,    97
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      72,    72,    90,    70,    95,    80,    28,    75,    73,    74,
      43,    99,    16,    17,    10,    29,     9,    44,    45,    65,
      30,     9,    81,    82,   105,    46,    47,    48,    49,    89,
       1,    91,     2,    72,     3,    24,     8,   115,    18,    98,
      72,     8,    72,    72,    72,    72,    36,    43,    14,    12,
      21,    20,    15,   103,    44,    45,   111,    76,   113,    81,
      82,    77,    83,    47,    48,    49,    72,   112,   118,   119,
      38,    86,    39,    40,    25,    87,     1,    26,     2,    27,
       3,    41,    31,    32,   -18,    37,    42,    43,    64,    67,
      68,    69,    66,    71,    44,    45,    78,    27,    79,    84,
      85,    88,    46,    47,    48,    49,    38,    92,    39,    40,
      94,    93,     1,   104,     2,    15,     3,    41,   106,   107,
     108,   109,    42,    43,    86,   110,   116,   117,   114,    11,
      44,    45,   101,    27,     0,   100,     0,     0,    46,    47,
      48,    49,   102
};

static const yytype_int8 yycheck[] =
{
      43,    44,    68,    41,    76,    53,    22,    45,    43,    44,
      20,    83,    34,    35,     0,    29,     0,    27,    28,    35,
      34,     5,    22,    23,    90,    35,    36,    37,    38,    67,
       9,    69,    11,    76,    13,    19,     0,   109,    29,    77,
      83,     5,    85,    86,    87,    88,    30,    20,    28,    38,
      38,    36,    32,    88,    27,    28,   104,    28,   106,    22,
      23,    32,    25,    36,    37,    38,   109,   105,   116,   117,
       3,    20,     5,     6,    33,    24,     9,    32,    11,    30,
      13,    14,    38,    36,    31,    33,    19,    20,    31,    28,
      28,    28,    38,    28,    27,    28,    38,    30,    31,    35,
      26,    21,    35,    36,    37,    38,     3,    35,     5,     6,
      29,    38,     9,    29,    11,    32,    13,    14,    29,    29,
      29,    34,    19,    20,    20,    33,     4,    29,    35,     5,
      27,    28,    86,    30,    -1,    85,    -1,    -1,    35,    36,
      37,    38,    87
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    11,    13,    41,    42,    43,    44,    52,    53,
       0,    43,    38,    54,    28,    32,    34,    35,    29,    45,
      36,    38,    47,    48,    53,    33,    32,    30,    49,    29,
      34,    38,    36,    50,    51,    46,    53,    33,     3,     5,
       6,    14,    19,    20,    27,    28,    35,    36,    37,    38,
      49,    52,    53,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    31,    49,    38,    28,    28,    28,
      59,    28,    58,    64,    64,    59,    28,    32,    38,    31,
      56,    22,    23,    25,    35,    26,    20,    24,    21,    59,
      57,    59,    35,    38,    29,    60,    66,    67,    59,    60,
      61,    63,    62,    64,    29,    57,    29,    29,    29,    34,
      33,    56,    59,    56,    35,    60,     4,    29,    56,    56
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    45,    46,    44,
      47,    44,    48,    48,    48,    48,    50,    49,    51,    49,
      52,    53,    53,    53,    54,    54,    54,    54,    55,    55,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    57,
      57,    58,    58,    59,    59,    60,    60,    61,    61,    62,
      62,    63,    63,    64,    64,    64,    65,    65,    65,    65,
      65,    65,    65,    66,    66,    67,    67
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     0,     0,     8,
       0,     6,     4,     3,     2,     1,     0,     4,     0,     3,
       3,     1,     1,     1,     3,     6,     1,     4,     1,     2,
       1,     1,     1,     7,     5,     7,     5,     5,     3,     1,
       2,     1,     4,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     2,     2,     1,     1,     4,     3,     1,
       1,     2,     2,     1,     0,     3,     1
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
#line 65 "22101848_22101069.y"
        {
		outlog << "At line no: " << lines << " start : program " << endl << endl;
		table->print_all_scopes(outlog);
	}
#line 1385 "y.tab.c"
    break;

  case 3: /* program: program unit  */
#line 72 "22101848_22101069.y"
        {
		outlog << "At line no: " << lines << " program : program unit " << endl << endl;
		outlog << yyvsp[-1]->getname() + "\n" + yyvsp[0]->getname() << endl << endl;
		yyval = new symbol_info(yyvsp[-1]->getname() + "\n" + yyvsp[0]->getname(), "program");
	}
#line 1395 "y.tab.c"
    break;

  case 4: /* program: unit  */
#line 78 "22101848_22101069.y"
        {
		outlog << "At line no: " << lines << " program : unit " << endl << endl;
		outlog << yyvsp[0]->getname() << endl << endl;
		yyval = new symbol_info(yyvsp[0]->getname(), "program");
	}
#line 1405 "y.tab.c"
    break;

  case 5: /* unit: var_declaration  */
#line 86 "22101848_22101069.y"
         {
		outlog << "At line no: " << lines << " unit : var_declaration " << endl << endl;
		outlog << yyvsp[0]->getname() << endl << endl;
		yyval = new symbol_info(yyvsp[0]->getname(), "unit");
	 }
#line 1415 "y.tab.c"
    break;

  case 6: /* unit: func_definition  */
#line 92 "22101848_22101069.y"
     {
		outlog << "At line no: " << lines << " unit : func_definition " << endl << endl;
		outlog << yyvsp[0]->getname() << endl << endl;
		yyval = new symbol_info(yyvsp[0]->getname(), "unit");
	 }
#line 1425 "y.tab.c"
    break;

  case 7: /* $@1: %empty  */
#line 99 "22101848_22101069.y"
                                           { current_func_name = yyvsp[-1]->getname(); }
#line 1431 "y.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 99 "22101848_22101069.y"
                                                                                                        {		
			if(!check_function_declaration(yyvsp[-4]->getname()) && !check_current_scope_variables(yyvsp[-4]->getname())) {

				vector<pair<string, string> > params = current_func_params;
				symbol_info* func = new symbol_info(yyvsp[-4]->getname(), "ID", yyvsp[-5]->getname());
				func->set_as_function(yyvsp[-5]->getname(), params);
				table->insert(func);
			}else{
				outlog << "At line no: " << lines << " Multiple declaration of function " << yyvsp[-4]->getname() << endl << endl;
				error_log << "At line no: " << lines << " Multiple declaration of function " << yyvsp[-4]->getname() << endl << endl;
				error_count++;
			}

		    // The function definition is complete.
            // You can now insert necessary information about the function into the symbol table

		}
#line 1453 "y.tab.c"
    break;

  case 9: /* func_definition: type_specifier ID LPAREN $@1 parameter_list RPAREN $@2 compound_statement  */
#line 116 "22101848_22101069.y"
                {	
			outlog << "At line no: " << lines << " func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement " << endl << endl;
			outlog << yyvsp[-7]->getname() << " " << yyvsp[-6]->getname() << "(" + yyvsp[-3]->getname() + ")\n" << yyvsp[0]->getname() << endl << endl;
			
			yyval = new symbol_info(yyvsp[-7]->getname() + " " + yyvsp[-6]->getname() + "(" + yyvsp[-3]->getname() + ")\n" + yyvsp[0]->getname(), "func_def");
			current_func_params.clear();
			
		}
#line 1466 "y.tab.c"
    break;

  case 10: /* $@3: %empty  */
#line 124 "22101848_22101069.y"
                                                  {
			if(!check_function_declaration(yyvsp[-2]->getname())) {
				vector<pair<string, string> > params;
				symbol_info* func = new symbol_info(yyvsp[-2]->getname(), "ID", yyvsp[-3]->getname());
				func->set_as_function(yyvsp[-3]->getname(), params);
				table->insert(func);
			}
			
		}
#line 1480 "y.tab.c"
    break;

  case 11: /* func_definition: type_specifier ID LPAREN RPAREN $@3 compound_statement  */
#line 133 "22101848_22101069.y"
                {
			outlog << "At line no: " << lines << " func_definition : type_specifier ID LPAREN RPAREN compound_statement " << endl << endl;
			outlog << yyvsp[-5]->getname() << " " << yyvsp[-4]->getname() << "()\n" << yyvsp[0]->getname() << endl << endl;
			
			yyval = new symbol_info(yyvsp[-5]->getname() + " " + yyvsp[-4]->getname() + "()\n" + yyvsp[0]->getname(), "func_def");	
		}
#line 1491 "y.tab.c"
    break;

  case 12: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 142 "22101848_22101069.y"
                {
			outlog << "At line no: " << lines << " parameter_list : parameter_list COMMA type_specifier ID " << endl << endl;
			outlog << yyvsp[-3]->getname() << "," << yyvsp[-1]->getname() << " " << yyvsp[0]->getname() << endl << endl;
					
			yyval = new symbol_info(yyvsp[-3]->getname() + "," + yyvsp[-1]->getname() + " " + yyvsp[0]->getname(), "param_list");
			
			pair<string, string> param(yyvsp[-1]->getname(), yyvsp[0]->getname());
			if(!current_func_params.empty()) {
				for(auto p : current_func_params) {
					if(p.second==yyvsp[0]->getname()) {
						outlog << "At line no: " << lines << " Multiple declaration of variable " << yyvsp[0]->getname() << " in parameter of " << current_func_name <<endl << endl;
						error_log << "At line no: " << lines << " Multiple declaration of variable " << yyvsp[0]->getname() << " in parameter of " << current_func_name <<endl << endl;
						error_count++;
					}
				}
			}

			current_func_params.push_back(param);
		}
#line 1515 "y.tab.c"
    break;

  case 13: /* parameter_list: parameter_list COMMA type_specifier  */
#line 162 "22101848_22101069.y"
                {
			outlog << "At line no: " << lines << " parameter_list : parameter_list COMMA type_specifier " << endl << endl;
			outlog << yyvsp[-2]->getname() << "," << yyvsp[0]->getname() << endl << endl;
			
			yyval = new symbol_info(yyvsp[-2]->getname() + "," + yyvsp[0]->getname(), "param_list");

			pair<string, string> param(yyvsp[0]->getname(), "");
			current_func_params.push_back(param);
		}
#line 1529 "y.tab.c"
    break;

  case 14: /* parameter_list: type_specifier ID  */
#line 172 "22101848_22101069.y"
                {
			outlog << "At line no: " << lines << " parameter_list : type_specifier ID " << endl << endl;
			outlog << yyvsp[-1]->getname() << " " << yyvsp[0]->getname() << endl << endl;
			
			yyval = new symbol_info(yyvsp[-1]->getname() + " " + yyvsp[0]->getname(), "param_list");


			pair<string, string> param(yyvsp[-1]->getname(), yyvsp[0]->getname());
			current_func_params.push_back(param);
		}
#line 1544 "y.tab.c"
    break;

  case 15: /* parameter_list: type_specifier  */
#line 183 "22101848_22101069.y"
                {
			outlog << "At line no: " << lines << " parameter_list : type_specifier " << endl << endl;
			outlog << yyvsp[0]->getname() << endl << endl;
			
			yyval = new symbol_info(yyvsp[0]->getname(), "param_list");

			pair<string, string> param(yyvsp[0]->getname(), "");
			current_func_params.push_back(param);
		}
#line 1558 "y.tab.c"
    break;

  case 16: /* $@4: %empty  */
#line 194 "22101848_22101069.y"
                           {
		table->enter_scope();
		
		if(!current_func_params.empty()) {
			for(auto param : current_func_params) {
				if(!param.second.empty()) {
					symbol_info* param_symbol = new symbol_info(param.second, "ID", param.first);
					table->insert(param_symbol);
				}
			}
		}
	}
#line 1575 "y.tab.c"
    break;

  case 17: /* compound_statement: LCURL $@4 statements RCURL  */
#line 206 "22101848_22101069.y"
        { 
		outlog << "At line no: " << lines << " compound_statement : LCURL statements RCURL " << endl << endl;
		outlog << "{\n" + yyvsp[-1]->getname() + "\n}" << endl << endl;
		
		table->print_current_scope();
		
		table->exit_scope();
		
		yyval = new symbol_info("{\n" + yyvsp[-1]->getname() + "\n}", "comp_stmnt");
	}
#line 1590 "y.tab.c"
    break;

  case 18: /* $@5: %empty  */
#line 216 "22101848_22101069.y"
                {
		table->enter_scope();
	}
#line 1598 "y.tab.c"
    break;

  case 19: /* compound_statement: LCURL $@5 RCURL  */
#line 219 "22101848_22101069.y"
        { 
		outlog << "At line no: " << lines << " compound_statement : LCURL RCURL " << endl << endl;
		outlog << "{\n}" << endl << endl;
		
		table->print_current_scope();

		table->exit_scope();
		
		yyval = new symbol_info("{\n}", "comp_stmnt");
	}
#line 1613 "y.tab.c"
    break;

  case 20: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 232 "22101848_22101069.y"
                 {
			outlog << "At line no: " << lines << " var_declaration : type_specifier declaration_list SEMICOLON " << endl << endl;
			outlog << yyvsp[-2]->getname() << " " << yyvsp[-1]->getname() << ";" << endl << endl;
			
			yyval = new symbol_info(yyvsp[-2]->getname() + " " + yyvsp[-1]->getname() + ";", "var_dec");

			current_type = yyvsp[-2]->getname();
			if (current_type == "void") {
				outlog << "At line no: " << lines << " variable type can not be void " << endl << endl;
				error_log << "At line no: " << lines << " variable type can not be void " << endl << endl;
				error_count++;
			}
			current_type = "";
		 }
#line 1632 "y.tab.c"
    break;

  case 21: /* type_specifier: INT  */
#line 249 "22101848_22101069.y"
        {
		outlog << "At line no: " << lines << " type_specifier : INT " << endl << endl;
		outlog << "int" << endl << endl;
		
		yyval = new symbol_info("int", "type");
	}
#line 1643 "y.tab.c"
    break;

  case 22: /* type_specifier: FLOAT  */
#line 256 "22101848_22101069.y"
        {
		outlog << "At line no: " << lines << " type_specifier : FLOAT " << endl << endl;
		outlog << "float" << endl << endl;
		
		yyval = new symbol_info("float", "type");
	}
#line 1654 "y.tab.c"
    break;

  case 23: /* type_specifier: VOID  */
#line 263 "22101848_22101069.y"
        {
		outlog << "At line no: " << lines << " type_specifier : VOID " << endl << endl;
		outlog << "void" << endl << endl;
		
		yyval = new symbol_info("void", "type");
	}
#line 1665 "y.tab.c"
    break;

  case 24: /* declaration_list: declaration_list COMMA ID  */
#line 272 "22101848_22101069.y"
                  {
		  	outlog << "At line no: " << lines << " declaration_list : declaration_list COMMA ID " << endl << endl;
			outlog << yyvsp[-2]->getname() << "," << yyvsp[0]->getname() << endl << endl;
			
			yyval = new symbol_info(yyvsp[-2]->getname() + "," + yyvsp[0]->getname(), "decl_list");

			if(check_current_scope_variables(yyvsp[0]->getname())) {
				outlog << "At line no: " << lines << " Multiple declaration of variable " << yyvsp[0]->getname() << endl << endl;
				error_log << "At line no: " << lines << " Multiple declaration of variable " << yyvsp[0]->getname() << endl << endl;
				error_count++;
			}
			else {
				symbol_info* var = new symbol_info(yyvsp[0]->getname(), "ID", current_type);
				table->insert(var);
			}
		  }
#line 1686 "y.tab.c"
    break;

  case 25: /* declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD  */
#line 289 "22101848_22101069.y"
                  {
		  	outlog << "At line no: " << lines << " declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD " << endl << endl;
			outlog << yyvsp[-5]->getname() << "," << yyvsp[-3]->getname() << "[" << yyvsp[-1]->getname() << "]" << endl << endl;
			
			yyval = new symbol_info(yyvsp[-5]->getname() + "," + yyvsp[-3]->getname() + "[" + yyvsp[-1]->getname() + "]", "decl_list");

			if(check_current_scope_variables(yyvsp[-3]->getname())) {
				outlog << "At line no: " << lines << " Multiple declaration of variable " << yyvsp[-3]->getname() << endl << endl;
				error_log << "At line no: " << lines << " Multiple declaration of variable " << yyvsp[-3]->getname() << endl << endl;
				error_count++;
			}
			else {
				int array_sz = stoi(yyvsp[-1]->getname());
				symbol_info* arr = new symbol_info(yyvsp[-3]->getname(), "ID", current_type, array_sz);
				table->insert(arr);
			}
		  }
#line 1708 "y.tab.c"
    break;

  case 26: /* declaration_list: ID  */
#line 307 "22101848_22101069.y"
                  {
		  	outlog << "At line no: " << lines << " declaration_list : ID " << endl << endl;
			outlog << yyvsp[0]->getname() << endl << endl;
			
			yyval = new symbol_info(yyvsp[0]->getname(), "decl_list");

			if(check_current_scope_variables(yyvsp[0]->getname())) {
				outlog << "At line no: " << lines << " Multiple declaration of variable " << yyvsp[0]->getname() << endl << endl;
				error_log << "At line no: " << lines << " Multiple declaration of variable " << yyvsp[0]->getname() << endl << endl;
				error_count++;
			}
			else {
				symbol_info* var = new symbol_info(yyvsp[0]->getname(), "ID", current_type);
				table->insert(var);
			}
		  }
#line 1729 "y.tab.c"
    break;

  case 27: /* declaration_list: ID LTHIRD CONST_INT RTHIRD  */
#line 324 "22101848_22101069.y"
                  {
		  	outlog << "At line no: " << lines << " declaration_list : ID LTHIRD CONST_INT RTHIRD " << endl << endl;
			outlog << yyvsp[-3]->getname() << "[" << yyvsp[-1]->getname() << "]" << endl << endl;
			
			yyval = new symbol_info(yyvsp[-3]->getname() + "[" + yyvsp[-1]->getname() + "]", "decl_list");

			if(check_current_scope_variables(yyvsp[-3]->getname())) {
				outlog << "At line no: " << lines << " Multiple declaration of variable " << yyvsp[-3]->getname() << endl << endl;
				error_log << "At line no: " << lines << " Multiple declaration of variable " << yyvsp[-3]->getname() << endl << endl;
				error_count++;
			}
			else {
				int array_sz = stoi(yyvsp[-1]->getname());
				symbol_info* arr = new symbol_info(yyvsp[-3]->getname(), "ID", current_type, array_sz);
				table->insert(arr);
			}
		  }
#line 1751 "y.tab.c"
    break;

  case 28: /* statements: statement  */
#line 344 "22101848_22101069.y"
        {
	   	outlog << "At line no: " << lines << " statements : statement " << endl << endl;
		outlog << yyvsp[0]->getname() << endl << endl;
		
		yyval = new symbol_info(yyvsp[0]->getname(), "stmnts");
	}
#line 1762 "y.tab.c"
    break;

  case 29: /* statements: statements statement  */
#line 351 "22101848_22101069.y"
        {
	   	outlog << "At line no: " << lines << " statements : statements statement " << endl << endl;
		outlog << yyvsp[-1]->getname() + "\n" + yyvsp[0]->getname() << endl << endl;
		
		yyval = new symbol_info(yyvsp[-1]->getname() + "\n" + yyvsp[0]->getname(), "stmnts");
	}
#line 1773 "y.tab.c"
    break;

  case 30: /* statement: var_declaration  */
#line 360 "22101848_22101069.y"
        {
	   	outlog << "At line no: " << lines << " statement : var_declaration " << endl << endl;
		outlog << yyvsp[0]->getname() << endl << endl;
		
		yyval = new symbol_info(yyvsp[0]->getname(), "stmnt");
	}
#line 1784 "y.tab.c"
    break;

  case 31: /* statement: expression_statement  */
#line 367 "22101848_22101069.y"
        {
	   	outlog << "At line no: " << lines << " statement : expression_statement " << endl << endl;
		outlog << yyvsp[0]->getname() << endl << endl;
		
		yyval = new symbol_info(yyvsp[0]->getname(), "stmnt");
	}
#line 1795 "y.tab.c"
    break;

  case 32: /* statement: compound_statement  */
#line 374 "22101848_22101069.y"
        {
	   	outlog << "At line no: " << lines << " statement : compound_statement " << endl << endl;
		outlog << yyvsp[0]->getname() << endl << endl;
		
		yyval = new symbol_info(yyvsp[0]->getname(), "stmnt");
	}
#line 1806 "y.tab.c"
    break;

  case 33: /* statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement  */
#line 381 "22101848_22101069.y"
        {
	   	outlog << "At line no: " << lines << " statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement " << endl << endl;
		outlog << "for(" << yyvsp[-4]->getname() << yyvsp[-3]->getname() << yyvsp[-2]->getname() << ")\n" << yyvsp[0]->getname() << endl << endl;
		
		yyval = new symbol_info("for(" + yyvsp[-4]->getname() + yyvsp[-3]->getname() + yyvsp[-2]->getname() + ")\n" + yyvsp[0]->getname(), "stmnt");
	}
#line 1817 "y.tab.c"
    break;

  case 34: /* statement: IF LPAREN expression RPAREN statement  */
#line 388 "22101848_22101069.y"
        {
	   	outlog << "At line no: " << lines << " statement : IF LPAREN expression RPAREN statement " << endl << endl;
		outlog << "if(" << yyvsp[-2]->getname() << ")\n" << yyvsp[0]->getname() << endl << endl;
		
		yyval = new symbol_info("if(" + yyvsp[-2]->getname() + ")\n" + yyvsp[0]->getname(), "stmnt");
	}
#line 1828 "y.tab.c"
    break;

  case 35: /* statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 395 "22101848_22101069.y"
        {
	   	outlog << "At line no: " << lines << " statement : IF LPAREN expression RPAREN statement ELSE statement " << endl << endl;
		outlog << "if(" << yyvsp[-4]->getname() << ")\n" << yyvsp[-2]->getname() << "\nelse\n" << yyvsp[0]->getname() << endl << endl;
		
		yyval = new symbol_info("if(" + yyvsp[-4]->getname() + ")\n" + yyvsp[-2]->getname() + "\nelse\n" + yyvsp[0]->getname(), "stmnt");
	}
#line 1839 "y.tab.c"
    break;

  case 36: /* statement: WHILE LPAREN expression RPAREN statement  */
#line 402 "22101848_22101069.y"
        {
	   	outlog << "At line no: " << lines << " statement : WHILE LPAREN expression RPAREN statement " << endl << endl;
		outlog << "while(" << yyvsp[-2]->getname() << ")\n" << yyvsp[0]->getname() << endl << endl;
		
		yyval = new symbol_info("while(" + yyvsp[-2]->getname() + ")\n" + yyvsp[0]->getname(), "stmnt");
	}
#line 1850 "y.tab.c"
    break;

  case 37: /* statement: PRINTLN LPAREN ID RPAREN SEMICOLON  */
#line 409 "22101848_22101069.y"
        {
	   	outlog << "At line no: " << lines << " statement : PRINTLN LPAREN ID RPAREN SEMICOLON " << endl << endl;
		outlog << "printf(" << yyvsp[-2]->getname() << ");" << endl << endl;

		symbol_info* var_info = get_variable_info(yyvsp[-2]->getname());
		if (var_info == NULL) {
			outlog << "At line no: " << lines << " Undeclared variable " << yyvsp[-2]->getname() << endl << endl;
			error_log << "At line no: " << lines << " Undeclared variable " << yyvsp[-2]->getname() << endl << endl;
			error_count++;
		}
		
		yyval = new symbol_info("printf(" + yyvsp[-2]->getname() + ");", "stmnt");
	}
#line 1868 "y.tab.c"
    break;

  case 38: /* statement: RETURN expression SEMICOLON  */
#line 423 "22101848_22101069.y"
        {
	   	outlog << "At line no: " << lines << " statement : RETURN expression SEMICOLON " << endl << endl;
		outlog << "return " << yyvsp[-1]->getname() << ";" << endl << endl;
		
		yyval = new symbol_info("return " + yyvsp[-1]->getname() + ";", "stmnt");
	}
#line 1879 "y.tab.c"
    break;

  case 39: /* expression_statement: SEMICOLON  */
#line 432 "22101848_22101069.y"
                        {
				outlog << "At line no: " << lines << " expression_statement : SEMICOLON " << endl << endl;
				outlog << ";" << endl << endl;
				
				yyval = new symbol_info(";", "expr_stmt");
	        }
#line 1890 "y.tab.c"
    break;

  case 40: /* expression_statement: expression SEMICOLON  */
#line 439 "22101848_22101069.y"
                        {
				outlog << "At line no: " << lines << " expression_statement : expression SEMICOLON " << endl << endl;
				outlog << yyvsp[-1]->getname() << ";" << endl << endl;
				
				yyval = new symbol_info(yyvsp[-1]->getname() + ";", "expr_stmt");
	        }
#line 1901 "y.tab.c"
    break;

  case 41: /* variable: ID  */
#line 448 "22101848_22101069.y"
      {
	    outlog << "At line no: " << lines << " variable : ID " << endl << endl;
		outlog << yyvsp[0]->getname() << endl << endl;
		
		symbol_info* var_info = get_variable_info(yyvsp[0]->getname());

		if (var_info == NULL) {
			outlog << "At line no: " << lines << " Undeclared variable " << yyvsp[0]->getname() << endl << endl;
			error_log << "At line no: " << lines << " Undeclared variable " << yyvsp[0]->getname() << endl << endl;
			error_count++;
			
			yyval = new symbol_info(yyvsp[0]->getname(), "varbl");
			yyval->set_is_undefined_function();
		}
		else {
			yyval = new symbol_info(yyvsp[0]->getname(), "varbl");
			yyval->set_data_type(var_info->get_data_type());
			
			if (var_info->get_is_array()) {
				outlog << "At line no: " << lines << " variable is of array type : " << yyvsp[0]->getname() << endl << endl;
				error_log << "At line no: " << lines << " variable is of array type : " << yyvsp[0]->getname() << endl << endl;
				error_count++;
			}
		}
	 }
#line 1931 "y.tab.c"
    break;

  case 42: /* variable: ID LTHIRD expression RTHIRD  */
#line 474 "22101848_22101069.y"
         {
	 	outlog << "At line no: " << lines << " variable : ID LTHIRD expression RTHIRD " << endl << endl;
		outlog << yyvsp[-3]->getname() << "[" << yyvsp[-1]->getname() << "]" << endl << endl;
		
		symbol_info* var_info = get_variable_info(yyvsp[-3]->getname());
		
		if (var_info == NULL) {
			outlog << "At line no: " << lines << " Undeclared variable " << yyvsp[-3]->getname() << endl << endl;
			error_log << "At line no: " << lines << " Undeclared variable " << yyvsp[-3]->getname() << endl << endl;
			error_count++;
			
			yyval = new symbol_info(yyvsp[-3]->getname() + "[" + yyvsp[-1]->getname() + "]", "varbl");
		}
		else {
			yyval = new symbol_info(yyvsp[-3]->getname() + "[" + yyvsp[-1]->getname() + "]", "varbl");
			yyval->set_data_type(var_info->get_data_type());
			
			if (!var_info->get_is_array()) {
				outlog << "At line no: " << lines << " variable is not of array type : " << yyvsp[-3]->getname() << endl << endl;
				error_log << "At line no: " << lines << " variable is not of array type : " << yyvsp[-3]->getname() << endl << endl;
				error_count++;
			}
			
			if (yyvsp[-1]->get_data_type() != "int") {
				outlog << "At line no: " << lines << " array index is not of integer type" << endl << endl;
				error_log << "At line no: " << lines << " array index is not of integer type" << endl << endl;
				error_count++;
			}
		}
	 }
#line 1966 "y.tab.c"
    break;

  case 43: /* expression: logic_expression  */
#line 507 "22101848_22101069.y"
        {
	   	outlog << "At line no: " << lines << " expression : logic_expression " << endl << endl;
		outlog << yyvsp[0]->getname() << endl << endl;
		
		yyval = new symbol_info(yyvsp[0]->getname(), "expr");
		yyval->set_data_type(yyvsp[0]->get_data_type());
		
		if (yyvsp[0]->get_is_function()) {
			yyval->set_as_function(yyvsp[0]->get_return_type(), yyvsp[0]->get_parameters());
		}
	}
#line 1982 "y.tab.c"
    break;

  case 44: /* expression: variable ASSIGNOP logic_expression  */
#line 519 "22101848_22101069.y"
        {
	   	outlog << "At line no: " << lines << " expression : variable ASSIGNOP logic_expression " << endl << endl;
		outlog << yyvsp[-2]->getname() << "=" << yyvsp[0]->getname() << endl << endl;
		
		yyval = new symbol_info(yyvsp[-2]->getname() + "=" + yyvsp[0]->getname(), "expr");

		string left_type = yyvsp[-2]->get_data_type();
		string right_type = yyvsp[0]->get_data_type();

		if (yyvsp[0]->get_is_function()) {
			if (yyvsp[0]->get_return_type() == "void") {
				outlog << "At line no: " << lines << " operation on void type" << endl << endl;
				error_log << "At line no: " << lines << " operation on void type" << endl << endl;
				error_count++;
			}
			right_type = yyvsp[0]->get_return_type();
		}

		// Check for float to int assignment (should trigger even if left is undeclared but we know it's int from context)
		if (!yyvsp[-2]->get_is_undefined_function() && left_type == "int" && right_type == "float") {
			outlog << "At line no: " << lines << " Warning: Assignment of float value into variable of integer type " << endl << endl;
			error_log << "At line no: " << lines << " Warning: Assignment of float value into variable of integer type " << endl << endl;
			error_count++;
		}

		if (left_type != "" && right_type != "" && left_type != right_type && !(left_type == "float" && right_type == "int")) {
			outlog << "At line no: " << lines << " Type mismatch in assignment" << endl << endl;
			error_log << "At line no: " << lines << " Type mismatch in assignment" << endl << endl;
			error_count++;
		}
	}
#line 2018 "y.tab.c"
    break;

  case 45: /* logic_expression: rel_expression  */
#line 553 "22101848_22101069.y"
        {
	   	outlog << "At line no: " << lines << " logic_expression : rel_expression " << endl << endl;
		outlog << yyvsp[0]->getname() << endl << endl;
		
		yyval = new symbol_info(yyvsp[0]->getname(), "logic_expr");
		yyval->set_data_type(yyvsp[0]->get_data_type());
		
		if (yyvsp[0]->get_is_function()) {
			yyval->set_as_function(yyvsp[0]->get_return_type(), yyvsp[0]->get_parameters());
		}
		if (yyvsp[0]->get_is_undefined_function()) {
			yyval->set_is_undefined_function();
		}
	}
#line 2037 "y.tab.c"
    break;

  case 46: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 568 "22101848_22101069.y"
        {
	   	outlog << "At line no: " << lines << " logic_expression : rel_expression LOGICOP rel_expression " << endl << endl;
		outlog << yyvsp[-2]->getname() << yyvsp[-1]->getname() << yyvsp[0]->getname() << endl << endl;
		
		yyval = new symbol_info(yyvsp[-2]->getname() + yyvsp[-1]->getname() + yyvsp[0]->getname(), "logic_expr");
		yyval->set_data_type("int");

		if (yyvsp[-2]->get_is_function() && yyvsp[-2]->get_return_type() == "void") {
			outlog << "At line no: " << lines << " operation on void type" << endl << endl;
			error_log << "At line no: " << lines << " operation on void type" << endl << endl;
			error_count++;
		}

		if (yyvsp[0]->get_is_function() && yyvsp[0]->get_return_type() == "void") {
			outlog << "At line no: " << lines << " operation on void type" << endl << endl;
			error_log << "At line no: " << lines << " operation on void type" << endl << endl;
			error_count++;
		}
	}
#line 2061 "y.tab.c"
    break;

  case 47: /* rel_expression: simple_expression  */
#line 590 "22101848_22101069.y"
        {
	   	outlog << "At line no: " << lines << " rel_expression : simple_expression " << endl << endl;
		outlog << yyvsp[0]->getname() << endl << endl;
		
		yyval = new symbol_info(yyvsp[0]->getname(), "rel_expr");
		yyval->set_data_type(yyvsp[0]->get_data_type());
		
		if (yyvsp[0]->get_is_function()) {
			yyval->set_as_function(yyvsp[0]->get_return_type(), yyvsp[0]->get_parameters());
		}
		if (yyvsp[0]->get_is_undefined_function()) {
			yyval->set_is_undefined_function();
		}
	}
#line 2080 "y.tab.c"
    break;

  case 48: /* rel_expression: simple_expression RELOP simple_expression  */
#line 605 "22101848_22101069.y"
        {
	   	outlog << "At line no: " << lines << " rel_expression : simple_expression RELOP simple_expression " << endl << endl;
		outlog << yyvsp[-2]->getname() << yyvsp[-1]->getname() << yyvsp[0]->getname() << endl << endl;
		
		yyval = new symbol_info(yyvsp[-2]->getname() + yyvsp[-1]->getname() + yyvsp[0]->getname(), "rel_expr");
		yyval->set_data_type("int");

		if (yyvsp[-2]->get_is_function() && yyvsp[-2]->get_return_type() == "void") {
			outlog << "At line no: " << lines << " operation on void type" << endl << endl;
			error_log << "At line no: " << lines << " operation on void type" << endl << endl;
			error_count++;
		}

		if (yyvsp[0]->get_is_function() && yyvsp[0]->get_return_type() == "void") {
			outlog << "At line no: " << lines << " operation on void type" << endl << endl;
			error_log << "At line no: " << lines << " operation on void type" << endl << endl;
			error_count++;
		}
	}
#line 2104 "y.tab.c"
    break;

  case 49: /* simple_expression: term  */
#line 627 "22101848_22101069.y"
        {
	   	outlog << "At line no: " << lines << " simple_expression : term " << endl << endl;
		outlog << yyvsp[0]->getname() << endl << endl;
		
		yyval = new symbol_info(yyvsp[0]->getname(), "simp_expr");
		yyval->set_data_type(yyvsp[0]->get_data_type());
		
		if (yyvsp[0]->get_is_function()) {
			yyval->set_as_function(yyvsp[0]->get_return_type(), yyvsp[0]->get_parameters());
		}
		if (yyvsp[0]->get_is_undefined_function()) {
			yyval->set_is_undefined_function();
		}
	}
#line 2123 "y.tab.c"
    break;

  case 50: /* simple_expression: simple_expression ADDOP term  */
#line 642 "22101848_22101069.y"
        {
	   	outlog << "At line no: " << lines << " simple_expression : simple_expression ADDOP term " << endl << endl;
		outlog << yyvsp[-2]->getname() << yyvsp[-1]->getname() << yyvsp[0]->getname() << endl << endl;
		
		yyval = new symbol_info(yyvsp[-2]->getname() + yyvsp[-1]->getname() + yyvsp[0]->getname(), "simp_expr");

		string type1 = yyvsp[-2]->get_data_type();
		string type3 = yyvsp[0]->get_data_type();

		if (yyvsp[-2]->get_is_function()) {
			type1 = yyvsp[-2]->get_return_type();
			if (type1 == "void") {
				outlog << "At line no: " << lines << " operation on void type" << endl << endl;
				error_log << "At line no: " << lines << " operation on void type" << endl << endl;
				error_count++;
			}
		}

		if (yyvsp[0]->get_is_function()) {
			type3 = yyvsp[0]->get_return_type();
			if (type3 == "void") {
				outlog << "At line no: " << lines << " operation on void type" << endl << endl;
				error_log << "At line no: " << lines << " operation on void type" << endl << endl;
				error_count++;
			}
		}

		if (type1 == "float" || type3 == "float") {
			yyval->set_data_type("float");
		} else {
			yyval->set_data_type("int");
		}
	}
#line 2161 "y.tab.c"
    break;

  case 51: /* term: unary_expression  */
#line 678 "22101848_22101069.y"
        {
	   	outlog << "At line no: " << lines << " term : unary_expression " << endl << endl;
		outlog << yyvsp[0]->getname() << endl << endl;
		
		yyval = new symbol_info(yyvsp[0]->getname(), "term");
		yyval->set_data_type(yyvsp[0]->get_data_type());
		
		if (yyvsp[0]->get_is_function()) {
			yyval->set_as_function(yyvsp[0]->get_return_type(), yyvsp[0]->get_parameters());
		}
		if (yyvsp[0]->get_is_undefined_function()) {
			yyval->set_is_undefined_function();
		}
	}
#line 2180 "y.tab.c"
    break;

  case 52: /* term: term MULOP unary_expression  */
#line 693 "22101848_22101069.y"
        {
	   	outlog << "At line no: " << lines << " term : term MULOP unary_expression " << endl << endl;
		outlog << yyvsp[-2]->getname() << yyvsp[-1]->getname() << yyvsp[0]->getname() << endl << endl;
		
		yyval = new symbol_info(yyvsp[-2]->getname() + yyvsp[-1]->getname() + yyvsp[0]->getname(), "term");

		string type1 = yyvsp[-2]->get_data_type();
		string type3 = yyvsp[0]->get_data_type();

		if (yyvsp[-2]->get_is_function()) {
			type1 = yyvsp[-2]->get_return_type();
			if (type1 == "void") {
				outlog << "At line no: " << lines << " operation on void type" << endl << endl;
				error_log << "At line no: " << lines << " operation on void type" << endl << endl;
				error_count++;
			}
		}

		if (yyvsp[0]->get_is_function()) {
			type3 = yyvsp[0]->get_return_type();
			if (type3 == "void") {
				outlog << "At line no: " << lines << " operation on void type" << endl << endl;
				error_log << "At line no: " << lines << " operation on void type" << endl << endl;
				error_count++;
			}
		}

		if (yyvsp[-1]->getname() == "%") {
			if (type1 != "int" || type3 != "int") {
				outlog << "At line no: " << lines << " Modulus operator on non integer type" << endl << endl;
				error_log << "At line no: " << lines << " Modulus operator on non integer type" << endl << endl;
				error_count++;
			}
		}

		if (yyvsp[-1]->getname() == "/" || yyvsp[-1]->getname() == "%") {
			if (yyvsp[0]->getname() == "0") {
				outlog << "At line no: " << lines << " Modulus by 0" << endl << endl;
				error_log << "At line no: " << lines << " Modulus by 0" << endl << endl;
				error_count++;
			}
		}

		if (type1 == "float" || type3 == "float") {
			yyval->set_data_type("float");
		} else {
			yyval->set_data_type("int");
		}
	}
#line 2234 "y.tab.c"
    break;

  case 53: /* unary_expression: ADDOP unary_expression  */
#line 745 "22101848_22101069.y"
                 {
	    	outlog << "At line no: " << lines << " unary_expression : ADDOP unary_expression " << endl << endl;
			outlog << yyvsp[-1]->getname() << yyvsp[0]->getname() << endl << endl;
			
			yyval = new symbol_info(yyvsp[-1]->getname() + yyvsp[0]->getname(), "un_expr");
			yyval->set_data_type(yyvsp[0]->get_data_type());

			if (yyvsp[0]->get_is_function() && yyvsp[0]->get_return_type() == "void") {
				outlog << "At line no: " << lines << " operation on void type" << endl << endl;
				error_log << "At line no: " << lines << " operation on void type" << endl << endl;
				error_count++;
			}
	     }
#line 2252 "y.tab.c"
    break;

  case 54: /* unary_expression: NOT unary_expression  */
#line 759 "22101848_22101069.y"
                 {
	    	outlog << "At line no: " << lines << " unary_expression : NOT unary_expression " << endl << endl;
			outlog << "!" << yyvsp[0]->getname() << endl << endl;
			
			yyval = new symbol_info("!" + yyvsp[0]->getname(), "un_expr");
			yyval->set_data_type("int");
	     }
#line 2264 "y.tab.c"
    break;

  case 55: /* unary_expression: factor  */
#line 767 "22101848_22101069.y"
                 {
	    	outlog << "At line no: " << lines << " unary_expression : factor " << endl << endl;
			outlog << yyvsp[0]->getname() << endl << endl;
			
			yyval = new symbol_info(yyvsp[0]->getname(), "un_expr");
			yyval->set_data_type(yyvsp[0]->get_data_type());

			if (yyvsp[0]->get_is_function()) {
				yyval->set_as_function(yyvsp[0]->get_return_type(), yyvsp[0]->get_parameters());
	     	}
			if (yyvsp[0]->get_is_undefined_function()) {
				yyval->set_is_undefined_function();
			}
		 }
#line 2283 "y.tab.c"
    break;

  case 56: /* factor: variable  */
#line 785 "22101848_22101069.y"
    {
	    outlog << "At line no: " << lines << " factor : variable " << endl << endl;
		outlog << yyvsp[0]->getname() << endl << endl;
			
		yyval = new symbol_info(yyvsp[0]->getname(), "fctr");
		yyval->set_data_type(yyvsp[0]->get_data_type());

		if (yyvsp[0]->get_is_undefined_function()) {
			yyval->set_is_undefined_function();
		}
	}
#line 2299 "y.tab.c"
    break;

  case 57: /* factor: ID LPAREN argument_list RPAREN  */
#line 797 "22101848_22101069.y"
        {
	    outlog << "At line no: " << lines << " factor : ID LPAREN argument_list RPAREN " << endl << endl;
		outlog << yyvsp[-3]->getname() << "(" << yyvsp[-1]->getname() << ")" << endl << endl;

		symbol_info* func_info = get_variable_info(yyvsp[-3]->getname());
		yyval = new symbol_info(yyvsp[-3]->getname() + "(" + yyvsp[-1]->getname() + ")", "fctr");

		if (func_info == NULL) {
			outlog << "At line no: " << lines << " Undeclared function: " << yyvsp[-3]->getname() << endl << endl;
			error_log << "At line no: " << lines << " Undeclared function: " << yyvsp[-3]->getname() << endl << endl;
			error_count++;
			yyval->set_is_undefined_function();
		}
		else if (!func_info->get_is_function()) {
			outlog << "At line no: " << lines << " " << yyvsp[-3]->getname() << " is not a function" << endl << endl;
			error_log << "At line no: " << lines << " " << yyvsp[-3]->getname() << " is not a function" << endl << endl;
			error_count++;
		}
		else {
			yyval->set_as_function(func_info->get_return_type(), func_info->get_parameters());

			vector<pair<string, string> > params = func_info->get_parameters();
			if (current_func_params.size() != params.size()) {
				outlog << "At line no: " << lines << " Inconsistencies in number of arguments in function call : " << yyvsp[-3]->getname() << endl << endl;
				error_log << "At line no: " << lines << " Inconsistencies in number of arguments in function call : " << yyvsp[-3]->getname() << endl << endl;
				error_count++;
			}
			else {
				for (int i = 0; i < current_func_params.size(); i++) {
					symbol_info* arg_info = get_variable_info(current_func_params[i].first);
					string arg_type = current_func_params[i].second;

					if (arg_info != NULL && !arg_info->get_is_array()) {
						if (arg_type != params[i].first) {
							outlog << "At line no: " << lines << " argument " << (i+1) << " type mismatch in function call: " << yyvsp[-3]->getname() << endl << endl;
							error_log << "At line no: " << lines << " argument " << (i+1) << " type mismatch in function call: " << yyvsp[-3]->getname() << endl << endl;
							error_count++;
						}
					}
				}
			}
		}

		current_func_params.clear();
	}
#line 2349 "y.tab.c"
    break;

  case 58: /* factor: LPAREN expression RPAREN  */
#line 843 "22101848_22101069.y"
        {
	   	outlog << "At line no: " << lines << " factor : LPAREN expression RPAREN " << endl << endl;
		outlog << "(" << yyvsp[-1]->getname() << ")" << endl << endl;
		
		yyval = new symbol_info("(" + yyvsp[-1]->getname() + ")", "fctr");
		yyval->set_data_type(yyvsp[-1]->get_data_type());
	}
#line 2361 "y.tab.c"
    break;

  case 59: /* factor: CONST_INT  */
#line 851 "22101848_22101069.y"
        {
	    outlog << "At line no: " << lines << " factor : CONST_INT " << endl << endl;
		outlog << yyvsp[0]->getname() << endl << endl;
			
		yyval = new symbol_info(yyvsp[0]->getname(), "fctr");
		yyval->set_data_type("int");
	}
#line 2373 "y.tab.c"
    break;

  case 60: /* factor: CONST_FLOAT  */
#line 859 "22101848_22101069.y"
        {
	    outlog << "At line no: " << lines << " factor : CONST_FLOAT " << endl << endl;
		outlog << yyvsp[0]->getname() << endl << endl;
		
		yyval = new symbol_info(yyvsp[0]->getname(), "fctr");
		yyval->set_data_type("float");
	}
#line 2385 "y.tab.c"
    break;

  case 61: /* factor: variable INCOP  */
#line 867 "22101848_22101069.y"
        {
	    outlog << "At line no: " << lines << " factor : variable INCOP " << endl << endl;
		outlog << yyvsp[-1]->getname() << "++" << endl << endl;
			
		yyval = new symbol_info(yyvsp[-1]->getname() + "++", "fctr");
		yyval->set_data_type(yyvsp[-1]->get_data_type());
	}
#line 2397 "y.tab.c"
    break;

  case 62: /* factor: variable DECOP  */
#line 875 "22101848_22101069.y"
        {
	    outlog << "At line no: " << lines << " factor : variable DECOP " << endl << endl;
		outlog << yyvsp[-1]->getname() << "--" << endl << endl;
			
		yyval = new symbol_info(yyvsp[-1]->getname() + "--", "fctr");
		yyval->set_data_type(yyvsp[-1]->get_data_type());
	}
#line 2409 "y.tab.c"
    break;

  case 63: /* argument_list: arguments  */
#line 885 "22101848_22101069.y"
                          {
					outlog << "At line no: " << lines << " argument_list : arguments " << endl << endl;
					outlog << yyvsp[0]->getname() << endl << endl;
						
					yyval = new symbol_info(yyvsp[0]->getname(), "arg_list");
			  }
#line 2420 "y.tab.c"
    break;

  case 64: /* argument_list: %empty  */
#line 892 "22101848_22101069.y"
                          {
					outlog << "At line no: " << lines << " argument_list :  " << endl << endl;
					outlog << "" << endl << endl;
						
					yyval = new symbol_info("", "arg_list");
			  }
#line 2431 "y.tab.c"
    break;

  case 65: /* arguments: arguments COMMA logic_expression  */
#line 901 "22101848_22101069.y"
                  {
				outlog << "At line no: " << lines << " arguments : arguments COMMA logic_expression " << endl << endl;
				outlog << yyvsp[-2]->getname() << "," << yyvsp[0]->getname() << endl << endl;
				
				pair<string, string> param(yyvsp[0]->getname(), yyvsp[0]->get_data_type());
				current_func_params.push_back(param);
						
				yyval = new symbol_info(yyvsp[-2]->getname() + "," + yyvsp[0]->getname(), "arg");
		  }
#line 2445 "y.tab.c"
    break;

  case 66: /* arguments: logic_expression  */
#line 911 "22101848_22101069.y"
              {
				outlog << "At line no: " << lines << " arguments : logic_expression " << endl << endl;
				outlog << yyvsp[0]->getname() << endl << endl;
				
				pair<string, string> param(yyvsp[0]->getname(), yyvsp[0]->get_data_type());
				current_func_params.push_back(param);
						
				yyval = new symbol_info(yyvsp[0]->getname(), "arg");
		  }
#line 2459 "y.tab.c"
    break;


#line 2463 "y.tab.c"

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

#line 923 "22101848_22101069.y"


int main(int argc, char *argv[])
{
	if(argc != 2) 
	{
		cout << "Please input file name" << endl;
		return 0;
	}
	yyin = fopen(argv[1], "r");
	outlog.open("22101848_22101069_log.txt", ios::trunc);
	error_log.open("22101848_22101069_error.txt", ios::trunc);


	if(yyin == NULL)
	{
		cout << "Couldn't open file" << endl;
		return 0;
	}

	table = new symbol_table(10);  
	
	yyparse();
	
	delete table;
	
	outlog << endl << "Total lines: " << lines << endl;
	outlog << "Total errors: " << error_count << endl;

	error_log << "Total errors: " << error_count << endl;
	outlog.close();
	error_log.close();
	fclose(yyin);
	
	return 0;
}
