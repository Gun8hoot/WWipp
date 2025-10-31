# :==================:
# |		VARIABLE	 |
# :==================:

NAME=WIPER

CC=gcc
SRC=main.c src/libs.c src/converter.c src/gutmann.c src/find.c
OBJECT_DIR=obj
OBJECT_FILE=$(SRC:.c=.o)
CFLAGS=-I. -c 

$(OBJECT_DIR)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) $@ -o $<

$(NAME): $(OBJECT)
	echo $< " SPACE " $@
#	$(CC) $< -o $(NAME)


all: $(NAME)

rm:
	rm -f WIPER