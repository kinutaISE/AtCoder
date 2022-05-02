#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std ;

vector<string> split(string str, char del) {
  vector<string> result ;
  result.push_back("") ;
  int pos = 0 ;
  for (char c : str) {
    if (c == del) {
      result.push_back("") ;
      pos++ ;
      continue ;
    }
    result[pos] += c ;
  }
  return result ;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
struct Room {
  bool is_low ;
  int room_number ;
  int capacity ;
  int fee ;

  int customer_id ;
  int time_checkin ;
  bool is_cleaning ;
  int time_cleaning_finish ;
  Room(bool il, int i, int c, int f) {
    is_low = il ;
    room_number = i ;
    capacity = c ;
    fee = f ;

    customer_id = -1 ;
    time_checkin = -1 ;
    is_cleaning = false ;
    time_cleaning_finish = -1 ;
  }
  string to_string() {
    string type = is_low ? "LOW" : "HIGH" ;
    return ::to_string(room_number) + " " + type + " " + ::to_string(capacity) + " " + ::to_string(fee) ;
  }
  void reset() {
    customer_id = -1 ;
    time_checkin = -1 ;
  }
  bool is_occupied() {
    return customer_id != -1 ;
  }
  void checkin(int id, int d, int h, int m) {
    customer_id = id ;
    time_checkin = (360 * 24) * d + 60 * h + m ;
  }
  int calc_total_fee(int d, int h, int m) {
    int day = time_checkin / (360 * 24) ;
    int hour = (time_checkin % (360 * 24)) / 60 ;
    int minute = (time_checkin % (360 * 24)) % 60 ;
    int total_fee = 0 ;
    for (int dd = day + 1 ; dd <= d ; dd++) {
      if (dd == 6 || dd == 7) {
        total_fee += int( fee * 1.5 ) ;
        continue ;
      }
      total_fee += fee ;
    }
    return total_fee ;
  }
  int checkout(int d, int h, int m) {
    int total_fee = calc_total_fee(d, h, m) ;
    reset() ;
    int minute_finish = (m + 30) % 60 ;
    int hour_finish = ( h + ( (m + 30) / 60 ) ) % 24 ;
    int day_finish = d + ( h + ( (m + 30) / 60) / 24 ) ;
    time_cleaning_finish = (360 * 24) * day_finish + 60 * hour_finish + minute_finish ;
    is_cleaning = true ;
    return total_fee ;
  }
  bool operator< (const Room r) const {
    return time_cleaning_finish < r.time_cleaning_finish ;
  }
} ;
//////////////////////////////////////////////////////////////////////////////////////////////////////
int number_of_rooms, number_of_staff ;
int number_of_residual_staff ;
vector<Room> rooms ;
queue<Room> room_queue_h ;
queue<Room> room_queue_l ;
vector<bool> is_stay(99999) ;

void process_checkin(vector<string> query_info) {
  int day_checkin = stoi( query_info[0] ) ;
  auto hm = split(query_info[1], ':') ;
  int hour_checkin = stoi( hm[0] ) ;
  int minute_checkin = stoi( hm[1] ) ;
  int customer_id = stoi( query_info[3] ) ;
  int room_number = stoi( query_info[4] ) ;
  int number_of_customers = stoi( query_info[5] ) ;
  int stay_days = stoi( query_info[6] ) ;
  if ( room_number < 1 || room_number > 999 || rooms[room_number].room_number != room_number ) {
    // 指定された番号の部屋が存在しない場合
    cout << query_info[0] << " " << query_info[1] << " " << "ERROR: " << query_info[4] << " does not exist." << endl ;
    return ;
  }
  Room& room = rooms[room_number] ;
  if ( room.capacity < number_of_customers ) {
    // 人数が部屋の収容人数より多い場合
    cout << query_info[0] << " " << query_info[1] << " " << "ERROR: " << query_info[4] << " cannot accommodate " << query_info[3] << "." << endl ;
    return ;
  }
  if ( room.is_cleaning ) {
    // 部屋が清掃中の場合
    cout << query_info[0] << " " << query_info[1] << " " << "ERROR: " << query_info[4] << " is being cleaned." << endl ;
    return ;
  }
  if ( room.is_occupied() ) {
    // 部屋が利用中の場合
    cout << query_info[0] << " " << query_info[1] << " " << "ERROR: " << query_info[4] << " is occupied." << endl ;
    return ;
  }
  // チェックインを完了させる
  room.checkin(customer_id, day_checkin, hour_checkin, minute_checkin) ;
  is_stay[customer_id] = true ;
  cout << query_info[0] << " " << query_info[1] << " " << query_info[3] << " successfully checked in to " << query_info[4] << "." << endl ;
}
void process_checkout(vector<string> query_info) {
  // チェックアウトクエリ：D HH:MM check-out [宿泊客ID] [部屋番号]
  int day_checkout = stoi( query_info[0] ) ;
  auto hm = split(query_info[1], ':') ;
  int hour_checkout = stoi( hm[0] ) ;
  int minute_checkout = stoi( hm[1] ) ;
  int customer_id = stoi( query_info[3] ) ;
  int room_number = stoi( query_info[4] ) ;
  if ( room_number < 1 || room_number > 999 || rooms[room_number].room_number != room_number ) {
    // 指定された番号の部屋が存在しない場合
    cout << query_info[0] << " " << query_info[1] << " " << "ERROR: " << query_info[4] << " does not exist." << endl ;
    return ;
  }
  Room& room = rooms[room_number] ;
  if ( ! is_stay[customer_id] ) {
    // 宿泊客IDの宿泊客がどの部屋にも宿泊していない場合
    // [日付] [時刻] ERROR: [宿泊客ID] does not exist.
    cout << query_info[0] << " " << query_info[1] << " " << "ERROR: " << query_info[3] << " does not exist." << endl ;
    return ;
  }
  if ( room.customer_id != customer_id ) {
    // 宿泊客IDの宿泊客がその部屋を利用中でない場合
    cout << query_info[0] << " " << query_info[1] << " " << "ERROR: " << query_info[3] << " is not in " << query_info[4] << "." << endl ;
    return ;
  }
  // チェックアウトを完了させる
  int total_fee = room.checkout(day_checkout, hour_checkout, minute_checkout) ;
  is_stay[customer_id] = false ;
  cout << query_info[0] << " " << query_info[1] << " " << query_info[3] << " has to pay " << ::to_string(total_fee) << " to leave " << query_info[4] << "." << endl ;

  // 清掃員の割当を試みる

  // // 清掃員の空き状況を調べる
  // for (Room& r : rooms) {
  //   if ( ! r.is_cleaning ) continue ;
  //   int t = (360 * 24) * day_checkout + 60 * hour_checkout + minute_checkout ;
  //   if ( r.time_cleaning_finish > t) continue ;
  //   r.is_cleaning = false ;
  //   number_of_residual_staff++ ;
  // }

  if ( number_of_residual_staff == 0 ) {
    // 手の空いた清掃員がいない場合
    cout << query_info[0] << " " << query_info[1] << " No cleaner is available." << endl ;
    if ( room.is_low )
      room_queue_l.push(room) ;
    else
      room_queue_h.push(room) ;
    return ;
  }
  // 手の空いた清掃員がいる場合
  cout << query_info[0] << " " << query_info[1] << " A cleaner is assigned to " << query_info[4] << "." << endl ;
  number_of_residual_staff-- ;
}
void accept_query(string query) {
  auto query_info = split(query, ' ') ;
  int day = stoi( query_info[0] ) ;
  auto hm = split(query_info[1], ':') ;
  int hour = stoi( hm[0] ) ;
  int minute = stoi( hm[1] ) ;

  // 清掃員の空き状況を調べる
  for (Room& r : rooms) {
    if ( ! r.is_cleaning ) continue ;
    int t = (360 * 24) * day + 60 * hour + minute ;
    if ( r.time_cleaning_finish > t) continue ;
    r.is_cleaning = false ;
    number_of_residual_staff++ ;
  }

  if (query_info[2] == "check-in")
    process_checkin(query_info) ;
  else if (query_info[2] == "check-out")
    process_checkout(query_info) ;

}

int main(int argc, char* argv[]) {
  for (int i = 0 ; i <= 999 ; i++)
    rooms.push_back( Room(0, 0, 0, 0) ) ;

  // 入力受け取り
  int line_count = 0 ;
  string line ;
  while ( ! cin.eof() ) {
    line_count++ ;
    getline(cin, line) ;

    if (line == "") break ;

    // 部屋数と清掃員数の受け取り
    if (line_count == 1) {
      auto data = split(line, ' ') ;
      number_of_rooms = stoi(data[0]) ;
      number_of_staff = stoi(data[1]) ;
      number_of_residual_staff = number_of_staff ;
      continue ;
    }

    // 部屋情報の受け取り
    if ( line_count <= number_of_rooms + 1 ) {
      auto room_info = split(line, ' ') ;
      bool il = (room_info[1] == "LOW") ;
      int i = stoi(room_info[0]) ;
      int c = stoi(room_info[2]) ;
      int f = stoi(room_info[3]) ;
      rooms[i] = Room(il, i, c, f) ;
      continue ;
    }

    // クエリの受け取り
    accept_query(line) ;
  }
}
