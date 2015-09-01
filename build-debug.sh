#!/bin/bash

CC="clang"
CFLAGS="-g -std=c++11 -stdlib=libc++"
LDFLAGS="-framework SFML -framework sfml-graphics -framework sfml-window -framework sfml-system -lstdc++ -lpugi-s-d -ltmx-loader-s-d -lz"
CPP_FILES="director.cpp scene.cpp input_manager.cpp main.cpp test_scene.cpp "

$CC $CFLAGS $LDFLAGS $CPP_FILES -o app
