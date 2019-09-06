#include <array>
#include <cmath>
#include <cstring>
#include <limits>
#include <map>
#include <memory>
#include <iostream>
#include "SchoenTree.h"
#include <stdlib.h>
#include <string>
#include <vector>

typedef unsigned char usNum;
typedef std::pair<usNum, usNum> schoenPair;


/**
 * Generates a random parent tree
 */
SchoenTree::SchoenTree(){
  srand(time(NULL));
  std::array<usNum, 15> p_row;
  p_row.fill(0);
  bool zero = false;
  usNum zVal = 0;
  for(int i = 0; i < p_row.size(); i++){
    usNum val = rand() % 15;
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
  parent_row_ = p_row;
  generate_map(p_row);
  generate_nmap();
}

/**
 * Constructs SchoenTree from supplied parent row
 */
SchoenTree::SchoenTree(std::array<usNum, 15>& arr){
  parent_row_ = arr;
}

/**
 * Generates map of note values t note value index in parent_row_
 */
void SchoenTree::generate_map(std::array<usNum, 15>& row){
  for (auto i : row){
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
  schoenPair three(6, 7);
  schoenPair four(7, 8);
  schoenPair five(8, 9);
  schoenPair six(10, 11);
  schoenPair seven(11, 12);
  schoenPair eight(12, 13);
  schoenPair nine(13, 14);

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
 * Returns the note value at a given index 
 */
usNum SchoenTree::get_note(const usNum& index){
  return parent_row_[index];
}

/**
 * Returns the parent row
 */
std::array<usNum, 15> SchoenTree::get_parent_row(){
  return parent_row_;
}

/**
 * Generates depth-first traversal from note to leaf notes paths. 
 */
void SchoenTree::depth_path(usNum& note, 
    std::vector<usNum>* vec){
  if (vec == nullptr){
    std::shared_ptr<std::vector<usNum>> holder = 
      std::make_shared<std::vector<usNum>>(); 
    vec = holder.get();
  }

  usNum index = note_index(note);
  if(index > 9 && index < 16){
    vec->push_back(note);
    for (auto i : *vec){
      std::cout << +i << " ";
    }
    std::cout << std::endl;
    return;
  }else{
    vec->push_back(note);
    usNum left = get_lneighbor(index);
    usNum left_note = get_note(left);
    usNum right = get_rneighbor(index);
    usNum right_note = get_note(right);
    depth_path(left_note, vec);
    vec->pop_back();
    depth_path(right_note, vec);
    vec->pop_back();
  }
}

double SchoenTree::note_frq(const double& base, const double& distance){
  return base * pow(pow(2., (1./16.)), distance);
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

  std::cout << std::endl;
}
