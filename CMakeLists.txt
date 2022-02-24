cmake_minimum_required (VERSION 3.6)
project(GaryBotV2)

add_executable(GaryBotV2 src/main.cpp src/Token.cpp src/Constants.cpp)

add_subdirectory(deps/sleepy-discord)
target_link_libraries(GaryBotV2 sleepy-discord)