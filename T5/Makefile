cc=gcc
all: build
build:
	gcc fileio.c game.c gameconfig.c  main.c movementalgorithm.c placementalgorithm.c -o penguing.out -lm
run:
	./penguing.out phase=placement penguins=2 input.txt test.txt
clean:
	rm -f "penguing.out"
