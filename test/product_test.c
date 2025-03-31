#include "product_test.h"
#include "helper.h"
#include "unity.h" 
#include <string.h>
#include <stdlib.h>

void test_product(void) {
  node_t *p = NULL;

  // le agremos elementos
  product_t prod = new_product("strudels", 61945, 1, 183.13, 240.0, 20250322);
  add_product(&p, prod);

  // crear un archivo temporal
  const char* filename = "test.txt";
  FILE *file;

  // abrir el archivo temporal y escribir en el 
  file = fopen(filename, "w+b");
  show_products(file, p);
  fclose(file);

  char *buffer = get_str_from_file(filename);

  // eliminar el archivo temporal
  if ( remove(filename) == -1 ) {
    perror("Error deleting file");
  }

  TEST_ASSERT_EQUAL_STRING("---\nstrudels\n61945\n1\n183.13\n240.00\n20250322\n", buffer);
  free(buffer);

  free_products(&p);
  TEST_ASSERT_NULL(p);
}
