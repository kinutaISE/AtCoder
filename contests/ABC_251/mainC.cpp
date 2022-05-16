#include <iostream>
#include <vector>
#include <string>

using namespace std ;

int node_num = 0 ;

class Node {
  public:
    char letter ;
    vector<Node> children ;
  public: Node(char c) {
    letter = c ;
    node_num++ ;
  }
  public: bool is_original(string p, int pos = 0) {

    if (pos == p.length() - 1) {
      for (auto& child : children) {
        if (child.letter == p[pos])
          return false ;
      }
      return true ;
    }

    cout << "check p[" << pos << "]: " << p[pos] << endl ;

    for (auto& child : children) {

      cout << "letter of child: " << child.letter << endl ;

      if (p[pos] != child.letter) continue ;
      return child.is_original(p, pos + 1) ;
    }
    return true ;
  }
  public: void insert(string p, int pos = 0) {
    if (pos == p.length()) {
      cout << "reach last letter" << endl ;
      return ;
    }

    cout << "insert as a child of " << (size_t)&*this << endl ;

    for (auto& child : children) {
      if (p[pos] != child.letter) continue ;

      cout << "move to child with " << (size_t)&child << endl ;

      child.insert(p, pos + 1) ;

      return ;
    }
    Node node(p[pos]) ;

    cout << "add a new node with " << (size_t)&node << endl ;

    children.push_back(node) ;

    node.insert(p, pos + 1) ;
  }
} ;

////////////////////////////////////////////////////////////////

Node root('*') ;
int main() {

  cout << "root node is " << (size_t)&root <<endl ;


  int poem_num ;
  cin >> poem_num ;

  int best_poem_index = -1 ;
  int best_score = -1 ;
  string poem ;
  int score ;
  for (int i = 1 ; i <= poem_num ; i++) {
    cin >> poem >> score ;

    cout << "poem: " << poem << "/score: " << score << endl ;
    cout << poem.length() << endl ;

    if (! root.is_original(poem))
      continue ;

    cout << "insert to tree" << endl ;

    root.insert(poem) ;
    if (score <= best_score) continue ;
    best_poem_index = i ;
    best_score = score ;
  }
  cout << best_poem_index << endl ;

  cout << node_num << endl ;
}
