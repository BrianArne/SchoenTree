#ifndef SchoenTree_H
#define SchoenTree_H
#include <array>
#include <cmath>
#include <map>
#include <string>
#include <utility>

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
    SchoenTree(std::array<usNum, 15>& arr);

    /**
     * Returns the note value at a given index
     */
    usNum get_note(const usNum& index);

    /**
     * Returns the parent row
     */
    std::array<usNum, 15> get_parent_row();

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
    
    /**
     * Returns the frequency in hz of a pitch
     * @param base The base pitch used to generate all notes
     *    typically 440hz
     * @param distance The distance, in equal division of the
     *    octave 16 times, away from the base pitch
     * @return double Frequency of the pitch desired
     */
    double note_frq(const double& base, const double& distance);
    
  private:

    /**
     * Generates map of note values to note value index in parent_row_
     */
    void generate_map(std::array<usNum, 15>& row);

    /**
     * Creates map of all indexes and it's neighbors
     */
    void generate_nmap();

    //void generate_neighbors();


    std::array<usNum, 15> parent_row_;    
    std::map<usNum, schoenPair> neighbor_map_;
    std::map<usNum, usNum> map_;

};

#endif
