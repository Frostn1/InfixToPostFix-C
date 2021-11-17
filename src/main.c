#include "../inc/stack.h"
#include "../inc/parser.h"
#include "../inc/utils.h"
#include <stdio.h>
#include <string.h>
#include <io.h>



int main(int argc, char** argv) {
    stack* st = initStack();
    parser* pr = NULL;
    if(argv[1] != NULL && !strcmp(argv[1], "-t")) {
        pr = initParser(readFile(argv[2]));
        parse(pr);
        printf("%s\n", pr->out);
    } else if(argv[1] != NULL && !strcmp(argv[1],"-n")) {
        char* output = (char*)malloc(sizeof(char));
        output[0] = '\0';
        for(int i = 2;i<argc;i++) {
            output = (char*)realloc(output, sizeof(char)*(strlen(output)+strlen(argv[i])+1));
            strcat(output, argv[i]);
        }
        pr = initParser(output);
        parse(pr);
        printf("%s\n", pr->out);    
    } else {
        char buffer[MAX_LENGTH] = {0};
        for(;;) {
            printf("~ ");
            fgets(buffer, MAX_LENGTH, stdin);
            buffer[strlen(buffer)-1] = '\0';
            if(!strcmp(buffer,"")) break;
            pr = initParser(buffer);
            parse(pr);
            printf("%s\n", pr->out);
        }
    }



    
    return 0;
}