CC = gcc
CFLAGS = -Wall -Iinclude
OBJ_DIR = obj
BIN_DIR = bin
SRC_DIR = src

OBJS = $(OBJ_DIR)/myshell.o $(OBJ_DIR)/cat_command.o $(OBJ_DIR)/exec_command.o

myshell: $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/myshell $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/myshell

