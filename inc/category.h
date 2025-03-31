#pragma once
#include <stdio.h>

typedef struct Category {
  struct Category *next;
  char name[20];
  int numprods;
  int id;
} category_t;

typedef struct StockList {
  category_t *head;
  int count_id;
} stock_list_t;

stock_list_t *new_stock_list(void);
void add_category(stock_list_t **p);
void free_category(stock_list_t **p);
int del_category(stock_list_t **p, int id);
void print_categories(FILE *out, stock_list_t *p);
