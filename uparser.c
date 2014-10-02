/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is included that follows the "include" declaration
** in the input grammar file. */
#include <stdio.h>
#line 3 "uparser.y"

#include <stdio.h>
#include "basetypes.h"
#include "ucodegen.h"
#include "uparser.h"
#include "ulexer.h"
#line 15 "uparser.c"
/* Next is all token values, in a form suitable for use by makeheaders.
** This section will be null unless lemon is run with the -m switch.
*/
/* 
** These constants (all generated automatically by the parser generator)
** specify the various kinds of tokens (terminals) that the parser
** understands. 
**
** Each symbol here is a terminal symbol in the grammar.
*/
/* Make sure the INTERFACE macro is defined.
*/
#ifndef INTERFACE
# define INTERFACE 1
#endif
/* The next thing included is series of defines which control
** various aspects of the generated parser.
**    YYCODETYPE         is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 terminals
**                       and nonterminals.  "int" is used otherwise.
**    YYNOCODE           is a number of type YYCODETYPE which corresponds
**                       to no legal terminal or nonterminal number.  This
**                       number is used to fill in empty slots of the hash 
**                       table.
**    YYFALLBACK         If defined, this indicates that one or more tokens
**                       have fall-back values which should be used if the
**                       original value of the token will not parse.
**    YYACTIONTYPE       is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 rules and
**                       states combined.  "int" is used otherwise.
**    ParseTOKENTYPE     is the data type used for minor tokens given 
**                       directly to the parser from the tokenizer.
**    YYMINORTYPE        is the data type used for all minor tokens.
**                       This is typically a union of many types, one of
**                       which is ParseTOKENTYPE.  The entry in the union
**                       for base tokens is called "yy0".
**    YYSTACKDEPTH       is the maximum depth of the parser's stack.  If
**                       zero the stack is dynamically sized using realloc()
**    ParseARG_SDECL     A static variable declaration for the %extra_argument
**    ParseARG_PDECL     A parameter declaration for the %extra_argument
**    ParseARG_STORE     Code to store %extra_argument into yypParser
**    ParseARG_FETCH     Code to extract %extra_argument from yypParser
**    YYNSTATE           the combined number of states.
**    YYNRULE            the number of rules in the grammar
**    YYERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
*/
#define YYCODETYPE unsigned char
#define YYNOCODE 84
#define YYACTIONTYPE unsigned char
#define ParseTOKENTYPE Token
typedef union {
  int yyinit;
  ParseTOKENTYPE yy0;
  Instruction* yy15;
  Register* yy88;
} YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 100
#endif
#define ParseARG_SDECL  Function* f ;
#define ParseARG_PDECL , Function* f 
#define ParseARG_FETCH  Function* f  = yypParser->f 
#define ParseARG_STORE yypParser->f  = f 
#define YYNSTATE 156
#define YYNRULE 81
#define YYFALLBACK 1
#define YY_NO_ACTION      (YYNSTATE+YYNRULE+2)
#define YY_ACCEPT_ACTION  (YYNSTATE+YYNRULE+1)
#define YY_ERROR_ACTION   (YYNSTATE+YYNRULE)

/* The yyzerominor constant is used to initialize instances of
** YYMINORTYPE objects to zero. */
static const YYMINORTYPE yyzerominor = { 0 };

/* Define the yytestcase() macro to be a no-op if is not already defined
** otherwise.
**
** Applications can choose to define yytestcase() in the %include section
** to a macro that can assist in verifying code coverage.  For production
** code the yytestcase() macro should be turned off.  But it is useful
** for testing.
*/
#ifndef yytestcase
# define yytestcase(X)
#endif


