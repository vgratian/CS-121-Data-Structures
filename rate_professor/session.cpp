class Session {
private:
  std::string m_email;
  std::string m_psw;
  Students* aua;
  bool loggedin;
  void start();
  void login();
  void registr();
  void get_details();
  bool valid_email(std::string email);

public:
  Session();
};

Session::Session() {
  aua = new Students;
  loggedin = false;
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
  if(loggedin) {
    std::cout << "You are already logged in." << std::endl;
    return start();
  }
  else {
    get_details();

    if(aua->is_registered(m_email)) {
      std::cout << "log in succesful" << std::endl;
      loggedin = true;
      return start();
    }

    else {
      std::cout << "email or password incorrect" << std::endl;
      return start();
    }
  }
}

void Session::registr() {

  std::hash <std::string> hash_fn; // This hasqh function is not safe
  std::string raw_psw;

  std::cout << std::endl;
  std::cout << "Regsitation page" << std::endl;

  get_details();

  // Check if user is not already registered
  /*
  if(aua->is_registered(m_email)) {
    std::cout << "Email already registered" << std::endl;
    return start();
  }
  else if(!valid_email(m_email)) {
    std::cout << "Invalid email, please choose email associated with your university." << std::endl;
    return registr();
  }
*/
  aua->insert(m_email, m_psw);
  std::cout << "Welcome " << m_email << "!" << std::endl;
  //std::cout << "Tree size:" << aua->get_size() << std::endl;
  //loggedin = true;
  //return start();
}

void Session::get_details() {
  std::string raw_psw;
  std::hash <std::string> hashfn;

  std::cout << "E-mail: ";
  std::cin >> m_email;
  std::cout << "Password: ";
  std::cin >> raw_psw;
  m_psw = hashfn(raw_psw);
}

bool Session::valid_email(std::string email) {
  std::string domain = email.substr(email.find("@") + 1);
  if(domain == "edu.aua.am")
    return true;
  return false;
}
