#include "unity.h" 
#include "category_test.h" 
#include "product_test.h"

void setUp(void) {}
void tearDown(void) {}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_product);
  // TEST category
  RUN_TEST(test_add_category);
  RUN_TEST(test_del_category);
  RUN_TEST(test_print_categories);
  return UNITY_END();
}
