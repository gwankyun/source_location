#pragma once

#ifndef NOEXCEPT
#  if __cplusplus >= 201103L
#    define NOEXCEPT noexcept
#  else
#    define NOEXCEPT
#  endif
#endif

#ifndef NULLPTR
#  if __cplusplus >= 201103L
#    define NULLPTR nullptr
#  else
#    define NULLPTR NULL
#  endif
#endif

#ifndef EQ_DELETE
#  if __cplusplus >= 201103L
#    define EQ_DELETE = delete;
#  else
#    define EQ_DELETE
#  endif
#endif

#ifndef EQ_DEFAULT
#  if __cplusplus >= 201103L
#    define EQ_DEFAULT = default
#  else
#    define EQ_DEFAULT {}
#  endif
#endif

#ifndef CONSTEXPR
#  if __cplusplus >= 201103L
#    define CONSTEXPR constexpr
#  else
#    define CONSTEXPR inline
#  endif
#endif

#ifndef CONSTEVAL
#  if defined(__cpp_consteval)
#    define CONSTEVAL consteval
#  else
#    define CONSTEVAL
#  endif
#endif

#ifndef UNIQUE_ID
#  if defined(__COUNTER__) && (__COUNTER__ + 1 == __COUNTER__ + 0)
#    define UNIQUE_ID __COUNTER__
#  else
#    define UNIQUE_ID __LINE__
#  endif
#endif

#ifndef UNIQUE_NAME_CAT
#  define UNIQUE_NAME_CAT(name, unique) name##unique
#endif

#ifndef UNIQUE_VALUE_NAME
#  define UNIQUE_VALUE_NAME(name, unique) UNIQUE_NAME_CAT(name, unique)
#endif
