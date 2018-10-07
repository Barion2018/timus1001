#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <sstream>

#include <math.h>

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

int main(int argc, char *argv[])
{
        std::string line;

        std::vector<std::string> ip_clean;
        while (getline(std::cin, line))
        {
            std::vector<std::string> v = split(line, ' ');
            for(std::string str: v){
                if(str == "") continue;
                ip_clean.push_back(str);
            }

        }

        std::stack<long long> args;
        long long number;
        for(std::string str: ip_clean){
            std::istringstream stream(str);
            stream >> number;
            //number = std::stoi(str, nullptr, 0); // РґР»СЏ long long  -С…СЂРµРЅСЊ! РїРѕСЌС‚РѕРјСѓ С‡РµСЂРµР· stream
            args.push(number);
        }

        std::cout.setf(std::ios::fixed);
        std::cout.precision(4); // С‡РёСЃР»Рѕ СЃРёРјРІРѕР»РѕРІ РїРѕСЃР»Рµ С‚РѕС‡РєРё

        while (!args.empty()) {
            std::cout << sqrt(args.top()) << std::endl;
            args.pop();
        }

    return 0;
}
