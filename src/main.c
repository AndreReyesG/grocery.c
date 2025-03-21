#include "product.h"

int main(void) {
  node_t *p = NULL;
  product_t prod;

  prod = new_product("strudels", "pan y pastelillos", 61945, 1, 183.13, 240.0, 20250322);
  add_product(&p, prod);

  prod = new_product("strudels", "pan y pastelillos", 61945, 1, 183.13, 240.0, 20250322);
  add_product(&p, prod);

  show_products(stdout, p);
  
  free_products(&p);
  return 0;
}
