/*
Neh Patel                                                                      
TuTh 5:30pm                                                                    
CMSC 421                                                                        
allocating memory and concatenating the two strings as many times as the count 
and also freeing the memory so we dont have memory leaks 
 
Compile on GL: gcc -Wall hw1_leaky.c -o leaky    
Run on GL:     ./nonleaky <count> <string1> <string2>                         

currently "double free/ corruption error. Meaning the same memory is being 
deleted. 
trying to figure out how to free it without it being deleted
I just cant think of a way to pass the addresses from the function back 
to the main. I tried but the ouput is not working since I free it before 
it is even passed down ffrom the fucntion, hence the empty string is being 
printed. I dont know why this confused me. The second part shouldn't have 
scarred me like this haha .. ha .. :'/
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXCHAR 10

void* mymalloc(int size) {
  void* ptr = malloc(size);
  fprintf(stderr,"malloc: %p\n",ptr);
  return ptr;
}
void myfree(void* ptr) {
  fprintf(stderr,"free: %p\n",ptr);
  free(ptr);
}

char *concatenate(char* a, char* b) {
  // replace this with your string concatenation code
  int i = 0;
  //  printf("A string is %s\n", a);
  //  printf("B string is %s\n", b);
  
  char *str = mymalloc(sizeof(char));
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
  //*string = *str;
  myfree(str);

  //printf("The concatenation is: %s\n", str);
  return str;
}

int main(int argc, char** argv) {
  if(argc<4) { 
    printf("Usage: hw1_leaky <count> <firstword> <secondword>\n");
    exit(1); }
  char *middle="cruel";
  char number[MAXCHAR];
  int i=0;
  for(i=0;i<atoi(argv[1]);i++) {
    sprintf(number,"%d",i); // update the number string
    // begin leaky
    char *line = concatenate( // not leaked
			     concatenate(argv[2],number), // leaked
			     concatenate(middle, // leaked
					 concatenate(number, argv[3]))); // leaked
    // myfree(line);
    if(i>0)  // can't free the statically allocated "cruel" string above
     free(middle); 
    //   // end leaky      
   printf("%s\n", line);
   middle=line;
  }
  //free(middle);
}
