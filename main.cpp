#include "SchoenTree.h"
#include <iostream>

int main(int argc, char * argv[]){
  unsigned char myArr[] = {1,2,3,4,5,1,2,3,4,5,1,2,3,4,5};
  SchoenTree myTree(myArr);
  SchoenTree myTreeTwo;

  myTreeTwo.print_tree();
  myTreeTwo.depth_path(1);

  return 0;
}
