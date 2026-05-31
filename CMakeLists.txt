cmake_minimum_required(VERSION 3.10)
project(youtube-downloader-tool)

set(CMAKE_CXX_STANDARD 17)

find_package(CURL REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Threads REQUIRED)

add_executable(youtube-downloader-tool
    src/main.cpp
    src/downloader.cpp
    src/utils.cpp
)

target_link_libraries(youtube-downloader-tool
    PRIVATE
    CURL::libcurl
    OpenSSL::SSL
    Threads::Threads
)