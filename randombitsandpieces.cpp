#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>


/*
*character classification*
*useful for tokenizing*
isspace(ch) //return true if ch is a whitespace
isdigit(ch) //return true if ch is a number
isalpha(ch) //return true if ch is an identifier (eg. if, case, const)
*/


/*using bases other than decimal*/
/*
int main() {
  int a;
  int b;
  int c;
  int d;
  std::cin >> a >> std::hex >> b >> std::oct >> c >> d;
  std::cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';
  //if you type 1234 4d2 2322 2322 this will print 1234 1234 1234 1234
}
*/




/*
*get user input, store in a vector, and sum number of inputs*
fstreams
error handling
*/
/*
int main()
try {
    std::cout << "Please enter some numbers (press '|' to stop):" << std::endl;
    std::vector<int>userinput;
    int temp;
    while (std::cin >> temp) {
        userinput.push_back(temp);
    }
    std::cout << "Please enter how many of the numbers you wish to sum, starting from the first:" << std::endl;
    std::cin.clear();
    std::cin.ignore(5, '\n'); //after the first cin, cin will keep an empty line in its buffer and use that as an input for the next cin (so N below will turn out to be 0), .ignore flushes '\n';
    int N;
    std::cin >> N;
    if (N >= userinput.size()) {throw 1;}

    int sum = 0;
    for (int i=0;i<N;i++) {
        sum += userinput[i];
    }
    std::cout << "The sum of the first " << N << " numbers is " << sum << std::endl;
    return 0;
}
*/
