#include <stdio.h>

void printArgs(char *arg){
    printf("%s\n", arg);
}

int main(int argc, char *argv[]){
    if(argc < 2) printf("%s\n", "One argument expected.");
    else{
        char *input = argv[1];
        printArgs(input);
    }
    return 0;
}