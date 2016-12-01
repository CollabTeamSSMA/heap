#ifndef HEAP_H
#define HEAP_H

#include <vector>
//#include <typeinfo>
#include <iostream>
using namespace std;

template <class T>
class heap{
 private:
  void remove_max_helper(unsigned index);
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
  //T position_zero = NULL;
  //buffer.push_back(position_zero);
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
  for(unsigned i = 1; i < buffer.size(); i++)
    cout << buffer[i] << " ";
  cout << endl;
}
template <typename T>
T heap<T>::max(){
  return buffer[1];
}

template <class T>
void heap<T>::remove_max(){
  swap(buffer[1], buffer[buffer.size()-1]);
  buffer.pop_back();
  if(buffer.size() > 2)
    remove_max_helper(1);
}

template <class T>
void heap<T>::remove_max_helper(unsigned index){
  if(buffer[index] < buffer[index*2] && index*2+1 >= buffer.size()-1){
    swap(buffer[index], buffer[index*2]);
  }
	 
    if(buffer[index] < buffer[index*2] && buffer[index] < buffer[(index*2)+1]){
      if(buffer[(index*2)+1] < buffer[index*2] && (index*2) < buffer.size()){
    	cout << buffer[index] << " swap with " << buffer[index*2];
    	swap(buffer[index], buffer[index*2]);
    	remove_max_helper(index+1);
	insert_helper(index);
      }
      else if(buffer[(index*2)+1] >= buffer[index*2] && (index*2)+1 < buffer.size()){
    	cout << buffer[index] << " swap with " << buffer[index*2+1] << endl;
    	swap(buffer[index], buffer[(index*2)+1]);
    	remove_max_helper(index+1);
	insert_helper(index);
      }
    }
    else if (buffer[index] < buffer[index*2] && (index*2) < buffer.size() && buffer[index*2+1] <= buffer[index]){
      cout << buffer[index] << " swap with " << buffer[index*2] << endl;
      swap(buffer[index], buffer[index*2]);
      remove_max_helper(index+1);
      insert_helper(index);
    } 
    else if(buffer[index] < buffer[(index*2)+1] && (index*2)+1 < buffer.size()  && buffer[index*2] <= buffer[index]){
      cout << buffer[index] << " swap with " << buffer[index*2+1] << endl;
      swap(buffer[index], buffer[(index*2)+1]);
      remove_max_helper(index+1);
      insert_helper(index);
    }
    
}

template <class T>
void heap<T>::swap(T &First_num, T &Second_num){
  T temp = First_num;
  First_num = Second_num;
  Second_num = temp;
}
