all: main

main: queue.o main.o dl_list.o
	gcc $^ -o $@

clean:
	rm -rf main *.o
