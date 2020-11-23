cmake_minimum_required(VERSION 3.17)
project(project1 C)

set(CMAKE_C_STANDARD 11)

add_executable(project1 main.c mymusic/music.c mymusic/music.h playlist/playlist.c playlist/playlist.h)