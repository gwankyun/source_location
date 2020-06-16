#include <iostream>
#include "source_location/source_location.hpp"

int main()
{
    auto&& loc = SOURCE_LOCATION_CURRENT();
    std::cout << loc.file_name() << std::endl;
    std::cout << loc.function_name() << std::endl;
    std::cout << loc.line() << std::endl;
    return 0;
}
