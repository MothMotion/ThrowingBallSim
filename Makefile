TARGET=program

SRC_DIR=src
OBJ_DIR=obj
INCLUDE_DIR=include

LIB_DIR=/lib
RAYLIB=raylib

SRC=$(wildcard $(SRC_DIR)/*.cpp)
OBJ=$(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o, $(SRC))

GCC = g++
GCCFLAGS = -Wall -Wextra -I$(INCLUDE_DIR) -L$(LIB_DIR) -l$(RAYLIB)

$(TARGET): $(OBJ)
	$(GCC) $(GCCFLAGS) $^ -o $(TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(GCC) $(GCCFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
