/*
Assignment Name: Assignment #1
Group: Hamza Saeed, Zain Syed, Neh N. Patel
Date: 09/16/2014
Professor: William Echlin
Class: CMSC 331
*/
#include<iostream>
#include<fstream>
#include <deque>
#include <algorithm>
#include <iterator>
#include<cctype>
#include<locale>
#include <string>
#include<cstring>
using namespace std;
int main()
{
  std::locale loc;      //Declaring an object of class std::locale.

  //Declaring all the other variables with their respecive data types.
  bool isWord = false;
  int size = 0;
  int vowels = 0;
  string input = "NULL";
  string holder[100];

  fstream namefile;        //Declaring an input/output stream class object. This object will then go ahead and open the text file for processing.
  namefile.open("project.txt", ios::in);

  if (namefile)
    {
      while (namefile >> input) //Using the while loop, the content of the text file is being read into an array of strings named holder.
	{

	  holder[size] = input;
	  size++;

	}

      //close the file.
      namefile.close();
    }
  else
    {
      cout << "Error: Cannot open the file.\n"; //For displaying the error message if an error occurs with reading the file.
    }

  /*
    Check if each element in the array is an alphabet or not using the isalpha function and locale object (loc) from the locale class.
    The isWord will be true if the element in the array is an alphabet, otherwise it will turn false.
  */

  for (int counter = 0; counter < size; counter++)
    {

      std::string str = holder[counter];   // Used the source: "Std::isalpha." Isalpha. N.p., n.d. Web. 17 Sept. 2014. http://www.cplusplus.com/reference/locale/isalpha/
      for (std::string::iterator it = str.begin(); it != str.end(); ++it)
	{
	  if (std::isalpha(*it, loc)){

	    isWord = true;
	  }
	  else

	    isWord = false;
	}

      /*
	Finding if the elements of the file contain atleast 3 vowels. Used the string find() function. 
	If atleast 3 vowels were found then the program prints "3 vowels found in [string element]"
	SOURCE [MLA FORMAT]
	"Find If a String Contains a Character in C++ (boost Allowed)." - Stack Overflow. N.p., n.d. Web. 17 Sept. 2014.
	http://stackoverflow.com/questions/14028343/find-if-a-string-contains-a-character-in-c-boost-allowed
      */
      if (isWord){

	int vowels = 0;

	if (str.find('a') != std::string::npos){
	  vowels=vowels+ 1;
	}
	if (str.find('e') != std::string::npos){
	  vowels = vowels + 1;
	}
	if (str.find('i') != std::string::npos){
	  vowels = vowels + 1;
	}
	if (str.find('0') != std::string::npos){
	  vowels=vowels + 1;
	}
	if (str.find('u') != std::string::npos){
	  vowels=vowels + 1;
	}
	if (vowels >= 3)

	  {
	    cout << "3 Vowels Found in " << holder[counter] << endl;
	  }

	/*
	  Used the source to learn how to assign an element of a string array to a string:
	  SOURCE [MLA]:
	  "Convert First Letter in String to Uppercase." C++. N.p., n.d. Web. 17 Sept. 2014
	  http://stackoverflow.com/questions/8530529/convert-first-letter-in-string-to-uppercase
	*/

	string str = holder[counter];

	/* Assigning the last character of each string to the character variable ch.
	   Used the source to learn how to move to the last character of a string.
	   SOURCE [MLA]:
	    "Get the Last Element of a Std::string." C++. N.p., n.d. Web. 17 Sept. 2014. 
	    http://stackoverflow.com/questions/4884548/get-the-last-element-of-a-stdstring
	*/

	char ch = str.back();

	/*
	  Checking if the word starts with the letter L/l and ends with the letter E/e.
	  The system will print out "The Word starts with L and ends with e" if a word
	  matches the criteria.
	*/
	if (str[0] == 'l' || str[0] == 'L'){
	  if (ch == 'e' || ch == 'E'){

	    cout << holder[counter] << "  The Word starts with L and ends with e" << endl;


	  }

	}

      }

      /*
	Checking if the element is a prime number or not. If the element (integer in the text file) is a
	prime number, than the system prints out "[The integer] is a prime number"
	SOURCE [MLA FORMAT]:
	"Prime Number Program - C++ Forum." Prime Number Program - C++ Forum. N.p., n.d. Web. 17 Sept. 2014.
	http://www.cplusplus.com/forum/general/1125/
      */

      else
	{

	  int value = atoi(str.c_str()); //Converting the string to an integer using atoi().
	  bool isPrime = false;
	  if (value < 10000)
	    {
	      for (int i = 2; i <= value; i++)
		{
		  isPrime = true;
		  for (int n = 3; n < i - 1; n++)
		    {
		      if (i % n == 0 && i < 10000)
			{
			  isPrime = false;
			}
		    }
		}

	      if (isPrime)
		{
		  cout << value << " is a prime number" << endl;
		}
	    }

	}

    }

  system("pause");
  return 0;

}
