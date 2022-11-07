CC=g++ -std=c++11
EXE_FILE=gofish_run
all: $(EXE_FILE)
$(EXE_FILE): card.o card.h deck.o deck.h hand.o hand.h player.o player.h game.o game.h run_gofish.cpp
	$(CC) card.o deck.o hand.o player.o game.o run_gofish.cpp -o $(EXE_FILE)
card.o: card.h card.cpp
	$(CC) -c card.cpp
deck.o: deck.h deck.cpp
	$(CC) -c deck.cpp
hand.o: hand.h hand.cpp
	$(CC) -c hand.cpp
player.o: player.h player.cpp
	$(CC) -c player.cpp
game.o: game.h game.cpp
	$(CC) -c game.cpp