#include "heap.h"

heap::heap(){
  buffer.reserve(2);
}
int heap::size(){
  return buffer.size();
}
void heap::insert(int value){
  buffer.push_back(value);
  cout << buffer.size() << endl;
  if(buffer.size() == 1)
    return;
  else 
    insert_helper(buffer.size());

}
void heap::insert_helper(int index){
  if (index == 1)
    return;
  else if (buffer[index] > buffer[index/2]){
    int temp = buffer[index];
    buffer[index] = buffer[index/2];
    buffer[index/2] = temp;
    insert_helper(index/2);
  }
}
void heap::print(){
  for(int i = 0; i < buffer.size(); i++)
    cout << buffer[i] << endl;
}
