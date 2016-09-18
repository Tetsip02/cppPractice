#include <iostream>
#include <string>
#include <fstream>

bool is_palindrome(const char* first, const char* last) {
  while (first<last) { //while we haven't reached the middle
    if (*first!=*last) {return false;}
    ++first;
    --last;
  }
  return true;
}

std::istream& read_word(std::istream& is, char* buffer, int max) { //read at most max-1 characters into buffer
  is.width(max);
  is >> buffer;
  return is;
}


int main() {
  const int max = 128;
  char s[max];
  while (read_word(std::cin,s,max)) {
    std::cout << s << " is";
    if(!is_palindrome(&s[0],&s[std::strlen(s)-1])) {std::cout << " not";}
    std::cout << " a palindrome\n";
  }
  return 0;
}
