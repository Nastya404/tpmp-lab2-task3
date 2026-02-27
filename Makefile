# Makefile for TRAIN project
# Author: Yarmolik Anastasia, group 11

CC = gcc
CFLAGS = -Wall -Iinclude

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INC_DIR = include

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/train.c
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/train.o
BIN = $(BIN_DIR)/task3

all: dirs $(BIN)

dirs:
	mkdir -p $(OBJ_DIR) $(BIN_DIR)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c $(INC_DIR)/train.h 
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/train.o: $(SRC_DIR)/train.c $(INC_DIR)/train.h 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(BIN)

check:

distcheck:

.PHONY: all dirs clean check distcheck

