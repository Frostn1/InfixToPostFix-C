#ifndef PARSER_H
#define PARSER_H
#include <string.h>
#include <stdlib.h>
#include "stack.h"
typedef struct parser {
    stack* st;
    char* expression;
    char* out;
    int current;
    int outSize;
}parser;

parser* initParser();
void parse(parser* pr);
int isNumeric(char num);
int isSpace(char space);
int isOp(char op);
int isStrongerOp(char first, char second);
#endif // !PARSER_H