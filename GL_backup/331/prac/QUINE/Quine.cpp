#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
                                                             
  string l[] = {
    "#include <iostream>",
    "#include <string>",
    "#include <fstream>",
    "using namespace std;",
    "",
    "int main(int argc, char* argv[])",
    "{",
    "",
    "    string l[] = { " ,
    "\"        \"",
    "    };",
    "    ofstream outFile(\"newQuine.cpp\"); ",
    "     for(int i = 0; i <= bstop; i++)",
    "       outFile << l[i] << endl;",
    "    outFile.close();",
    "    return 0;",
    "}"
  };
  
  int begin = 0;
  int arrayBegin = 9;
  int arrayStop = 11;
  int end = 17;
  char *p;
  string backslash = 0134;
  ofstream outFile("newQuine.cpp");
  for(int i = begin; i < arrayBegin; i++){
    outFile << l[i] << endl;
  }
  for(int i = 0; i <= arrayStop; i++){
    string temp = l[i];
    for(int j = 0 ; j < (signed)temp.size();j++){          
      if(temp[i].compare(backslash)){
	outFile << "\\";
      }else{
	outFile << temp[j];
      }
    } 
    outFile << endl;
  }
  for(int i = begin; i < arrayBegin; i++){
    outFile << l[i] << endl;
  }
  outFile.close();
  return 0;
}
