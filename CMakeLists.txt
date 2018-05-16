cmake_minimum_required(VERSION 3.9)
project(Tiger_Game)

set(CMAKE_CXX_STANDARD 11)

add_executable(Tiger_Game
        main.cpp
        Alphabet.h
        Circle.h
        Confetti.h
        Draw.h
        Global.h
        Men.h
        Plot.h
        Point.h
        SDL_Plotter.h
        Tiger.h)
target_link_libraries(Tiger_Game
        /Library/Frameworks/SDL2_mixer.framework
        /Library/Frameworks/SDL2.framework)