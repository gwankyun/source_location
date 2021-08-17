module;
#ifndef USE_SOURCE_LOCATION_MODULE
#  if defined(__cpp_modules)
#    define USE_SOURCE_LOCATION_MODULE 1
#  else
#    define USE_SOURCE_LOCATION_MODULE 0
#  endif
#endif

#if USE_SOURCE_LOCATION_MODULE
#  include <lite/source_location/marco.h>
#else
#  include <iostream>
#  include <lite/source_location.hpp>
#endif
module main;

#if USE_SOURCE_LOCATION_MODULE
import std.core;
import lite.source_location;
#endif

int main()
{
    auto loc(SOURCE_LOCATION_CURRENT());
    std::cout << loc.file_name() << std::endl;
    std::cout << loc.function_name() << std::endl;
    std::cout << loc.line() << std::endl;
    return 0;
}
