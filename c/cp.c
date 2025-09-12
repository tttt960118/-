#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;
#define BUFFER_SIZE 4096 // Optimal buffer size for efficient I/O

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    FILE *src = fopen(argv[1], "rb");
    if (src == NULL)
    {
        fprintf(stderr, "Could not open source file %s\n", argv[1]);
        return 1;
    }

    FILE *dst = fopen(argv[2], "wb");
    if (dst == NULL)
    {
        fclose(src);
        fprintf(stderr, "Could not open destination file %s\n", argv[2]);
        return 1;
    }

    BYTE buffer[BUFFER_SIZE];
    size_t bytes_read;

    // Read chunks from source and write to destination
    while ((bytes_read = fread(buffer, sizeof(BYTE), BUFFER_SIZE, src)) > 0)
    {
        fwrite(buffer, sizeof(BYTE), bytes_read, dst);
    }

    fclose(src);
    fclose(dst);
    return 0;
}