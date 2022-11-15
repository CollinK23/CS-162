CC=g++ -std=c++11
EXE_FILE=wumpus_run
all: $(EXE_FILE)
$(EXE_FILE): room.o room.h player.o player.h event.o event.h bats.o bats.h pit.o pit.h wumpus.o wumpus.h gold.o gold.h start.o start.h run_wumpus.cpp
	$(CC) room.o player.o event.o bats.o pit.o wumpus.o gold.o start.o run_wumpus.cpp -o $(EXE_FILE)
room.o: room.h room.cpp
	$(CC) -c room.cpp
player.o: player.h player.cpp
	$(CC) -c player.cpp
event.o: event.h event.cpp
	$(CC) -c event.cpp
bats.o: bats.h bats.cpp
	$(CC) -c bats.cpp
pit.o: pit.h pit.cpp
	$(CC) -c pit.cpp
wumpus.o: wumpus.h wumpus.cpp
	$(CC) -c wumpus.cpp
gold.o: gold.h gold.cpp
	$(CC) -c gold.cpp
start.o: start.h start.cpp
	$(CC) -c start.cpp
