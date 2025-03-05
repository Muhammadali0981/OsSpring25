#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    if (!inputFile || !outputFile) {
        perror("Error opening file");
        return 1;
    }

    char ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        fputc(ch, outputFile);
    }

    printf("File copied successfully!\n");

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
