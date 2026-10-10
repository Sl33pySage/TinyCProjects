#include <stdio.h>
#include <string.h>

int main() {
  char sometext[64];
  char *match;

  printf("Type some text: ");
  fgets(sometext, 64, stdin);

  // The initial call to strtok(), with the string to search.
  match = strtok(sometext, " ");

  // Loops as long as the return value isn't NULL
  while (match) {
    printf("%s\n", match);
    // In the second call to strtok(), NULL is used to keep searching the same
    // string.
    match = strtok(NULL, " ");
  }
  return (0);
}
