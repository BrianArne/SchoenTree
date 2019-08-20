#include "SchoenTree.h"

int main(int argc, char * argv[]){
  unsigned short myArr[] = {1,2,3,4,5,1,2,3,4,5,1,2,3,4,5};

  SchoenTree myTree(myArr);
  SchoenTree myTreeTwo;

  myTreeTwo.print_tree();



  return 0;
}
