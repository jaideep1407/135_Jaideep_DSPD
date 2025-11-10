/*Write a C program (name it "filecopy. c")  that copies the contents of one file to a destination file. This program will read data from one file and copy them to another. The first input that the program will need is the names of the two files: input file ("input.txt") and output file ("output.txt"). Once the two file names have been obtained, the program must open the input file and create and open the output file.*/
#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *inputFile, *outputFile;
    char ch;
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return 1;
    }
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return 1;
    }
    while ((ch = fgetc(inputFile)) != EOF) {
        fputc(ch, outputFile);
    }
    printf("File copied successfully from input.txt to output.txt\n");
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}

/*Sample Output:
File copied successfully from input.txt to output.txt
*/