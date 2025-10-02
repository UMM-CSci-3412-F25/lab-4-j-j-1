#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "file_disemvowel.h"

bool is_vowel(char vowel) {
  return (
    vowel == 'a' || vowel == 'A' ||
    vowel == 'e' || vowel == 'E' ||
    vowel == 'i' || vowel == 'I' ||
    vowel == 'o' || vowel == 'O' ||
    vowel == 'u' || vowel == 'U'
  );
}

char *disemvowel(char *str) {
  int non_vowels = 0;
  int length = strlen(str);
  for (int i=0; i<length; i++) {
    if (!is_vowel(str[i])) {
      non_vowels++;
    }
  }
  char *result = (char*) calloc(non_vowels+1, sizeof(char));
  int j = 0;
  for (int i=0; i<length; i++) {
    if (!is_vowel(str[i])) {
      if (result != NULL) {
        result[j] = str[i];
      }
      j++;
    }
  }
  if (result != NULL) {
    result[non_vowels] = '\0';
  }
  
  return result;
}


