/**************************************************************      
 * File:    TrafficSim.cpp          
 * Project: CMSC 341 - Project 1 - Traffic Light Simulation       
 * Author : Neh N. Patel                                              
 * Date   : Sept 29                                                
 * Section: 2                                                          
 * E-mail:  npatel10@umbc.edu                                        
 *                                                                  
 * Base class for the project.The instance of this object is      
 * created in the driver. It uses every object created for this    
 * object. uses queues This is the main source file with all the
 * implemetation 
 *                                                            
 *************************************************************/

#include "TrafficSim.h"
#include <iostream>
#include <cstdlib>
#include <fstream>   // file IO
#include <string>    // string
#include <ctype.h>    
#include <stdlib.h>   // atoi
using namespace std;

//------------------------------------------------------------
//CONTRUCTOTRS 
//    used to create the entire simulation
//    only PRE is a provided file name through the command-line
//    POST: intializes a few queues 
//-----------------------------------------------------------
TrafficSim::TrafficSim(){
  cout << "Please provide a file name in the command line" << endl;
  exit(1);
}

TrafficSim::TrafficSim(char* filename){
  // set to false so we know every code in read file has occured 
  bool fileRead = false;
  //  cout << " in constructor" << endl;
 fileRead = ReadFromFile(filename);
  // intializing the queues 
 // cout << "read file done" << endl;
 if(fileRead == false){
   cout << "Problem in opening the file" << endl;
    exit(1);
 }

 int i = 1;
 // loop twice 
 while(i <= 2){
   // cannot just create the instance of a car inside the push()
   // need to create the object then push it in the queue 
   Vehicle car('c');
   NorthBound.push(car);
   SouthBound.push(car);
   EastBound.push(car);
   WestBound.push(car);
   i++;
  }
 // print at zero time 
 printBoard(0);

}

/*-----------------------------------------------------------------------
// DO RUN
      pre: needs a file name in the constructor so this would be the 
           next thing to be run 
     post: outputs multiple boards according to the time limit 
-----------------------------------------------------------------------
*/
void TrafficSim::DoRun(){
  // at every second the output is printed 
  // with time at bottom 
  // other things to do every second 
  // 1) determine if light should change 
  // 2) remove cars from queue
  // 3) add cars from queue
  // 4) print intersection(board) 
  int const MINS= 2;
  int secs = MINS * 60;
  int NSrun = 1,EWrun = 1;
  // acting like these functions are working as bool signals
  // true is green, red is false
  // north and south are green
  bool north = true, south = true, east = false, west = false;

  for(int i = 1; i <= secs; i++){
    // pushing in cars at north
    if((i % flow.GetNorthCars()) == 0){
      Vehicle car('c');
      NorthBound.push(car);
    }
    // pushing in cars at south 
    if((i % flow.GetSouthCars()) == 0){
      Vehicle car('c');
      car.SetTime(i);
      SouthBound.push(car);
    }
    // pushing in cars at east 
    if((i % flow.GetEastCars()) == 0){
      Vehicle car('c');
      car.SetTime(i);
      EastBound.push(car);
    }
    // pushing in cars in west
    if((i % flow.GetWestCars()) == 0){
      Vehicle car('c');
      car.SetTime(i);
      WestBound.push(car);
    }
    // pushing in trucks in north 
    if((i % flow.GetNorthTrucks()) == 0){
      Vehicle car('t');
      car.SetTime(i);
      NorthBound.push(car);
    }
    // pusing in the trucks at south 
    if((i % flow.GetSouthTrucks()) == 0){
      Vehicle car('t');
      car.SetTime(i);
      SouthBound.push(car);
    }
    // pushing in the trucks at east
    if((i % flow.GetEastTrucks()) == 0){
      Vehicle car('t');
      car.SetTime(i);
      EastBound.push(car);
    }
    // pushing in the trcuks at west 
    if((i % flow.GetWestTrucks()) == 0){
      Vehicle car('t');
      car.SetTime(i);
      WestBound.push(car);
    }



    // popping the cars depending on the light that is open 
    if(north){
      NorthBound.pop();
      SouthBound.pop();
    }else{
      EastBound.pop();
      WestBound.pop();
    }
    
    
    // if no traffic in E/W then N/S is set to green 
    if((EastBound.size()==0) && (WestBound.size()==0)){
      cout << "TRAFFIC LIGHT CHANGED TO NORTH/SOUTH GREEN" << endl;
      north = true;
      south = true;
      east = false;
      west = false;
    }
    
    // every 30 secs NS checks for traffic change 
    if(north){
      if((NSrun%30)==0){
	if((EastBound.size()>0) || (WestBound.size()>0)){
	  // change N/S to red and E/W to green 
	  north = false;
	  south = false;
	  east = true;
	  west = true;
	  // print message 
	  cout << "TRAFFIC CHANGED TO EAST/WEST GREEN" << endl;
	}
      }

      //increment the seconds
      NSrun++;
    }
    
    if(east){
      if(EWrun > 10){
	// if nothing is in E/W lanes 
	if((EastBound.size()==0) || (WestBound.size()==0)){
	  // switch signals 
	  north = true;
	  south = true;
	  west = false;
	  east = false;
	  // print message 
	  cout << "traffic light change to N/S:green" << endl;
	}
      }
      //increment teh sconds
      
      EWrun++;
    }
    printBoard(i);
  }  


}

