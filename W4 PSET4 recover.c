#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int main(int argc, char *argv[])
{
    // PSEUDOCODE
    typedef uint8_t BYTE;
    BYTE buffer[512];
    int bytes_read, counter = 0;
    char filename[8];
    // Open memory card
    FILE *f = fopen(argv[1], "r");
    FILE *image = NULL;
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }
    if (f == NULL)
    {
        printf("./recover card.raw");
        return 1;
    }
    // Repeat until end of card
    while (1)
    {
        // Read 512 bytes into a buffer
        bytes_read = fread(buffer, sizeof(BYTE), 512, f);
        // If start of new jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))
        {
            // If first JPEG
            if (counter == 0)
            {
                //.... create file and write
                sprintf(filename, "%03i.jpg", counter);
                image = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), bytes_read, image);
                counter++;
            }
            // Else
            else
            {
                // Close the file and open a new file to write to
                fclose(image);
                sprintf(filename, "%03i.jpg", counter);
                image = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), bytes_read, image);
                counter++;
            }
        }
        // Else
        // If already found JPEG
        else if (counter != 0)
        {
            //... keep writing to it, and it might occur multiple times
            fwrite(buffer, sizeof(BYTE), bytes_read, image);
            if (bytes_read == 0)
            {
                fclose(image);
                fclose(f);
                return 0;
            }
        }
    }
    // If end of file reached, close file
    fclose(image);
    // Close any remaining files
    fclose(f);
}