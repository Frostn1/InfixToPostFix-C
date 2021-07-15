#include "../include/parser.h"

parser* initParser(char* text) {
    parser* pr = (parser*)malloc(sizeof(parser));
    pr->st = initStack();
    pr->current = 0;
    pr->expression = (char*)malloc(sizeof(char) * (strlen(text)+1));
    pr->outSize = 1;
    pr->out = (char*)malloc(sizeof(char));
    strcpy(pr->expression, text);
    return pr;
}
void parse(parser* pr) {
    while(pr->current < strlen(pr->expression)) {
        while( pr->current < strlen(pr->expression) && isNumeric(pr->expression[pr->current])) {
        pr->out = (char*)realloc(pr->out,sizeof(char)*++pr->outSize);
        pr->out[pr->outSize-2] = pr->expression[pr->current];
        pr->out[pr->outSize-1] = '\0';
        pr->current++;
        }
        if(pr->current < strlen(pr->expression) && isOp(pr->expression[pr->current])) {
            if(pr->st->sp && (peek(pr->st)[0], pr->expression[pr->current])) {
                pr->out = (char*)realloc(pr->out,sizeof(char)*++pr->outSize);
                pr->out[pr->outSize-2] = pop(pr->st)[0];
                pr->out[pr->outSize-1] = '\0';
            }
            char* temp = (char*)malloc(sizeof(char)*2);
            temp[0] = pr->expression[pr->current];
            temp[1] = '\0';
            push(pr->st, temp);
        }
        pr->current++;
    }
    while(pr->st->sp > 0) {
        pr->out = (char*)realloc(pr->out,sizeof(char)*++pr->outSize);
        pr->out[pr->outSize-2] = pop(pr->st)[0];
        pr->out[pr->outSize-1] = '\0';
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
    printf("got here %c %c", first, second);
    return (first=='*' || first=='/') && (second=='+' || second=='-');
}