all: pin word
pin: pin.c tool.c
	gcc -o pin -g pin.c tool.c
word: word.c tool.c
	gcc -o word -g word.c tool.c
