/*
学生クラスの実装
*/
#include "../functions/functions_str.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std ;

const char DELIMITER = ' ' ; // 区切り文字

// Studentクラスの実装 //////////////////////////////////
Student::Student(string line):Student( split(line, DELIMITER) ) {}
Student::Student(vector<string> data) {
  id = data[0] ;
  name = data[1] ;
  gender = (GENDER) find(gender_str, data[2]) ;
  height = stof(data[3]) ;
  weight = stof(data[4]) ;
}
string Student::get_id() {
  return id ;
}
string Student::get_name() {
  return name ;
}
string Student::get_gender() {
  return gender_str[gender] ;
}
float Student::get_height() {
  return height ;
}
float Student::get_weight() {
  return weight ;
}
vector<Student> Student::get_friends() {
  return friends ;
}
char* Student::get_info() {
  char* info ;
  sprintf(info, "%s %s %s %3.1fm %3.1fkg", id.c_str(), name.c_str(), gender_str[gender], height, weight) ;
  return info ;
}
float Student::get_BMI() {
  return weight / (height * height) ;
}
string Student::get_friends_str() {
  string friends_str = "{" ;
  for (Student& f : friends)
    friends_str += f.get_name() + "," ;
  *friends_str.end() = '}' ;
  return friends_str ;
}
////////////////////////////////////////////////////////

// ElementarySchoolStudentクラスの実装 ///////////////////
ElementarySchoolStudent::ElementarySchoolStudent(string line):ElementarySchoolStudent( split(line, DELIMITER) ) {}
ElementarySchoolStudent::ElementarySchoolStudent(vector<string> data):Student(data) {
  grade = stoi(data[5]) ;
  class_number = stoi(data[6]) ;
}
char* ElementarySchoolStudent::get_info() {
  char* info ;
  sprintf(info, "%s %s %d %d %s %3.1fm %3.1fkg", id.c_str(), name.c_str(), grade, class_number, gender_str[gender], height, weight) ;
  return info ;
}
int ElementarySchoolStudent::get_grade() {
  return grade ;
}
int ElementarySchoolStudent::get_class_number() {
  return class_number ;
}
////////////////////////////////////////////////////////
