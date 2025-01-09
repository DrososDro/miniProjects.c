# Directories
SRC_DIR = source
OBJ_DIR = build
BIN_DIR = build

# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Find all source files in src/ and its subdirectories
SRC_FILES = $(shell find $(SRC_DIR) -name '*.c')

# Convert source files to object files
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Define output executable name
TARGET = $(BIN_DIR)/my_program

# Default target to build everything
all: $(TARGET)

# Rule to build the final executable
$(TARGET): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(TARGET)

# Rule to build object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/$(dir $*)  # Ensure the object directory structure matches
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the build directories
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Run the program
run: $(TARGET)
	$(TARGET)
#
# # Phony targets (not actual files)
# .PHONY: all clean run

