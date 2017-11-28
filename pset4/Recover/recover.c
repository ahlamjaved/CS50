/**
 * Recovers JPEGs from an image.
 */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZEOF 512

int main(void)
{
    // open memory card file
    FILE *inputs = fopen("card.raw", "r");
    if (inputs == NULL)
    {
        printf("Could not open card.raw.\n");
        return 1; // Error
    }

    // create a buffer
    unsigned char buffer[BUFFER_SIZEOF];

    // filename counter
    int filecount = 0;

    FILE *pictures = NULL;

    // JPEG found?
    int jpg_found = 0; //false

    // sift through entire cardfile
    while (fread(buffer, BUFFER_SIZEOF, 1, inputs) == 1)
    {
        // read first 4 bytes of buffer, verify if jpeg found
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0)
        {
            if (jpg_found == 1)
            {
                // close current pic if new pic is found
                fclose(pictures);
            }
            else
            {
                // jpg found, now we can write
                jpg_found = 1;
            }

            char filename[8];
            sprintf(filename, "%03d.jpg", filecount);
            pictures = fopen(filename, "a");
            filecount++;
        }

        if (jpg_found == 1)
        {
            // write bytes to file when jpegs found
            fwrite(&buffer, BUFFER_SIZEOF, 1, pictures);
        }

    }

    // close files
    fclose(inputs);
    fclose(pictures);

    return 0;
}