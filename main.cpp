
#include <array>
#include "SchoenTree.h"
#include <iostream>

typedef unsigned char usNum;

int main(int argc, char * argv[]){
  std::array<usNum, 15> myArr;
  myArr.fill(7);

  SchoenTree myTree(myArr);
  SchoenTree myTreeTwo;

  //Test Value
  usNum val = 1;
  myTreeTwo.print_tree();
  myTreeTwo.depth_path(val);

  return 0;
}
