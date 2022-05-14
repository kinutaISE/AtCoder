#ifndef READEF1_R_20220514_HOJBA72933_INCLUDE_
#define READEF1_R_20220514_HOJBA72933_INCLUDE_

enum STATUS {
  UNDISCOVERED,
  DISCOVERED,
  PROCESSED,
} ;

struct Node {
  int index ;
  vector<Node> adjacents ;
  Node(int i) {
    index = i ;
  }
  void add_to_adjacents(Node& u) {
    adjacents.push_back(u) ;
    u.add_to_adjacents(this) ;
  }
} ;

#endif
