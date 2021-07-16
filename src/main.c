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
    if(!strcmp(argv[1], "-t")) {
        parser* pr = initParser(readFile(argv[2]));
        parse(pr);
        printf("Finished\n");
        printf("PostFixExp is %s\n", pr->out);
    } else if(!strcmp(argv[1],"-n")) {
        char* output = (char*)malloc(sizeof(char));
        output[0] = '\0';
        printf("argc is %d\n",argc);
        for(int i = 2;i<argc;i++) {
            printf("current is %s\n",argv[i]);
            output = (char*)realloc(output, sizeof(char)*(strlen(output)+strlen(argv[i])+1));
            strcat(output, argv[i]);
        }
        printf("%s\n",output);
        parser* pr = initParser(output);
        parse(pr);
        printf("Finished\n");
        printf("PostFixExp is %s\n", pr->out);
    }
    else {
        printf("missing flag\n");
    }
    return 0;
}