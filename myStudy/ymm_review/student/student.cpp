#include "student.h"

using namespace std ;
Student::Student(InputStream &in, int i) {
  id = data[0] ;
  auto attributes = in.get_attributes() ;
  string* subject_name = attributes.begin() + 1 ;
  while (subject_name != attributes.end()) {
    scores[*subject_name] =
    subject_name++ ;
  }
}
string get_id() ; // id を返す
int get_score(string subject_name) ; // 科目名を指定し、その科目の点数を返す
float get_average(int d = 2) ; // 平均点を返す
