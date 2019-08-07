#include "SchoenTree.h"
#include <iostream>
#include <stdlib.h>

SchoenTree::SchoenTree(unsigned short[] row) : parent_row_(row){}

//Need to import random seed
SchoenTree::SchoenTree(){
  unsigned short val = std::rand() % 16;
}

SchoenTree::get_parent(){
  return parent_row_;
}

SchoenTree::generate_paths(){

}

SchoenTree::get_rows(){
  return all_rows_;
}

SchoenTree::


