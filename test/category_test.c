#include "category_test.h"
#include "helper.h"
#include "unity.h" 
#include <string.h>
#include <stdlib.h>

void test_add_category(void) {
  stock_list_t *stock_list = new_stock_list();
  TEST_ASSERT_NULL(stock_list->head);
  TEST_ASSERT_EQUAL_INT(1, stock_list->count_id);

  add_category(&stock_list);
  TEST_ASSERT_EQUAL_INT(1, stock_list->head->id);

  add_category(&stock_list);
  TEST_ASSERT_NOT_NULL(stock_list->head->next);

  TEST_ASSERT_EQUAL_INT(2, stock_list->head->next->id);
  TEST_ASSERT_NULL(stock_list->head->next->next);

  add_category(&stock_list);
  TEST_ASSERT_NOT_NULL(stock_list->head->next->next);
  TEST_ASSERT_EQUAL_INT(3, stock_list->head->next->next->id);
  TEST_ASSERT_NULL(stock_list->head->next->next->next);

  free_category(&stock_list);
}

void test_del_category(void) {
  stock_list_t *p = new_stock_list();
  add_category(&p);
  int del;

  del = del_category(&p, 1);
  TEST_ASSERT_EQUAL_INT(0, del);

  del = del_category(&p, 2);
  TEST_ASSERT_EQUAL_INT(-1, del);

  free_category(&p);
}

void test_print_categories(void) {
  stock_list_t *p = new_stock_list();
  add_category(&p);
  add_category(&p);
  add_category(&p);

  const char *tmpfile = "tmpfile.dat";
  print_categories_h(tmpfile, p);

  char *got = get_str_from_file(tmpfile);

  remove(tmpfile);

  TEST_ASSERT_EQUAL_STRING("1, 2, 3, \n", got);

  free(got);
  free_category(&p);
}

void test_add_and_del_categories(void) {
  stock_list_t *p = new_stock_list();
  add_category(&p);
  add_category(&p);
  add_category(&p);
  add_category(&p);
  add_category(&p);

  const char *tmpfile = "tmpfile.dat";
  char *got;

  print_categories_h(tmpfile, p);
  got = get_str_from_file(tmpfile);
  remove(tmpfile);
  TEST_ASSERT_EQUAL_STRING("1, 2, 3, 4, 5, \n", got);
  free(got);

  del_category(&p, 1);
  add_category(&p);
  add_category(&p);
  print_categories_h(tmpfile, p);
  got = get_str_from_file(tmpfile);
  remove(tmpfile);
  TEST_ASSERT_EQUAL_STRING("2, 3, 4, 5, 6, 7, \n", got);

  free(got);
  free_category(&p);
}

void print_categories_h(const char *pathname, stock_list_t *p) {
  FILE* f = fopen(pathname, "w+b");
  print_categories(f, p);
  fclose(f);
}
