// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;


int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // Copy header from input file to output file

    // "Buffer" to temporarily take memory, a type for unsigned 8-bit integeers just representing bytes
    unit8_header[HEADER_SIZE];
    // Reading buffer origin
    fread(header, HEADER_SIZE, 1, input);
    // Write data read in the new file, with the size of header
    fwrite(header, HEADER_SIZE, 1, output);

    // Reads samples from input file and write updated data to output file
    int16_t buffer;

    while((buffer = fgetc()) != EOF){
        // Change volume of the samples multiplying 
        buffer *= factor;
        
        // Update the file
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
