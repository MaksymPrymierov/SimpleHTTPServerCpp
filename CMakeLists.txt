cmake_minimum_required(VERSION 3.25)
project(SimpleHTTPServerCpp)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(SimpleHTTPServerCpp
        src/main.cpp
        include/HTTPServer.h src/HTTPServer.cpp include/HTTPClient.h src/HTTPClient.cpp)

target_include_directories(SimpleHTTPServerCpp PUBLIC ./include)

if(MINGW)
    target_link_libraries(SimpleHTTPServerCpp
            PUBLIC
            ${CONAN_LIBS}
            ws2_32)
endif()

if(UNIX)
    target_link_libraries(SimpleHTTPServerCpp
            PUBLIC
            ${CONAN_LIBS})
endif()

