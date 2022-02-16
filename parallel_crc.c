#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

uint8_t gencrc(uint8_t *data, size_t len)
{
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

// void removeSpace(char *input, char **final){
//     for(int i = 0; i < 1024; i++){
//         final[i] = strsep(&input, " ");
//         if(final[i] == NULL) break; 
//         if(strlen(final[i]) == 0) i--;
//     }
// }

int main(int argc, char **argv){
    char **final;
    final = argv; 
    // removeSpace(argv, final);
    int index = 0;
    while(argv[index] != NULL){
        int pid = fork(); 

        if(pid < 0) printf("fork uncessful\n");
        else if(pid > 0) wait(NULL);
        else{
            uint8_t *data;  // unsure how to get these
            size_t len; // unsure how to get these

            uint8_t crcValue = gencrc(data, len);
            printf("%s=%d\n",final[index], crcValue);
        }
        index++;
    }
}

