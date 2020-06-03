CC = gcc
LDLIBS = -lncurses 
CFLAGS = -Wall -Werror -c -MP -MMD -std=c99
FLAGS = -Wall -Werror -std=c99 

SRC = src/
BUILD = build/
DIRT=buildt/
OBJECTS = $(BUILD)k.o   $(BUILD)main.o 
OBJECTS_TEST = $(DIRT)k.o   $(DIRT)main_test.o 

BIN = bin/
EXE = $(BIN)main
TEST = $(BIN)main_test

.PHONY: all default clean test 
all: bin build buildt default test
default: $(EXE) 
test: $(TEST)
	$(TEST)
$(EXE): $(OBJECTS)
	$(CC) $(FLAGS)  $(OBJECTS) -o $@ $(LDLIBS)
$(BUILD)main.o: $(SRC)main.c $(SRC)k.h 
	$(CC) $(CFLAGS) $(SRC)main.c -o $@
$(BUILD)k.o: $(SRC)k.c $(SRC)k.h  
	$(CC) $(CFLAGS) $(SRC)k.c -o $@
$(TEST): $(OBJECTS_TEST)
	$(CC) $(FLAGS) $(OBJECTS_TEST) -o $@ $(LDLIBS)
$(DIRT)main_test.o: test/main.c thirdparty/ctest.h   
	$(CC) $(CFLAGS) -I thirdparty -I src -c test/main.c -o $@
$(DIRT)k.o: $(SRC)k.c $(SRC)k.h  
	$(CC) $(CFLAGS) $(SRC)k.c -o $@

bin:
	mkdir bin 
build:
	mkdir build
buildt:
	mkdir buildt	
run:
	./bin/main verbs.txt
clean:
	rm -rf build buildt bin/main  