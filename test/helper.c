#include "helper.h"

long fsize(FILE *f) {
  long actual = ftell(f);
  fseek(f, 0, SEEK_END);
  long last = ftell(f);
  fseek(f, actual, SEEK_SET);
  return last;
}
