#include <iostream>

void calcNextRow (const int* prevRow, int* nextRow, int rowNo) {
  nextRow[0] = 1;
  for (int i=1; i < rowNo; i++) {
    nextRow[i] = prevRow[i-1] + prevRow[i];
  }
}

int main() {
  int num;
  std::cout << "Enter size of triangle: ";
  std::cin >> num;
  num += 2;

  int* prevRow = new int[num];
  int* nextRow = new int[num];

  prevRow[0] = 1;
  for (int i=0; i<num; i++) {
    calcNextRow(prevRow,nextRow,i);
    for (int j=0; j<i-1; j++) {
      std::cout << prevRow[j] << " ";
    }
    std::cout << std::endl;
    int* tmpRow = prevRow;
    prevRow = nextRow;
    nextRow = tmpRow;
  }

  delete[] prevRow;
  delete[] nextRow;

  return 0;
}
