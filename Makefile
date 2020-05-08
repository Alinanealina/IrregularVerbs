CC = gcc
LDLIBS = -lncurses 
CFLAGS = -Wall -Werror -c -MP -MMD -std=c99
FLAGS = -Wall -Werror -std=c99 
SRC = src/


BUILD = build/
OBJECTS = $(BUILD)k.o   $(BUILD)main.o 

BIN = bin/
EXE = $(BIN)main

.PHONY: all default clean
all: bin build default run
default: $(EXE)

$(EXE): $(OBJECTS)
	$(CC) $(FLAGS)  $(OBJECTS) -o $@ $(LDLIBS)
$(BUILD)main.o: $(SRC)main.c $(SRC)k.h 
	$(CC) $(CFLAGS) $(SRC)main.c -o $@
$(BUILD)k.o: $(SRC)k.c $(SRC)k.h  
	$(CC) $(CFLAGS) $(SRC)k.c -o $@
bin:
	mkdir bin 
build:
	mkdir build
run:
	./bin/main verbs.txt
clean:
	rm   build/*.o build/*.d bin/main  