/* Next are the tables used to determine what action to take based on the
** current state and lookahead token.  These tables are used to implement
** functions that take a state number and lookahead value and return an
** action integer.  
**
** Suppose the action integer is N.  Then the action is determined as
** follows
**
**   0 <= N < YYNSTATE                  Shift N.  That is, push the lookahead
**                                      token onto the stack and goto state N.
**
**   YYNSTATE <= N < YYNSTATE+YYNRULE   Reduce by rule N-YYNSTATE.
**
**   N == YYNSTATE+YYNRULE              A syntax error has occurred.
**
**   N == YYNSTATE+YYNRULE+1            The parser accepts its input.
**
**   N == YYNSTATE+YYNRULE+2            No such action.  Denotes unused
**                                      slots in the yy_action[] table.
**
** The action table is constructed as a single large table named yy_action[].
** Given state S and lookahead X, the action is computed as
**
**      yy_action[ yy_shift_ofst[S] + X ]
**
** If the index value yy_shift_ofst[S]+X is out of range or if the value
** yy_lookahead[yy_shift_ofst[S]+X] is not equal to X or if yy_shift_ofst[S]
** is equal to YY_SHIFT_USE_DFLT, it means that the action is not in the table
** and that yy_default[S] should be used instead.  
**
** The formula above is for computing the action when the lookahead is
** a terminal symbol.  If the lookahead is a non-terminal (as occurs after
** a reduce action) then the yy_reduce_ofst[] array is used in place of
** the yy_shift_ofst[] array and YY_REDUCE_USE_DFLT is used in place of
** YY_SHIFT_USE_DFLT.
**
** The following are the tables generated in this section:
**
**  yy_action[]        A single table containing all actions.
**  yy_lookahead[]     A table containing the lookahead for each entry in
**                     yy_action.  Used to detect hash collisions.
**  yy_shift_ofst[]    For each state, the offset into yy_action for
**                     shifting terminals.
**  yy_reduce_ofst[]   For each state, the offset into yy_action for
**                     shifting non-terminals after a reduce.
**  yy_default[]       Default action for each state.
*/
#define YY_ACTTAB_COUNT (620)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    41,   13,   26,   23,   22,   22,   22,   22,   22,   22,
 /*    10 */    21,   20,   20,   20,   20,   20,   38,   11,   20,   26,
 /*    20 */    23,   22,   22,   22,   22,   22,   22,   21,   20,   20,
 /*    30 */    20,   20,   20,   15,  156,   20,  143,   65,   31,  238,
 /*    40 */   107,  151,   51,  142,   26,   23,   22,   22,   22,   22,
 /*    50 */    22,   22,   21,   20,   20,   20,   20,   20,   46,  125,
 /*    60 */    20,  146,  145,   78,   72,  130,   91,   90,    5,  141,
 /*    70 */    26,   23,   22,   22,   22,   22,   22,   22,   21,   20,
 /*    80 */    20,   20,   20,   20,    8,  150,   20,   20,   20,   20,
 /*    90 */   126,   20,   20,   86,   99,   26,   23,   22,   22,   22,
 /*   100 */    22,   22,   22,   21,   20,   20,   20,   20,   20,  140,
 /*   110 */   123,   20,  122,   37,   83,  127,    2,  139,   81,  129,
 /*   120 */    26,   23,   22,   22,   22,   22,   22,   22,   21,   20,
 /*   130 */    20,   20,   20,   20,  136,  123,   20,   12,   26,   23,
 /*   140 */    22,   22,   22,   22,   22,   22,   21,   20,   20,   20,
 /*   150 */    20,   20,  102,   18,   20,   26,   23,   22,   22,   22,
 /*   160 */    22,   22,   22,   21,   20,   20,   20,   20,   20,   19,
 /*   170 */   128,   20,  138,   10,  101,  143,   54,   31,   47,   19,
 /*   180 */    16,  100,  142,   19,   94,   28,   51,  210,  106,  120,
 /*   190 */    51,  144,   47,   93,   32,  100,    6,   79,  115,  210,
 /*   200 */   146,  145,   24,  137,   39,  209,   24,   24,   86,  149,
 /*   210 */   149,  149,  149,  148,  147,   17,   24,  209,    2,  132,
 /*   220 */    24,   24,   19,  149,  149,  149,  149,  148,  147,   17,
 /*   230 */   139,   47,    2,  134,  144,   23,   22,   22,   22,   22,
 /*   240 */    22,   22,   21,   20,   20,   20,   20,   20,  121,   76,
 /*   250 */    20,   30,  105,   14,   51,   24,  142,  119,  114,   24,
 /*   260 */    24,  135,  149,  149,  149,  149,  148,  147,  113,  112,
 /*   270 */   124,    2,   22,   22,   22,   22,   22,   22,   21,   20,
 /*   280 */    20,   20,   20,   20,   19,   15,   20,  103,    4,   51,
 /*   290 */   143,   62,   31,   47,   89,   19,  144,  142,    9,   42,
 /*   300 */   215,   27,   29,    1,   34,  138,   45,  144,    4,   95,
 /*   310 */    44,   51,  109,    7,   43,  146,  145,   24,  154,  215,
 /*   320 */   215,   24,   24,  108,  149,  149,  149,  149,  148,  147,
 /*   330 */     3,  155,   73,    2,   30,   77,  133,  153,  152,   70,
 /*   340 */    48,   49,   40,   33,  215,  215,   75,   50,  215,   96,
 /*   350 */    21,   20,   20,   20,   20,   20,   88,  118,   20,   51,
 /*   360 */   143,   54,   31,   36,  116,  111,   51,  142,  143,   53,
 /*   370 */    31,   74,   92,  239,   51,  142,   82,   35,   51,  239,
 /*   380 */   143,   62,   31,  117,   87,  146,  145,  142,  239,  110,
 /*   390 */   239,  239,  239,  146,  145,  143,   62,   31,  239,   85,
 /*   400 */   239,  239,  142,  239,  239,  146,  145,  143,   62,   31,
 /*   410 */   239,   84,  239,  239,  142,  143,   62,   31,    5,   80,
 /*   420 */   146,  145,  142,  143,   65,   31,  239,  239,  239,  239,
 /*   430 */   142,  239,  146,  145,  239,  239,  239,   97,   98,  239,
 /*   440 */   146,  145,  239,  143,   58,   31,  239,  239,  146,  145,
 /*   450 */   142,  239,  131,  143,   66,   31,  239,  239,  239,  239,
 /*   460 */   142,  239,  122,   25,  239,  239,    2,  239,  146,  145,
 /*   470 */   143,   55,   31,  143,  104,   31,  239,  142,  146,  145,
 /*   480 */   142,  239,  239,  239,  143,   67,   31,  143,   69,   31,
 /*   490 */   239,  142,  239,  239,  142,  146,  145,  239,  146,  145,
 /*   500 */   239,  239,  239,  239,  143,   68,   31,  239,  239,  146,
 /*   510 */   145,  142,  146,  145,  143,   71,   31,  143,   57,   31,
 /*   520 */   239,  142,  239,  239,  142,  143,   64,   31,  239,  146,
 /*   530 */   145,  239,  142,  239,  143,   56,   31,  239,  239,  146,
 /*   540 */   145,  142,  146,  145,  239,  143,   63,   31,  239,  239,
 /*   550 */   146,  145,  142,  239,  239,  239,  239,  239,  239,  146,
 /*   560 */   145,  239,  239,  239,  239,  143,   61,   31,  239,  239,
 /*   570 */   146,  145,  142,  143,   60,   31,  239,  239,  239,  239,
 /*   580 */   142,  143,   52,   31,  239,  239,  239,  239,  142,  239,
 /*   590 */   146,  145,  239,  143,   59,   31,  239,  239,  146,  145,
 /*   600 */   142,  239,  239,  239,  239,  239,  146,  145,  239,  239,
 /*   610 */   239,  239,  239,  239,  239,  239,  239,  239,  146,  145,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     5,   23,   24,   25,   26,   27,   28,   29,   30,   31,
 /*    10 */    32,   33,   34,   35,   36,   37,   15,   16,   40,   24,
 /*    20 */    25,   26,   27,   28,   29,   30,   31,   32,   33,   34,
 /*    30 */    35,   36,   37,   23,    0,   40,   53,   54,   55,   63,
 /*    40 */    64,    6,   66,   60,   24,   25,   26,   27,   28,   29,
 /*    50 */    30,   31,   32,   33,   34,   35,   36,   37,   72,   49,
 /*    60 */    40,   78,   79,   77,   81,   82,   21,   22,    2,   49,
 /*    70 */    24,   25,   26,   27,   28,   29,   30,   31,   32,   33,
 /*    80 */    34,   35,   36,   37,   14,    6,   40,   35,   36,   37,
 /*    90 */    59,   40,   40,   23,   48,   24,   25,   26,   27,   28,
 /*   100 */    29,   30,   31,   32,   33,   34,   35,   36,   37,    6,
 /*   110 */    79,   40,   46,   17,   10,   59,   50,   13,   23,   48,
 /*   120 */    24,   25,   26,   27,   28,   29,   30,   31,   32,   33,
 /*   130 */    34,   35,   36,   37,    2,   79,   40,   23,   24,   25,
 /*   140 */    26,   27,   28,   29,   30,   31,   32,   33,   34,   35,
 /*   150 */    36,   37,   58,   11,   40,   24,   25,   26,   27,   28,
 /*   160 */    29,   30,   31,   32,   33,   34,   35,   36,   37,    1,
 /*   170 */    13,   40,   13,   11,   80,   53,   54,   55,   10,    1,
 /*   180 */    11,   13,   60,    1,   64,   23,   66,   11,   64,   69,
 /*   190 */    66,   13,   10,   71,   13,   13,   11,   75,   76,   23,
 /*   200 */    78,   79,   34,   44,    5,   11,   38,   39,   23,   41,
 /*   210 */    42,   43,   44,   45,   46,   47,   34,   23,   50,   51,
 /*   220 */    38,   39,    1,   41,   42,   43,   44,   45,   46,   47,
 /*   230 */    13,   10,   50,   51,   13,   25,   26,   27,   28,   29,
 /*   240 */    30,   31,   32,   33,   34,   35,   36,   37,    6,   53,
 /*   250 */    40,   55,   64,    4,   66,   34,   60,    6,    6,   38,
 /*   260 */    39,   44,   41,   42,   43,   44,   45,   46,   13,   13,
 /*   270 */    49,   50,   26,   27,   28,   29,   30,   31,   32,   33,
 /*   280 */    34,   35,   36,   37,    1,   23,   40,   64,    3,   66,
 /*   290 */    53,   54,   55,   10,   57,    1,   13,   60,   11,    5,
 /*   300 */     2,    7,    8,    9,   10,   13,   12,   13,   23,   64,
 /*   310 */    13,   66,   18,   19,   20,   78,   79,   34,   65,   21,
 /*   320 */    22,   38,   39,    6,   41,   42,   43,   44,   45,   46,
 /*   330 */    67,    3,   53,   50,   55,   56,   51,   65,   65,   60,
 /*   340 */    61,   62,   73,    2,   46,   47,   58,   68,   50,   70,
 /*   350 */    32,   33,   34,   35,   36,   37,   13,   64,   40,   66,
 /*   360 */    53,   54,   55,   73,   64,   13,   66,   60,   53,   54,
 /*   370 */    55,   58,   64,   83,   66,   60,   64,   73,   66,   83,
 /*   380 */    53,   54,   55,   76,   57,   78,   79,   60,   83,   74,
 /*   390 */    83,   83,   83,   78,   79,   53,   54,   55,   83,   57,
 /*   400 */    83,   83,   60,   83,   83,   78,   79,   53,   54,   55,
 /*   410 */    83,   57,   83,   83,   60,   53,   54,   55,    2,   57,
 /*   420 */    78,   79,   60,   53,   54,   55,   83,   83,   83,   83,
 /*   430 */    60,   83,   78,   79,   83,   83,   83,   21,   22,   83,
 /*   440 */    78,   79,   83,   53,   54,   55,   83,   83,   78,   79,
 /*   450 */    60,   83,   82,   53,   54,   55,   83,   83,   83,   83,
 /*   460 */    60,   83,   46,   47,   83,   83,   50,   83,   78,   79,
 /*   470 */    53,   54,   55,   53,   54,   55,   83,   60,   78,   79,
 /*   480 */    60,   83,   83,   83,   53,   54,   55,   53,   54,   55,
 /*   490 */    83,   60,   83,   83,   60,   78,   79,   83,   78,   79,
 /*   500 */    83,   83,   83,   83,   53,   54,   55,   83,   83,   78,
 /*   510 */    79,   60,   78,   79,   53,   54,   55,   53,   54,   55,
 /*   520 */    83,   60,   83,   83,   60,   53,   54,   55,   83,   78,
 /*   530 */    79,   83,   60,   83,   53,   54,   55,   83,   83,   78,
 /*   540 */    79,   60,   78,   79,   83,   53,   54,   55,   83,   83,
 /*   550 */    78,   79,   60,   83,   83,   83,   83,   83,   83,   78,
 /*   560 */    79,   83,   83,   83,   83,   53,   54,   55,   83,   83,
 /*   570 */    78,   79,   60,   53,   54,   55,   83,   83,   83,   83,
 /*   580 */    60,   53,   54,   55,   83,   83,   83,   83,   60,   83,
 /*   590 */    78,   79,   83,   53,   54,   55,   83,   83,   78,   79,
 /*   600 */    60,   83,   83,   83,   83,   83,   78,   79,   83,   83,
 /*   610 */    83,   83,   83,   83,   83,   83,   83,   83,   78,   79,
};
#define YY_SHIFT_USE_DFLT (-23)
#define YY_SHIFT_COUNT (107)
#define YY_SHIFT_MIN   (-22)
#define YY_SHIFT_MAX   (416)
static const short yy_shift_ofst[] = {
 /*     0 */   -23,  283,  182,  294,  168,  221,  283,  283,  283,  283,
 /*    10 */   283,  283,  283,  283,  283,  283,  283,  283,  283,  283,
 /*    20 */   283,  283,  283,  283,  283,  283,  283,  283,  178,  -23,
 /*    30 */   416,  416,   66,  217,  352,  -23,  -23,  -23,  -23,  -23,
 /*    40 */   -23,  -23,  -23,  104,  341,  343,  341,  341,  328,  328,
 /*    50 */   328,  -23,  114,  -22,   96,   71,   46,   20,   -5,  131,
 /*    60 */   131,  131,  131,  131,  131,  131,  210,  246,  318,  318,
 /*    70 */   298,   52,  285,  194,  185,   70,  176,  162,   45,    1,
 /*    80 */    10,  159,  317,  297,  262,  262,  292,  262,  287,  262,
 /*    90 */   256,  255,  252,  251,  249,  242,  199,  181,  157,  169,
 /*   100 */   142,  132,   95,  103,   51,   79,   35,   34,
};
#define YY_REDUCE_USE_DFLT (-25)
#define YY_REDUCE_COUNT (51)
#define YY_REDUCE_MIN   (-24)
#define YY_REDUCE_MAX   (540)
static const short yy_reduce_ofst[] = {
 /*     0 */   -24,  122,  -17,  279,  370,  362,  354,  342,  327,  315,
 /*    10 */   237,  307,  540,  528,  520,  512,  492,  481,  472,  464,
 /*    20 */   461,  451,  434,  431,  420,  417,  400,  390,  196,  120,
 /*    30 */    56,   56,   31,   94,  -14,  312,  308,  300,  293,  245,
 /*    40 */   223,  188,  124,  313,  304,  288,  290,  269,  273,  272,
 /*    50 */   253,  263,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   162,  237,  237,  159,  237,  237,  237,  182,  237,  237,
 /*    10 */   237,  237,  237,  237,  237,  237,  237,  237,  237,  237,
 /*    20 */   237,  237,  237,  237,  237,  237,  237,  237,  237,  162,
 /*    30 */   237,  201,  237,  225,  237,  162,  162,  162,  162,  162,
 /*    40 */   162,  162,  162,  237,  237,  237,  237,  237,  158,  158,
 /*    50 */   158,  164,  195,  237,  237,  237,  237,  237,  237,  196,
 /*    60 */   161,  194,  193,  236,  235,  234,  204,  205,  207,  206,
 /*    70 */   173,  208,  237,  214,  184,  237,  214,  237,  187,  176,
 /*    80 */   237,  237,  237,  237,  185,  183,  237,  175,  191,  172,
 /*    90 */   237,  237,  237,  237,  237,  237,  237,  237,  237,  237,
 /*   100 */   211,  237,  226,  237,  203,  237,  237,  237,  186,  181,
 /*   110 */   174,  189,  190,  188,  171,  178,  180,  179,  177,  170,
 /*   120 */   169,  168,  222,  221,  219,  220,  218,  217,  213,  212,
 /*   130 */   232,  233,  231,  230,  229,  227,  224,  228,  192,  191,
 /*   140 */   223,  216,  215,  214,  211,  202,  200,  199,  198,  197,
 /*   150 */   167,  166,  165,  163,  160,  157,
};

