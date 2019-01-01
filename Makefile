game: code.c
	gcc -Wall -Werror -ggdb code.c -o game
clean:
	rm -f game
