CXXFLAGS:= -g -Wall
CXX:= g++
INCLUDES:= -I include/

CLI: main.cc
	$(CXX) $(CXXFLAGS) build/main.o build/command.o -o CLI

main.cc: command.cc
	$(CXX) $(CXXFLAGS) -c src/main.cc -o build/main.o

command.cc:
	$(CXX) $(CXXFLAGS) -c src/command.cc $(INCLUDES) -o build/command.o
	
clean:
	rm -f build/*
	rm -f CLI