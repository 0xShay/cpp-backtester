cmake_minimum_required(VERSION 4.1)
project(backtester)

set(CMAKE_CXX_STANDARD 23)

include_directories(include)

add_executable(backtester
    main.cpp
        src/Portfolio.cpp
        src/Strategy.cpp
        src/strategies/SMA2050Strategy.cpp
)
