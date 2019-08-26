#ifndef SchoenPair_H
#define SchoenPair_H

typedef sVal unsigned short;

class SchoenPair{

  public:
  
    /**
     * Empty Constructor
     */
    SchoenPair();

    /**
     * Constructor
     */
    SchoenPair(sVal& val, sVal& left, sVal& right);

    /**
     * Returns the right neighbor index
    sVal get_rneighbor();

    sVal get_lneighbor();





  private:
    unsigned short left_;
    unsigned short right_;



};
#endif
