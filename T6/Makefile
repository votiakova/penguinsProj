cc=gcc
all: build
build:
	gcc fileio.c game.c gameconfig.c  main.c movementalgorithm.c placementalgorithm.c -o sau.out -lm
runplacement:
	./sau.out phase=placement penguins=3 input.txt output.txt
runmovement:
	./sau.out phase=movement input.txt output.txt
clean:
	rm -f "sau.out"
