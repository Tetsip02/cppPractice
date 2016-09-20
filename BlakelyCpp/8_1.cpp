#include <iostream>
#include "./7_1.cpp" //Date class

//virtual functions allow functions which were defined in the base class to be reimplemented in a derived class

class Researcher {
private:
  std::string m_name;
public:
  std::string name()const;
  virtual std::string title()const = 0;
};

//split between students and non'students
class Student : public Researcher {
public:
  int lectureHoursTakenPerWeek()const;
  Date submissionDeadLine()const;
protected:
  //lecture hours can be changed by/is available to MPhil/Phd Students
  int m_lectureHours;
};

class MPhilStudent : public Student {
public:
  virtual std::string title()const; //implemets same title function as reseracher
};
std::string MPhilStudent::title()const { //have a special title function for MPhil Student
  return "MPhil Student";
}

class PhdStudent : public Student {
public:
  virtual std::string title()const;
};
std::string PhdStudent::title()const {
  return "Phd Student";
}

//all non-students are also researchers but give lectureHoursGivenPerWeek
class nonStudent : public Researcher {
public:
  virtual int lectureHoursGivenPerWeek();
protected:
  int hoursPerWeek;
};
int nonStudent::lectureHoursGivenPerWeek() {
  return hoursPerWeek;
}

class postDoc : public nonStudent {
public:
  virtual std::string title()const;
};
std::string postDoc::title()const {
  return "postDoc";
}

int main() {
  return 0;
}
