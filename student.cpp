class Student {
private:
  std::string m_name;
  std::string m_email;
  std::string m_psw;
  std::string courses[100];

public:
  Student(std::string name, std::string email, std::string password);
  std::string get_name;

};

Student::Student(std::string name, std::string email, std::string psw) {
  m_name = name;
  m_email = email;
  m_psw = psw;

  std::ofstream myfile;
  myfile.open ("students.csv");
  myfile << name << "," << email << "," << psw << ";" << std::endl;
  myfile.close();
}
