## Build and run instructions

- Running `make` while in the file directory should create a file called `sau.out`
- If that doesn't work try running `make build` or run `gcc fileio.c game.c gameconfig.c  main.c movementalgorithm.c placementalgorithm.c -o sau.out -lm` directly
- The code works with the specifications provided in the instructions. Example usecase: `./sau.out phase=placement penguins=3 input.txt output.txt`
