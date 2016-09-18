#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip> //setw()
#include <cstdlib> //system()

int main() {
  std::cout << "Please enter the maximum square: ";
  int max;
  while(true) {
    std::cin >> max;
    if(max<0) {std::cout << "I only accept positive integers as input. PLease enter another number: ";}
    else {break;}
  }
  double temp;
  std::ofstream ofs("squares.dat");
  for (int i=0;i<=max;i++) {
    temp = std::pow(i,2);
    std::cout << i << "*" << i << " = " << temp << std::endl;
    ofs << std::setw(4) << i << std::setw(10) << temp << std::endl;
  }
  std::ofstream ofs_plot("squares.gnu");
  ofs_plot << "reset" << std::endl;
  ofs_plot << "set terminal png" << std::endl;
  ofs_plot << "set output 'squares.png'" << std::endl;
  ofs_plot << "set xlabel 'x'" << std::endl;
  ofs_plot << "set ylabel 'y = x^2'" << std::endl;
  ofs_plot << "plot 'squares.dat' using 1:2 with lines" << std::endl;
  std::system("gnuplot squares.gnu");
  return 0;
}
