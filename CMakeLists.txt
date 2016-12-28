# Created by Hal@shurabaP
# This code is under The BSD 3-Caluse License.
# See more Licence.txt.
cmake_minimum_required(VERSION 3.6)
project(vfont)

include(ExternalProject)

add_subdirectory(util)

add_subdirectory(voicebank)

enable_testing()
