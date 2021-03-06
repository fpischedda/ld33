#!/bin/bash

CC="clang"
CFLAGS="-g -std=c++11 -stdlib=libc++"
LDFLAGS="-framework SFML -framework sfml-graphics -framework sfml-window -framework sfml-system -lstdc++ -lpugi -ltmx-loader"

$CC $CFLAGS $LDFLAGS director.cpp scene.cpp main.cpp test_scene.cpp -o app
