#include <iostream>
#include <cstdlib>   // This defines the library for atoi()

// ADD #include's HERE FOR ANY OTHER LIBRARIES YOU USE

using namespace std;

// ADD ANY GLOBAL CONSTANTS HERE

// STEP 1: ADD YOUR "Record" STRUCTURE DEFINITION HERE
struct Record{
  char *m_firstName;
  char *m_lastName;
  int m_age;
};

  void MungeRecord(Record myRec);
  void MungeRecordForReal(Record &myRec);
  void MungeRecordFail(Record &myRec);

int main(int argc, char *argv[]) {

    // STEP 2: DECLARE A LOCAL VARIABLE "myRec" HERE, OF TYPE "Record"
    //   INITIALIZE THE MEMBERS FROM argv[] ELEMENTS
  Record myRec;

  myRec.m_firstName = argv[1];
  myRec.m_lastName = argv[2];
  myRec.m_age = atoi(argv[3]);
    // STEP 3: WRITE THE FUNCTION MungeRecord() DOWN BELOW, AFTER main().
    // ADD CALL TO MungeRecord() HERE, PASSING IN myRec AS ARGUMENT
  MungeRecord(myRec);

    // AFTER IT RETURNS, PRINT OUT THE CONTENTS OF myRec
  cout << myRec.m_firstName << " " << myRec.m_lastName << " " <<myRec.m_age<<endl;

    // STEP 4: WRITE THE FUNCTION MungeRecordForReal() DOWN BELOW, AFTER main().
    // ADD CALL TO MungeRecordForReal() HERE, PASSING IN myRec AS ARGUMENT
  MungeRecordForReal(myRec);

    // AFTER IT RETURNS, PRINT OUT THE CONTENTS OF myRec
    // (Step 4 can be done by just cutting-and-pasting Step 3 above, then
    //  editing it slightly)
 cout << myRec.m_firstName << " " << myRec.m_lastName << " " <<myRec.m_age<<endl;

    // STEP 5: WRITE THE FUNCTION MungeRecordFail() DOWN BELOW, AFTER main().
    // ADD CALL TO MungeRecordFail() HERE, PASSING IN myRec AS ARGUMENT
 MungeRecordFail(myRec);

    // AFTER IT RETURNS, PRINT OUT THE CONTENTS OF myRec
    // (Again, can just cut-and-paste from Step 3 above, then
    //  edit it slightly)
 cout << myRec.m_firstName << " " << myRec.m_lastName << " " <<myRec.m_age<<endl;

    return 0;
}


void MungeRecord(Record myRec)
{
  char *temp;
  temp = myRec.m_lastName;
  myRec.m_firstName = myRec.m_lastName; 
  myRec.m_lastName = temp;
  myRec.m_age = -1;
}


void MungeRecordForReal(Record &myRec)
{
  char *temp;
  temp = myRec.m_lastName;
  myRec.m_lastName = myRec.m_firstName; 
  myRec.m_firstName = temp;
  myRec.m_age = -1;
}

void MungeRecordFail(Record const &myRec)
{
char *temp;
  temp = myRec.m_lastName;
  myRec.m_lastName = myRec.m_firstName; 
  myRec.m_firstName = temp;
  myRec.m_age = -1;
}
