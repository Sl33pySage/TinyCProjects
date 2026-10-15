#include <stdio.h>

int main() {
  //  I/O deals with integers, not characters.
  int ch;
  // Reads input until the end of file is encountered; EOF is an integer value.
  while ((ch = getchar()) != EOF)
    // Spews output
    putchar(ch);
  return (0);
}
