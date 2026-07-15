PROJ_NAME := Game

debug: $(Src/Main.cpp)
	cmake --build ./Build
	./Build/$(PROJ_NAME)

cmake_setup:
	cmake -S . -B ./Build

cmake_setup_ninja:
	cmake -S . -B ./Build -G ninja
	