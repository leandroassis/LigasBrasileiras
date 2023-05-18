SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
CPPFLAGS = -Wall

%.o: %.cpp
	g++ -c -o $@ $< $(CPPFLAGS)

ligas: $(OBJ)
	g++ -o $@ $^

clean:
	rm -rf $(OBJ) ./ligas