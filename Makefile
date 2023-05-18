SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
CPPFLAGS = -Wall -std=c++11

%.o: %.cpp
	g++ -c -o $@ $< $(CPPFLAGS)

ligas: $(OBJ)
	g++ -o $@ $^

clean:
	rm -rf $(OBJ) ./ligas