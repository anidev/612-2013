cmake_minimum_required(VERSION 2.8)
include(FRCDeploy)

project(612-2013)
find_package(WPILib)
include_directories(${WPILib_INCLUDE_DIRS})

file(GLOB_RECURSE SOURCE_CODE *.cpp)

add_executable(612-2013.out ${SOURCE_CODE})
target_link_libraries(612-2013.out ${WPILib_LIBRARY})

add_make_deploy(my-code 10.6.12.2) # where your team number is xxyy
