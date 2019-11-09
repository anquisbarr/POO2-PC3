cmake_minimum_required(VERSION 3.15)
project(PC3)

set(CMAKE_CXX_STANDARD 17)

add_executable(PC3 main.cpp Repo.h deserializador.h serializador.h serializadorCountry.h deserializadorCountry.h Country.h)