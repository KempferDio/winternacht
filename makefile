CC = g++
TARGET = WN
SRC = src
OBJ = obj
BIN = bin

CFLAGS = -c -Wall -DDEBUG -std=c++11
LFLAGS =  -lSDL2  -lSDL2_image
INCLUDE = include
LIB = -L/usr/local/lib -L/usr/lib

ifeq ($(OS), Windows_NT)
	DELETE = del /S *.o
endif
ifeq ($(OS), Linux)
	DELETE = find . -name "*.o" -delete
endif

ifeq ($(OS), Windows_NT)
	CFLAGS += -D WIN
	LIB = -Llib
	TARGET = WN.exe
endif
ifeq ($(OS), Linux)
	CFLAGS += -D LINUX
	LIB = -L/usr/local/lib -L/usr/lib
	INCLUDE += -I/usr/local/include -I/usr/include
	TARGET = WN
endif

SRCS = $(wildcard $(SRC)/*.cpp \
		$(SRC)/*.c \
		$(SRC)/Game/*.cpp \
		$(SRC)/Game/*.c)

OBJS = $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))

all: $(BIN)/$(TARGET)

compile: $(OBJS)

$(BIN)/$(TARGET) : $(OBJS)
	$(CC) $^ -I$(INCLUDE) $(LFLAGS) $(LIB) -o $@

$(OBJ)/%.o : $(SRC)/%.cpp
	$(CC) $< -I$(INCLUDE) $(LIB) $(CFLAGS) -o $@

$(OBJ)/Game/%.o : $(SRC)/Game/%.cpp
	$(CC) $< -I$(INCLUDE) $(LIB) $(CFLAGS) -o $@

$(OBJ)/%.o : $(SRC)/%.c
	$(CC) $< -I$(INCLUDE) $(LIB) $(CFLAGS) -o $@

$(OBJ)/Game/%.o : $(SRC)/Game/%.c
	$(CC) $< -I$(INCLUDE) $(LIB) $(CFLAGS) -o $@

clear:
	$(DELETE)

.PHONY: all clear compile