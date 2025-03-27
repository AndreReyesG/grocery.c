#include "product_test.h"
#include "unity.h" 
#include <string.h>
#include <stdlib.h>

long fsize(FILE *f) {
  long actual = ftell(f);
  fseek(f, 0, SEEK_END);
  long last = ftell(f);
  fseek(f, actual, SEEK_SET);
  return last;
}

void test_product(void) {
  node_t *p = NULL;

  // le agremos elementos
  product_t prod = new_product("strudels", "pan y pastelillos", 61945, 1, 183.13, 240.0, 20250322);
  add_product(&p, prod);

  // crear un archivo temporal
  const char* filename = "test.txt";
  FILE *file;

  // abrir el archivo temporal y escribir en el 
  file = fopen(filename, "w+b");
  show_products(file, p);
  fclose(file);

  // abrir el archivo temporal con permiso de escribir 
  file = fopen(filename, "r+b");
  char *buffer = (char*)malloc(sizeof(char) * fsize(file));
  char *aux = (char*)malloc(sizeof(char));
  fread(aux, sizeof(char), 1, file);

  // TODO: Leer el contenido del archivo de forma más eficiente
  while ( !feof(file) ) {
    strcat(buffer, aux);
    fread(aux, sizeof(char), 1, file);
  }

  free(aux);
  fclose(file);

  // eliminar el archivo temporal
  if ( remove(filename) == -1 ) {
    perror("Error deleting file");
  }

  TEST_ASSERT_EQUAL_STRING("---\nstrudels\npan y pastelillos\n61945\n1\n183.13\n240.00\n20250322\n", buffer);
  free(buffer);

  free_products(&p);
  TEST_ASSERT_NULL(p);
}