/* The next table maps tokens into fallback tokens.  If a construct
** like the following:
** 
**      %fallback ID X Y Z.
**
** appears in the grammar, then ID becomes a fallback token for X, Y,
** and Z.  Whenever one of the tokens X, Y, or Z is input to the parser
** but it does not parse, the type of the token is changed to ID and
** the parse is retried before an error is thrown.
*/
#ifdef YYFALLBACK
static const YYCODETYPE yyFallback[] = {
    0,  /*          $ => nothing */
    0,  /*       OPEN => nothing */
    1,  /*     LPAREN => OPEN */
};
#endif /* YYFALLBACK */

/* The following structure represents a single element of the
** parser's stack.  Information stored includes:
**
**   +  The state number for the parser at this level of the stack.
**
**   +  The value of the token stored at this level of the stack.
**      (In other words, the "major" token.)
**
**   +  The semantic value stored at this level of the stack.  This is
**      the information used by the action routines in the grammar.
**      It is sometimes called the "minor" token.
*/
struct yyStackEntry {
  YYACTIONTYPE stateno;  /* The state-number */
  YYCODETYPE major;      /* The major token value.  This is the code
                         ** number for the token at this stack level */
  YYMINORTYPE minor;     /* The user-supplied minor token value.  This
                         ** is the value of the token  */
};
typedef struct yyStackEntry yyStackEntry;

/* The state of the parser is completely contained in an instance of
** the following structure */
struct yyParser {
  int yyidx;                    /* Index of top element in stack */
#ifdef YYTRACKMAXSTACKDEPTH
  int yyidxMax;                 /* Maximum value of yyidx */
#endif
  int yyerrcnt;                 /* Shifts left before out of the error */
  ParseARG_SDECL                /* A place to hold %extra_argument */
#if YYSTACKDEPTH<=0
  int yystksz;                  /* Current side of the stack */
  yyStackEntry *yystack;        /* The parser's stack */
#else
  yyStackEntry yystack[YYSTACKDEPTH];  /* The parser's stack */
#endif
};
typedef struct yyParser yyParser;

#ifndef NDEBUG
#include <stdio.h>
static FILE *yyTraceFILE = 0;
static char *yyTracePrompt = 0;
#endif /* NDEBUG */

