//Name: Abhinav Jambulingam
//Session: 17
//Email: abhij1@umbc.edu
//This is project 2
#include <iostream>
#include<string.h>
// ADD #include's HERE FOR ANY OTHER LIBRARIES YOU USE

using namespace std;

const int MAX_STR = 50;

void getAnswerFromUser(char prompt[],char input[],int inputLen);

bool testForAnagram(char input[]);

void  convertToCanonical (char buffer[]);

// expected unqualified-id before ‘return’

int main() {

  // For following to work you must be sure to define MAX_STR above
  // as a global constant (it must be global because it is used again
  // elsewhere).

  char buffer[MAX_STR];
  char msg [] = "Please enter your c-string value:"; 
  getAnswerFromUser(msg,buffer,MAX_STR);
  bool isAnagram = testForAnagram(buffer);
  if(isAnagram)
    {
      cout << "The string " << buffer << " is an anagram." << endl;

    }
  else
    {
      cout << "The string " << buffer << " is not an anagram" << endl;
    }

  // First, prompt for, and get sentence to test from user, reading
  // it into buffer[]
  // _______ = getAnswerFromUser( ... );

  // Now, test the inpu string to see if it's an anagram
  // _______ = testForAnagram( ... );

  // Lastly, see what testForAnagram() returned, and use that
  // to output the proper result

  // ...  // SOME CODE HERE

    return 0;
}
void getAnswerFromUser(char prompt[],char input[],int inputLen)
{
  cout << prompt << endl;
  cout << "Make sure your input string does not exeed " << inputLen << " characters" << endl;
  cin.getline(input,inputLen);
}
bool testForAnagram(char input[])
{
  char testStr[MAX_STR];
  strcpy(testStr,input);
  convertToCanonical(testStr);
  bool isAnagram = true;
  char temp;
  char templ;
  int start = 0;
  int end = strlen(testStr) - 1;
   
  while (start < end)
    {
      if(testStr[start] == testStr[end])
	{
	  start++;
	  end--;
	}
      else 
	{
	  isAnagram = false;
	  break;
	}
    }
  /* for(int a = 0; a < strlen(testStr); a++)
    {
      for(int b = strlen(testStr); b > 0; b++)
      testStr[a] = test  
  */ 
  return isAnagram;
}
void  convertToCanonical (char buffer[])
{
  
  int i = 0;
  int filter = 0;
  while(buffer[i] != '\0')
    {
      char ch = buffer[i];
      if(ch >= 'a' && ch <= 'z')
	{
	  buffer[filter] = ch;
	  filter++;
	}
      else if (ch >= 'A' && ch <= 'Z')
	{
	  buffer[filter] = ch + 32;
	  filter++;
	}
      i++;
    
    }
  
}
//
// NOW, ADD YOUR OTHER FUNCTIONS HERE
//   (Do not put it ABOVE main()! )
//
