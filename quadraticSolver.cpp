#include <iostream>
#include <fstream>
#include <cmath> //sqrt()
#include <vector>

std::vector<double> qrsolver(double a, double b, double c)
{
    std::vector<double>roots(2);
    double discriminant = b*b - 4*a*c;
    if (discriminant < 0) {throw 1;}
    roots[0] = (-b + std::sqrt(discriminant))/2*a;
    roots[1] = (-b - std::sqrt(discriminant))/2*a;
    return roots;
}

int main ()
try {
    std::cout << "A quadratic is in the form a*x*x + b*x + c = 0, please enter your coefficients a, b and c." << std::endl;
    double a, b, c;
    std::cin >> a >> b >> c;
    std::vector<double>roots = qrsolver(a, b, c);
    std::cout << "Roots are " << roots[0] << " and " << roots[1] << std::endl;
    return 0;
}

catch (int error) {
   std::cerr << "Error: No real roots" << std::endl;
   return 1;
}
