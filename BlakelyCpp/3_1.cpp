#include <iostream>
#include <cmath>
#include <iomanip> //setw()
#include <cstdlib>
#include <fstream>

int main() {
  std::cout << "Solving dy/dt = sqrt(y) using Euler's update formaula:" << std::endl;
  double T, delta, y_zero;
  std::cout << "Please enter the following:" << std::endl;
  std::cout << "Maximum time value: ";
  std::cin >> T;
  std::cout << "time step: ";
  std::cin >> delta;
  std::cout << "y when time=zero: ";
  std::cin >> y_zero;
  double y_prev, y_next;
  y_prev = y_zero;
  std::ofstream ofs("ODE.dat");
  ofs << std::setw(7) << 0 << std::setw(10) << y_prev << std::endl;
  for(double t=delta;t<=T;t+=delta) {
    y_next = y_prev + delta*std::pow(y_prev,0.5);
    y_prev = y_next;
    ofs << std::setw(7) << t << std::setw(10) << y_prev << std::endl;
  }
  std::ofstream ofs_plot("ODE.gnu");
  ofs_plot << "reset" << std::endl;
  ofs_plot << "set terminal png" << std::endl;
  ofs_plot << "set output 'ODE.png'" << std::endl;
  ofs_plot << "set xlabel 'time'" << std::endl;
  ofs_plot << "set ylabel 'y(t)'" << std::endl;
  ofs_plot << "plot 'ODE.dat' using 1:2 with lines" << std::endl;
  std::system("gnuplot ODE.gnu");
  return 0;
}
