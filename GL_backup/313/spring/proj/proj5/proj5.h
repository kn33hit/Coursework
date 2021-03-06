// gcc -o main5 -m32 -g main5.c proj5.c proj5.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h> 
 
typedef struct BOOK_INFO
{
  char title[50];
  char author[40];
  unsigned int year_published;
}book_info;

static book_info memory[20]; 
static int head;

void init_heap();

book_info *new_book_info();

void del_book_info(book_info *book);

void dump_heap();
 
void findHead();
