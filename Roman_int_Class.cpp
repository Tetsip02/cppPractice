#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>

class Roman_int {
private:
    std::string value;
public:
    class Invalid{};    //exception class
    //constructors
    Roman_int() {value = "";}
    Roman_int(std::string s);
    Roman_int(int n);
    //members
    int as_int() const;
    std::string get_string() const {return value;}
    //arithmetic operators
    Roman_int operator+(const Roman_int& rhs);
    Roman_int operator-(const Roman_int& rhs);
    Roman_int operator*(const Roman_int& rhs);
    Roman_int operator/(const Roman_int& rhs);
    Roman_int operator%(const Roman_int& rhs);

    void operator+=(const Roman_int& rhs);
    void operator-=(const Roman_int& rhs);
    void operator*=(const Roman_int& rhs);
    void operator/=(const Roman_int& rhs);
    void operator%=(const Roman_int& rhs);

    //bool operators
    bool operator==(const Roman_int& rhs);
    bool operator!=(const Roman_int& rhs);
};



//Roman_int operator+(const Roman_int& r1, const Roman_int& r2);

//------------------------------------------------------
//arithmetic operators
Roman_int Roman_int::operator+(const Roman_int& rhs) {
    return Roman_int(as_int() + rhs.as_int());
}
Roman_int Roman_int::operator-(const Roman_int& rhs) {
    return Roman_int(as_int() - rhs.as_int());
}
Roman_int Roman_int::operator*(const Roman_int& rhs) {
    return Roman_int(as_int() * rhs.as_int());
}
Roman_int Roman_int::operator/(const Roman_int& rhs) {
    return Roman_int(as_int() / rhs.as_int());
}
Roman_int Roman_int::operator%(const Roman_int& rhs) {
    return Roman_int(as_int() % rhs.as_int());
}

void Roman_int::operator+=(const Roman_int& rhs) {
    value = Roman_int(as_int() + rhs.as_int()).get_string();
}
void Roman_int::operator-=(const Roman_int& rhs) {
    value = Roman_int(as_int() - rhs.as_int()).get_string();
}
void Roman_int::operator*=(const Roman_int& rhs) {
    value = Roman_int(as_int() * rhs.as_int()).get_string();
}
void Roman_int::operator/=(const Roman_int& rhs) {
    value = Roman_int(as_int() / rhs.as_int()).get_string();
}
void Roman_int::operator%=(const Roman_int& rhs) {
    value = Roman_int(as_int() % rhs.as_int()).get_string();
}

//bool operators
bool Roman_int::operator==(const Roman_int& rhs) {
    if (value == rhs.get_string()) {return true;}
    return false;
}
bool Roman_int::operator!=(const Roman_int& rhs) {
    if (value != rhs.get_string()) {return true;}
    return false;
}
//-------------------------------------------------------
//helper functions to check validity

const std::vector<char>& valid_symb() {
    static std::vector<char> valid;
    if (valid.size()) {return valid;}   //if valid not empty
    //below code will be run only once at the first instatnce valid_symb() is called
    valid.push_back('I');
    valid.push_back('V');
    valid.push_back('X');
    valid.push_back('L');
    valid.push_back('C');
    valid.push_back('D');
    valid.push_back('M');
    return valid;
}

int symb_value(const char& ch) { //return value of ch
    static std::vector<int>val;
    if (!val.size()) {
    //below code is only once at first instatnce symb_value is called
    val.push_back(1); //I
    val.push_back(5); //V
    val.push_back(10); //X
    val.push_back(50); //L
    val.push_back(100); //C
    val.push_back(500); //D
    val.push_back(1000); //M
    }
    for (int i=0;i<valid_symb().size();i++) {
        if (ch == valid_symb()[i]) {return val[i];}
    }
    std::cerr <<"symb_value: something gone wrong!\n" << ch;
    throw Roman_int::Invalid();
}

bool is_valid_symbols(const std::string& s) { //checks if s consists of valid symbols
    int ok = 0;
    for (int i=0;i<s.size();i++) {
        for (int j=0;j<valid_symb().size();j++) {
            if (s[i] == valid_symb()[j]) {++ok;}
        }
    }
    if (ok == s.size()) {return true;}
    std::cerr << "Valid_symb: false\n";
    return false;
}

