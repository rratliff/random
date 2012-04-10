all: coinstreaks coinstreaks-stl

coinstreaks: coinstreaks.cpp
	g++ -Wall -o coinstreaks coinstreaks.cpp -lgsl -lgslcblas

coinstreaks-stl: coinstreaks-stl.cpp
	g++ -std=c++0x -Wall -o coinstreaks-stl coinstreaks-stl.cpp
