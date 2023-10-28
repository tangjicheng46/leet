#include <iostream>
#include <boost/algorithm/string.hpp>

int main() {
    std::string str = "Hello, Boost Library!";

    boost::to_upper(str);

    std::cout << "Uppercase string: " << str << std::endl;

    return 0;
}
