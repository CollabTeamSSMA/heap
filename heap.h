#ifndef HEAP_H
#define HEAP_H

#include <vector>
//#include <typeinfo>
#include <iostream>
using namespace std;

//template is there is time
class heap{
 private:
  void remove_max_helper(int index);
  void insert_helper(int index);
  vector<int> buffer;
 public:
  heap();
  int size();
  void insert(int value);
  void remove_max();
  int max();
  void print();
};
#endif //HEAP_H
