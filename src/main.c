#include "../include/stack.h"
#include "../include/parser.h"
#include <stdio.h>
#include <string.h>
#include <io.h>
char* readFile(char* filePath) {

    
    // if (argc - 1 == flags.size()) throwError("missing file input");
    // if (i != argc - 1) throwError("arguments order is misaligned");
    if (_access(filePath, 0) == -1) printf("file doesn't exist.\n"); 
    FILE* filePointer = fopen(filePath,"r");
    if (!filePointer) printf("can't open file\n");
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
        printf("missing text file or expression\n");
        return 1;
    }
    stack* st = initStack();
    parser* pr = NULL;
    if(!strcmp(argv[1], "-t")) {
        pr = initParser(readFile(argv[2]));
    } else if(!strcmp(argv[1],"-n")) {
        char* output = (char*)malloc(sizeof(char));
        output[0] = '\0';
        for(int i = 2;i<argc;i++) {
            output = (char*)realloc(output, sizeof(char)*(strlen(output)+strlen(argv[i])+1));
            strcat(output, argv[i]);
        }
        pr = initParser(output);
    }
    else {
        printf("missing flag\n");
        return 0;
    }

    parse(pr);
    printf("%s\n", pr->out);
    return 0;
}