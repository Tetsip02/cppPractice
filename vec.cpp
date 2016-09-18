#include <iostream>
#include <fstream>

class vec {
private:
  int sz;
  double* elem;
  int space;

  void copy(const vec&); //helper function to define copy contructor. Assumes there are sz elements available in its argument and target vector. Make this member private to ensure that

public:
  vec();
  explicit vec(int); //explicit gives you an error when trying to convert from int to vec. eg. vec v=10; v=20 ->error
  vec(int ,double); //new vector, sz=int; elem[i]=double for all i
  vec(const vec&); //copy constructor
  vec& operator = (const vec&); //copy assingnment

  ~vec() {delete[] elem;} //delete[] means delete array

  double& operator[](int n) {return elem[n];} //return reference, allows us to read and set elements with the notation v[i]=i and cout<<v[i], rather than using set() and get()
  const double& operator[](int n) const {return elem[n];} ////same as the other one but for const vec. the other can't do that since it could potentially change a vec.

  int size() const {return sz;}
  int capacity() const {return space;}

  void reserve(int);
  void resize(int);
  void push_back(double); //increase size by one and initialize new element with argument

  void print();
  void read(std::string);

};

vec::vec() {
  sz = 0;
  elem = 0;
  space = 0;
}

vec::vec(int s) {
  sz = s;
  elem = new double[s];
  space = s;
  for (int i=0; i<sz; ++i) {elem[i] = 0;}
}

vec::vec(int a,double b) {
  sz = a;
  elem = new double[a];
  space = a;
  for (int i=0;i<sz;++i) {elem[i] = b;}
}

void vec::copy(const vec& arg) {
  for (int i=0;i<arg.sz;++i) {elem[i] = arg.elem[i];}
}

vec::vec (const vec& arg) {
  sz = arg.sz;
  elem = new double[arg.sz];
  copy(arg);
}

void vec::reserve(int newalloc){
  if (newalloc<=space) {return;} //never decrease allocation
  double* p = new double[newalloc];
  for (int i=0;i<sz;++i) {p[i] = elem[i];}
  delete[] elem; //free up old space
  elem = p;
  space = newalloc;
}

void vec::resize(int newsize) {
  reserve(newsize); //new vector will have newsize elements
  for (int i=sz;i<newsize;++i) {elem[i] = 0;}
  sz = newsize;
}

void vec::push_back(double d) {
  if (space==0) {reserve(8);} //in praticce we rarely change the size just once. To optimize the program we can anticipate future changes by allocating space beforehand
  else if (sz==space) {reserve(2*space);}
  elem[sz] = d;
  ++sz;
}

void vec::print() {
  for (int i=0;i<sz;i++) {std::cout << elem[i] << std::endl;}
}

void vec::read(std::string fileName) {
  std::ifstream ifs(fileName.c_str());
  if (!ifs) {
    std::cout << "Error: Problem with opening the file " << fileName << std::endl;
    return;
  }
  //count number of necessary elements
  int count = 0;
  double num;
  while (ifs>>num) {++count;}
  //set pointer back to begining of file
  ifs.clear();
  ifs.seekg(0, std::ios::beg);

  double* p = new double[count];
  int index = 0;
  while (ifs>>num) {
    p[index] = num;
    ++index;
  }
  sz = count;
  delete[] elem;
  elem = p;
  space = 0;
}

int main() {
  return 0;
}
