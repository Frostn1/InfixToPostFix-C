#include "../include/stack.h"
#include "../include/parser.h"
#include <stdio.h>
#include <string.h>
char* readFile(char* filePath) {

    
    // if (argc - 1 == flags.size()) throwError("missing file input");
    // if (i != argc - 1) throwError("arguments order is misaligned");
    if (_access(filePath, 0) == -1) throwError("file doesn't exist."); 
    FILE* filePointer = fopen(filePath,"r");
    if (!filePointer) throwError("can't open file");
    char* buffer = 0;
    long length;
    fseek(filePointer, 0, SEEK_END);
    length = ftell(filePointer);
    fseek(filePointer, 0, SEEK_SET);
    buffer = calloc(length, length);
    if (buffer) fread(buffer, 1, length, filePointer);
    fclose(filePointer);
    return buffer;
}

int main(int argc, char** argv) {
    if(argc < 2) {
        printf("Error occured : Missing text file or expression\n");
        return 1;
    }
    stack* st = initStack();
    if(!strcmp(argv[1], "-t")) {
        parser* pr = initParser(readFile(argv[2]));
        parse(pr);
        printf("PostFixExp is %s\n", pr->out);
    }
    return 0;
}