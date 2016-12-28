# Created by Hal@shurabaP
# This code is under The BSD 3-Caluse License.
# See more Licence.txt.
cmake_minimum_required(VERSION 3.1)
project(haruneko_voicebank_test)

# configuration for Qt
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

# cmake options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

# dependency
find_package(Qt5Test)
get_target_property(QtTest_location Qt5::Test LOCATION)
include_directories("." "../main" "../../util/main")

# include main sources.
add_executable(haruneko_voicebank_test test_main.cpp MultipleTest.h MultipleTest.cpp values/json/SegmentJsonSpec.h ../main/values/json/PrononuceJson.cpp ../main/values/json/PrononuceJson.h)

target_link_libraries(haruneko_voicebank_test
    PRIVATE
    haruneko_voicebank
    haruneko_util
    Qt5::Test
    gmock
)
