CXX = g++
CXXFLAGS	= -std=c++17 -Wall

all: TicTacToe

clean:
	rm TicTacToe.o main

TicTacToe:
	$(CXX) $(CXXFLAGS) TicTacToe.cpp  -o main