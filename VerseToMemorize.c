#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BSIZE 256

int main() {
  const char filename[] = "BibleVersesForProgrammersToMemorize.txt";
  FILE *fp;
  char buffer[BSIZE];
  char *r, *entry;
  int items, verse;
  char **list_base;

  fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "Unable to open file %s\n", filename);
    exit(1);
  }

  list_base = (char **)malloc(sizeof(char *) * 100);
  if (list_base == NULL) {
    fprintf(stderr, "Unable to allocate memory\n");
    exit(1);
  }

  items = 0;
  while (!feof(fp)) {
    entry = (char *)malloc(sizeof(char) * strlen(buffer) + 1);
    if (entry == NULL) {
      fprintf(stderr, "Unable to allocate memory\n");
      exit(1);
    }
    strcpy(entry, buffer);
    // This print statement prints every line because it's in the loop:
    // printf("%d: %s", items, entry);
    *(list_base + items) = entry;
    items++;
    if (items % 100 == 0) {
      list_base = (char **)realloc(list_base, sizeof(char *) * (items + 100));
      if (list_base == NULL) {
        fprintf(stderr, "Unableto reallocate memory\n");
        exit(1);
      }
    }
    r = fgets(buffer, BSIZE, fp);
    if (r == NULL) {
      break;
    }
    // printf("%s", buffer);
  }
  fclose(fp);
  srand((unsigned)time(NULL));
  verse = rand() % (items - 1);
  printf("%s", *(list_base + verse));
  return (0);
}
