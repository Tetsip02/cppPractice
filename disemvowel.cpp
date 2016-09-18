#include <iostream>
#include <fstream>
#include <vector>

int main () {

  std::vector<char> vowels;
  vowels.push_back('a');
  vowels.push_back('e');
  vowels.push_back('i');
  vowels.push_back('o');
  vowels.push_back('u');
  vowels.push_back('A');
  vowels.push_back('E');
  vowels.push_back('I');
  vowels.push_back('O');
  vowels.push_back('U');
  std::ifstream ifs("text.txt");
  std::ofstream ofs("text_disemvowel.txt");
  std::string word;
  char ch;
  while (ifs >> word) {
    for(int i=0;i<word.length();i++) {
      ch = word[i];
      for(int j=0;j<vowels.size();j++) {
        if (ch == vowels[j]) {
          word[i] = '\0';
          break;
        }
      }
    }
    ofs << word << " ";
  }
}
