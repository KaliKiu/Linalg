cmake_minimum_required(VERSION 3.16)
project(linalg)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/main.cpp
    src/math/vector.h
)

#set(SFML_DIR "C:/Users/mikas/Desktop/GitHub/sfml")  # <-- Adjust to your SFML path
#find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})

#target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)
