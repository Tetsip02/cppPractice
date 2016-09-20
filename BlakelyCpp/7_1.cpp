#include <iostream>
#include <assert.h>

int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int daysInMonthLeapYear[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

class Date {
private:
  int day, month, year;
public:
  Date();
  bool isLeapYear();
  Date(int, int, int);
  void next();
  int get_day() {return day;}
  int get_month() {return month;}
  int get_year() {return year;}
  void set_day(int);
  void set_month(int);
  void set_year(int);
};

Date::Date() {
  day = 0;
  month = 0;
  year = 0;
}
Date::Date(int d, int m, int y) {
  day = d;
  month = m;
  year = y;
  if (isLeapYear()) {
    assert (d <= daysInMonthLeapYear[month-1]);
  }
  else {
    assert (d <= daysInMonth[month-1]);
  }
  assert (m <= 12);
}
void Date::next() {
  if (day == 28 && month == 2 && isLeapYear()) {++day;}
  else {
    if (day == daysInMonth[month-1] || day == daysInMonthLeapYear[month-1]) {
      day = 1;
      if (month == 12) {
        month = 1;
        ++year;
      }
      else {
        ++month;
      }
    }
    else {
      day += 1;
    }
  }
}
void Date::set_day(int d) {
  if (isLeapYear()) {
    assert (d <= daysInMonthLeapYear[month-1]);
  }
  else {
    assert (d <= daysInMonth[month-1]);
    day = d;
  }
}
void Date::set_month(int m) {
  assert (m <= 12);
  month = m;
}
void Date::set_year(int y) {
  year = y;
}
bool Date::isLeapYear() {
  if (year % 4 == 0) {
    if (year % 100 == 0) {
      if (year % 400 == 0) {return true;}
      return false;
    }
    return true;
  }
  return false;
}

// int main() {
//   Date myBirthday(31,12,2005);
//   myBirthday.next();
//   //myBirthday.set_month(10);
//   std::cout << myBirthday.get_day() << '\t' << myBirthday.get_month() << '\t' << myBirthday.get_year() << std::endl;
//   return 0;
// }
