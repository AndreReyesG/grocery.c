#include "category_test.h"
#include "unity.h" 


void test_category(void) {
  category_t *p = NULL;
  add_category(&p);
  TEST_ASSERT_EQUAL_INT(1, p->id);
  TEST_ASSERT_NULL(p->next);
}
