# -*- MakeFile -*-

# Variables
CXXFLAGS = -std=c++20 -O3
SRCS = $(wildcard *.cpp)

main:
	g++ $(SRCS) -std=c++20 -O3 -o main.exe