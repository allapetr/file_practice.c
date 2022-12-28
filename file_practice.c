#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    //Create temporary holder(forbidden word)
    uint8_t tmp[512];

    //Create pointer to file/open file on read mode
    FILE *file_to_copy = fopen(argv[1], "r");
    //Create pointer to new file(the copy)
    FILE *copy = fopen(argv[2], "w");


    //Loop through file
    for (;;)
    {
        int sz = fread(tmp, 1, 512, file_to_copy);
        if (sz == 0)
            break;
        fwrite(tmp, 1, sz, copy);
    }

    fclose(file_to_copy);
    fclose(copy);
}
