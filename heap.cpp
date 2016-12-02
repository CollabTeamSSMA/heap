 #include "heap.h"

heap::heap(){
  buffer.reserve(2);
  buffer.resize(1);
  buffer[0] = 0;
}
int heap::size(){
  return buffer.size()-1;
}
void heap::insert(int value){
  buffer.push_back(value);
  insert_helper(buffer.size()-1);

}
void heap::insert_helper(unsigned index){
  if (index == 1)
    return;
  else if (buffer[index] >= buffer[index/2]){
    swap(buffer[index], buffer[index/2]);
    insert_helper(index/2);
  }
}
void heap::print(){
  // int numbers_printed = 0; //Keeps track of how many numbers have been printed on a line.
  // int expected_numbers_printed = 1; //Keeps track of how many numbers to print on a line.
  // for (unsigned int i = 1; i < buffer.size(); i++) //Killing off a warning.
  //   {
  //     cout << buffer[i] << " ";
  //     numbers_printed++;
  //     if (numbers_printed == expected_numbers_printed){
  // 	cout << endl;
  // 	numbers_printed = 0;
  // 	expected_numbers_printed *= 2;
  //     }
  //   }

  
  for(unsigned i = 1; i < buffer.size(); i++)
    cout << buffer[i] << " ";
  cout << endl;
}
int heap::max(){
  return buffer[1];
}
void heap::remove_max(){
  swap(buffer[1], buffer[buffer.size()-1]);
  buffer.pop_back();
  if(buffer.size() > 2)
    remove_max_helper(1);
}
void heap::remove_max_helper(unsigned index){
  if (unsigned(2 * index + 1) < buffer.size()){
    if (buffer[2 * index] > buffer[2 * index + 1]){ //Compare the two children first.
      if (buffer[index] < buffer[2 * index]){ //Compare the greatest child with its parent.
	int temp = buffer[index];
	buffer[index] = buffer[2 * index];
	buffer[2 * index] = temp;
      }
    }
    else{
      if (buffer[index] < buffer[2 * index + 1]){
	int temp = buffer[index];
	buffer[index] = buffer[2 * index + 1];
	buffer[2 * index + 1] = temp;
      }
    }
    remove_max_helper(index + 1);
  }
  
  // if(index*2+1 >= buffer.size()-1  && buffer[index*2] > buffer[index]){
    //   cout << buffer[index] << " swap with " << buffer[index*2] << endl;
    //   swap(buffer[index], buffer[index*2]);
    // }
    // else if(buffer[index] < buffer[index*2] && buffer[index] < buffer[(index*2)+1]){
    //   if(buffer[(index*2)+1] < buffer[index*2] && (index*2) < buffer.size()){
    // 	cout << buffer[index] << " swap with " << buffer[index*2];
    // 	swap(buffer[index], buffer[index*2]);
    // 	remove_max_helper(index+1);
    //   }
    //   else if(buffer[(index*2)+1] >= buffer[index*2] && (index*2)+1 < buffer.size()){
    // 	cout << buffer[index] << " swap with " << buffer[index*2+1] << endl;
    // 	swap(buffer[index], buffer[(index*2)+1]);
    // 	remove_max_helper(index+1);
    //   }
    // }
    // else if (buffer[index] < buffer[index*2] && (index*2) < buffer.size() && buffer[index*2+1] <= buffer[index]){
    //   cout << buffer[index] << " swap with " << buffer[index*2] << endl;
    //   swap(buffer[index], buffer[index*2]);
    //   remove_max_helper(index+1);
    // } 
    // else if(buffer[index] < buffer[(index*2)+1] && (index*2)+1 < buffer.size()  && buffer[index*2] <= buffer[index]){
    //   cout << buffer[index] << " swap with " << buffer[index*2+1] << endl;
    //   swap(buffer[index], buffer[(index*2)+1]);
    //   remove_max_helper(index+1);
    // }
    
} 
void heap::swap(int &First_num, int &Second_num){
  int temp = First_num;
  First_num = Second_num;
  Second_num = temp;
}
