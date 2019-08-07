#ifndef SchoenNode_H
#define SchoenNode_H
class SchoenNode{

  public:

    SchoenNode();

    SchoenNode(const unsigned short val);

    SchoenNode(const unsigned short val, SchoenNode* left, SchoenNode* right);
  
    /*
     * Returns the right neighbor node
     */
    SchoenNode* get_rneighbor();

    /*
     * Returns the left neighbor node
     */
    SchoenNode* get_lneighbor();

  private:
    SchoenNode* left_;
    SchoenNode* right_;


};
#endif
