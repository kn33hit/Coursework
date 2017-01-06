// neh patel 
// buf_desc.h 

#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#ifndef HEXDUMP_COLS 
#define HEXDUMP_COLS 8
#endif

typedef struct BUF_DESC{
  void *buffer;
  unsigned int len;
  struct buf_desc *next;
}buf_desc;

static buf_desc *head;

void init_buf_desc();

buf_desc* new_buf_desc();

void del_buf_desc(buf_desc *buf);

void clean_buf_desc();

void dump_buf_desc();

void hexdump_buf_desc(buf_desc *buf);

int getLength(buf_desc *buf);
