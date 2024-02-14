# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(MyCProject C)

set(SOURCE_FILES
    src/main.c
    src/hash.c
    src/miller-rabin-test.c
    src/linked-list.c
)

# Set the executable name and the source files
add_executable(my_executable ${SOURCE_FILES})

# Specify the C standard
set_property(TARGET my_executable PROPERTY C_STANDARD 11)