#ifndef NDEBUG
/* 
** Turn parser tracing on by giving a stream to which to write the trace
** and a prompt to preface each trace message.  Tracing is turned off
** by making either argument NULL 
**
** Inputs:
** <ul>
** <li> A FILE* to which trace output should be written.
**      If NULL, then tracing is turned off.
** <li> A prefix string written at the beginning of every
**      line of trace output.  If NULL, then tracing is
**      turned off.
** </ul>
**
** Outputs:
** None.
*/
static void ParseTrace(FILE *TraceFILE, char *zTracePrompt){
  yyTraceFILE = TraceFILE;
  yyTracePrompt = zTracePrompt;
  if( yyTraceFILE==0 ) yyTracePrompt = 0;
  else if( yyTracePrompt==0 ) yyTraceFILE = 0;
}
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing shifts, the names of all terminals and nonterminals
** are required.  The following table supplies these names */
static const char *const yyTokenName[] = { 
  "$",             "OPEN",          "LPAREN",        "SEMICOL",     
  "UNTIL",         "DO",            "END",           "WHILE",       
  "REPEAT",        "IF",            "FUNCTION",      "SET",         
  "FOR",           "NAME",          "IN",            "ELSE",        
  "ELSEIF",        "THEN",          "BREAK",         "RETURN",      
  "LOCAL",         "COLON",         "DOT",           "COMMA",       
  "OR",            "AND",           "L",             "LE",          
  "G",             "GE",            "EQ",            "NE",          
  "CONCAT",        "PLUS",          "MINUS",         "TIMES",       
  "DIVIDE",        "MOD",           "NOT",           "HASH",        
  "POW",           "NIL",           "TRUE",          "FALSE",       
  "DOTS",          "NUMBER",        "STRING",        "SLPAREN",     
  "SRPAREN",       "RPAREN",        "LBRACE",        "RBRACE",      
  "error",         "var",           "exp",           "prefixexp",   
  "setlist",       "explist1",      "namelist",      "args",        
  "functioncall",  "stat",          "binding",       "chunk",       
  "block",         "semi",          "scope",         "statlist",    
  "laststat",      "ublock",        "repetition",    "conds",       
  "funcname",      "params",        "explist23",     "condlist",    
  "cond",          "dottedname",    "function",      "tableconstructor",
  "parlist",       "fieldlist",     "field",       
};
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing reduce actions, the names of all rules are required.
*/
static const char *const yyRuleName[] = {
 /*   0 */ "chunk ::= block",
 /*   1 */ "semi ::= SEMICOL",
 /*   2 */ "semi ::=",
 /*   3 */ "block ::= scope statlist",
 /*   4 */ "block ::= scope statlist laststat semi",
 /*   5 */ "ublock ::= block UNTIL exp",
 /*   6 */ "scope ::=",
 /*   7 */ "scope ::= scope statlist binding semi",
 /*   8 */ "statlist ::=",
 /*   9 */ "statlist ::= statlist stat semi",
 /*  10 */ "stat ::= DO block END",
 /*  11 */ "stat ::= WHILE exp DO block END",
 /*  12 */ "stat ::= repetition DO block END",
 /*  13 */ "stat ::= REPEAT ublock",
 /*  14 */ "stat ::= IF conds END",
 /*  15 */ "stat ::= FUNCTION funcname params block END",
 /*  16 */ "stat ::= setlist SET explist1",
 /*  17 */ "stat ::= functioncall",
 /*  18 */ "repetition ::= FOR NAME SET explist23",
 /*  19 */ "repetition ::= FOR namelist IN explist1",
 /*  20 */ "conds ::= condlist",
 /*  21 */ "conds ::= condlist ELSE block",
 /*  22 */ "condlist ::= cond",
 /*  23 */ "condlist ::= condlist ELSEIF cond",
 /*  24 */ "cond ::= exp THEN block",
 /*  25 */ "laststat ::= BREAK",
 /*  26 */ "laststat ::= RETURN",
 /*  27 */ "laststat ::= RETURN explist1",
 /*  28 */ "binding ::= LOCAL namelist",
 /*  29 */ "binding ::= LOCAL namelist SET explist1",
 /*  30 */ "binding ::= LOCAL FUNCTION NAME params block END",
 /*  31 */ "funcname ::= dottedname",
 /*  32 */ "funcname ::= dottedname COLON NAME",
 /*  33 */ "dottedname ::= NAME",
 /*  34 */ "dottedname ::= dottedname DOT NAME",
 /*  35 */ "namelist ::= NAME",
 /*  36 */ "namelist ::= namelist COMMA NAME",
 /*  37 */ "explist1 ::= exp",
 /*  38 */ "explist1 ::= explist1 COMMA exp",
 /*  39 */ "explist23 ::= exp COMMA exp",
 /*  40 */ "explist23 ::= exp COMMA exp COMMA exp",
 /*  41 */ "exp ::= NIL|TRUE|FALSE|DOTS",
 /*  42 */ "exp ::= NUMBER",
 /*  43 */ "exp ::= STRING",
 /*  44 */ "exp ::= function",
 /*  45 */ "exp ::= prefixexp",
 /*  46 */ "exp ::= tableconstructor",
 /*  47 */ "exp ::= NOT|HASH|MINUS exp",
 /*  48 */ "exp ::= exp OR exp",
 /*  49 */ "exp ::= exp AND exp",
 /*  50 */ "exp ::= exp L|LE|G|GE|EQ|NE exp",
 /*  51 */ "exp ::= exp CONCAT exp",
 /*  52 */ "exp ::= exp PLUS|MINUS|TIMES|DIVIDE|MOD|POW exp",
 /*  53 */ "setlist ::= var",
 /*  54 */ "setlist ::= setlist COMMA var",
 /*  55 */ "var ::= NAME",
 /*  56 */ "var ::= prefixexp SLPAREN exp SRPAREN",
 /*  57 */ "var ::= prefixexp DOT NAME",
 /*  58 */ "prefixexp ::= var",
 /*  59 */ "prefixexp ::= functioncall",
 /*  60 */ "prefixexp ::= OPEN exp RPAREN",
 /*  61 */ "functioncall ::= prefixexp args",
 /*  62 */ "functioncall ::= prefixexp COLON NAME args",
 /*  63 */ "args ::= LPAREN RPAREN",
 /*  64 */ "args ::= LPAREN explist1 RPAREN",
 /*  65 */ "args ::= tableconstructor",
 /*  66 */ "args ::= STRING",
 /*  67 */ "function ::= FUNCTION params block END",
 /*  68 */ "params ::= LPAREN parlist LPAREN",
 /*  69 */ "parlist ::=",
 /*  70 */ "parlist ::= namelist",
 /*  71 */ "parlist ::= DOTS",
 /*  72 */ "parlist ::= namelist COMMA DOTS",
 /*  73 */ "tableconstructor ::= LBRACE RBRACE",
 /*  74 */ "tableconstructor ::= LBRACE fieldlist RBRACE",
 /*  75 */ "tableconstructor ::= LBRACE fieldlist COMMA|SEMICOL RBRACE",
 /*  76 */ "fieldlist ::= field",
 /*  77 */ "fieldlist ::= fieldlist COMMA|SEMICOL field",
 /*  78 */ "field ::= exp",
 /*  79 */ "field ::= NAME SET exp",
 /*  80 */ "field ::= SLPAREN exp SRPAREN SET exp",
};
#endif /* NDEBUG */


#if YYSTACKDEPTH<=0
/*
** Try to increase the size of the parser stack.
*/
static void yyGrowStack(yyParser *p){
  int newSize;
  yyStackEntry *pNew;

  newSize = p->yystksz*2 + 100;
  pNew = realloc(p->yystack, newSize*sizeof(pNew[0]));
  if( pNew ){
    p->yystack = pNew;
    p->yystksz = newSize;
#ifndef NDEBUG
    if( yyTraceFILE ){
      fprintf(yyTraceFILE,"%sStack grows to %d entries!\n",
              yyTracePrompt, p->yystksz);
    }
#endif
  }
}
#endif

/* 
** This function allocates a new parser.
** The only argument is a pointer to a function which works like
** malloc.
**
** Inputs:
** A pointer to the function used to allocate memory.
**
** Outputs:
** A pointer to a parser.  This pointer is used in subsequent calls
** to Parse and ParseFree.
*/
static void *ParseAlloc(void *(*mallocProc)(size_t)){
  yyParser *pParser;
  pParser = (yyParser*)(*mallocProc)( (size_t)sizeof(yyParser) );
  if( pParser ){
    pParser->yyidx = -1;
#ifdef YYTRACKMAXSTACKDEPTH
    pParser->yyidxMax = 0;
#endif
#if YYSTACKDEPTH<=0
    pParser->yystack = NULL;
    pParser->yystksz = 0;
    yyGrowStack(pParser);
#endif
  }
  return pParser;
}

/* The following function deletes the value associated with a
** symbol.  The symbol can be either a terminal or nonterminal.
** "yymajor" is the symbol code, and "yypminor" is a pointer to
** the value.
*/
static void yy_destructor(
  yyParser *yypParser,    /* The parser */
  YYCODETYPE yymajor,     /* Type code for object to destroy */
  YYMINORTYPE *yypminor   /* The object to be destroyed */
){
  ParseARG_FETCH;
  switch( yymajor ){
    /* Here is inserted the actions which take place when a
    ** terminal or non-terminal is destroyed.  This can happen
    ** when the symbol is popped from the stack during a
    ** reduce or during error processing or when a parser is 
    ** being destroyed before it is finished parsing.
    **
    ** Note: during a reduce, the only symbols destroyed are those
    ** which appear on the RHS of the rule, but which are not used
    ** inside the C code.
    */
    default:  break;   /* If no destructor action specified: do nothing */
  }
}

