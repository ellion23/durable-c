cmake_minimum_required(VERSION 3.0)
project(CLionProject C)

set(CMAKE_C_STANDARD 99)

add_executable(CLionProject
#        practice/p2-structures.c
#        practice/p4.c
        practice/p4-v2.c
        )

target_link_libraries(CLionProject m)
add_custom_command(TARGET CLionProject PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}
#        practice/p2.txt
        $<TARGET_FILE_DIR:CLionProject>)
