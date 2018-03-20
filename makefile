CC = g++
TARGET = WN
SRC = src
OBJ = obj
BIN = bin

CFLAGS = -c -Wall -DDEBUG -std=c++11
LFLAGS = -lSDL2 -lSDL2main -lSDL2_image
INCLUDE = include -I/usr/local/include -I/usr/include
LIB = -L/usr/local/lib -L/usr/lib


SRCS = $(wildcard $(SRC)/*.cpp \
		$(SRC)/*.c \
		$(SRC)/Game/*.cpp \
		$(SRC)/Game/*.c)

OBJS = $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))

all: $(BIN)/$(TARGET)

compile: $(OBJS)

$(BIN)/$(TARGET) : $(OBJS)
	$(CC) $^ $(LIB) $(LFLAGS)  -o $@

$(OBJ)/%.o : $(SRC)/%.cpp
	$(CC) $< -I$(INCLUDE) $(CFLAGS) -o $@

$(OBJ)/Game/%.o : $(SRC)/Game/%.cpp
	$(CC) $< -I$(INCLUDE) $(CFLAGS) -o $@

$(OBJ)/%.o : $(SRC)/%.c
	$(CC) $< -I$(INCLUDE) $(CFLAGS) -o $@

$(OBJ)/Game/%.o : $(SRC)/Game/%.c
	$(CC) $< -I$(INCLUDE) $(CFLAGS) -o $@

clear:
	find . -name "*.o" -delete

.PHONY: all clear compile