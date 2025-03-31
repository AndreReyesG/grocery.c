#include "helper.h"
#include <stdlib.h>

long fsize(FILE *f) {
  long actual = ftell(f);
  fseek(f, 0, SEEK_END);
  long last = ftell(f);
  fseek(f, actual, SEEK_SET);
  return last;
}

char *get_str_from_file(const char *pathname) {
  FILE* f = fopen(pathname, "r+b");
  long file_size = fsize(f);
  char *str = (char*)calloc(file_size + 1, sizeof(char));
  fread(str, sizeof(char), file_size, f);
  fclose(f);
  return str;
}
