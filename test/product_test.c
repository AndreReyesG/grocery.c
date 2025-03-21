#include "unity.h" 
#include "product.h"
#include <string.h>
#include <stdlib.h>

void setUp(void) {}
void tearDown(void) {}

long fsize(FILE *f) {
  long actual = ftell(f);
  fseek(f, 0, SEEK_END);
  long last = ftell(f);
  fseek(f, actual, SEEK_SET);
  return last;
}

void test(void) {
  node_t *p = NULL;
  product_t prod = new_product("strudels", "pan y pastelillos", 61945, 1, 183.13, 240.0, 20250322);
  add_product(&p, prod);

  const char* filename = "test.txt";
  FILE *file;

  // open and print the products in test.txt
  file = fopen(filename, "w+b");
  show_products(file, p);
  fclose(file);

  // open and read the file
  file = fopen(filename, "r+b");
  char *buffer = (char*)malloc(sizeof(char) * fsize(file));
  char *aux = (char*)malloc(sizeof(char));
  fread(aux, sizeof(char), 1, file);

  // TODO: forma más eficiente de leer el archivo
  while ( !feof(file) ) {
    strcat(buffer, aux);
    fread(aux, sizeof(char), 1, file);
  }

  free(aux);
  fclose(file);

  if ( remove(filename) == -1 ) {
    perror("Error deleting file");
  }

  TEST_ASSERT_EQUAL_STRING("test, \n", buffer);
  free(buffer);

  free_products(&p);
  TEST_ASSERT_NULL(p);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test);
  return UNITY_END();
}
