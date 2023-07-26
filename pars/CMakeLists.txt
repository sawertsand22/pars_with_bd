cmake_minimum_required(VERSION 3.5)

project(pars LANGUAGES CXX)

find_package(CURL REQUIRED)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14 )
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt5Core)
find_package(Boost 1.40 COMPONENTS program_options REQUIRED)
set(MYSQL_CONNECTOR_CPP_LIBRARIES "/usr/lib/x86_64-linux-gnu/libmysqlcppconn.so")
include_directories(${MYSQL_CONNECTOR_CPP_INCLUDE_DIRS})


add_executable(pars
    main.cpp

    index.html

)
target_link_libraries(pars Qt5::Core)
target_link_libraries(pars CURL::libcurl)
target_link_libraries(pars Boost::program_options)
  target_link_libraries(pars ${MYSQL_CONNECTOR_CPP_LIBRARIES})
