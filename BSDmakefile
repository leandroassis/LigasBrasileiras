CPPFLAGS = -Wall -std=c++11 -D_GLIBCXX_USE_C99 -D_GLIBCXX_USE_C99_MATH -D_GLIBCXX_USE_C99_MATH_TR1

all: ligas

src/Ano.o: src/Ano.cpp
	g++ -c -o $@ $< $(CPPFLAGS)

src/Time.o: src/Time.cpp
	g++ -c -o $@ $< $(CPPFLAGS)

src/Liga.o: src/Liga.cpp
	g++ -c -o $@ $< $(CPPFLAGS)

src/menu.o: src/menu.cpp
	g++ -c -o $@ $< $(CPPFLAGS)

src/main.o: src/main.cpp
	g++ -c -o $@ $< $(CPPFLAGS)

ligas: src/main.o src/menu.o src/Liga.o src/Time.o src/Ano.o
	g++ -o $@ src/*.o

clean:
	rm -rf src/*.o ./ligas
