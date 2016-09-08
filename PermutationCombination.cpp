#include <iostream>

/*
*enter two numbers and select between permutation or combination*
switch
error handling
*/

int permORcomb(int a, int b, char mode) {
    int ans = factorial(a)/factorial(a-b);
    switch (mode) {
        case 'p':
            break;
         case 'c':
            ans = ans/factorial(b);
            break;
         default:
            double q;
            throw q;
    }
    return ans;
}


int main()
try {
    std::cout << "Enter two intergers and choose between permutation and combination (p/c)" << std::endl;
    int a, b;
    char mode;
    std::cin >> a >> b >> mode;
    if (b>a) {throw 'c';}
    int ans = permORcomb(a, b, mode);
    std::cout << factorial(a) << "  " << factorial(b) << std::endl;
    std::cout << "Result = " << ans << std::endl;
}

catch (int a) {
    std::cerr << "Error: Factorial of " << a << " is not valid." <<std::endl;
    return 1;
}
catch (char c) {
    std::cerr << "Error: enter the larger number first." << std::endl;
    return 2;
}
catch (double q) {
    std::cerr << "Error: The options are p and c !" << std::endl;
}
