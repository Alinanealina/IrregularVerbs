CC = gcc
LDLIBS = -lncurses 
CFLAGS = -Wall -Werror -c -MP -MMD -std=c99
FLAGS = -Wall -Werror -std=c99 

SRC = src/
BUILD = build/
DIRT=buildt/
OBJECTS = $(BUILD)points.o   $(BUILD)main.o 
OBJECTS_TEST = $(DIRT)points.o   $(DIRT)main_test.o 

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
$(BUILD)main.o: $(SRC)main.c $(SRC)points.h 
	$(CC) $(CFLAGS) $(SRC)main.c -o $@
$(BUILD)points.o: $(SRC)points.c $(SRC)points.h  
	$(CC) $(CFLAGS) $(SRC)points.c -o $@
$(TEST): $(OBJECTS_TEST)
	$(CC) $(FLAGS) $(OBJECTS_TEST) -o $@ $(LDLIBS)
$(DIRT)main_test.o: test/main.c thirdparty/ctest.h   
	$(CC) $(CFLAGS) -I thirdparty -I src -c test/main.c -o $@
$(DIRT)points.o: $(SRC)points.c $(SRC)points.h  
	$(CC) $(CFLAGS) $(SRC)points.c -o $@

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