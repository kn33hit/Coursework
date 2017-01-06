#include <vector>
#include <iostream>

using namespace std;

class IntStack
{
public:
  // MaxSize should be an unsigned int, but for the sake of example...
  IntStack(int MaxSize)
  {
    if(MaxSize < 0)
      {
	cerr << "Cannot create a negative size stack" << endl;
	exit(1);
      }
    
    data.resize(MaxSize);
    cur_index = 0;
  }

  void push(int new_data)
  {
    if(cur_index == data.size())
      {
	cerr << "Push to full stack" << endl;
	exit(1);
      }
    else
      {
	data.at(cur_index) = new_data;
	cur_index++;
      }
  }

  int pop()
  {
    if(cur_index == 0)
      {
	cerr << "Pop from empty stack" << endl;
	exit(1);
      }
    else
      {
	// pop off the int and return it
	cur_index--;
	return data.at(cur_index);
      }
  }

private:
  vector<int> data;
  unsigned int cur_index;
};

int main()
{
  // Testing Constructor
  IntStack c_test(-10);
  
  c_test.push(3);
  c_test.push(4);
  c_test.pop();
  c_test.pop();
  
  
  // Testing push
  IntStack push_test(5);
  
  for(unsigned int i = 0; i < 7; i++) {
    push_test.push(i);
  }
  
  
  // Testing pop
  IntStack pop_test(2);
  
  pop_test.push(1);
  pop_test.push(2);
  pop_test.pop();
  pop_test.pop();
  pop_test.pop();
  
  //  Extra Credit
  /*
    IntStack<char> x(3);
    x.push('c');
    x.pop();
    
    
  */
  
  cout << "Completed!" << endl;
}
