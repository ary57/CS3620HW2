#include <stdio.h>
// print all args
void printArgs(char *arg){
    printf("%s\n", arg);
}

int main(int argc, char *argv[]){
    int index = 1; 
    if(argc < 1) printf("%s\n", "One argument expected.");
    else{
        while(argv[index] != NULL){
            char *input = argv[index];
            printArgs(input);
            index++;
        }
    }
    return 0;
}