bool is_valid_roman(const std::string& s) { //checks if s in correct format, eg xxxxv is wrong
    //...
    return true;
}
//--------------------------------------------------------

//member functions:
Roman_int::Roman_int(std::string s) {
    value = s;
}

Roman_int::Roman_int(int n) {
    //check if in range
    if (n<0 || n>3999) {throw 1;}

    std::string ss;
    //thousands
    int M = n/1000;
    if(M) {
        n %= 1000;
        for (int i=0;i<M;i++) {ss +='M';}
    }
    //hundreds
    int C = n/100;
    if(C) {
        n %= 100;
        switch(C) {
            case 1: case 2: case 3:
                for (int i=0;i<C;i++) {ss += 'C';}
                break;
            case 4:
                ss += "CD";
                break;
            case 5: case 6: case 7: case 8:
                ss += 'D';
                for (int i=0;i<C-5;i++) {ss += 'C';}
                break;
            case 9:
                ss += "CM";
                break;
        }
    }
    //tens
    int X = n/10;
    if(X) {
        n %= 10;
        switch(X) {
            case 1: case 2: case 3:
                for (int i=0;i<X;i++) {ss += 'X';}
                break;
            case 4:
                ss += "XL";
                break;
            case 5: case 6: case 7: case 8:
                ss += 'L';
                for (int i=0;i<X-5;i++) {ss += 'X';}
                break;
            case 9:
                ss += "XC";
                break;
        }
    }
    //ones
    if(n) {
        n %= 10;    //is this necessary?
        switch(n) {
            case 1: case 2: case 3:
                for (int i=0;i<n;i++) {ss += 'I';}
                break;
            case 4:
                ss += "IV";
                break;
            case 5: case 6: case 7: case 8:
                ss += 'V';
                for (int i=0;i<n-5;i++) {ss += 'I';}
                break;
            case 9:
                ss += "IX";
                break;
        }
    }
        value = ss;
}

int Roman_int::as_int() const { //express value as an int
    int val = 0;
    int size = value.size();

    if (size == 1) {return symb_value(value[0]);}
    if (size == 2) {
        if (symb_value(value[1])>symb_value(value[0])) {
            return symb_value(value[1]) - symb_value(value[0]);
        }
        else {
            return symb_value(value[1]) + symb_value(value[0]);
        }
    }

    for (int k=2;k<size;k+=2) {
        if (symb_value(value[k-1])>symb_value(value[k-2])) {
            val += symb_value(value[k-1]) - symb_value(value[k-2]);
        }
        else if (symb_value(value[k])>symb_value(value[k-1])) {
            val += symb_value(value[k-2]) - symb_value(value[k-1]);
        }
        else {
            val += symb_value(value[k-2]) + symb_value(value[k-1]);
        }
    }

    if (size%2==1) {val += symb_value(value[size-1]);}//should be one character left
    else { //should be two characters left
        if (symb_value(value[size-1])>symb_value(value[size-2])) {val += symb_value(value[size-1]) - symb_value(value[size-2]);}
        else {val += symb_value(value[size-2]) + symb_value(value[size-1]);}
    }

    return val;
}

//input/output
std::ostream& operator<<(std::ostream& ost, const Roman_int& r) {
    ost << r.get_string();
    return ost;
}

std::istream& operator>>(std::istream& ist, Roman_int& r) {
    std::string ss;
    char ch;
    bool validsymb;
    while (true) {
        //check if ch is valid
        if (std::isspace(ch)) {break;}
        if (ch=='\n') {break;}
        validsymb = false;
        for (int i=0;i<valid_symb().size();i++) {
            if (ch==valid_symb()[i]) {validsymb = true;}
        }
        if(validsymb) {
            ist >> ch;
            ss += ch;
        }
        else {break;}
    }

    r = Roman_int(ss);  //update r
    return ist;
}

int main()
try {
    Roman_int num1(2);
    std::string s = num1.get_string();
    std::cout << num1 << std::endl;
    Roman_int num2(2);
    std::cout << num2 << std::endl;
    Roman_int num3 = num1 % num2;
    if (num1 == num2) {
        std::cout << "bool works" << std::endl;
    }
    num1 += 3;
    int a = num1.as_int();
    std::cout << a << std::endl;
}
catch(int n) {
    std::cerr << "Error: out of range" << std::endl;
    return 1;
}
