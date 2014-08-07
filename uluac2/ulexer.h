#ifndef ULEXER_H
#define ULEXER_H

#include <ctype.h>
#include <stdlib.h>
#include "basetypes.h"
#include "llerror.h"
#include "uparser.h"

//#define TK_AND 257
//#define TK_BREAK 258
//#define TK_DO 259
//#define TK_ELSE 260
//#define TK_ELSEIF 261
//#define TK_END 262
//#define TK_FALSE 263
//#define TK_FOR 264
//#define TK_FUNCTION 265
#define TK_GOTO 266
//#define TK_IF 267
//#define TK_IN 268
//#define TK_LOCAL 269
//#define TK_NIL 270
//#define TK_NOT 271
//#define TK_OR 272
//#define TK_REPEAT 273
//#define TK_RETURN 274
//#define TK_THEN 275
//#define TK_TRUE 276
//#define TK_UNTIL 277
//#define TK_WHILE 278
// other terminal symbols
//#define TK_CONCAT 279
//#define TK_DOTS 280
//#define TK_EQ 281
//#define TK_GE 282
//#define TK_LE 283
//#define TK_NE 284
#define TK_DBCOLON 285
#define TK_EOS 286
//#define TK_NUMBER 287
//#define TK_NAME 288
//#define TK_STRING 289



typedef struct {
	u16 type;
	u08 keyword[10];
} reserved;

static reserved keywords[] = {
	{TK_AND, "and"},
	{TK_BREAK, "break"},
	{TK_DO, "do"},
	{TK_ELSE, "else"},
	{TK_ELSEIF, "elseif"},
	{TK_END, "end"},
	{TK_FALSE, "false"},
	{TK_FOR, "for"},
	{TK_FUNCTION, "function"},
	{TK_IF, "if"},
	{TK_IN, "in"},
	{TK_LOCAL, "local"},
	{TK_NIL, "nil"},
	{TK_NOT, "not"},
	{TK_OR, "or"},
	{TK_REPEAT, "repeat"},
	{TK_RETURN, "return"},
	{TK_THEN, "then"},
	{TK_TRUE, "true"},
	{TK_UNTIL, "until"},
	{TK_WHILE, "while"},
/*	{TK_CONCAT, ".."},
	{TK_DOTS, "..."},
	{TK_EQ, "=="},
	{TK_GE, ">="},
	{TK_LE, "<="},
	{TK_NE, "~="},
	{TK_NAME, "<name>"},
	{TK_NUMBER, "<number>"},
	{TK_STRING, "<string>"},
	{TK_EOS, "<eof>"},*/
};

typedef struct SString { //String structure - store only pointer to existing stream position and string lengh. Used to save RAM.
	u08 bempty; //boolean if buff is emtry and not saved
	u16 bp; //pointer in stream for buff
	u16 bplen; //buff len
} SString;

typedef struct Token {
	u16 token;
	SString semInfo;
	union {
		u32 nvalue;
		float fvalue;
	} number;
} Token;

typedef struct LexState {
	u08 current;
	u08 linenumber;
	u08 lastline;
	Token t;
	Token lookahead;
	u08 decpoint;
	u08* z; //input stream
	u16 zp; //current pointer in z input stream
	SString buff;
} LexState;

//lexer function export
u16 llex(LexState* ls, Token* t);
void next(LexState* ls);
void setInput(LexState* ls, u08* stream);
ERROR_CODE getLastULexError();

/*
//parser function export
void *ParseAlloc(void *(*mallocProc)(size_t));
void Parse(
  void *yyp,                   // The parser 
  int yymajor,                 // The major token code number 
  ParseTOKENTYPE yyminor       // The value for the token 
  ParseARG_PDECL               // Optional %extra_argument parameter 
);
void ParseFree(
  void *p,                    // The parser to be deleted 
  void (*freeProc)(void*)     // Function used to reclaim memory 
);
*/
#endif