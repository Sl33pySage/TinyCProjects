#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char isterm(char *term) {
  const char *nato[] = {
      "Alpha",  "Bravo",   "Charlie", "Delta",  "Echo",   "Foxtrot", "Golf",
      "Hotel",  "India",   "Juliet",  "Kilo",   "Lima",   "Mike",    "November",
      "Oscar",  "Papa",    "Quebec",  "Romeo",  "Sierra", "Tango",   "Uniform",
      "Victor", "Whiskey", "Xray",    "Yankee", "Zulu"};
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
  char word[64];
  char *match;
  char ch;
  FILE *n;
  int offset;

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

  offset = 0;

  // Loops as long as the file has bytes to read
  while ((ch = fgetc(n)) != EOF) {

    // Words start with a letter of the alphabet
    if (isalpha(ch)) {

      // Stores the character to build the word
      word[offset] = ch;
      offset++;

      // Checks for overflow; bails if so
      if (offset >= 64) {
        fprintf(stderr, "Buffer overflow\n");
        return (1);
      }
    }

    // A nonalphabetic character is found, meaning the end of a word.
    else {
      // Confirms the word[] buffer has some text in it
      if (offset > 0) {

        // Cap your strings!
        word[offset] = '\0';

        // Processes the word, returning a valid character or the null
        // character (doesn't print)
        putchar(isterm(word));
        // Resets the offset to store the next word
        offset = 0;
      }
    }
  }
  putchar('\n');
}
