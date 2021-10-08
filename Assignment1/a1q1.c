#include <stdio.h>

int main(int argc, char *argv[])
{
    char buffer[512];           // define a buffer of 512 chars
    size_t bytes;               //bytes is an unsigned int
    FILE *in, *out;             //declare in and out as file pointers
    in = fopen(argv[1], "rb");  //open the 1st cmd line arg for reading and store the returned file pointer to 'in'
    out = fopen(argv[2], "wb"); //open the 2nd cmd line arg for writing and store the returned file pointer to 'out'
    if (in == NULL)
    {
        printf("Error: Source File does not exist\n"); // print error if source does not exist
        return 0; //exit the prog
    }
    while ((bytes = fread(buffer, 1, sizeof(buffer), in)) != 0) //loop to read input from 'in' and store inside buffer and continue
    {                                                           //doing so till no bytes can be read

        if (fwrite(buffer, 1, bytes, out) != bytes)         //write contents stored in buffer to 'out'
        {
            printf("Error writing to Destination File\n");  //print error in case amount of bytes written != amount of bytes read
            return 0; //exit the prog
        }
    }
    fclose(out);        //close the files
    fclose(in);
    printf("Source File has been copied to destnation file succesfully!\n");
    return 0;     //exit the prog
}