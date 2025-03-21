#pragma once
#include <stdio.h>

typedef struct Product {
  char name[100];
  char category[100];
  int code;
  int stock;
  double purchase_price;
  double sale_price;
  long expiration_date;
} product_t;

typedef struct Node {
  product_t product;
  struct Node *next;
} node_t;

product_t new_product(char* name, char* category, int code, int stock, double pprice, double sprice, long expdate);
void add_product(node_t **p, product_t product);
void free_products(node_t **p);
void show_products(FILE *out, node_t *p);
