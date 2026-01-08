cc=gcc
all: build
build:
	gcc fileio.c game.c gameconfig.c visualmode.c main.c -o penguing.out
run:
	./penguing.out phase=placement penguins=2 input.txt test.txt
visual:
	./penguing.out phase=placement penguins=2 input.txt test.txt vis
rbuild:
	gcc fileio.c game.c gameconfig.c visualmode.c main.c -o penguing.out -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
rbuild_run:
	gcc fileio.c game.c gameconfig.c visualmode.c main.c -o penguing.out -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
	./penguing.out phase=placement penguins=2 input.txt test.txt vis
clean:
	rm -f "penguing.out"