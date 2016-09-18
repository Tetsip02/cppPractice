#include <iostream>
#include <cmath>

int main() {
  std::cout << "Solving a*x*x + b*x + c = 0:" << std::endl;
  std::cout << "Enter a: ";
  double a;
  std::cin >> a;
  std::cout << "Enter b: ";
  double b;
  std::cin >> b;
  std::cout << "Enter c: ";
  double c;
  std::cin >> c;
  double discriminant = b*b - 4*a*c;
  if (discriminant<0) {
    double real = -b/(2*a);
    double complex = std::pow(-discriminant,0.5)/(2*a);
    std::cout << "Solutions are " << real << " +- " << complex << "i" << std::endl;
    return 0;
  }
  double root1, root2;
  root1 = (-b + std::pow(discriminant,0.5))/(2*a);
  root2 = (-b - std::pow(discriminant,0.5))/(2*a);
  std::cout << "Solutions are " << root1 << " and " << root2 << "." << std::endl;
  return 0;
}
