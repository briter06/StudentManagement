# Compiler
CC = gcc

# Compiler flags
INCLUDE_FLAG = -Iinclude

# Directories
SRC_DIR = src
BUILD_DIR = build

# Source files
SRC = $(wildcard $(SRC_DIR)/*.c)

# Object files
OBJ = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Executable
EXEC = myprogram.exe

# Default target
all: $(EXEC)
# all:
# 	echo $(OBJ)

# Link object files to create the executable
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(INCLUDE_FLAG) -c $< -o $@

# Clean target to remove object files and executable
clean:
	rm -f $(BUILD_DIR)/*.o $(EXEC)