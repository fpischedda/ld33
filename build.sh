#!/bin/bash

LDFLAGS="-framework SFML -framework sfml-graphics -framework sfml-window -framework sfml-system -lstdc++"

clang $LDFLAGS director.cpp scene.cpp main.cpp test_scene.cpp -o app
