#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]){
    // printf("    USER=%s\n", getenv("USER"));
    printf("TERM_PROGRAM=%s\n", getenv("TERM_PROGRAM")); // on fastx it shows (null)
    printf("SHELL=%s\n", getenv("SHELL"));
    printf("TERM=%s\n", getenv("TERM"));
    printf("TMPDIR=%s\n", getenv("TMPDIR")); // on fastx it shows (null)
    printf("TERM_PROGRAM_VERSION=%s\n", getenv("TERM_PROGRAM_VERSION")); // on fastx it shows (null)
    printf("TERM_SESSION_ID=%s\n", getenv("TERM_SESSION_ID")); // shows (null) for both my mac and fastx
    printf("USER=%s\n",getenv("USER"));
    return 0; 
}