cmake_minimum_required(VERSION 3.10)
project(industrial_sensor C)

include_directories(include)

file(GLOB SRC
    src/main.c
    core/linklist.c
    io/fileio.c
    encrypt/crypto.c
    log/logger.c
)

add_executable(sensor_master ${SRC})
