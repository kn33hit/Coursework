/**************************************************************         
 * File:    Driver.cpp                          
 * Project: CMSC 341 - Project 4                               
 * Author : Neh Patel                                                          
 * Date   : 16-November-2014                                                   
 * Section: Lecture-02                                                         
 * E-mail:  npatel10@umbc.edu                                                  
 *                                                                             
 *  The main Driver file. Used to test and run the Hash Table 
 *  code: Linear, Quadratic, and Double Hash. Writes the created
 *  table using data from file, recieved in command line. 
 *  Also outputs some data concerning wth probing for the hash
 *  tables.
 *                                                                             
 *************************************************************/
#include <iomanip>
#include <iostream>
#include "LinearProbing.h"
#include "QuadraticProbing.h"
#include "DoubleHash.h"
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>
using namespace std;

void OutputResults(string m, int s);

int main(int argc, char* argv[]){

  if(argc == 6){
    // argv[4] = M the size of the hash table  
    int size = atoi(argv[4]);
    // argv[2] = N -- total number of random integers attempted to insert   
    int N = atoi(argv[2]);
    // argv[3] = INTERVAL -- the interval(number of attempted insertions) for 
    //           reporting data  
    int I = atoi(argv[3]);
    // R (double hashing) = the largest prime less than M    
    int R = atoi(argv[5]);
    // argv[4] is M which is the size of the hash table 
    
    // making a few objects
    // to store fetched data a vector is used, then the data in the vector is 
    // used to insert in the hash table. 
    vector<int> numbers;
    LinearProbing linear(size);
    QuadraticProbing Qprobe(size);
    DoubleHash doubleH(size,R);
    
    ifstream infile;
    infile.open(argv[1],ios_base::in);
    if(infile.fail()){
      cout << "failed to open the file" << endl;
      exit(1);
    }

    // JUST DOING THIS SO THE FILE IS NOT APPENDED EVERYTIME. A FRESG FILE IS MADE
    // WHEN PROGRAM IS RE-RAN
    ofstream outfile;
    outfile.open("output.txt");
    outfile << "\n";
    outfile.close();

    // READING IN THE FILE AND ONLY THE INSERTION SIZE GIVEN IS USED TO FETCH THE DATA 
    int number;
    int insertionCount = 0;
    while(infile >> number){
      if(insertionCount == N){
	break;
      }
      numbers.push_back(number);
      insertionCount++;      
    }
    
    fstream ofile;
    ofile.open("output.txt", fstream::in | fstream::out | fstream::app);

    // the headers for the output.txt
    //---------------------------------------------------------- 
    // LINEAR PROBING (insert / output)                          
    //---------------------------------------------------------- 
    OutputResults("Linear Probing", size);
    int temp = N/I;                                       
    // gap between intervals                                            
    int initial = N/temp;                                    
    // this will be index to be printed               
    int inc = initial;                                           
    // just to compare and see how many time to print              
    int i = 1;                                                                
    // condition is to how many times the print is ran                                                        
    // n is the amount of insertion attempted 
    while(i <= N){             
      // numbers[] is the vector that holds all the data 
      linear.insert(numbers[i-1]);
      // inc keeps track of the stuff we want to input in here
      if(i == inc){
	//output
	ofile << "     " << inc << "       ";
	// get lambda gets you the load factor of the table 
	ofile <<setiosflags(ios::fixed) << setprecision(2) << linear.GetLambda() ;
	// get success and unsuccess data returns the number of insertion 
	// that were successful and failed 
	// total probes returns that probes that have ocured overall
	ofile << "         " <<						\
	  // total probes returns the number of probing that occured 
	  linear.GetSuccessData() << "         " <<  linear.GetUnSuccessData() << "          "  << \
	  linear.GetTotalProbes() << 	"          ";
	// total probes returns the number of probing that occured
	// i is the current i number in the loop
	ofile << setiosflags(ios::fixed) << setprecision(2) << (double)linear.GetTotalProbes()/(double)i;
	// get max probes returns the max number of probes
	ofile <<  "          " << linear.GetMaxProbes() << "          " << linear.GetCluster();
	// get avg cluster gets the average length in all cluster  
        ofile << "          " << setiosflags(ios::fixed) << setprecision(2) << linear.GetAvgCluster();
	// get max cluster gives you the biggest cluster size 
        ofile << "          "  << linear.GetMaxCluster() << endl;
	inc = initial +inc;
      }
      i++;
    }

    //---------------------------------------------------------- 
    // QUADRATIC PROBING (insert / output)                                    
    //---------------------------------------------------------- 
    OutputResults("Quadratic Probing", size);
    inc = initial;
    i = 0;
    // n is the amount of insertion attempted  
    while(i <= N){
      Qprobe.insert(numbers[i-1]);
      if(i == inc){
        ofile << "     " << inc << "       ";
	// get lambda gets you the load factor of the table          
        ofile <<setiosflags(ios::fixed) << setprecision(2) << Qprobe.GetLambda();
	// get success and unsuccess data returns the number of insertion      
        // that were successful and failed                                     
        // total probes returns that probes that have ocured overall   
        ofile << "         " <<    Qprobe.GetSuccessData() << "         " <<  Qprobe.GetUnSuccessData() << "          "  << Qprobe.GetTotalProbes() <<    "          ";
	// total probes returns the number of probing that occured             
        // i is the current i number in the loop    
        ofile << setiosflags(ios::fixed) << setprecision(2) << (double)Qprobe.GetTotalProbes()/(double)i;
	// get max probes returns the max number of probes          
	ofile <<  "          " << Qprobe.GetMaxProbes() << "          " << Qprobe.GetCluster();
	// get avg cluster gets the average length in all cluster 
        ofile << "          " << setiosflags(ios::fixed) << setprecision(2) << Qprobe.GetAvgCluster();
	// get max cluster gives you the biggest cluster size  
        ofile << "          "  << Qprobe.GetMaxCluster() << endl;
        inc = initial +inc;
      }
      i++;
    }


    //----------------------------------------------------------
    // DOUBLE HASHING (insert / output)
    //----------------------------------------------------------
    OutputResults("Double Hashing" , size);
    inc = initial;
    i = 0;
    // n is the amount of insertion attempted                             
    while(i <= N){
      doubleH.insert(numbers[i-1]);
      // inc is to keep track of the intervals we want to outputat 
      if(i == inc){
	// output
        ofile << "     " << inc << "       ";
	// get lambda gets you the load factor of the table    
        ofile <<setiosflags(ios::fixed) << setprecision(2) << doubleH.GetLambda();
	// get success and unsuccess data returns the number of insertion      
        // that were successful and failed                                     
        // total probes returns that probes that have ocured overall       
        ofile << "         " <<                                         \
          doubleH.GetSuccessData() << "         " <<  doubleH.GetUnSuccessData() << "          "  << \
          doubleH.GetTotalProbes() <<    "          ";
	// total probes returns the number of probing that occured             
        // i is the current i number in the loop       
        ofile << setiosflags(ios::fixed) << setprecision(2) << (double)doubleH.GetTotalProbes()/(double)i;
	// get max probes returns the max number of probes
	ofile <<  "          " << doubleH.GetMaxProbes() << "          " << doubleH.GetCluster();
	// get avg cluster gets the average length in all cluster     
        ofile << "          " << setiosflags(ios::fixed) << setprecision(2) << doubleH.GetAvgCluster();
	// get max cluster gives you the biggest cluster size            
        ofile << "          "  << doubleH.GetMaxCluster() << endl;
        // adding on the increment for the next call
	inc = initial +inc;
      }
      i++;
    } 

    ofile.close();
    infile.close();
    
    // printing the tables
    linear.OutputResults();  
    Qprobe.OutputResults();
    doubleH.OutputResults();
    
    // a message for the user
    cout << "\n\nOutput in output.txt.\nActual Tables in outputTable.txt\n\n" << endl;
  
  }else{
    cout << "Not enough data passed in the command-line" << endl;
  }
}


/* ===========================================================================
   OUTPUT RESULTS
      this function helps us modify a file called output.txt 
      Basically write to that file the header of Table Analysis
      PRE
        needs a string and the size of the table passd into it 
============================================================================*/
void OutputResults(string m, int size){  
  // used f stream to append the file on it.
  // so it is usable by all 3 tables
  fstream outfile;
  outfile.open("output.txt", fstream::in | fstream::out | fstream::app);
  // size is the size of the table passed into the fucntion from the command
  // line input 
  outfile << "                      " << m << " Analysis(Table Size = " << size   << ")" << endl;
  outfile << "                      ----- Inserts ----     ---------- Probes -----------        --------- Clusters -------" << endl;
  outfile << "     N     lambda     success     failed     total          avg        max        number       avg       max" << endl;
 
  outfile << "\n";
  outfile.close();
}
