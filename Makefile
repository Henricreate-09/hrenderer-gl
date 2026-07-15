PROJ_NAME := Game

debug: $(Src/Main.cpp)
	cmake --build ./Build
	./Build/$(PROJ_NAME)

cmake_setup:
	cmake -S . -B ./Build