/*
** Pop the parser's stack once.
**
** If there is a destructor routine associated with the token which
** is popped from the stack, then call it.
**
** Return the major token number for the symbol popped.
*/
static int yy_pop_parser_stack(yyParser *pParser){
  YYCODETYPE yymajor;
  yyStackEntry *yytos = &pParser->yystack[pParser->yyidx];

  if( pParser->yyidx<0 ) return 0;
#ifndef NDEBUG
  if( yyTraceFILE && pParser->yyidx>=0 ){
    fprintf(yyTraceFILE,"%sPopping %s\n",
      yyTracePrompt,
      yyTokenName[yytos->major]);
  }
#endif
  yymajor = yytos->major;
  yy_destructor(pParser, yymajor, &yytos->minor);
  pParser->yyidx--;
  return yymajor;
}

/* 
** Deallocate and destroy a parser.  Destructors are all called for
** all stack elements before shutting the parser down.
**
** Inputs:
** <ul>
** <li>  A pointer to the parser.  This should be a pointer
**       obtained from ParseAlloc.
** <li>  A pointer to a function used to reclaim memory obtained
**       from malloc.
** </ul>
*/
static void ParseFree(
  void *p,                    /* The parser to be deleted */
  void (*freeProc)(void*)     /* Function used to reclaim memory */
){
  yyParser *pParser = (yyParser*)p;
  if( pParser==0 ) return;
  while( pParser->yyidx>=0 ) yy_pop_parser_stack(pParser);
#if YYSTACKDEPTH<=0
  free(pParser->yystack);
#endif
  (*freeProc)((void*)pParser);
}

/*
** Return the peak depth of the stack for a parser.
*/
#ifdef YYTRACKMAXSTACKDEPTH
int ParseStackPeak(void *p){
  yyParser *pParser = (yyParser*)p;
  return pParser->yyidxMax;
}
#endif

/*
** Find the appropriate action for a parser given the terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_shift_action(
  yyParser *pParser,        /* The parser */
  YYCODETYPE iLookAhead     /* The look-ahead token */
){
  int i;
  int stateno = pParser->yystack[pParser->yyidx].stateno;
 
  if( stateno>YY_SHIFT_COUNT
   || (i = yy_shift_ofst[stateno])==YY_SHIFT_USE_DFLT ){
    return yy_default[stateno];
  }
  //assert( iLookAhead!=YYNOCODE );
  i += iLookAhead;
  if( i<0 || i>=YY_ACTTAB_COUNT || yy_lookahead[i]!=iLookAhead ){
    if( iLookAhead>0 ){
#ifdef YYFALLBACK
      YYCODETYPE iFallback;            /* Fallback token */
      if( iLookAhead<sizeof(yyFallback)/sizeof(yyFallback[0])
             && (iFallback = yyFallback[iLookAhead])!=0 ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE, "%sFALLBACK %s => %s\n",
             yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[iFallback]);
        }
#endif
        return yy_find_shift_action(pParser, iFallback);
      }
#endif
#ifdef YYWILDCARD
      {
        int j = i - iLookAhead + YYWILDCARD;
        if( 
#if YY_SHIFT_MIN+YYWILDCARD<0
          j>=0 &&
#endif
#if YY_SHIFT_MAX+YYWILDCARD>=YY_ACTTAB_COUNT
          j<YY_ACTTAB_COUNT &&
#endif
          yy_lookahead[j]==YYWILDCARD
        ){
#ifndef NDEBUG
          if( yyTraceFILE ){
            fprintf(yyTraceFILE, "%sWILDCARD %s => %s\n",
               yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[YYWILDCARD]);
          }
#endif /* NDEBUG */
          return yy_action[j];
        }
      }
#endif /* YYWILDCARD */
    }
    return yy_default[stateno];
  }else{
    return yy_action[i];
  }
}

/*
** Find the appropriate action for a parser given the non-terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_reduce_action(
  int stateno,              /* Current state number */
  YYCODETYPE iLookAhead     /* The look-ahead token */
){
  int i;
#ifdef YYERRORSYMBOL
  if( stateno>YY_REDUCE_COUNT ){
    return yy_default[stateno];
  }
#else
  //assert( stateno<=YY_REDUCE_COUNT );
#endif
  i = yy_reduce_ofst[stateno];
  //assert( i!=YY_REDUCE_USE_DFLT );
  //assert( iLookAhead!=YYNOCODE );
  i += iLookAhead;
#ifdef YYERRORSYMBOL
  if( i<0 || i>=YY_ACTTAB_COUNT || yy_lookahead[i]!=iLookAhead ){
    return yy_default[stateno];
  }
#else
  //assert( i>=0 && i<YY_ACTTAB_COUNT );
  //assert( yy_lookahead[i]==iLookAhead );
#endif
  return yy_action[i];
}

/*
** The following routine is called if the stack overflows.
*/
static void yyStackOverflow(yyParser *yypParser, YYMINORTYPE *yypMinor){
   ParseARG_FETCH;
   yypParser->yyidx--;
#ifndef NDEBUG
   if( yyTraceFILE ){
     fprintf(yyTraceFILE,"%sStack Overflow!\n",yyTracePrompt);
   }
#endif
   while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
   /* Here code is inserted which will execute if the parser
   ** stack every overflows */
   ParseARG_STORE; /* Suppress warning about unused %extra_argument var */
}

/*
** Perform a shift action.
*/
static void yy_shift(
  yyParser *yypParser,          /* The parser to be shifted */
  int yyNewState,               /* The new state to shift in */
  int yyMajor,                  /* The major token to shift in */
  YYMINORTYPE *yypMinor         /* Pointer to the minor token to shift in */
){
  yyStackEntry *yytos;
  yypParser->yyidx++;
#ifdef YYTRACKMAXSTACKDEPTH
  if( yypParser->yyidx>yypParser->yyidxMax ){
    yypParser->yyidxMax = yypParser->yyidx;
  }
#endif
#if YYSTACKDEPTH>0 
  if( yypParser->yyidx>=YYSTACKDEPTH ){
    yyStackOverflow(yypParser, yypMinor);
    return;
  }
#else
  if( yypParser->yyidx>=yypParser->yystksz ){
    yyGrowStack(yypParser);
    if( yypParser->yyidx>=yypParser->yystksz ){
      yyStackOverflow(yypParser, yypMinor);
      return;
    }
  }
#endif
  yytos = &yypParser->yystack[yypParser->yyidx];
  yytos->stateno = (YYACTIONTYPE)yyNewState;
  yytos->major = (YYCODETYPE)yyMajor;
  yytos->minor = *yypMinor;
#ifndef NDEBUG
  if( yyTraceFILE && yypParser->yyidx>0 ){
    int i;
    fprintf(yyTraceFILE,"%sShift %d\n",yyTracePrompt,yyNewState);
    fprintf(yyTraceFILE,"%sStack:",yyTracePrompt);
    for(i=1; i<=yypParser->yyidx; i++)
      fprintf(yyTraceFILE," %s",yyTokenName[yypParser->yystack[i].major]);
    fprintf(yyTraceFILE,"\n");
  }
#endif
}

