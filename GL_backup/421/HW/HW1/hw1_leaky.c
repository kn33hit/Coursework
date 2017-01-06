/*
Neh Patel
TuTh 5:30pm 
CMSC 421 
allocating memory and concatenating the two strings as many times as the count 

Compile on GL: gcc -Wall hw1_leaky.c -o leaky 
Run on GL:     ./leaky <count> <string1> <string2>
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXCHAR 10
char *concatenate(char* a, char* b) {
 // replace this with your string concatenation code
  int i = 0;
  //printf("A string is %s\n", a);
  //  printf("B string is %s\n", b);

  char *str = (char *) malloc(sizeof(char));
  int n = strlen(a);
  int m = strlen(b);
  
  for(i = 0; i < n ; i++){
    *str = *a;
    a++;
    str++;
  }
  for(i = 0; i < m ; i++){
    *str = *b;
    b++;
    str++;
  }
  for( i = 0; i < (n+m);i++){
    str--;
  }

  //printf("The concatenation is: %s\n", str);
  return str;
}

int main(int argc, char** argv) {
  if(argc<4) { 
    printf("Usage: hw1_leaky <count> <firstword> <secondword>\n");
    exit(1); }
  char *middle = "cruel" ;
  char number[MAXCHAR];
  int i=0;
  for(i=0;i<atoi(argv[1]);i++) {
    sprintf(number,"%d",i); // update the number string
    // begin leaky
    char *line = concatenate( // not leaked
			     concatenate(argv[2],number), // leaked
			     concatenate(middle, // leaked
					 concatenate(number, argv[3]))); // leaked
   if(i>0)  // can't free the statically allocated "cruel" string above
     //free(middle); 
   // end leaky      
   printf("%s\n",line);
   middle=line;
  }
  //free(middle);
}
