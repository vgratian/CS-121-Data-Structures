#include <iostream>
#include <string>

class Professor {
private:
  string name;
  string courses[];
  int rating;
  void update_rating();

public:
  Professor();
  int get_rating();
  string get_name();

};

class Student {
private:
  string name;
  string email;
  string hash_password;
  string courses[];

public:
  Student();
  string get_name;

};

class Rating() {
private:
  int rating;
  string description;
  string to_professor;
  string from_student;

public:
  Rating();
};

class Course() {
private:
  string name;
  string professor;
  string students;

public:
  Course();
}


main() {

  return 0;
}
