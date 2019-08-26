#include "SchoenTree.h"
#include <iostream>
#include <map>
#include <stdlib.h>
#include <limits>
#include <string>

typedef unsigned char usNum;
typedef std::pair<usNum, usNum> schoenPair;


/**
 * Generates a random parent tree
 */
SchoenTree::SchoenTree(){
  srand(time(NULL));
  usNum p_row[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  bool zero = false;
  usNum zVal = 0;
  for( int i = 0; i < (sizeof(p_row) / sizeof(usNum)); i++){
    usNum val = std::rand() % 15;
    if (!zero){
      zero = true;
      p_row[val] = i;
      zVal = val;
    }else if (p_row[val] == 0 && val != zVal){
      p_row[val] = i;
    }else{
      i--;
    }
  }
  memcpy(parent_row_, p_row, 15*sizeof(usNum));
  generate_map(p_row, (usNum)sizeof(p_row)/sizeof(usNum));
  generate_nmap();
}

/**
 * Constructs SchoenTree from supplied parent row
 */
SchoenTree::SchoenTree(usNum* row){
  memcpy(parent_row_, row, 15 * sizeof(usNum));
}

/**
 * Generates map of note values t note value index in parent_row_
 */
void SchoenTree::generate_map(const usNum* row, usNum size){
  for (usNum i = 0; i < size; i++){
    map_.insert(std::pair<usNum, usNum>(row[i], i));
  }
}

/**
 * Generates all neighbors for each index of the SchoenTree
 */
void SchoenTree::generate_nmap(){
  schoenPair zero(1, 2);
  schoenPair one(3, 4);
  schoenPair two(4, 5);
  schoenPair three(6,7);
  schoenPair four(7,8);
  schoenPair five(8,9);
  schoenPair six(10,11);
  schoenPair seven(11,12);
  schoenPair eight(12,13);
  schoenPair nine(13,14);

  neighbor_map_.insert(std::pair<usNum, schoenPair>(0, zero));
  neighbor_map_.insert(std::pair<usNum, schoenPair>(1, one));
  neighbor_map_.insert(std::pair<usNum, schoenPair>(2, two));
  neighbor_map_.insert(std::pair<usNum, schoenPair>(3, three));
  neighbor_map_.insert(std::pair<usNum, schoenPair>(4, four));
  neighbor_map_.insert(std::pair<usNum, schoenPair>(5, five));
  neighbor_map_.insert(std::pair<usNum, schoenPair>(6, six));
  neighbor_map_.insert(std::pair<usNum, schoenPair>(7, seven));
  neighbor_map_.insert(std::pair<usNum, schoenPair>(8, eight));
  neighbor_map_.insert(std::pair<usNum, schoenPair>(9, nine));
}

/**
 * Returns the note value of the index
 */
usNum SchoenTree::get_note(usNum& val){
  return parent_row_[val];
}

/**
 * Returns the parent row
 */
usNum* SchoenTree::get_parent_row(){
  return parent_row_;
}

/**
 * Generates depth-first traversal from note to leaf notes paths. 
 */
void SchoenTree::depth_path(const usNum& note){
  usNum index = note_index(note);
  if(index > 9 && index < 16){
    std::cout << +note << " " << std::endl;
    return;
  }else{
    std::cout << +note << " " << std::endl;
    if(index < 16){
      usNum left = get_lneighbor(index);
      usNum right = get_rneighbor(index);
      depth_path(get_note(left));
      depth_path(get_note(right));
    }
  }
  return;
}

/**
 * Returns the index of the right neighbor for an index of the tree
 */
usNum SchoenTree::get_rneighbor(const usNum& index){
  schoenPair node = neighbor_map_[index];
  return node.second;
}

/**
 * Returns the index of the left neighbor for an index of the tree
 */
usNum SchoenTree::get_lneighbor(const usNum& index){
  schoenPair node = neighbor_map_[index];
  return node.first;
}

/**
 * Returns the array index in parent_row_ of the note value
 */
usNum SchoenTree::note_index(const usNum& note){
  return map_[note];
}

/**
 * Prints the tree to std::cout
 */
void SchoenTree::print_tree(){

  std::cout << "        " 
     << +parent_row_[0] <<  std::endl;

  std::cout << "      " 
     << +parent_row_[1] << "   " 
     << +parent_row_[2] << std::endl;

  std::cout << "    " 
    << +parent_row_[3] << "   " 
    << +parent_row_[4] << "   "
    << +parent_row_[5]<<  std::endl;

  std::cout << "  "
    << +parent_row_[6] <<  "   " 
    << +parent_row_[7] << "   " 
    << +parent_row_[8] << "   " 
    << +parent_row_[9] << std::endl;

  std::cout << "" 
    << +parent_row_[10] << "   " 
    << +parent_row_[11] << "   " 
    << +parent_row_[12] << "   " 
    << +parent_row_[13] << "   " 
    << +parent_row_[14] <<  std::endl;
}

