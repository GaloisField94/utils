PROJECT = utils
CC = gcc
CFLAGS = -g -Wall -Wextra
SRC = src
SRCS = $(wildcard $(SRC)/*.c)
OBJ = obj
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
LIB = lib$(PROJECT).a

test_bin: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@.out

lib: $(OBJS)
	ar rcs $(LIB) $(OBJS)

$(OBJ)/%.o: $(SRC)/%.c
	mkdir -p $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@ -I.

clean:
	rm -r $(OBJ)/*

release: CFLAGS = -Wall -Wextra -O2 -DNDEBUG
release: clean
release: $(LIB)

