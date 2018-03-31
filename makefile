CC = g++
TARGET = WN
SRC = src
OBJ = obj
BIN = bin

CFLAGS = -c -Wall -DDEBUG -std=c++11
LFLAGS =  -lSDL2  -lSDL2_image
INCLUDE = include
LIB = -L/usr/local/lib -L/usr/lib
DELETE = find . -name "*.o" -delete

ifeq ($(OS), Windows_NT)
	DELETE = del /S *.o
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

SRCS = $(wildcard $(SRC)/*.cpp)
SRCS += $(wildcard $(SRC)/Game/*.cpp)
SRCS += $(wildcard $(SRC)/Input/*.cpp)
SRCS += $(wildcard $(SRC)/Input/Commands/*.cpp)
SRCS += $(wildcard $(SRC)/GameObjects/*.cpp)



OBJS = $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))

all: $(BIN)/$(TARGET)

compile: $(OBJS)

$(BIN)/$(TARGET) : $(OBJS)
	$(CC) $^ -I$(INCLUDE) $(LFLAGS) $(LIB) -o $@

#Base src folder
$(OBJ)/%.o : $(SRC)/%.cpp
	$(CC) $< -I$(INCLUDE) $(CFLAGS) -o $@

$(OBJ)/%.o : $(SRC)/%.c
	$(CC) $< -I$(INCLUDE) $(CFLAGS) -o $@

#Game folder
$(OBJ)/%.o : $(SRC)/Game/%.cpp
	$(CC) $< -I$(INCLUDE) $(CFLAGS) -o $@

$(OBJ)/%.o : $(SRC)/Game/%.c
	$(CC) $< -I$(INCLUDE) $(CFLAGS) -o $@

#Input folder
$(OBJ)/%.o : $(SRC)/Input/%.cpp
	$(CC) $< -I$(INCLUDE) $(CFLAGS) -o $@

$(OBJ)/%.o : $(SRC)/Input/%.c
	$(CC) $< -I$(INCLUDE) $(CFLAGS) -o $@

#Input/Commands folder
$(OBJ)/%.o : $(SRC)/Input/Commands/%.cpp
	$(CC) $< -I$(INCLUDE) $(CFLAGS) -o $@

$(OBJ)/%.o : $(SRC)/Input/Commands/%.c
	$(CC) $< -I$(INCLUDE) $(CFLAGS) -o $@

#GameObjects
$(OBJ)/%.o : $(SRC)/GameObjects/%.cpp
	$(CC) $< -I$(INCLUDE) $(CFLAGS) -o $@

$(OBJ)/%.o : $(SRC)/GameObjects/%.c
	$(CC) $< -I$(INCLUDE) $(CFLAGS) -o $@

clear:
	$(DELETE)

show_files: 
	@echo $(SRCS)

.PHONY: all clear compile show_files