# cmake最低版本
cmake_minimum_required(VERSION 3.17)

# 啟用IDE目錄功能
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# 包括模板
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/CMake)
include(CMakePrintHelpers)

# 輸出目錄
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# 項目名
set(project source_location)
project(${project})

if(${MSVC})
    add_compile_options(/W4 /MP)
endif()

# 生成執行文件
add_executable(${project} "")

target_sources(${project} 
    PRIVATE
        src/main.cpp
)

# 頭文件目錄
target_include_directories(${project}
    PRIVATE
        include
)
