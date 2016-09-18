#include <iostream>
#include <fstream>

int main() {
  std::ifstream ifs("text.txt");
  std::ofstream ofs("textLower.txt");
  std::string word;
  while (ifs >> word) {
    char ch = word[0];
    ch = tolower(ch);
    word[0] = ch;
    ofs << word << " ";
  }
}