/*-----------------------------------------------------------------------
// READ FROM FILE
    Pre: needs a fiename passed to it 
    Post: returns a boolean depending on whether it was able to open 
          a proper file. Also the flow rates for both vehicles 
	  in each direction is set 
-----------------------------------------------------------------------
*/
bool TrafficSim::ReadFromFile(char* filename){
  ifstream infile;
  infile.open(filename, ios_base::in);
  // just to be on a safer side if the fiel does not open properly      
   
  if(infile.fail()){
    // return flase if opening the file fails  
    return false;
   }
  // cout << "after fail" << endl;
  string file;
  int cars, trucks;
  // as there is only going to be four lines to read, compare with 4      
  // this takes one variable after the other in the file 
  // since we know the order of the file. We can code it so 
  // first thing it takes is direction, then colons, then cars and trucks 
  
  while(infile >> file >> cars >> trucks){
    //     cout << file << cars << " " << trucks << endl;
    // above line just for testing 
    if(file == "N:"){
      // setting north flow rate 
      flow.SetNorthCars(cars);
      flow.SetNorthTrucks(trucks);
    }else if(file == "S:"){
      // setting south flow rate
      flow.SetSouthCars(cars);
      flow.SetSouthTrucks(trucks);
    }else if(file == "E:"){
      // setting east flow rate  
      flow.SetEastCars(cars);
      flow.SetEastTrucks(trucks);
    }else if(file == "W:"){
      // setting west flow rate  
     flow.SetWestCars(cars);
     flow.SetWestTrucks(trucks);
    }
  }
  // cout << "after loop" << endl;
  // dont forget to close the file                                            
  infile.close();
  return true;
}


/*-----------------------------------------------------------------------
//PRINT BOARD
    Pre: needs the current time passed in 
    Post: prints a board of the simulation at the given second 
-----------------------------------------------------------------------
*/
void TrafficSim::printBoard(int sec) const{

  // SETTING SOUTH 
  // printing number of cars in SB 
  cout << "  SB     " << SouthBound.size() << endl;
  //6
  if(SouthBound.size() > 5){
    cout << "      x "   <<endl;
  }else{
    cout << endl;
  }
  //5
  if(SouthBound.size() > 4){
    cout << "      x "   <<endl;
  }else{
    cout << endl;
  }
  //4
  if(SouthBound.size() > 3){
    cout << "      x "   <<endl;
  }else{
    cout << endl;
  }
  //3
  if(SouthBound.size() > 2){
    cout << "      x "   <<endl;
  }else{
    cout << endl;
  }
  //2
  if(SouthBound.size() > 1){
    cout << "EB    x"   <<endl;
  }else{
    cout << "EB " <<endl;
  }
  //1
  if(SouthBound.size() > 0){
    cout <<" "<< EastBound.size()<< "    c "   <<endl;
  }else{
    cout << " " << EastBound.size() << endl;
  }
  //-------------------------------------------------------------------
  // EAST BOUND 
  //cout << six << five << four << three << two << one << " ";
  if(EastBound.size() > 5){
    cout << "x";
  }else{
    cout<<" ";
  }

  //5
  if(EastBound.size() > 4){
    cout << "x";
  }else{
    cout<<" ";
  }

    //4
  if(EastBound.size() > 3){
    cout << "x";
  }else{
    cout<<" ";
  }

    //3
  if(EastBound.size() > 2){
    cout << "x";
  }else{
      cout<<" ";
    }

  //2
  if(EastBound.size() > 1){
    cout << "x";
  }else{
    cout<<" ";
  }

  //1
  if(EastBound.size() > 0){
    cout <<"c";
  }else{
    cout<<" ";
  }

  //------------------------------------------------------------------
  // WEST BOUND 
  //  cout << one << two << three << four << five << six <<endl;

  if(WestBound.size() > 0){
    cout << " c";
  }else{
    cout<<" ";
  }

  //5
  if(WestBound.size() > 1){
    cout << "x";
  }else{
    cout<<" ";
  }

  //4
  if(WestBound.size() > 2){
    cout << "x";
  }else{
    cout<<" ";
  }

  //3
  if(WestBound.size() > 3){
    cout << "x";
  }else{
    cout<<" ";
  }

  //2
  if(WestBound.size() > 4){
    cout << "x";
  }else{
    cout<<" ";
  }
  //1
  if(WestBound.size() > 5){
    cout <<"x" << endl;
  }else{
    cout<<" " << endl;
  }


  //------------------------------------------------------------------
  //cout << "      " << one << "    "<< WestBound.size() << endl;
  
  // NORTH BOUND 
  //1
  if(NorthBound.size() > 0){
    cout <<"      c   WB"   << endl;
  }else{
    cout <<"        WB" << endl;
  }
  //2
  //cout << "      " << two << "    WB " <<endl;
  if(NorthBound.size() > 1){
    cout <<"      x     "   << WestBound.size() << endl;
  }else{
    cout << "          "<< WestBound.size()<<endl;
  }
  //3
  //cout << "      " << three <<endl;
  if(NorthBound.size() > 2){
    cout <<"      x"   << endl;
  }else{
    cout << " "<<endl;
  }
  //4
  //cout << "      " << four <<endl;
  if(NorthBound.size() > 3){
    cout <<"      x"   << endl;
  }else{
    cout << " "<<endl;
  }
  //5
  //cout << "      " << five <<endl;
  if(NorthBound.size() > 4){
    cout <<"      x"   << endl;
  }else{
    cout << " "<<endl;
  }
  //6
  //cout << "      " << six <<endl;
  if(NorthBound.size() > 5){
    cout <<"      x"   << endl;
  }else{
    cout << " "<<endl;
  }
  // printing the north bound size 
  cout << "   NB    " << NorthBound.size() <<endl;
  
  // printing the clock 
  cout << "clock: " << sec << endl;
  cout << "----------------------------------------" << endl;

}
