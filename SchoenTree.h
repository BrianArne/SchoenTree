#ifndef SchoenTree_H
#define SchoenTree_H
#include <map>
#include <utility>
#include <string>

typedef unsigned char usNum;
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
     * Returns the array index in parent_row_ of the note value
     */
    usNum note_index(const usNum& note);

    /**
     * Prints the tree
     */
    void print_tree();

    /**
     * Generates depth-first traversal from @param note to leaf notes
     */
    void depth_path(usNum& note, 
                    std::vector<usNum>* vec = nullptr);
    
  private:

    /**
     * Generates map of note values to note value index in parent_row_
     */
    void generate_map(const usNum* row, usNum size);

    /**
     * Creates map of all indexes and it's neighbors
     */
    void generate_nmap();

    //void generate_neighbors();
    
    usNum parent_row_[15];
    std::map<usNum, schoenPair> neighbor_map_;
    std::map<usNum, usNum> map_;

};

#endif
