# which compiler
CC = g++
ARGS = -Wall -Wextra -O2

# define directories
BIN_DIR = bin
SRC_DIR = src

all: $(SRC_DIR)/gameOfLife.cpp
	$(CC) $(ARGS) -o $(BIN_DIR)/gameOfLife $(SRC_DIR)/gameOfLife.cpp