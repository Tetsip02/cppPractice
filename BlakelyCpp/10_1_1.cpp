#include <iostream>
#include <vector>

int main() {
  std::cout << "Please enter a list of positive numbers, ending with a negative one: " << std::endl;
  std::vector<float> list;
  float num;
  while (true) {
    std::cin >> num;
    if (num<0) {break;}
    list.push_back(num);
  }
  const int l = list.size();
  std::vector<float> sortedList(l);
  float largest = 0;
  int j;
  for (int i=0; i<l; i++) {
    j = 0;
    while (true) {
      float a;
      a = list[j];
      ++j;
      if (a>largest) {largest = a;}
      if (a==list.back()) {break;}
    }
    sortedList[i] = largest;
    largest = 0;
    list[i] = 0;
  }
  std::cout << "Sorted Vector, every other element:" << std::endl;
  for (int i=0; i<l; i+=2) {
    std::cout << sortedList[i] << std::endl;
  }
  return 0;
}
