#include <stdio.h>
#include <stdlib.h>
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

int main(int argc, char *argv[]) {
    char *fileName = argv[1];
    FILE *file = fopen(fileName, "r");
    if(file == NULL){
        perror("Unable to open the file.\n");
        exit(1);
    }
    char line[200];
}
