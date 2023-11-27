all:
	gcc -std=c11 -g -Wall -I../include src/*.c -o ./endless -lm
clean:
	rm ./endless
	@echo Cleanup complete!
run: all
	./endless
add: clean
	git add --all