CC = gcc

CFLAGS = -Wall -Werror -c -MP -MMD -std=c99
FLAGS= -Wall -Werror -std=c99

SRC=src/


BUILD = build/
OBJECTS = $(BUILD)printb.o  $(BUILD)console.o $(BUILD)main.o 

BIN = bin/
EXE = $(BIN)main

.PHONY: all default clean
all: bin build default run
default: $(EXE)

$(EXE): $(OBJECTS)
	$(CC) $(FLAGS)  $(OBJECTS) -o $@ 
$(BUILD)main.o:  $(SRC)main.c   $(SRC)console.h  
	$(CC) $(CFLAGS) $(SRC)main.c -o $@
$(BUILD)printb.o: $(SRC)printb.c $(SRC)printb.h  
	$(CC) $(CFLAGS) $(SRC)printb.c -o $@
$(BUILD)console.o:  $(SRC)printb.h $(SRC)console.c   $(SRC)console.h  
	$(CC) $(CFLAGS) $(SRC)console.c -o $@
bin:
	mkdir bin 
build:
	mkdir build
run:
	./bin/main pole.txt
clean:
	rm   build/*.o build/*.d bin/main  
