#include <iostream>
#include <sstream>
#include <stack>
#include <math.h>

//test

int main()
{
    std::stack<long long> args;

    std::string line;
    getline(std::cin, line);

    long long number;
    for(std::istringstream stream(line); stream >> number; ) {
        args.push(number);
    }

    std::cout.setf(std::ios::fixed);
    std::cout.precision(4); // число символов после точки

    while (!args.empty()) {
        std::cout << sqrt(args.top()) << std::endl;
        args.pop();
    }

    return 0;
}


