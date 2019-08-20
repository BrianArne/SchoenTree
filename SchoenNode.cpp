#include "SchoenNode.h"
/**
 * Empty default constructor
 */
SchoenNode::SchoenNode(){}

/**
 * SchoenNode with NULL neighbornodes
 */
SchoenNode::SchoenNode(const unsigned short& val) : val_(val) {}

/**
 * SchoenNode constructor with val and both neighbors set
 */
SchoenNode::SchoenNode(const unsigned short& val, SchoenNode* left, SchoenNode* right) : 
  left_(left), right_(right) {}

/**
 * Returns the right neighbor a row down
 */
SchoenNode* SchoenNode::get_rneighbor(){
  return left_;
}

/**
 * Returns the left neighbor a row down
 */
SchoenNode* SchoenNode::get_lneighbor(){
  return right_;
}


