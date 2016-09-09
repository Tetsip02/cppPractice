#include <iostream>
#include <fstream>

int main() {
  std::fstream fs("myfile.txt", std::ios_base::app); //append (i.e., add to the end of the file)
  std::ofstream of("myfile.txt"); //by default ios_base::out
  std::ifstream if1("myfile.txt"); //by default ios_base::in


  /*getline()*/
  /*if cin is used instead of getline, only hello will be read in (because of whitespace)*/
  std::string name;
  std::getline(std::cin,name);  //input 'hello world'
  std::cout << name << '\n';
}
