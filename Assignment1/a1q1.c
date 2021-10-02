#include <stdio.h>

int main(int argc, char *argv[])
{
    char buffer[512];
    size_t bytes;
    FILE *in, *out;
    in = fopen(argv[1], "rb");
    out = fopen(argv[2], "wb");
    if (in == NULL)
    {
        printf("Error: Source File does not exist\n");
        return 0;
    }
    while ((bytes = fread(buffer, 1, sizeof(buffer), in)) != 0)
    {
        if (fwrite(buffer, 1, bytes, out) != bytes)
        {
            printf("Error writing to Destination File\n");
            return 0;
        }
    }
    fclose(out);
    fclose(in);
    printf("Source File has been copied to destnation file succesfully!\n");
    return 0;
}