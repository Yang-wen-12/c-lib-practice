cmake_minimum_required(VERSION 3.10)
project(embed)
aux_source_directory(. SRC)
add_executable(app ${SRC})
