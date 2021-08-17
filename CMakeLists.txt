# cmake最低版本
cmake_minimum_required(VERSION 3.21)

option(ENABLE_SOURCE_LOCATION_TEST "" OFF)
option(USE_SOURCE_LOCATION_MODULE "" ON)

# 啟用IDE目錄功能
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# 包括模板
include(CMakePrintHelpers)
include(CMakePackageConfigHelpers)

# 輸出目錄
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# 項目名
project(source_location)

set(CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH}
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(common)

add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/W4;/MP;/Zc:__cplusplus;/std:c++latest;/std:c17;/experimental:module;>")

set(target source_location)

add_library(${target} INTERFACE)

include(GNUInstallDirs)

install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/lite" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

target_include_directories(${target}
  INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

target_sources(${target}
  INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/lite/source_location.cppm>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/lite/source_location.cppm>"
)

target_compile_definitions(${target}
  INTERFACE
    USE_SOURCE_LOCATION_MODULE=$<BOOL:${USE_SOURCE_LOCATION_MODULE}>)

target_install(${target} "0.0.1")

if(ENABLE_SOURCE_LOCATION_TEST)
  set(main main)
  add_executable(${main})
  target_sources(${main}
    PRIVATE
      src/main.cppm
      src/main.cpp
      include/lite/source_location.cppm
      include/lite/source_location.hpp
      include/lite/source_location/common.h
      include/lite/source_location/marco.h
  )
  target_link_libraries(${main} PUBLIC source_location)
  target_include_directories(${main} PRIVATE include)

  # 設置C++標準
  target_compile_features(${main} PRIVATE cxx_std_20)

  # 設置宏
  # target_compile_definitions(${main} PRIVATE USE_SOURCE_LOCATION_MODULE=$<BOOL:${USE_SOURCE_LOCATION_MODULE}>)
endif()
