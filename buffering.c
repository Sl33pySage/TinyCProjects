#include <stdio.h>

int main() {
  // A holding bin for standard output; BUFSIZ is defined in stdio.h.
  char buffer[BUFSIZ];
  int a, b;

  // Commits standard output to block suffering
  setbuf(stdout, buffer);

  printf("Type a letter:");
  a = getchar();
  printf("Type a letter:");
  b = getchar();

  printf("a='%c', b='%c'\n", a, b);
  return (0);
}
