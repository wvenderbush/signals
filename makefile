GCC = gcc -g

all: run.c
	$(GCC) run.c -o prog

run.c: run.c
	$(GCC) -c run.c

clean:
	rm *.o
	rm *~

run: all
	./prog

debug: all
	gdb prog
