#include <stdio.h>
#include <stdlib.h>

#include "file_disemvowel.h"

int main(int argc, char *argv[]) {
  char *line;
  size_t size;
  FILE *inputFile = stdin;
  FILE *outputFile = stdout;
  size = 100;
  line = (char*) malloc (size + 1);
  if (argc >= 2) {
    // printf("Arg 1: %s\n", argv[0]);
    inputFile = fopen(argv[1], "r");
  }
   if (argc >= 3) {
    // printf("Arg 2: %s\n", argv[1]);
    outputFile = fopen(argv[2], "w");
  }


  while (getline(&line, &size, inputFile) > 0) {
    char *result = disemvowel(line);
    fprintf(outputFile, "%s\n", result);
    // printf("%s\n", result);
    free(result);
  }
  
  free(line);
  fclose(inputFile);
  fclose(outputFile);
}
