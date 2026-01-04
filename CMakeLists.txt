cmake_minimum_required(VERSION 4.1)
project(backtester)

set(CMAKE_CXX_STANDARD 23)

include_directories(include)

add_executable(backtester
    src/main.cpp
    src/portfolio.cpp
    src/strategy.cpp
        src/strategies/sma2050strategy.cpp
        include/strategies/sma2050strategy.hpp
)
