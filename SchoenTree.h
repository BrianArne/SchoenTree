#ifndef SchoenTree_H
#define SchoenTree_H
class SchoenTree{

  public:

    /**
     * Constructor using an array of values,  0-15, no duplicates
     * @param row array of unsigned shorts of len 16
     */
    SchoenTree(const unsigned short[] parent_row);

    /**
     * Construct that randomly consturcts an array of values 0-15
     */
    SchoenTree();

    /**
     * Returns the parent row
     */
    unsigned short[] get_parent();

    /**
     * Returns the paths for a given row
     */
    std::vector<unsigned short*> get_rows();

    
  private:

    /**
     * Returns a vector of possible depth first paths through SchoenTree
     */
    generate_paths();
    
    unsigned short[] parent_row_;
    std::vector<unsigned short*> all_rows_;


};

#endif
