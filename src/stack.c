#include "../include/stack.h"

stack* initStack() {
    stack* st = (stack*)malloc(sizeof(stack));
    st->sp = 0;
}
void push(stack* st, char* slot) {
    st->memory = (char**)malloc(sizeof(char)*(st->sp+1));
    st->memory[st->sp] = (char*)malloc(sizeof(char)*(strlen(slot)+1));
    strcpy(st->memory[st->sp++], slot);
}
char* pop(stack* st) {
    assert(st->sp > 0);
    char* out = (char*)malloc(sizeof(char)*(strlen(st->memory[st->sp-1])+1));
    strcpy(out, st->memory[st->sp-1]);
    free(st->memory[st->sp-1]);
    st->memory = (char**)malloc(sizeof(char)*(st->sp));
    st->sp--;
    return out;
}
char* peek(stack* st) {
    assert(st->sp > 0);
    char* out = (char*)malloc(sizeof(char)*(strlen(st->memory[st->sp-1])+1));
    strcpy(out, st->memory[st->sp-1]);
    return out;
}