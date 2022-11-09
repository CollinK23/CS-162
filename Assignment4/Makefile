CC=g++ -std=c++11 -lncurses
EXE_FILE=wumpus_run
all: $(EXE_FILE)
$(EXE_FILE): board.o board.h player.o player.h run_wumpus.cpp
	$(CC) board.o player.o run_wumpus.cpp -o $(EXE_FILE)
board.o: board.h board.cpp
	$(CC) -c board.cpp
player.o: player.h player.cpp
	$(CC) -c player.cpp