NAME=Wwipp

CC=gcc
SRC=src/main.c\
		src/libs.c\
		src/gutmann.c\
		src/find.c

OBJ=$(SRC:.c=.o)
CFLAGS=-Wall -Wextra -Werror -I. -c -O3

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJ)
	$(CC) $^ -o $(NAME)

dummy:
	rm -rf dummy
	mkdir -p dummy/lib
	mkdir -p dummy/dev
	mkdir -p dummy/home/dummy/.hidden
	mkdir -p dummy/home/dummy/Downloads
	echo "Some character" > dummy/root_file.txt
	echo "Just to verify skip condition" > dummy/dev/skip_test
	echo "Some binary file" > dummy/lib/special_lib.so
	echo "hkjdhqqgsdhgqsjdgqjdgqshdhsd" > dummy/home/dummy/.hidden/file
	echo "???" > dummy/home/dummy/Downloads/qm
	echo "./.KEMLAKKZELAKEALKDAJDSJQDJSQHDKJSQJDKLQSJDK" > dummy/home/dummy/Downloads/very_special_file
	cp xato-net-10-million-passwords.txt dummy/home/dummy/Downloads/large_file.txt

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf dummy

re: fclean $(NAME)
