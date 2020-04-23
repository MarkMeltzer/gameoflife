# which compiler
CC = g++
ARGS = -Wall -Wextra -O2

# define directories
BIN_DIR = bin
SRC_DIR = src
HPP_DIR = headers

# # all: $(SRC_DIR)/gameOfLife.cpp
# 	$(CC) $(ARGS) -o $(BIN_DIR)/gameOfLife $(SRC_DIR)/gameOfLife.cpp

OBJECTS = main.o gameMenu.o gameWorld.o gameOfLife.o randomNumberGenerator.o
all: $(OBJECTS)
	$(CC) $(ARGS) -o $(BIN_DIR)/main $(OBJECTS) && rm *.o

main.o: $(SRC_DIR)/main.cpp
	$(CC) -c $(SRC_DIR)/main.cpp

gameMenu.o: $(SRC_DIR)/gameMenu.cpp $(HPP_DIR)/gameMenu.hpp 
	$(CC) -c $(SRC_DIR)/gameMenu.cpp

gameWorld.o: $(SRC_DIR)/gameWorld.cpp $(HPP_DIR)/gameWorld.hpp 
	$(CC) -c $(SRC_DIR)/gameWorld.cpp

gameOfLife.o: $(SRC_DIR)/gameOfLife.cpp $(HPP_DIR)/gameOfLife.hpp 
	$(CC) -c $(SRC_DIR)/gameOfLife.cpp

randomNumberGenerator.o: $(SRC_DIR)/randomNumberGenerator.cpp $(HPP_DIR)/randomNumberGenerator.hpp 
	$(CC) -c $(SRC_DIR)/randomNumberGenerator.cpp

clean: 
	rm *.o $(BIN_DIR)/main