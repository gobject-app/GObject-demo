cmake_minimum_required(VERSION 3.13)
project(GObject_demo C)

set(CMAKE_C_STANDARD 11)

include_directories(
        /usr/local/Cellar/glib/2.60.3/include/glib-2.0
        /usr/local/Cellar/glib/2.60.3/lib/glib-2.0/include
)


add_executable(GObject_demo main.c)