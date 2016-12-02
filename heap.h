#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

template <class T>
class heap{
 private:
  void remove_max_helper(unsigned index);
  int print_helper(unsigned index, int number_of_leaves);
  void insert_helper(unsigned index);
  vector<T> buffer;
 public:
  heap();
  int size();
  void insert(T value);
  void remove_max();
  T max();
  void print();
  void swap(T & First_num, T & Second_num);
};
#endif //HEAP_H

template <class T>
heap<T>::heap(){
  buffer.resize(1);
}

template <class T>
int heap<T>::size(){
  return buffer.size()-1;
}

template <class T>
void heap<T>::insert(T value){
  buffer.push_back(value);
  insert_helper(buffer.size()-1);

}

template <class T>
void heap<T>::insert_helper(unsigned index){
  if (index == 1)
    return;
  else if (buffer[index] >= buffer[index/2]){
    swap(buffer[index], buffer[index/2]);
    insert_helper(index/2);
  }
}

template <class T>
void heap<T>::print(){
  if (buffer.size() != 1){
    int space_subtract = 2;
    int spaces = 41;
    unsigned power = 2;
    cout << setfill(' ') << setw(spaces) << "|" << buffer[1]<< "|" << endl;
    unsigned i = 2;
    spaces-=space_subtract;
    while ( i < buffer.size()){
      cout << setfill(' ')  << setw(spaces);
      for(unsigned j = 0; j < power; j++){
	if(i < buffer.size()){
	  cout <<  "|" << buffer[i] << "| ";
	  space_subtract++;
	}
	i++;
      }
      spaces-=space_subtract;
      power*=2;
      cout << endl;
    }
  }
}

template <class T>
T heap<T>::max(){
  return buffer[1];
}

template <class T>
void heap<T>::remove_max(){
  if (size() >0){
    swap(buffer[1], buffer[buffer.size()-1]);
    buffer.pop_back();
  }
  if(buffer.size() > 2)
    remove_max_helper(1);
}

template <class T>
void heap<T>::remove_max_helper(unsigned index){
  if (index < buffer.size()){
    unsigned right = index*2+1;
    unsigned left = index*2;
    if(buffer[index] < buffer[left] && right >= buffer.size()-1){
      swap(buffer[index], buffer[left]);
    }
    if(buffer[index] < buffer[left] && buffer[index] < buffer[right]){
      if(buffer[right] < buffer[left] && left < buffer.size()){
    	swap(buffer[index], buffer[left]);
    	remove_max_helper(index+1);
	insert_helper(index);
      }
      else if(buffer[right] >= buffer[left] && right < buffer.size()){
    	swap(buffer[index], buffer[right]);
    	remove_max_helper(index+1);
	insert_helper(index);
      }
    }
    else if (buffer[index] < buffer[left] && left < buffer.size() && buffer[right] <= buffer[index]){
      swap(buffer[index], buffer[left]);
      remove_max_helper(index+1);
      insert_helper(index);
    } 
    else if(buffer[index] < buffer[right] && right < buffer.size()  && buffer[left] <= buffer[index]){
      swap(buffer[index], buffer[right]);
      remove_max_helper(index+1);
      insert_helper(index);
    }
  }
}

template <class T>
void heap<T>::swap(T &First_num, T &Second_num){
  T temp = First_num;
  First_num = Second_num;
  Second_num = temp;
}
