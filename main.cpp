
#include "heap.h"

int main(){
  heap h;
  h.insert(2);
  h.insert(4);
  h.insert(8);
  h.insert(123);
  h.insert(54);
  h.print();
  h.remove_max();
  h.print();
  h.remove_max();
  h.print();
  h.remove_max();
  h.print();
  h.remove_max();
  h.print();
  //  h.remove_max();
  //h.print();
  return 0;
}

  
