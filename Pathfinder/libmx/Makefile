CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
INC_DIR = -Iinc
INC = $(wildcard inc/*.h)
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c,obj/%.o,$(SRC))
LIB_NAME = libmx.a
NAME = LIBMX

.PHONY: all clean uninstall reinstall

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(LIB_NAME) $^

obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) $(INC_DIR) -o $@ -c $<

clean:
	rm -rf obj

uninstall: clean
	rm -rf $(LIB_NAME)

reinstall: uninstall all
