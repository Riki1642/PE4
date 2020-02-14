CXX = g++
CXXFLAGS	= -std=c++17 -Wall

all: TicTacToe

clean:
	rm main

TicTacToe:
	$(CXX) $(CXXFLAGS) TicTacToe.cpp  -o main