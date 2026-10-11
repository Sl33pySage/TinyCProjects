#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *nato[] = {
    "Alpha",  "Bravo",   "Charlie", "Delta",  "Echo",   "Foxtrot", "Golf",
    "Hotel",  "India",   "Juliet",  "Kilo",   "Lima",   "Mike",    "November",
    "Oscar",  "Papa",    "Quebec",  "Romeo",  "Sierra", "Tango",   "Uniform",
    "Victor", "Whiskey", "Xray",    "Yankee", "Zulu"

};

char isterm(char *term) {
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

int main(int argc, char *argv[]) {
  char phrase[64];
  char *match;
  char ch;
  FILE *n;

  // If fewer than two arguments are present, the filename option is missing.
  if (argc < 2) {
    fprintf(stderr, "Please supply a text file argument\n");
    exit(1);
  }

  // Opens the filename supplied at the command prompt, referenced as argv[1]
  n = fopen(argv[1], "r");
  if (n == NULL) {
    fprintf(stderr, "Unable to open '%s'\n", argv[1]);
    exit(1);
  }

  // Loops until the end of open file handle n
  while (!feof(n)) {
    // Grabs a line of text up to 63 characters
    fgets(phrase, 64, n);
    // Filters out a lot of characters
    match = strtok(phrase, " ,.!?=()[]{}'\"");
    // Loops until all the words in the line are read
    while (match) {
      // Sends the matching word off to the isterm() function
      if ((ch = isterm(match)) != '\0')
        putchar(ch);
      match = strtok(NULL, " ,.!?=()[]{}'\"");
    }
  }
  putchar('\n');
  fclose(n);
  return (0);
}
