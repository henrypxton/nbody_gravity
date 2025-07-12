CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I./src $(shell pkg-config --cflags raylib)
LDFLAGS = $(shell pkg-config --libs raylib) -lm

SRC_DIR = src
BLD_DIR = build
TARGET = $(BLD_DIR)/simulation

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BLD_DIR)/%.o, $(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BLD_DIR)
	$(CC) $^ -o $@ $(LDFLAGS)

$(BLD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BLD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BLD_DIR)

.PHONY: all
