cc=gcc
all: build
build:
	gcc fileio.c game.c gameconfig.c  main.c movementalgorithm.c placementalgorithm.c -lm -o penguing.out
runplacement:
	./penguing.out phase=placement penguins=3 input.txt output.txt
runmovement:
	./penguing.out phase=movement input.txt output.txt
clean:
	rm -f "penguing.out"
