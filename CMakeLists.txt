# cmake最低版本
cmake_minimum_required(VERSION 3.20)

# 啟用IDE目錄功能
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# 包括模板
include(CMakePrintHelpers)

# 輸出目錄
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# 項目名
project(source_location)

set(target source_location)

add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/W4;/MP;/Zc:__cplusplus;/std:c17;>")

add_library(${target} INTERFACE)

set_target_properties(${target} PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR};${CMAKE_CURRENT_SOURCE_DIR}/include>;$<INSTALL_INTERFACE:include>"
)

# install the target and create export-set
install(TARGETS ${target}
        EXPORT ${target}Targets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include
)

# install header file
install(FILES include/lite/source_location.hpp DESTINATION include/lite)

# generate and install export file
install(EXPORT ${target}Targets
        FILE ${target}Targets.cmake
        NAMESPACE ${target}::
        DESTINATION lib/cmake/${target}
)

# include CMakePackageConfigHelpers macro
include(CMakePackageConfigHelpers)

# set version
set(version 0.0.1)

set_property(TARGET ${target} PROPERTY VERSION ${version})
set_property(TARGET ${target} PROPERTY SOVERSION 0)
set_property(TARGET ${target} PROPERTY
  INTERFACE_${target}_MAJOR_VERSION 0)
set_property(TARGET ${target} APPEND PROPERTY
  COMPATIBLE_INTERFACE_STRING ${target}_MAJOR_VERSION
)

# generate the version file for the config file
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/${target}ConfigVersion.cmake"
  VERSION "${version}"
  COMPATIBILITY AnyNewerVersion
)

# create config file
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/${target}Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/${target}Config.cmake"
  INSTALL_DESTINATION lib/cmake/${target}
)

# install config files
install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/${target}Config.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/${target}ConfigVersion.cmake"
  DESTINATION lib/cmake/${target}
)

# generate the export targets for the build tree
export(EXPORT ${target}Targets
  FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/${target}Targets.cmake"
  NAMESPACE ${target}::
)

set(main main)
add_executable(${main})
target_sources(${main}
  PRIVATE
    src/main.cpp
    include/lite/source_location.hpp
)
target_link_libraries(${main} PUBLIC source_location)
target_include_directories(${main} PRIVATE include)
target_compile_features(${main} PRIVATE cxx_std_17)
