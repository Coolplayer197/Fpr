# -*- MakeFile -*-

# Variables
SRCS = $(wildcard *.cpp)

main:
	g++ $(SRCS) -O3 -o main

clean:
	rm main