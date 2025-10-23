cmake_minimum_required(VERSION 3.16)

project(Physis_Test)

add_executable(${PROJECT_NAME} main.cpp Vector3Test.cpp)

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_BINARY_DIR}/Tests/Physis)
