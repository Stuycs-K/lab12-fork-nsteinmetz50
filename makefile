.PHONY: compile run clean
compile fork: main.o fork.o
	@gcc -o fork main.o fork.o
main.o: main.c fork.h
	@gcc -c fork.c
fork.o: fork.c fork.h
	@gcc -c fork.c
run: fork
	@./fork
clean:
	rm *.o
	rm fork
