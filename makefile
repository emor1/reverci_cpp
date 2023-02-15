CC=g++

Game: main.cpp Reversi.cpp SimpleShape.cpp
	$(CC) -o game main.cpp Reversi.cpp SimpleShape.cpp `sdl2-config --cflags --libs`

clean:
	rm -f game