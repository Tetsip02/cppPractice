// use valgrind --leak-check=yes --show-reachable=yes ./5_2.cpp to check if there is leaked memory

#include <iostream>

int** mat_alloc(int N) { //elem[i][j] points to ith rows in jth column
  int* mat = new int[N*N]; //2D matrix is stored a vector
  int** elem = new int*[N]; //elem[0] points to the first row of mat
  for (int i=0; i<N; i++) {
    elem[i] = mat + i*N;
  }
  return elem;
}

void mat_dealloc(int** mat) {
  delete[] mat[0];
  delete[] mat;
}

int main() {
  int** matrix = mat_alloc(3);
  mat_dealloc(matrix);
  return 0;
}
