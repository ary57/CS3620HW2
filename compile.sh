#!/bin/bash

# should I recompile the programs or shoud I see if there is an already compiled file or not
#   I can use -nt to see if a compiled file exists, but how will I know if the file has been changed and needs recompiling or not?


gcc print_args.c
# RESULT=`./a.out Example` # am I supposed to pass in argument like this or should it be done in './compile.sh' step?
./a.out Example
# echo "$RESULT" # echo is required for me to see the results, is echo ok or are we supposed to use something else?

gcc print_env.c
./a.out
# RESULT=`./a.out`
# echo "$RESULT"