/* The following table contains information about every rule that
** is used during the reduce.
*/
static const struct {
  YYCODETYPE lhs;         /* Symbol on the left-hand side of the rule */
  unsigned char nrhs;     /* Number of right-hand side symbols in the rule */
} yyRuleInfo[] = {
  { 63, 1 },
  { 65, 1 },
  { 65, 0 },
  { 64, 2 },
  { 64, 4 },
  { 69, 3 },
  { 66, 0 },
  { 66, 4 },
  { 67, 0 },
  { 67, 3 },
  { 61, 3 },
  { 61, 5 },
  { 61, 4 },
  { 61, 2 },
  { 61, 3 },
  { 61, 5 },
  { 61, 3 },
  { 61, 1 },
  { 70, 4 },
  { 70, 4 },
  { 71, 1 },
  { 71, 3 },
  { 75, 1 },
  { 75, 3 },
  { 76, 3 },
  { 68, 1 },
  { 68, 1 },
  { 68, 2 },
  { 62, 2 },
  { 62, 4 },
  { 62, 6 },
  { 72, 1 },
  { 72, 3 },
  { 77, 1 },
  { 77, 3 },
  { 58, 1 },
  { 58, 3 },
  { 57, 1 },
  { 57, 3 },
  { 74, 3 },
  { 74, 5 },
  { 54, 1 },
  { 54, 1 },
  { 54, 1 },
  { 54, 1 },
  { 54, 1 },
  { 54, 1 },
  { 54, 2 },
  { 54, 3 },
  { 54, 3 },
  { 54, 3 },
  { 54, 3 },
  { 54, 3 },
  { 56, 1 },
  { 56, 3 },
  { 53, 1 },
  { 53, 4 },
  { 53, 3 },
  { 55, 1 },
  { 55, 1 },
  { 55, 3 },
  { 60, 2 },
  { 60, 4 },
  { 59, 2 },
  { 59, 3 },
  { 59, 1 },
  { 59, 1 },
  { 78, 4 },
  { 73, 3 },
  { 80, 0 },
  { 80, 1 },
  { 80, 1 },
  { 80, 3 },
  { 79, 2 },
  { 79, 3 },
  { 79, 4 },
  { 81, 1 },
  { 81, 3 },
  { 82, 1 },
  { 82, 3 },
  { 82, 5 },
};

static void yy_accept(yyParser*);  /* Forward Declaration */

