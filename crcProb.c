#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <math.h>


uint8_t gencrc(uint8_t *data, size_t len)
{
    // printf("Values Passed: data: %hhu, len: %zu\n", *data, len);        
    uint8_t crc = 0xff;
    size_t i, j;
    for (i = 0; i < len; i++) {
        crc ^= data[i];
        for (j = 0; j < 8; j++) {
            if ((crc & 0x80) != 0)
                crc = (uint8_t)((crc << 1) ^ 0x31);
            else
                crc <<= 1;
        }
    }
    return crc;
}


// got help for this method from: https://stackoverflow.com/questions/238603/how-can-i-get-a-files-size-in-c
long long sizeOfFile(char *fileName){
    struct stat st;
    stat(fileName, &st);
    return st.st_size;
}

// got help for this method from: https://www.codevscolor.com/c-program-read-file-contents-character
uint8_t parseFile(char *fileName){
    //1
    FILE *filePointer;
    char ch;
    int size = sizeOfFile(fileName);
    int sizeInBytes = (int)ceil(size/8);
    char *buffer = malloc(sizeof(char) * size);

    //2
    filePointer = fopen(fileName, "r");

    //3
    if (filePointer == NULL) printf("File is not available \n");
    
    else{
        //4
        int index = 0;
        while ((ch = fgetc(filePointer)) != EOF){
            buffer[index] = ch; 
            index++;
            // printf("%c", ch);
            
        }
    }
    // printf("buffer = %s\n", buffer);
    uint8_t crcVal = gencrc((uint8_t *)buffer, size); 

    free(buffer); 
    //5
    fclose(filePointer);
    return crcVal; 
}

int main(int argc, char *argv[]){
    int index = 1; 
    while(argv[index] != NULL){
        // char *fileName = argv[1];
        char *fileName = argv[index];
        // char *fileName = "parallel_crc.c";
        int fileSize = sizeOfFile(fileName); 
        // printf("fileName = %s, size = %d\n", fileName, fileSize); 

        int pid = fork();
        if(pid < 0) printf("fork  uncessful\n");
        else if(pid > 0) wait (NULL); 
        else{
            uint8_t crcVal = parseFile(fileName); 
            printf("%s crc=%d\n",fileName, crcVal);
            exit(pid); 

        }
        index++;
    }
    return 0; 
}