#pragma once
#ifndef SOURCE_LOCATION_CURRENT
#  define SOURCE_LOCATION_CURRENT() lite::source_location(__LINE__, 0, __FILE__, __FUNCTION__)
#endif
