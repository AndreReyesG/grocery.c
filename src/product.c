#include "product.h"
#include <stdlib.h>
#include <string.h>

product_t new_product(char* name, char* category, int code, int stock, double pprice, double sprice, long expdate) {
  product_t new = {
    .code = code,
    .stock = stock,
    .purchase_price = pprice,
    .sale_price = sprice,
    .expiration_date = expdate,
  };
  strcpy(new.name, name);
  strcpy(new.category, category);
  return new;
}

void add_product(node_t **p, product_t product) {
  node_t *new = (node_t*)malloc(sizeof(node_t));
  new->product = product;
  new->next = NULL;

  if ( *p == NULL ) {
    *p = new;
  } else {
    node_t *aux = *p;

    while ( aux->next != NULL ) {
      aux = aux->next;
    }
    aux->next = new;
  }
}

void free_products(node_t **p) {
  while ( *p != NULL ) {
    node_t *next = (*p)->next;
    free(*p);
    *p = next;
  }
}

void show_products(FILE *out, node_t *p) {
  node_t *aux = p;

  while ( aux != NULL ) {
    fprintf(out, "%s, ", p->product.name);
    aux = aux->next;
  }
  fprintf(out, "\n");
}
