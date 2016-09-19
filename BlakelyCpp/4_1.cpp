#include <iostream>
#include <cmath>

int sum (int a, int b) {
  return a + b;
}

void decrease (int &a, int b) {
  a -= b;
}

int q (double a, double b, double c, double &x1, double &x2) {
  double discriminant = b*b - 4*a*c;
  int num_solution;
  if (discriminant<0) {
    num_solution = 0;
    return num_solution;
  }
  else if (discriminant == 0) {num_solution = 1;}
  else {num_solution = 2;}
  x1 = (-b + std::pow(discriminant,0.5))/(2*a);
  x2 = (-b - std::pow(discriminant,0.5))/(2*a);
  return num_solution;
}

int main() {
  int res = sum(2,6);
  std::cout << res << std::endl;
  int x = 7;
  decrease(x,4);
  std::cout << x << std::endl;
  double x1,x2;
  int n = q(1,5,6,x1,x2);
  std::cout << x1 << '\t' << x2 << std::endl;
  return 0;
}
