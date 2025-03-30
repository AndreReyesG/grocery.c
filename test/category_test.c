#include "category_test.h"
#include "unity.h" 

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
