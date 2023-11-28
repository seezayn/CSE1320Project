all:
	gcc -std=c11 -g -Wall -I../include 1.04\ TerminalBattle.c -o ./battle -lm
clean:
	rm ./battle
	@echo Cleanup complete!
run: all
	./battle
add: clean
	git add --all