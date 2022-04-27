#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Menu {
  int food_index ; // 料理番号
  int stock ; // 初期在庫数
  int price ; // 価格
  Menu(int d, int s, int p) {
    food_index = d ;
    stock = s ;
    price = p ;
  }
} ;

struct Menu_set {
  vector<Menu> container ;
  Menu find(int d) {
    // 料理番号 d のメニューを探す
    for (int i = 0 ; i < container.size() ; i++) {
      if (container.at(i).food_index == d)
        return container.at(i) ;
    }
    return NULL ;
  }
  Menu find(Order order) {
    return find(order.food_index) ;
  }
} ;

struct Order {
  int table_index ; // 席番号
  int food_index ; // 料理番号
  int food_num ; // 注文数
  Order(int t, int d, int n) {
    table_index = t ;
    food_index = d ;
    food_num = n ;
  }
} ;

int step ;
int food_num ;
vector<Menu> menu_set ;
vector<Order> order_set ;

void initialize() {
  /*
  food_num, menu_info の初期化
  */
  cin >> step ;
  cin >> food_num ;
  for (int i = 0 ; i < food_num ; i++) {
    int d, s, p ;
    cin >> d >> s >> p ;
    Menu menu(d, s, p) ;
    menu_set.container.push_back(menu) ;
  }
  while (!cin.eof()) {
    int s, t, d, n ;
    cin >> s >> t >> d >> n ;
    Order order(t, d, n) ;
    order_set.push_back(order) ;
  }
}

void function_step1() {
  for (int i = 0 ; i < order_set.size() ; i++) {
    Order order = order_set.at(i) ;
    Menu menu = menu_set.find(order) ;
    if ( menu.stock >= order.food_num ) {
      cout << "received order " ;
      cout << order.table_index << " " << order.food_index << endl ;
      menu.stock -= order.food_num ;
      continue ;
    }
    cout << "sold out " << order.table_index << endl ;
  }
}

int main(int argc, char *argv[]) {
  // このコードは標準入力と標準出力を用いたサンプルコードです。
  // このコードは好きなように編集・削除してもらって構いません。
  // ---
  // This is a sample code to use stdin and stdout.
  // Edit and remove this code as you like.
  /*
  string line;
  int index = 1;
  while (!cin.eof()) {
    getline(cin, line);
    cout << "line[" << index++ << "]:" << line << "\n";
  }
  */
  initialize() ;

  if (step == 1) {
    function_step1() ;
  }

  return 0;
}
