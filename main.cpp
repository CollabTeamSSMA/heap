/*Author: Matthew Austin
 *File: main.cpp
 *Date:11/15/2016
 *Purpose: 
 *
 */
#include "heap.h"
#include <cstdlib>
using namespace std;

void print_welcome();

int main(){
  //const int SOME_NUMBER = 10;
  heap h;
  int value;
  char answer;
  print_welcome();//welcome screen
  cin >> answer;//priming read
  while(answer != 'q'){
    if (answer == '1'){//inserts a given valueand data
      cout << "Please enter the value you would like to insert: ";
      cin >> value;
      h.insert(value);
      // for(int i=0; i<SOME_NUMBER; i++){
      // 	int r = rand()%100;
      // 	h.insert(r);
      // 	h.print();
      // }
     }
    else if(answer == '2')//prints the heap
      h.print();
    else if(answer == '3')
      cout << "The max value in the heap is: " << h.max() << endl;
    else if(answer == '4'){
      h.remove_max();
       // while(h.size() > 0) {
       // 	cout << h.max() << endl;
       // 	h.print();
       // 	h.remove_max();
       // }
    }
    else if(answer == '5')//reads from a file and inserts into the tree
      cout << "The size of the heap is " << h.size() << endl;
    
    print_welcome();//welcome screen
    cin >> answer;//last read
  }
  return 0;
}
void print_welcome(){
  for (int i = 0; i<54; i++)
    cout << "-";//top of the box
  //Welcome screen
  cout << "\n|<<<<<WELCOME TO THE FANTASTIC HEAP MANIPULATOR>>>>>>|"
       << "\n|<<<<<Please enter one of the following options>>>>>>|\n|";
  
  for(int i = 0; i<52; i++)//empty line
    cout << " ";
  //options
  cout << "|\n|<<(1)->Enter a value to be inserted into the heap>>>|"
       << "\n|<<(2)->Print the heap>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|"
       << "\n|<<(3)->Print the max>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|"
       << "\n|<<(4)->Remove the max>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|"
       << "\n|<<(5)->Get the size of the heap>>>>>>>>>>>>>>>>>>>>>|"
       << "\n|<<(q)->Quit>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|"
       << endl;
  for (int i = 0; i<54; i++)
    cout << "-";//bottom of the box
  cout << "\n?";
}
