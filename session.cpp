
class Session {
private:
  void start();
  void login();
  void registr();

public:
  Session();
};

Session::Session() {
  start();
}

void Session::start() {
  int choice;

  std::cout << std::endl << std::endl;
  std::cout << "Welcome to Rate Professor" << std::endl;
  std::cout << "Choose your options:" << std::endl;
  std::cout << "1: Login" << std::endl << "2: Register" << std::endl;

  std::cin >> choice;

  if(choice == 1) return login();
  else if(choice == 2) return registr();
  else std::cout << "Please enter 1 or 2" << std::endl;

  return start();
}

void Session::login() {
  std::cout << "Login page" << std::endl;
}

void Session::registr() {
  std::string name;
  std::string email;
  std::string password;

  std::cout << std::endl << std::endl;
  std::cout << "Regsitation page" << std::endl;

  std::cout << "Name: ";
  std::cin >> name;
  std::cout << "E-mail: ";
  std::cin >> email;
  std::cout << "Password: ";
  std::cin >> password;

  std::cout << "Welcome " << name << "!" << std::endl;

  Student newguy(name, email, password);
}
