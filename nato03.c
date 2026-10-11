#include <stdio.h>
#include <string.h>

char isterm(char *term) {
  const char *nato[] = {
      "Alpha",  "Bravo",   "Charlie", "Delta",  "Echo",   "Foxtrot", "Golf",
      "Hotel",  "India",   "Juliet",  "Kilo",   "Lima",   "Mike",    "November",
      "Oscar",  "Papa",    "Quebec",  "Romeo",  "Sierra", "Tango",   "Uniform",
      "Victor", "Whiskey", "Xray",    "Yankee", "Zulu"

  };
  int x;
  char *n, *t;

  for (x = 0; x < 26; x++) {
    // Sets pointer n to the current NATO word
    n = nato[x];
    // Pointer t references the term passed.
    t = term;
    // Loops until the NATO term ends
    while (*n != '\0') {
      // Logically converts each letter to uppercaseand compares; refer to
      // chapter 5 for more info on this and other ASCII tricks.
      if ((*n | 0x20) != (*t | 0x20))
        // For no match, the loop breaks and the next term in nato[] is
        // compared.
        break;
      // Increments through each letter
      n++;
      // Increments through each letter
      t++;
    }
    // When pointer n is the null character, the terms have matched.
    if (*n == '\0')
      // Returns the first letter of the NATO term
      return (*nato[x]);
  }
  return ('\0');
}

int main() {
  char phrase[64];
  char *match;
  char ch;
  printf("NATO word or phrase: ");
  fgets(phrase, 64, stdin);
  match = strtok(phrase, " ");
  while (match) {
    if ((ch = isterm(match)) != '\0')
      putchar(ch);
    match = strtok(NULL, " ");
  }
  putchar('\n');

  return (0);
}
