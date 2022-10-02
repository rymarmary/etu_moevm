cmake_minimum_required(VERSION 3.21)
project(laba1)

set(CMAKE_CXX_STANDARD 17)

add_executable(laba1 cmake-build-debug/main.cpp cmake-build-debug/cell.cpp cmake-build-debug/cell.h cmake-build-debug/field.cpp cmake-build-debug/field.h cmake-build-debug/fieldView.cpp cmake-build-debug/fieldView.h cmake-build-debug/cellView.cpp cmake-build-debug/cellView.h cmake-build-debug/event.h cmake-build-debug/Player.cpp cmake-build-debug/Player.h cmake-build-debug/commandReader.cpp cmake-build-debug/commandReader.h cmake-build-debug/controller.cpp cmake-build-debug/controller.h cmake-build-debug/mediator.cpp cmake-build-debug/mediator.h)
