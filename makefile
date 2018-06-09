#source: https://stackoverflow.com/questions/9787160/makefile-that-compiles-all-cpp-files-in-a-directory-into-separate-executable
CXX= g++ -std=c++11
CXXFLAGS = -g -Wall

all: $(patsubst %.cpp, %.out, $(wildcard *.cpp))

%.out: %.cpp makefile
	$(CXX) $(CXXFLAGS) $< -o $@ 

clean:
	rm *.out
