#include "category_test.h"
#include "helper.h"
#include "unity.h" 
#include <string.h>
#include <stdlib.h>

void test_add_category(void) {
  category_t *p = NULL;
  add_category(&p);
  TEST_ASSERT_EQUAL_INT(1, p->id);

  add_category(&p);
  TEST_ASSERT_NOT_NULL(p->next);

  TEST_ASSERT_EQUAL_INT(2, p->next->id);
  TEST_ASSERT_NULL(p->next->next);

  add_category(&p);
  TEST_ASSERT_NOT_NULL(p->next->next);
  TEST_ASSERT_EQUAL_INT(3, p->next->next->id);
  TEST_ASSERT_NULL(p->next->next->next);

  free_category(&p);
}

void test_del_category(void) {
  category_t *p = NULL;
  add_category(&p);
  int del;

  del = del_category(&p, 1);
  TEST_ASSERT_EQUAL_INT(0, del);

  del = del_category(&p, 2);
  TEST_ASSERT_EQUAL_INT(-1, del);

  free_category(&p);
}

void test_print_categories(void) {
  category_t *p = NULL;
  add_category(&p);
  add_category(&p);
  add_category(&p);

  FILE *file;
  file = fopen("test_1.txt", "w+b");
  print_categories(file, p);
  fclose(file);

  file = fopen("test_1.txt", "r+b");

  // Obtener tamaño del archivo
  long file_size = fsize(file);

  // Asignar memoria para almacenar el contenido del archivo
  char *got = (char*)calloc(file_size + 1, sizeof(char));
  fread(got, sizeof(char), file_size, file);
  fclose(file);

  // Comparar con la cadena esperada
  TEST_ASSERT_EQUAL_STRING("1, 2, 3, \n", got);

  // Liberar memoria
  free(got);
  free_category(&p);
}
