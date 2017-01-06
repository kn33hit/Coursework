#include <iostream>
#include <cctype>
#include <cstring>
// ADD #include's HERE FOR ANY OTHER LIBRARIES YOU USE

using namespace std;

// ADD ANY GLOBAL CONSTANT HERE
const MAX_STR= 180;
bool testForPalindrome(char inputString);
void convertToConanical(char inputString);
void getAnswerFromUser(std::string prompt,char inputString, int inputLen); 
//int argc, char *argv[]
int main() {

  // For following to work you must be sure to define MAX_STR above
  // as a global constant (it must be global because it is used again
  // elsewhere).

  char buffer[MAX_STR] = {} ;
  bool isPalindrome = false; 
  string prompt = "Type whatever: ";
 

  // First, prompt for, and get sentence to test from user, reading
  // it into buffer[]
  getAnswerFromUser(prompt,buffer,MAX_STR);

  // Now, test the inpu string to see if it's an palindrome
  isPalindrome = testForPalindrome(buffer);

  // Lastly, see what testForPalindrome() returned, and use that
  // to output the proper result

    // SOME CODE HERE
  if(isPalindrome == true){
    cout << "'" << buffer << "'" << " is a palindrome" << endl;
  } else{
    cout << "'" << buffer << "'" << " is a palindrome" << endl;

    return 0;
}

}
  bool testForPalindrome(char inputString){
    convertToConanical(inputString);
    char inputStringTwo[MAX_STR]={};
    for(int i = (strlen(inputString)-1); i>=0;i--){
      inputStringTwo = inputStringTwo + inputString[i];}
    if(strcmp(inputString,inputStringTwo)){
      return true;
    }
    return false;
}

  void convertToConanical(char &inputString){
    char newString[MAX_STR] = {};
    for(int i = 0; i < (strlen(inputString)); i++){
      if(isalpha(inputString[i])){
	  newString = newString + inputString[i]
	  }
     
	}
      newString = tolower(newString);
}

  void getAnswerFromUser(string prompt,char &inputString,int inputLen){
    cout << prompt << endl;
    cin >> inputString;
}
