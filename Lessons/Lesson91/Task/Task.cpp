#include <iostream>
#include <vector>

bool isUsernameFound(const std::vector<std::string> &names,
             const std::string &username) {
  for (const auto &name : names) {
    if (name == username)
      return true;
  }
  return false;
}

int main() {
  std::vector<std::string> names{"Sasha",    "Ivan", "John",  "Orlando",
                                 "Leonardo", "Nina", "Anton", "Molly"};

  std::cout << "Enter a name.\n"
            << "> ";
  std::string username;
  std::cin >> username;
  std::cout << '\n';

  if (isUsernameFound(names, username))
    std::cout << username << " is found.\n";
  else
    std::cout << username << " was not found.\n";
  std::cout << '\n';
  return 0;
}