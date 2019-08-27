#include "SchoenTree.h"
#include <iostream>

typedef unsigned char usNum;

int main(int argc, char * argv[]){
  unsigned char myArr[] = {1,2,3,4,5,1,2,3,4,5,1,2,3,4,5};
  SchoenTree myTree(myArr);
  SchoenTree myTreeTwo;

  usNum val = 1;

  
  myTreeTwo.print_tree();
  myTreeTwo.depth_path(val);

  return 0;
}
