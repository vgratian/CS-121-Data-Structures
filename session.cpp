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
  std::cout << "Regsiter page" << std::endl;
}
