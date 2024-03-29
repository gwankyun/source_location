#pragma once
#include <string>
#include "source_location/common.h"
#include "source_location/marco.h"

namespace lite
{
#ifdef _WIN32
    typedef unsigned __int32 uint_least32_t;
#else
    typedef unsigned int uint_least32_t;
#endif

    struct source_location
    {
        //static CONSTEVAL source_location current() NOEXCEPT;

        ~source_location() {}

        source_location(const source_location& other)
        {
            m_line = other.line();
            m_column = other.column();
            m_file_name = other.file_name();
            m_function_name = other.function_name();
        }

        source_location(
            uint_least32_t line, 
            uint_least32_t column, 
            std::string file_name,
            std::string function_name
        ) NOEXCEPT
            : m_line(line)
            , m_column(column)
            , m_file_name(file_name)
            , m_function_name(function_name)
        {
        }

        source_location() NOEXCEPT
            : m_line(0)
            , m_column(0)
            , m_file_name("")
            , m_function_name("")
        {
        }

        CONSTEXPR uint_least32_t line() const NOEXCEPT
        {
            return m_line;
        }

        CONSTEXPR uint_least32_t column() const NOEXCEPT
        {
            return m_column;
        }

        const char* file_name() const NOEXCEPT
        {
            return m_file_name.c_str();
        }

        const char* function_name() const NOEXCEPT
        {
            return m_function_name.c_str();
        }

    private:
        uint_least32_t m_line;
        uint_least32_t m_column;
        std::string m_file_name;
        std::string m_function_name;
    };
}