/*
** Perform a reduce action and the shift that must immediately
** follow the reduce.
*/
static void yy_reduce(
  yyParser *yypParser,         /* The parser */
  int yyruleno                 /* Number of the rule by which to reduce */
){
  int yygoto;                     /* The next state */
  int yyact;                      /* The next action */
  YYMINORTYPE yygotominor;        /* The LHS of the rule reduced */
  yyStackEntry *yymsp;            /* The top of the parser's stack */
  int yysize;                     /* Amount to pop the stack */
  ParseARG_FETCH;
  yymsp = &yypParser->yystack[yypParser->yyidx];
#ifndef NDEBUG
  if( yyTraceFILE && yyruleno>=0 
        && yyruleno<(int)(sizeof(yyRuleName)/sizeof(yyRuleName[0])) ){
    fprintf(yyTraceFILE, "%sReduce [%s].\n", yyTracePrompt,
      yyRuleName[yyruleno]);
  }
#endif /* NDEBUG */

  /* Silence complaints from purify about yygotominor being uninitialized
  ** in some cases when it is copied into the stack after the following
  ** switch.  yygotominor is uninitialized when a rule reduces that does
  ** not set the value of its left-hand side nonterminal.  Leaving the
  ** value of the nonterminal uninitialized is utterly harmless as long
  ** as the value is never used.  So really the only thing this code
  ** accomplishes is to quieten purify.  
  **
  ** 2007-01-16:  The wireshark project (www.wireshark.org) reports that
  ** without this code, their parser segfaults.  I'm not sure what there
  ** parser is doing to make this happen.  This is the second bug report
  ** from wireshark this week.  Clearly they are stressing Lemon in ways
  ** that it has not been previously stressed...  (SQLite ticket #2172)
  */
  /*memset(&yygotominor, 0, sizeof(yygotominor));*/
  yygotominor = yyzerominor;


  switch( yyruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **  #line <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  #line <lineno> <thisfile>
  **     break;
  */
      case 0: /* chunk ::= block */
#line 34 "uparser.y"
{
	printf("P_CHUNK\n");
}
#line 985 "uparser.c"
        break;
      case 1: /* semi ::= SEMICOL */
      case 2: /* semi ::= */ yytestcase(yyruleno==2);
#line 38 "uparser.y"
{
	printf("P_SEMI ------------------\n");
}
#line 993 "uparser.c"
        break;
      case 3: /* block ::= scope statlist */
#line 45 "uparser.y"
{
	printf("P_BLOCK_STATLIST\n");
}
#line 1000 "uparser.c"
        break;
      case 4: /* block ::= scope statlist laststat semi */
#line 48 "uparser.y"
{
	printf("P_BLOCK_STATLIST_LASTSTAT\n");
}
#line 1007 "uparser.c"
        break;
      case 5: /* ublock ::= block UNTIL exp */
#line 51 "uparser.y"
{
	printf("P_UBLOCK\n");
}
#line 1014 "uparser.c"
        break;
      case 6: /* scope ::= */
#line 55 "uparser.y"
{
	printf("P_SCOPE_EMPTY\n");
}
#line 1021 "uparser.c"
        break;
      case 7: /* scope ::= scope statlist binding semi */
#line 58 "uparser.y"
{
	printf("P_SCOPE_STATLIST\n");
}
#line 1028 "uparser.c"
        break;
      case 8: /* statlist ::= */
#line 62 "uparser.y"
{
	printf("P_STATLIST_EMPTY\n");
}
#line 1035 "uparser.c"
        break;
      case 9: /* statlist ::= statlist stat semi */
#line 65 "uparser.y"
{
	printf("P_STATLIST_ADD_STAT\n");
}
#line 1042 "uparser.c"
        break;
      case 16: /* stat ::= setlist SET explist1 */
#line 75 "uparser.y"
{
	yygotominor.yy15 = statSET(f, yymsp[-2].minor.yy88, yymsp[0].minor.yy88, FALSE);
	printf("P_STAT_SET\n");
}
#line 1050 "uparser.c"
        break;
      case 17: /* stat ::= functioncall */
#line 79 "uparser.y"
{
	freeRegister(yymsp[0].minor.yy88);
	printf("P_STAT_FCALL\n");
}
#line 1058 "uparser.c"
        break;
      case 28: /* binding ::= LOCAL namelist */
#line 97 "uparser.y"
{
	printf("P_LOCAL\n");
}
#line 1065 "uparser.c"
        break;
      case 29: /* binding ::= LOCAL namelist SET explist1 */
#line 100 "uparser.y"
{
	yygotominor.yy15 = statSET(f, yymsp[-2].minor.yy88, yymsp[0].minor.yy88, TRUE);
	printf("P_LOCAL_SET\n");
}
#line 1073 "uparser.c"
        break;
      case 30: /* binding ::= LOCAL FUNCTION NAME params block END */
#line 104 "uparser.y"
{
	printf("P_LOCAL_FUNCTION\n");
	pushConstString(f, &yymsp[-3].minor.yy0.semInfo);
}
#line 1081 "uparser.c"
        break;
      case 35: /* namelist ::= NAME */
#line 115 "uparser.y"
{
	Constant* c = pushVarName(f, &yymsp[0].minor.yy0.semInfo);
	yygotominor.yy88 = getVarRegister(f,c);
	printf("P_NAMELIST_NAME\n");
}
#line 1090 "uparser.c"
        break;
      case 36: /* namelist ::= namelist COMMA NAME */
#line 120 "uparser.y"
{
	Constant* c = pushVarName(f, &yymsp[0].minor.yy0.semInfo);
	yygotominor.yy88 = getVarRegister(f,c);
	printf("P_NAMELIST_COMMA_NAME\n");
}
#line 1099 "uparser.c"
        break;
      case 37: /* explist1 ::= exp */
#line 126 "uparser.y"
{
	yygotominor.yy88 = yymsp[0].minor.yy88;
	printf("P_EXPLIST_EXP\n");
}
#line 1107 "uparser.c"
        break;
      case 38: /* explist1 ::= explist1 COMMA exp */
#line 130 "uparser.y"
{
	yygotominor.yy88 = yymsp[0].minor.yy88;
	printf("P_EXPLIST_ADD_EXP\n");
}
#line 1115 "uparser.c"
        break;
      case 42: /* exp ::= NUMBER */
#line 147 "uparser.y"
{
	Constant* c;
	Register* r;

	printf("P_EXP_NUMBER\n");
	c = pushConstNumber(f, yymsp[0].minor.yy0.number.fvalue);
	r = getFreeRegister(f);
	r->consthold = TRUE;
	r->constpreloaded = FALSE;
	r->constnum = c->num;
	yygotominor.yy88 = r;
}
#line 1131 "uparser.c"
        break;
      case 43: /* exp ::= STRING */
#line 159 "uparser.y"
{
	Constant* c;
	Register* r;

	printf("P_EXP_STRING\n");
	c = pushConstString(f, &yymsp[0].minor.yy0.semInfo);
	r = getFreeRegister(f);
	r->consthold = TRUE;
	r->constpreloaded = FALSE;
	r->constnum = c->num;
	yygotominor.yy88 = r;
}
#line 1147 "uparser.c"
        break;
      case 44: /* exp ::= function */
#line 171 "uparser.y"
{
	printf("P_EXP_FUNCTION\n");
}
#line 1154 "uparser.c"
        break;
      case 45: /* exp ::= prefixexp */
#line 174 "uparser.y"
{
	printf("P_EXP_PREFIXEXP\n");
	yygotominor.yy88 = yymsp[0].minor.yy88;
}
#line 1162 "uparser.c"
        break;
      case 52: /* exp ::= exp PLUS|MINUS|TIMES|DIVIDE|MOD|POW exp */
#line 184 "uparser.y"
{
	printf("P_EXP_MATH\n");
	yygotominor.yy88 = doMath(f,yymsp[-2].minor.yy88,yymsp[0].minor.yy88,&yymsp[-1].minor.yy0);
}
#line 1170 "uparser.c"
        break;
      case 53: /* setlist ::= var */
#line 189 "uparser.y"
{
	printf("P_SETLIST_VAR\n");
	yygotominor.yy88 = yymsp[0].minor.yy88;
}
#line 1178 "uparser.c"
        break;
      case 54: /* setlist ::= setlist COMMA var */
#line 193 "uparser.y"
{
	printf("P_SETLIST_ADD_VAR\n");
	yygotominor.yy88 = yymsp[0].minor.yy88;
}
#line 1186 "uparser.c"
        break;
      case 55: /* var ::= NAME */
#line 198 "uparser.y"
{
	Constant* c;

	printf("P_VAR_NAME\n");
	c = pushVarName(f, &yymsp[0].minor.yy0.semInfo);
	yygotominor.yy88 = getVarRegister(f,c);
}
#line 1197 "uparser.c"
        break;
      case 56: /* var ::= prefixexp SLPAREN exp SRPAREN */
#line 205 "uparser.y"
{
	printf("P_PREFEXP_SPAREN_EXP\n");
}
#line 1204 "uparser.c"
        break;
      case 57: /* var ::= prefixexp DOT NAME */
#line 208 "uparser.y"
{
	printf("P_PREFEXP_DOT_NAME\n");
}
#line 1211 "uparser.c"
        break;
      case 58: /* prefixexp ::= var */
#line 212 "uparser.y"
{
	printf("P_PREFEXP_VAR\n");
	yygotominor.yy88 = yymsp[0].minor.yy88;
}
#line 1219 "uparser.c"
        break;
      case 59: /* prefixexp ::= functioncall */
#line 216 "uparser.y"
{
	printf("P_PREFEXP_FCALL\n");
}
#line 1226 "uparser.c"
        break;
      case 60: /* prefixexp ::= OPEN exp RPAREN */
#line 219 "uparser.y"
{
	printf("P_PREFEXP_EXP\n");
}
#line 1233 "uparser.c"
        break;
      case 61: /* functioncall ::= prefixexp args */
#line 223 "uparser.y"
{
	yygotominor.yy88 = functionCALL(f, yymsp[-1].minor.yy88, yymsp[0].minor.yy88);
	printf("P_FCALL_ARGS\n");
}
#line 1241 "uparser.c"
        break;
      case 62: /* functioncall ::= prefixexp COLON NAME args */
#line 227 "uparser.y"
{
	printf("P_FCALL_NAME_ARGS\n");
}
#line 1248 "uparser.c"
        break;
      case 63: /* args ::= LPAREN RPAREN */
#line 231 "uparser.y"
{
	yygotominor.yy88 = NULL;
	printf("P_ARGS_EMPTY\n");
}
#line 1256 "uparser.c"
        break;
      case 64: /* args ::= LPAREN explist1 RPAREN */
#line 235 "uparser.y"
{
	yygotominor.yy88 = yymsp[-1].minor.yy88;
	printf("P_ARGS_EXPLIST\n");
}
#line 1264 "uparser.c"
        break;
      case 66: /* args ::= STRING */
#line 240 "uparser.y"
{
	Constant* c;
	Register* r;

	c = pushConstString(f, &yymsp[0].minor.yy0.semInfo);
	r = getFreeRegister(f);
	r->consthold = TRUE;
	r->constpreloaded = FALSE;
	r->constnum = c->num;
	yygotominor.yy88 = r;
	printf("P_ARGS_STRING\n");
}
#line 1280 "uparser.c"
        break;
      default:
      /* (10) stat ::= DO block END */ yytestcase(yyruleno==10);
      /* (11) stat ::= WHILE exp DO block END */ yytestcase(yyruleno==11);
      /* (12) stat ::= repetition DO block END */ yytestcase(yyruleno==12);
      /* (13) stat ::= REPEAT ublock */ yytestcase(yyruleno==13);
      /* (14) stat ::= IF conds END */ yytestcase(yyruleno==14);
      /* (15) stat ::= FUNCTION funcname params block END */ yytestcase(yyruleno==15);
      /* (18) repetition ::= FOR NAME SET explist23 */ yytestcase(yyruleno==18);
      /* (19) repetition ::= FOR namelist IN explist1 */ yytestcase(yyruleno==19);
      /* (20) conds ::= condlist */ yytestcase(yyruleno==20);
      /* (21) conds ::= condlist ELSE block */ yytestcase(yyruleno==21);
      /* (22) condlist ::= cond */ yytestcase(yyruleno==22);
      /* (23) condlist ::= condlist ELSEIF cond */ yytestcase(yyruleno==23);
      /* (24) cond ::= exp THEN block */ yytestcase(yyruleno==24);
      /* (25) laststat ::= BREAK */ yytestcase(yyruleno==25);
      /* (26) laststat ::= RETURN */ yytestcase(yyruleno==26);
      /* (27) laststat ::= RETURN explist1 */ yytestcase(yyruleno==27);
      /* (31) funcname ::= dottedname */ yytestcase(yyruleno==31);
      /* (32) funcname ::= dottedname COLON NAME */ yytestcase(yyruleno==32);
      /* (33) dottedname ::= NAME */ yytestcase(yyruleno==33);
      /* (34) dottedname ::= dottedname DOT NAME */ yytestcase(yyruleno==34);
      /* (39) explist23 ::= exp COMMA exp */ yytestcase(yyruleno==39);
      /* (40) explist23 ::= exp COMMA exp COMMA exp */ yytestcase(yyruleno==40);
      /* (41) exp ::= NIL|TRUE|FALSE|DOTS */ yytestcase(yyruleno==41);
      /* (46) exp ::= tableconstructor */ yytestcase(yyruleno==46);
      /* (47) exp ::= NOT|HASH|MINUS exp */ yytestcase(yyruleno==47);
      /* (48) exp ::= exp OR exp */ yytestcase(yyruleno==48);
      /* (49) exp ::= exp AND exp */ yytestcase(yyruleno==49);
      /* (50) exp ::= exp L|LE|G|GE|EQ|NE exp */ yytestcase(yyruleno==50);
      /* (51) exp ::= exp CONCAT exp */ yytestcase(yyruleno==51);
      /* (65) args ::= tableconstructor */ yytestcase(yyruleno==65);
      /* (67) function ::= FUNCTION params block END */ yytestcase(yyruleno==67);
      /* (68) params ::= LPAREN parlist LPAREN */ yytestcase(yyruleno==68);
      /* (69) parlist ::= */ yytestcase(yyruleno==69);
      /* (70) parlist ::= namelist */ yytestcase(yyruleno==70);
      /* (71) parlist ::= DOTS */ yytestcase(yyruleno==71);
      /* (72) parlist ::= namelist COMMA DOTS */ yytestcase(yyruleno==72);
      /* (73) tableconstructor ::= LBRACE RBRACE */ yytestcase(yyruleno==73);
      /* (74) tableconstructor ::= LBRACE fieldlist RBRACE */ yytestcase(yyruleno==74);
      /* (75) tableconstructor ::= LBRACE fieldlist COMMA|SEMICOL RBRACE */ yytestcase(yyruleno==75);
      /* (76) fieldlist ::= field */ yytestcase(yyruleno==76);
      /* (77) fieldlist ::= fieldlist COMMA|SEMICOL field */ yytestcase(yyruleno==77);
      /* (78) field ::= exp */ yytestcase(yyruleno==78);
      /* (79) field ::= NAME SET exp */ yytestcase(yyruleno==79);
      /* (80) field ::= SLPAREN exp SRPAREN SET exp */ yytestcase(yyruleno==80);
        break;
  };
  yygoto = yyRuleInfo[yyruleno].lhs;
  yysize = yyRuleInfo[yyruleno].nrhs;
  yypParser->yyidx -= yysize;
  yyact = yy_find_reduce_action(yymsp[-yysize].stateno,(YYCODETYPE)yygoto);
  if( yyact < YYNSTATE ){
#ifdef NDEBUG
    /* If we are not debugging and the reduce action popped at least
    ** one element off the stack, then we can push the new element back
    ** onto the stack here, and skip the stack overflow test in yy_shift().
    ** That gives a significant speed improvement. */
    if( yysize ){
      yypParser->yyidx++;
      yymsp -= yysize-1;
      yymsp->stateno = (YYACTIONTYPE)yyact;
      yymsp->major = (YYCODETYPE)yygoto;
      yymsp->minor = yygotominor;
    }else
#endif
    {
      yy_shift(yypParser,yyact,yygoto,&yygotominor);
    }
  }else{
    //assert( yyact == YYNSTATE + YYNRULE + 1 );
    yy_accept(yypParser);
  }
}

