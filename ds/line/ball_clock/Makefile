all: main

main: queue.o sq_stack.o main.o
	gcc $^ -o $@

clean:
	rm -rf main *.o
