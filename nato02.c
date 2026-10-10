#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  const char *nato[] = {
      "Alpha",  "Bravo",   "Charlie", "Delta",  "Echo",   "Foxtrot", "Golf",
      "Hotel",  "India",   "Juliet",  "Kilo",   "Lima",   "Mike",    "November",
      "Oscar",  "Papa",    "Quebec",  "Romeo",  "Sierra", "Tango",   "Uniform",
      "Victor", "Whiskey", "Xray",    "Yankee", "Zulu",
  };

  FILE *n;
  int ch;

  // If fewer than two arguments are present, the filename option is missing.
  if (argc < 2) {
    fprintf(stderr, "Please supply a text file argument\n");
    exit(1);
  }

  // Opens the filename supplied at the command prompt,referenced as argv[1]
  n = fopen(argv[1], "r");
  if (n == NULL) {
    fprintf(stderr, "Unable to open '%s'\n", argv[1]);
    exit(1);
  }

  // Reads one character at a time from the file, storing it in the variable ch.
  // The EOF marks the end of the file.
  while ((ch = fgetc(n)) != EOF) {

    // Processes only text characters
    if (isalpha(ch))
      // Uses the uppercase version of the character, minus the value of 'A' to
      // index the nato[] array
      printf("%s ", nato[toupper(ch) - 'A']);
  }
  putchar('\n');
  fclose(n);
  return (0);
}