/*
** The following code executes when the parse fails
*/
#ifndef YYNOERRORRECOVERY
static void yy_parse_failed(
  yyParser *yypParser           /* The parser */
){
  ParseARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sFail!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
  ParseARG_STORE; /* Suppress warning about unused %extra_argument variable */
}
#endif /* YYNOERRORRECOVERY */

/*
** The following code executes when a syntax error first occurs.
*/
static void yy_syntax_error(
  yyParser *yypParser,           /* The parser */
  int yymajor,                   /* The major type of the error token */
  YYMINORTYPE yyminor            /* The minor type of the error token */
){
  ParseARG_FETCH;
#define TOKEN (yyminor.yy0)
#line 28 "uparser.y"

  printf ("Syntax error!\n");
#line 1389 "uparser.c"
  ParseARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following is executed when the parser accepts
*/
static void yy_accept(
  yyParser *yypParser           /* The parser */
){
  ParseARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sAccept!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser accepts */
  ParseARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/* The main parser program.
** The first argument is a pointer to a structure obtained from
** "ParseAlloc" which describes the current state of the parser.
** The second argument is the major token number.  The third is
** the minor token.  The fourth optional argument is whatever the
** user wants (and specified in the grammar) and is available for
** use by the action routines.
**
** Inputs:
** <ul>
** <li> A pointer to the parser (an opaque structure.)
** <li> The major token number.
** <li> The minor token number.
** <li> An option argument of a grammar-specified type.
** </ul>
**
** Outputs:
** None.
*/
static void Parse(
  void *yyp,                   /* The parser */
  int yymajor,                 /* The major token code number */
  ParseTOKENTYPE yyminor       /* The value for the token */
  ParseARG_PDECL               /* Optional %extra_argument parameter */
){
  YYMINORTYPE yyminorunion;
  int yyact;            /* The parser action. */
  int yyendofinput;     /* True if we are at the end of input */
#ifdef YYERRORSYMBOL
  int yyerrorhit = 0;   /* True if yymajor has invoked an error */
#endif
  yyParser *yypParser;  /* The parser */

  /* (re)initialize the parser, if necessary */
  yypParser = (yyParser*)yyp;
  if( yypParser->yyidx<0 ){
#if YYSTACKDEPTH<=0
    if( yypParser->yystksz <=0 ){
      /*memset(&yyminorunion, 0, sizeof(yyminorunion));*/
      yyminorunion = yyzerominor;
      yyStackOverflow(yypParser, &yyminorunion);
      return;
    }
#endif
    yypParser->yyidx = 0;
    yypParser->yyerrcnt = -1;
    yypParser->yystack[0].stateno = 0;
    yypParser->yystack[0].major = 0;
  }
  yyminorunion.yy0 = yyminor;
  yyendofinput = (yymajor==0);
  ParseARG_STORE;

#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sInput %s\n",yyTracePrompt,yyTokenName[yymajor]);
  }
#endif

  do{
    yyact = yy_find_shift_action(yypParser,(YYCODETYPE)yymajor);
    if( yyact<YYNSTATE ){
      //assert( !yyendofinput );  /* Impossible to shift the $ token */
      yy_shift(yypParser,yyact,yymajor,&yyminorunion);
      yypParser->yyerrcnt--;
      yymajor = YYNOCODE;
    }else if( yyact < YYNSTATE + YYNRULE ){
      yy_reduce(yypParser,yyact-YYNSTATE);
    }else{
      //assert( yyact == YY_ERROR_ACTION );
#ifdef YYERRORSYMBOL
      int yymx;
#endif
#ifndef NDEBUG
      if( yyTraceFILE ){
        fprintf(yyTraceFILE,"%sSyntax Error!\n",yyTracePrompt);
      }
#endif
#ifdef YYERRORSYMBOL
      /* A syntax error has occurred.
      ** The response to an error depends upon whether or not the
      ** grammar defines an error token "ERROR".  
      **
      ** This is what we do if the grammar does define ERROR:
      **
      **  * Call the %syntax_error function.
      **
      **  * Begin popping the stack until we enter a state where
      **    it is legal to shift the error symbol, then shift
      **    the error symbol.
      **
      **  * Set the error count to three.
      **
      **  * Begin accepting and shifting new tokens.  No new error
      **    processing will occur until three tokens have been
      **    shifted successfully.
      **
      */
      if( yypParser->yyerrcnt<0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yymx = yypParser->yystack[yypParser->yyidx].major;
      if( yymx==YYERRORSYMBOL || yyerrorhit ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE,"%sDiscard input token %s\n",
             yyTracePrompt,yyTokenName[yymajor]);
        }
#endif
        yy_destructor(yypParser, (YYCODETYPE)yymajor,&yyminorunion);
        yymajor = YYNOCODE;
      }else{
         while(
          yypParser->yyidx >= 0 &&
          yymx != YYERRORSYMBOL &&
          (yyact = yy_find_reduce_action(
                        yypParser->yystack[yypParser->yyidx].stateno,
                        YYERRORSYMBOL)) >= YYNSTATE
        ){
          yy_pop_parser_stack(yypParser);
        }
        if( yypParser->yyidx < 0 || yymajor==0 ){
          yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
          yy_parse_failed(yypParser);
          yymajor = YYNOCODE;
        }else if( yymx!=YYERRORSYMBOL ){
          YYMINORTYPE u2;
          u2.YYERRSYMDT = 0;
          yy_shift(yypParser,yyact,YYERRORSYMBOL,&u2);
        }
      }
      yypParser->yyerrcnt = 3;
      yyerrorhit = 1;
#elif defined(YYNOERRORRECOVERY)
      /* If the YYNOERRORRECOVERY macro is defined, then do not attempt to
      ** do any kind of error recovery.  Instead, simply invoke the syntax
      ** error routine and continue going as if nothing had happened.
      **
      ** Applications can set this macro (for example inside %include) if
      ** they intend to abandon the parse upon the first syntax error seen.
      */
      yy_syntax_error(yypParser,yymajor,yyminorunion);
      yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
      yymajor = YYNOCODE;
      
#else  /* YYERRORSYMBOL is not defined */
      /* This is what we do if the grammar does not define ERROR:
      **
      **  * Report an error message, and throw away the input token.
      **
      **  * If the input token is $, then fail the parse.
      **
      ** As before, subsequent error messages are suppressed until
      ** three input tokens have been successfully shifted.
      */
      if( yypParser->yyerrcnt<=0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yypParser->yyerrcnt = 3;
      yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
      if( yyendofinput ){
        yy_parse_failed(yypParser);
      }
      yymajor = YYNOCODE;
#endif
    }
  }while( yymajor!=YYNOCODE && yypParser->yyidx>=0 );
  return;
}
