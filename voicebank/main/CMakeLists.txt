# Created by Hal@shurabaP
# This code is under The BSD 3-Caluse License.
# See more Licence.txt.
cmake_minimum_required(VERSION 3.1)
project(haruneko_voicebank)

# configuration for Qt
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

# cmake options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

# dependency
find_package(Qt5Core)
include_directories(".")

# sources
add_library(haruneko_voicebank values/Segment.cpp values/Segment.h values/json/SegmentJson.h values/Pronounce.cpp values/Pronounce.h values/Mapping.cpp values/Mapping.h values/json/SegmentJson.cpp values/Range.cpp values/Range.h values/Meta.cpp values/Meta.h values/Voicebank.cpp values/Voicebank.h)
add_dependencies(haruneko_voicebank haruneko_util)

target_link_libraries(haruneko_voicebank Qt5::Core haruneko_util)

target_include_directories(haruneko_voicebank PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
