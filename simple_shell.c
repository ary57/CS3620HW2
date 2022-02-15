#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>


#define MAXINPUT = 1024; 

void greet(){
    printf("* * * * * * * * * * \n");
    printf("*                  *\n");
    printf("*    CS3620 HW2    *\n");
    printf("*   Simple Shell   *\n");
    printf("*                  *\n");
    printf(" * * * * * * * * * *\n");
}

// input method
int getInput(char *str){
    char *buf; 

	buf = readline("\n>>> ");

    if(strlen(buf) != 0){
        add_history(buf); 
        strcpy(str, buf);
        return 0; 
    }else{
        return 1; 
    }
}


int main(){
    char inputString[1024];
    greet();
    while(1){
        printf("TMPDIR=%s\n", getenv("TMPDIR")); // print directory
        if(!getInput(inputString)) break; 
    }
}