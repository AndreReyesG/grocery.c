#include "unity.h" 
#include "category_test.h" 
#include "product_test.h"

void setUp(void) {}
void tearDown(void) {}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_product);
  RUN_TEST(test_category);
  return UNITY_END();
}
