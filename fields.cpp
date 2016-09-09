#include <iostream>
#include <iomanip> //setw()
//setw() doesn't stick
int main() {
  std::cout << "|" << std::setw(9) << "last name" << "|" << std::setw(10)
            << "first name" << "|" << std::setw(16) << "telephone number"
            << "|" << std::setw(27) << "email address" << "|" << std::endl;
  std::cout << "|" << std::setw(9) << "Azizi" << "|" << std::setw(10)
            << "Sergio" << "|" << std::setw(16) << "123456"
            << "|" << std::setw(27) << "sergio.engineers@gmail.com" << "|" << std::endl;
}
