CC = g++
TARGET = WN
INCLUDE = -Iinclude
USRINCLUDE = -I/usr/local/include -I/usr/include
SRC = src
OBJ = obj
BIN = bin
LIB = -L/usr/local/lib -L/usr/lib

CFLAGS = -c -Wall -DDEBUG -std=c++11
LFLAGS = -lSDL2 -lSDL2_image

SRCS = $(wildcard $(SRC)/*.cpp \
		$(SRC)/*.c \
		$(SRC)/Game/*.cpp \
		$(SRC)/Game/*.c)
OBJS = $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))

all: $(BIN)/$(TARGET)
	

$(BIN)/$(TARGET) : $(OBJS)
	$(CC) $^  $(LIB) $(LFLAGS)  -o $@

$(OBJ)/%.o : $(SRC)/%.cpp
	$(CC) $< $(INCLUDE) $(USRINCLUDE) $(CFLAGS) -o $@

$(OBJ)/Game/%.o : $(SRC)/Game/%.cpp
	$(CC) $< $(INCLUDE) $(USRINCLUDE) $(CFLAGS) -o $@

$(OBJ)/%.o : $(SRC)/%.c
	$(CC) $< $(INCLUDE) $(USRINCLUDE) $(CFLAGS) -o $@

$(OBJ)/Game/%.o : $(SRC)/Game/%.c
	$(CC) $< $(INCLUDE) $(USRINCLUDE) $(CFLAGS) -o $@

clear:
	find . -name "*.o" -delete

.PHONY: all clear