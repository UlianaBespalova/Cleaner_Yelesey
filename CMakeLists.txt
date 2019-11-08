cmake_minimum_required(VERSION 3.15)
project(cleaner)

set(CMAKE_CXX_STANDARD 17)

add_executable(project_Cleaner main.cpp cleaner.cpp daemon.cpp)
add_executable(tests_cppunit tests_cppunit.cpp cleaner.cpp daemon.cpp)


include_directories(unit/cppunit/include)

find_library(CPPUNIT_LIB NAMES cppunit cppunitd PATHS /usr/local/lib)
set(CPPUNIT_LIBRARY ${CPPUNIT_LIB})
target_link_libraries(tests_cppunit ${CPPUNIT_LIBRARY})

target_link_libraries(tests_cppunit ${LIBNEW_LIBRARY})