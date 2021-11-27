# Based on code taken from Brigitte, written by Alban Grastien

SRC_DIR = src
OBJ_DIR = obj
SRC_DIRECTORIES = $(shell find $(SRC_DIR) -type d)
CPP_FILES = $(foreach dir,$(SRC_DIRECTORIES),$(wildcard $(dir)/*.cpp))
OBJ_DIRECTORIES = $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SRC_DIRECTORIES))
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(CPP_FILES))

EXE_NAME = silo

OPTIMIZATION_LEVEL=-O3
CONCURRENCY_ARGUMENTS=-pthread

# Use this to disable assertions. "ASSERTION_ARGUMENTS=-DNDEBUG" should work.
ASSERTION_ARGUMENTS=
#ASSERTION_ARGUMENTS=-DNDEBUG

build: $(OBJ)
	g++ -Wall -o $(EXE_NAME) $(OPTIMIZATION_LEVEL) $(ADDITIONAL_ARGUMENTS) $(OBJ) $(CONCURRENCY_ARGUMENTS) $(ASSERTION_ARGUMENTS)

debug: OPTIMIZATION_LEVEL=-Og
debug: ADDITIONAL_ARGUMENTS=-g
debug: build

run:
	./$(EXE_NAME)

all : build run

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/%.hpp
	mkdir -p $(dir $@)
	g++ -Wall -c $< -std=c++11 $(OPTIMIZATION_LEVEL) $(ADDITIONAL_ARGUMENTS) $(CONCURRENCY_ARGUMENTS) $(ASSERTION_ARGUMENTS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	g++ -Wall -c $< -std=c++11 $(OPTIMIZATION_LEVEL) $(ADDITIONAL_ARGUMENTS) $(CONCURRENCY_ARGUMENTS) $(ASSERTION_ARGUMENTS) -o $@

clean:
	rm -f $(OBJ)
	rm -f $(EXE_NAME)

# eof
