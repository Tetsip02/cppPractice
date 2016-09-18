#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class Punct_stream {

public:
  Punct_stream(std::istream& is)
      : source(is), sensitive(true) {}

  void whitespace(const std::string& s) {white = s;}//make s the whtiespace set
  void add_white(char c) {white +=c;} //add to the whitespace set
  bool is_whitespace(char c); //is c in the whitespace set?

  void case_sensitive(bool b) {sensitive = b;}
  bool is_case_sensitive() {return sensitive;}

  Punct_stream& operator>>(std::string& s);
  operator bool();
private:
  std::istream& source; //character source
  std::istringstream buffer; //we let buffer do our formatting
  std::string white; //characters considered "whitespace"
  bool sensitive; //is the stream case sensitive?
};

Punct_stream& Punct_stream::operator>>(std::string& s) {
  while(!(buffer>>s)) { //try to read from buffer
    if (buffer.bad() || !source.good()) {return *this;}
    buffer.clear();

    std::string line;
    std::getline(source,line); //get a line from source

    //do character replacement as neeed:
    for (int i=0;i<line.size();++i) {
      if (is_whitespace(line[i])) {line[i] = ' ';} //to space
      else if (!sensitive) {line[i] = std::tolower(line[i]);} //to lower case
    }
    buffer.str(line);  //put string into stream
  }
  return *this;
}

bool Punct_stream::is_whitespace(char c) {
  for (int i=0;i<white.size();++i) {
    if (c==white[i]) {return true;}
  }
  return false;
}

Punct_stream::operator bool() {
  return !(source.fail() || source.bad()) && source.good();
}


int main()
  //given text input, produce a sorted list of all words in that text
  //ignore punctuation and case differences
  //eliminate duplicates from the output
{
  Punct_stream ps(std::cin);
  ps.whitespace(";:,.?!()\"{}<>/&$@#%^|~"); //note, \ "means" in string
  ps.case_sensitive(false);

  std::cout << "please enter words\n";
  std::vector<std::string> vs;
  std::string word;
  while (ps>>word) {vs.push_back(word);} //read words

  sort(vs.begin(),vs.end()); //sort in lexicographical order
  for (int i=0;i<vs.size();i++) { //write dictionary
    if (i==0 || vs[i]!=vs[i-1]) {std::cout << vs[i] << std::endl;}
  }
}
