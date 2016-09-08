#include <iostream>
/*
switch
error handling
*/

double celkel(double t, char unit) {
    double tconv;
    switch(unit) {
        case 'c':
            if (t < -273.15) {throw 20;}
            tconv = t + 273.15;
            break;
        case 'k':
            if (t < 0) {throw 21;}
            tconv = t - 273.15;
            break;
        default:
            throw unit;
            break;
    }
    return tconv;
}

int main()
try {
   std::cout << "Enter temperature and unit (c/k)" << std::endl;
   double t;
   char unit;
   std::cin >> t;
   std::cin >> unit;
   double tconv = celkel(t, unit);
   std::cout << "converted temp is = " << tconv << std::endl;
}

catch (int error) {
    std::cerr << "Error: Absolute zero is at -273.15 celsius or 0 kelvin" << std::endl;
    return 1;
}
catch (char unit) {
    std::cerr << "Error: I don't know about the unit " << unit << std::endl;
    return 2;
}
