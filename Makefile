PROJECT = utils
CC = gcc
CFLAGS = -g -Wall -Wextra
SRC = src
SRCS = $(wildcard $(SRC)/*.c)
OBJ = obj
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
LIB = lib$(PROJECT).a

test: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(LIB): $(OBJS)
	ar ruv $(LIB) $(OBJS)
	libran $(LIB)

$(OBJ)/%.o: $(SRC)/%.c
	mkdir -p $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@ -I.

clean:
	rm -r $(OBJ)/*

release: CFLAGS = -Wall -Wextra -O2 -DNDEBUG
release: clean
release: $(LIB)

