#ifndef HEAP_H
#define HEAP_H

#include <vector>
//#include <typeinfo>
#include <iostream>
using namespace std;

//template is there is time
class heap{
 private:
  void remove_max_helper(unsigned index);
  void insert_helper(unsigned index);
  vector<int> buffer;
 public:
  heap();
  int size();
  void insert(int value);
  void remove_max();
  int max();
  void print();
  void swap(int & First_num, int & Second_num);
};
#endif //HEAP_H
