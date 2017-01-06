/*    NEH PATEL 
gcc -c -m32 -g -pthread main8.c -o main8.o
gcc -m32 -g -pthread -o main8 main8.o rot13_dev.o
*/

#include <stdio.h>
#include <string.h>
#include "rot13_dev.h"

void *myFunc(void * key){

}

int main(){
  char key[100];
  char enter = 13;
  void* (*interrupt_fn)(void*);
  interrupt_fn = &myFunc;
  do{
  printf("Input to ROT13 (ENTER to exit)\n");
  scanf("%s", key);
  char *i = init_rot13_dev( interrupt_fn(key), key);
  printf("ROT13 String: \n");
  printf("%c\n", i);
  }while(key[0] != 13);


  return 1;
} 
