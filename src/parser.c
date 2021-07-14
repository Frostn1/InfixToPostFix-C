#include "../include/parser.h"

parser* initParser(char* text) {
    parser* pr = (parser*)malloc(sizeof(parser));
    pr->st = initStack();
    pr->current = 0;
    pr->expression = (char*)malloc(sizeof(char) * (strlen(text)+1));
    pr->outSize = 1;
    strcpy(pr->expression, text);
    return pr;
}
void parse(parser* pr) {
    while(pr->current < strlen(pr->expression)) {
        while(isNumeric(pr->expression[pr->current])) {
        pr->out = (char*)malloc(sizeof(char)*++pr->outSize);
        pr->out[pr->outSize-1] = pr->expression[pr->current];
        pr->out[pr->outSize] = '\0';
        pr->current++;
        }
        if(isOp(pr->expression[pr->current])) {
            if(isStrongerOp(peek(pr->st)[0], pr->expression[pr->current])) {
                pr->out = (char*)malloc(sizeof(char)*++pr->outSize);
                pr->out[pr->outSize-1] = pop(pr->st)[0];
                pr->out[pr->outSize] = '\0';
            }
            push(pr->st, &pr->expression[pr->current]);
            pr->current++;
        }
        pr->current++;
    }
    while(pr->st->sp > 0) {
        pr->out = (char*)malloc(sizeof(char)*++pr->outSize);
        pr->out[pr->outSize-1] = pop(pr->st)[0];
        pr->out[pr->outSize] = '\0';
    }
}
int isNumeric(char num) {
    return num >= '0' && num <= '9';
}
int isSpace(char space) {
    return space == ' ';
}
int isOp(char op) {
    switch(op) {
        case '+':
        case '-':
        case '*':
        case '/': 
            return 1;
        default: 
            return 0;
    }
}

int isStrongerOp(char first, char second) {
    return (first=='*' || first=='/') && (second=='+' || second=='-');
}