cmake_minimum_required(VERSION 3.0)
project(CLionProject C)

set(CMAKE_C_STANDARD 99)

add_executable(CLionProject
#        practice/p2-structures.c
#        practice/p4.c
#        practice/p4-v2.c
#        practice/p5.c
#        lab/lab2-2.c
#        lab/lab1.c
#        lab/lab3-1.c
#        lab/lab3-2.c
#        lab/lab4-1.c
#        lab/lab4-2.c
        lab/lab5-1.c
#        lab/lab5-2.c
#        lab/lab6-1.c
#        lab/lab6-2.c
        )

target_link_libraries(CLionProject m)
#add_custom_command(TARGET CLionProject PRE_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy
#        ${CMAKE_SOURCE_DIR}
#        practice/p2.txt
#        $<TARGET_FILE_DIR:CLionProject>)
