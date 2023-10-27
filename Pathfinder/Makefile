NAME = pathfinder
CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

SRC_DIR  = src
INC_DIR  = inc
OBJ_DIR  = obj

INC_FILES = $(wildcard $(INC_DIR)/*.h)
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

LIB_DIR  = libmx
LIB_NAME:=  $(LIB_DIR)/libmx.a
LIB_INC:= $(LIB_DIR)/inc

.PHONY: all clean uninstall reinstall

all: $(LIB_NAME) $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -L$(LIB_DIR) -lmx -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIB_INC) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_FILES): | $(OBJ_DIR)

$(LIB_NAME):
	@make -sC $(LIB_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -sC $(LIB_DIR)

uninstall: clean
	@make -sC $(LIB_DIR) $@
	@rm -rf $(NAME)

reinstall: uninstall all