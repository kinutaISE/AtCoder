#ifndef PERSON_KAICAO1948919_INCLUDED_
#define PERSON_KAICAO1948919_INCLUDED_

#include <iostream>
#include <string>
using namespace std ;

class Person {
protected:
  string name ;
  int age ;
public:
  Person(string name, int age) ;
  void func() const ;
} ;

class AdultPerson : public Person {
public:
  AdultPerson(string name, int age) ;
  void func() ;
} ;

// 以下実装
Person::Person(string name, int age) {
  this->name = name ;
  this->age = age ;
}
void Person::func() const {
  cout << name << " " << age << endl ;
}

AdultPerson::AdultPerson(string name, int age) :
  Person(name, age)
{
}
void AdultPerson::func() {
  age++ ;
  cout << name << " " << age << endl ;
}

#endif
