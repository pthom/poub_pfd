cmake_minimum_required(VERSION 3.20)
project(mutex_issue)
add_compile_definitions(_DISABLE_CONSTEXPR_MUTEX_CONSTRUCTOR)
add_executable(main main.cpp)
