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
EXEC = program.exe

# Default target
all: clean setup $(EXEC)

wcompile: wclean setup-windows $(EXEC)

# Setup
setup:
	@mkdir -p $(BUILD_DIR)

setup-windows:
	@mkdir $(BUILD_DIR)

# Link object files to create the executable
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(INCLUDE_FLAG) -c $< -o $@

# Clean target to remove object files and executable
clean:
	rm -f $(BUILD_DIR)/*.o $(EXEC)

# Clean target to remove object files and executable
wclean:
	rmdir /s /q build