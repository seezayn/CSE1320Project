all:
	gcc -std=c11 -g -Wall -I../include src/*.c -o ./mysolution -lm
clean:
	rm ./mysolution
	@echo Cleanup complete!
run: all
	./mysolution
add:
	git add --all