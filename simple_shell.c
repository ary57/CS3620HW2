#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<readline/readline.h>

#define MAXINPUT 1024

int getInput(char *input);
void execute(char **args);
void removeSpace(char* input, char **final);

int main(){
    char inputString[1024];
    char *finalString[1024];

    printf("*** CS 3620 HW2 Simple Terminal ***\n");
    while(1){
        if(getInput(inputString))continue;

        removeSpace(inputString, finalString);

        if(strcmp(finalString[0], "quit") == 0){
            printf("bye\n");
            exit(0);
        }        
        execute(finalString);  
    }
}
void removeSpace(char *input, char **final){
    for(int i = 0; i < MAXINPUT; i++){
        final[i] = strsep(&input, " ");
        if(final[i] == NULL) break; 
        if(strlen(final[i]) == 0) i--;
    }
}
void execute(char **args){
    int pid = fork(); 

    if(pid < 0) printf("fork uncessful\n");
    else if(pid != 0) wait(NULL);
    else{
        int exec = execvp(args[0], args);
        if(exec < 0) perror(0);
        exit(0);
    }
}
int getInput(char *input){
    char *tempInput = readline(">--> ");
    if(strlen(tempInput) == 0) return 1; 
    strcpy(input, tempInput); 
    return 0; 
}