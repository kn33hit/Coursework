#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
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
    " ",
    "    };",
    "    char newline = 012, quote = 042, escape = 0134;",
    "    int i = 0, hstart = 0, hstop = 9, bstart = 9, bstop = 10, maxline = 18;",
    "    ofstream outFile(\"newQuine.cpp\"); ",
    "    for(int i = hstart; i <= hstop; i++)",
    "       outFile << l[i] << endl;",
    "    for (i = bstart; i < bstop; i++) {", 
    "       outFile << \"        \" ;",
    "       outFile << quote;",
    "       const char *cstr = l[i].c_str();",
    "       for (const char *p = cstr; *p; p++) {",
    "           if(*p == escape)",
    "               outFile << escape;",
    "           outFile << *p; ",
    "       }",
    "       outFile << quote << \",\" << endl;",
    "    }",
    "    for (i = bstop; i < maxline; i++) {",
    "        outFile << l[i] << endl;",
    "    }",
    "    outFile.close();",
    "    return 0;",
    "}"
  };
  char newline = 012, quote = 042, escape = 0134;
  int i = 0, hstart = 0, hstop = 9, bstart = 9, bstop = 10, maxline = 33;
  ofstream outFile("cppQuine.cpp");
  for (i = hstart; i < hstop; i++) 
    outFile << l[i] << endl;
  for (i = bstart; i < bstop; i++) {
    outFile << "         " ;
    outFile << quote;
    const char *cstr = l[i].c_str();
    for (const char *p = cstr; *p; p++) {
      if (*p == escape)
        outFile <<  escape;
      outFile << *p;
    }
    outFile << quote <<","<< endl;
  }
  for (i = bstop; i < maxline; i++) {
    outFile << l[i] << endl;
    }
  outFile.close();
  return 0;
}

