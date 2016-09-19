#include <iostream>

int trace(const int a[3][3]) {
  return a[0][0] + a[1][1] + a[2][2];
}

int determinant(const int a[3][3]) {
  return a[0][0] * (a[1][1]*a[2][2] - a[2][1]*a[1][2]) - a[0][1] * (a[1][0]*a[2][2] - a[2][0]*a[1][2]) + a[0][2] * (a[1][0]*a[2][1] - a[2][0]*a[1][1]);
}

int main() {
  int mat[3][3];
  std::cout << "Enter value of each element of your 3x3 matrix..." << std::endl;
  for (int r=0;r<3;r++) {
    for (int c=0;c<3;c++) {
      std::cout << "mat[" << r << "][" << c << "] = ";
      std::cin >> mat[r][c];
    }
  }
  std::cout << "Trace = " << trace(mat) << std::endl;
  std::cout << "Determinant = " << determinant(mat) << std::endl;
  return 0;
}
