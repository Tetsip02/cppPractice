#include <iostream>
#include <vector>

template <typename T>
T sum(std::vector<T> my_vec) {
  T sum = 0;
  for (int i=0; i<my_vec.size(); i++) {
    sum += my_vec[i];
  }
  return sum;
}

int main() {
  std::vector<float> test;
  std::cout << "enter elements, finish input with a negative number:" << std::endl;
  float num;
  while (std::cin >> num) {
    if (num<0) {break;}
    test.push_back(num);
  }
  float ans = sum(test);
  std::cout << ans << std::endl;
  return 0;
}
