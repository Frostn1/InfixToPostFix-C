#ifndef PARSER_H
#define PARSER_H
typedef struct parser {
    char* expression;
    char* out;
    int current;
}parser;

parser* initParser();
void parse(parser* pr);
int isNumeric(char num);
int isSpace(char space);
int isOp(char op);
#endif // !PARSER_H