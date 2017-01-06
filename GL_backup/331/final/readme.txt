Project Name:  Five Quine Relay
Course:        CMSC 331
Authors:       Nikolaus woehlke  woehlke1@umbc.edu
               Tae Song          jw65293@umbc.edu 
               James Guan        jguan3@umbc.edu
               Neh N. Patel      npatel10@umbc.edu
Last Update:   2014 December 11
Description:   The relay is a set of five programs
               in five different languages n0 thru n4,
               where for n(i) when compiled and run
               will produce the source code for n(i+1)
               for i = 0 to 3, and n(4) when compiled
               and run will produce the source for n(0).
               The chain followed in our project is:
               c -> c++ -> python -> ruby -> java -> c.

Files:         Six files are included in this project:

readme.txt:    Project information and commentary
cfinal.c:       program in C which, when compiled and
               run, produces the output file cpcopy.cpp,
               an exact duplicate of file cpfinal.cpp
cpfinal.cpp:   A program in C++ which, when compiled and
               run, produces the output file pcopy.py,
               an exact duplicate of the file pfinal.py
pfinal.py:     A Python program which, when run, produces
               the output file rcopy.rb, an exact
               duplicate of the file rfinal.rb
rfinal.rb:     A Ruby program which, when run, produces
               the output file Jcopy.java, an exact
               duplicate of the file Jfinal.java
Jfinal.java:   A Java program which, when run, produces
               the output file ccopy.c, an exact
               duplicate of the file cfinal.c

All programs in the Five Quine Relay project were designed
to compile and run on the UMBC gl Linux machines.

compile c code:    gcc -o cfinal cfinal.c
run the program:   cfinal
confirm output:    diff cpfinal.cpp cpcopy.cpp

compile c++ code:  g++ -o cpfinal cpfinal.cpp
run the program:   cpfinal
confirm output:    diff pfinal.py pcopy.py

compile and run
the python code:   python pfinal.py
confirm output:    diff rfinal.rb rcopy.rb

compile and run
the ruby code:     ruby rfinal.rb
confirm output     diff Jfinal.java Jcopy.java

compile java code: javac -d . Jfinal.java
run the program:   java quine.Jfinal
confirm output:    diff cfinal.c ccopy.c

Output can also be confirmed using md5sum.

--- Program Structure ---

All program files in the Five Quine Relay project follow
the same basic structure, with each file conceptually
divided into three distinct segments, the Header,
Text Array, and Body.

The Header consists of all code lines preceeding the
  initialization of the Text Array, terminating with the
  declaration of the array itself.

The Text Array is variously an array or list of Strings or
  character pointers which contains all of the lines of
  code of the Header and Body segments for each of the
  programs within the quine relay.  Each line of code
  is contained in a single string of the array.  Note
  that quote characters within lines of code must be
  preceeded by backslash escape characters.

The Body consists of all lines of code following the
  initialization of the Text Array, comencing with the
  closing brackets of the initialization itself.  In each
  program, the Body section performs several basic tasks:

  1) Define key variables:
     hstart: array index of start of the Header for the
       next program in the array.
     hstop: array index for the end of the Header for
       next program in the array.
     bstart: array index of the start of the Body of
       the next program in the array.
     bstop: array index of the end of the Body of the
       next program in the array.
     maxline: where necessary, an array index indicating
       the end of the array may be defined.

     Additionally, variables are set for new line,
     quotation mark, and backslash characters where
     necessary, in order to avoid including backslash
     characters within the code lines, except as escape
     characters within the array.

  2) Open the output file

  3) Print the Header lines for the next program in the
     relay to the output file, using the hstart and
     hstop indexes.

  4) Recreate the Text Array in the output file.  Spacing,
     opening and closing quotations, and terminating commas
     must be added before and after the code lines.  In
     addition, backslash escape characters must be added
     before quotation marks that appear within the lines of
     code.  Generally this is done by indexing over each
     individual string one character at a time, outputting
     a backslash if the character is a quotation mark, then
     outputting the character itself regardless.  In the
     Python code, this is instead done by calling the
     string.replaceAll() function.

  5) Print the Body lines for the next program in the the
     relay to the output file, using the bstart and
     bstop indexes.

  6) Close the output file and end program.

Sources:

- for basic program structure -
"Quine (computing)." Wikipedia. Wikimedia Foundation,
  12 Nov. 2014. Web. 2 Dec. 2014.
  http://en.wikipedia.org/wiki/Quine_(computing)

- for iteration over characters in c -
Burger, John, David Brill, and Filip Machi.
  The Quine Page. Ed. Gary Thompson II.
  22 Dec. 1998. Web. 2 Dec. 2014.
  http://www.nyx.net/~gthompso/self_c.txt