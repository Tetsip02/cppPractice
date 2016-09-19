#include <iostream>

void partial_sum(const int a[20], int (&b)[20]) {
  b[0] = a[0];
  for (int i=1; i<20; i++) {
    b[i] = a[i] + b[i-1];
  }
}

int main() {
  int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
  int b[20];
  int size = sizeof(a)/sizeof(*a);
  partial_sum(a,b);
  for (int i=0;i<size;i++) {
    std::cout << b[i] << std::endl;
  }
  return 0;
}
