#include "heap.h"

heap::heap(){
  buffer.reserve(2);
  buffer.resize(1);
  buffer[0] = 0;
}
int heap::size(){
  return buffer.size();
}
void heap::insert(int value){
  buffer.push_back(value);
  //cout << buffer.size() << endl;
  insert_helper(buffer.size()-1);

}
void heap::insert_helper(int index){
  if (index == 1)
    return;
  else if (buffer[index] > buffer[index/2]){
    int temp = buffer[index];
    cout << temp;
    buffer[index] = buffer[index/2];
    cout << " swap with " << buffer[index] << endl;
    buffer[index/2] = temp;
    cout << "New buffer at parent index is " << buffer[index/2] << endl;
    insert_helper(index/2);
  }
}
void heap::print(){
  for(int i = 1; i < buffer.size(); i++)
    cout << buffer[i] << " ";
  cout << endl;
}
int heap::max(){
  return buffer[1];
}
void heap::remove_max(){
  int temp = buffer[buffer.size()-1];
  buffer[buffer.size()-1] = buffer[1];
  buffer[1] = temp;
  buffer.resize(buffer.size()-1);
  remove_max_helper(1);
  
}
void heap::remove_max_helper(int index){
  int temp = buffer[index];
  if(buffer[index] < buffer[index*2] && buffer[index] < buffer[(index*2)+1]){
    if(buffer[(index*2)+1] < buffer[index*2] && (index*2) < buffer.size()-1){
      buffer[index] = buffer[index*2];
      buffer[index*2] = temp;
      remove_max_helper(index*2);
    }
    else if(buffer[(index*2)+1] > buffer[index*2] && (index*2)+1 < buffer.size()-1){
      buffer[index] = buffer[(index*2)+1];
      buffer[(index*2)+1] = temp;
      remove_max_helper((index*2)+1);    
    }
  }
  else if (buffer[index] < buffer[index*2] && (index*2) < buffer.size()-1){
    buffer[index] = buffer[index*2];
    buffer[index*2] = temp;
      remove_max_helper(index*2);
  } 
  else if(buffer[index] < buffer[(index*2)+1] && (index*2)+1 < buffer.size()-1){
      buffer[index] = buffer[(index*2)+1];
      buffer[(index*2)+1] = temp;
      remove_max_helper((index*2)+1);    
  }
}
