class Professor {
private:
  std::string name;
  std::string courses[100];
  int rating;
  void update_rating();

public:
  Professor();
  int get_rating();
  std::string get_name();

};
