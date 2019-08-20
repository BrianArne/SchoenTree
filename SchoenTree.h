#ifndef SchoenTree_H
#define SchoenTree_H
#include <map>
#include <utility>

typedef unsigned short usNum;
typedef std::pair<usNum, usNum> schoenPair;

class SchoenTree{

  public:

    /**
     * Construct that randomly consturcts an array of values 0-15
     */
    SchoenTree();

    /**
     * Constructor using an array of values,  0-14, no duplicates
     * @param row array of usNums of len 15
     */
    SchoenTree(usNum* row);

    /**
     * Returns the note value at a given index
     */
    usNum get_note(usNum& val);

    /**
     * Returns the parent row
     */
    usNum* get_parent_row();

    /**
     * Returns the index of the right neighbor for an index of the tree
     */
    usNum get_rneighbor(const usNum& index);

    /**
     * Returns the index of the left neighbor for an index of the tree
     */
    usNum get_lneighbor(const usNum& index);

    /**
     * Prints the tree
     */
    void print_tree();

    
  private:

    /**
     * Returns a vector of possible depth first paths through SchoenTree
     */
    void generate_paths();

    /**
     * Creates map of all indexes and it's neighbors
     */
    void generate_map();

    //void generate_neighbors();
    
    usNum parent_row_[15];
    std::map<usNum, schoenPair> neighbor_map_;

};

#endif
