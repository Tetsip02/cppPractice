#include <iostream>
#include <cmath>
#include <assert.h>

class Rational {
public:
  Rational(int,int);
  Rational();
  Rational(int);
  void reduce();
  int num()const {return numerator;}
  int denom()const {return denominator;}
  double value();
  void print();

  Rational& operator+=(const Rational& RHS);
  Rational& operator*=(const Rational& RHS);

  //input/output operators are not member functions. By declaring them inside the class with friend, the function will have access to all members even though it's defined outside the class.
  friend std::ostream& operator<<(std::ostream& os, const Rational& r);
  friend std::istream& operator>>(std::istream& is, Rational& r);

private:
  int numerator;
  int denominator;
};

Rational::Rational(int n,int d) {
  numerator = n;
  assert (d != 0);
  denominator = d;
}

Rational::Rational() {
  numerator = 1;
  denominator = 1;
}

Rational::Rational(int n) {
  numerator = n;
  denominator = 1;
}

double Rational::value() {
  return (double)numerator / (double)denominator;
}

void Rational::print() {
  std::cout << numerator << "/" << denominator << std::endl;
}

void Rational::reduce() {
  //find gcd using Euclid's method
  int gcd;
  int r1 = numerator;
  int r2 = denominator;
  int remains = r1 % r2;
  while (true) {
    if (remains == 0) {
      gcd = r2;
      break;
    }
    r1 = r2;
    r2 = remains;
    remains = r1 % r2;
  }
  numerator /= gcd;
  denominator /= gcd;
}

Rational& Rational::operator+=(const Rational& RHS) {
  Rational result;
  result.numerator = numerator*RHS.denominator + RHS.numerator*denominator;
  result.denominator = denominator * RHS.denominator;
  result.reduce();
  numerator = result.numerator;
  denominator = result.denominator;
  return *this;
}

Rational& Rational::operator*=(const Rational& RHS) {
  Rational result;
  result.numerator = numerator * RHS.numerator;
  result.denominator = denominator * RHS.denominator;
  result.reduce();
  numerator = result.numerator;
  denominator = result.denominator;
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Rational& r) {
  os << r.numerator << "/" << r.denominator;
  return os;
}

std::istream& operator>>(std::istream& is, Rational& r) {
  is >> r.numerator;
  char c;
  is >> c;
  assert (c == '/');
  is >> r.denominator;
  r.reduce();
  return is;
}

int main() {
  Rational exp(8,6);
  int a = exp.num();
  std::cout << a << std::endl;
  std::cout << exp.value() << std::endl;
  exp.print();
  exp.reduce();
  exp.print();
  Rational t(2,5);
  exp += t;
  exp.print();
  exp *= t;
  exp.print();
  std::cout << "next" << std::endl;
  std::cout << "using << operator" << '\t' << exp << std::endl;
  Rational inp;
  std::cout << "enter a rational in the format a/b: ";
  std::cin >> inp;
  std::cout << "input = " << inp << std::endl;
  return 0;
}
