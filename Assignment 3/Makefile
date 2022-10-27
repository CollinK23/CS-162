CC=g++ -std=c++11
EXE_FILE=gofish_run
all: $(EXE_FILE)
$(EXE_FILE): gofish.o gofish.h run_gofish.cpp
	$(CC) gofish.o run_gofish.cpp -o $(EXE_FILE)
gofish.o: gofish.h gofish.cpp
	$(CC) -c gofish.cpp