
cmake_minimum_required(VERSION 3.17)
project(EnglishSpeaker VERSION 1.0.0 LANGUAGES C CXX)

file(GLOB_RECURSE  header_files  ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h )
source_group("Header Files" FILES  ${header_files}) # step 1 to add a fliter named "Header Files" 

include_directories(EnglishSpeaker PRIVATE ./include )

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug) # or Release

add_executable(${PROJECT_NAME} ./src/main.cpp ./src/Speaker.cpp ${header_files} ) # step 2 to add a fliter named "Header Files" 


