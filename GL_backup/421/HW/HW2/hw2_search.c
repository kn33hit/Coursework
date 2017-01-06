/*
Neh Patel 
Homework 2 part (i)
searching for a number in an array using fork() 
compile: gcc -Wall hw2_search.c -o hw2
run: ./hw2
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define ARRAY_SIZE 16

int search(int data[ARRAY_SIZE],int num, int begin, int end){
  if(begin == end){
    if(num == *(data + end)){
      printf("THE POSITION OF %d IS IN INDEX: %d\n", num,end);
      return end;
    }else{
      exit(0);
      return -1;
    }
  }
  pid_t pid = fork();
  if(pid < 0){
    exit(0);
  }else if(pid == 0){
    // child  
    return search(data, num, begin, ((begin+end) / 2) );
  }else{
    // parent
    return search(data, num, ((begin + end) / 2+1), end);
  }
}

int main(int argc, char** argv){
  if(argc == 2){
    int data[ARRAY_SIZE]={1,2,3,4,5,6,7,8,9,0,11,12,13,14,15,16};
    int inData = -1;
    int num = atoi(argv[1]);
    inData = search(data, num, 0, ARRAY_SIZE);
    if(inData == -1){
      printf("The number is not in the table\n");
    }
  }else{
    printf("Run command: ./hw2 <number to find> \n");
  } 
  return 0;
}

