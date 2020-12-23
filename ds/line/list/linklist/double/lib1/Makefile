all: dl_list

dl_list: dl_list.o main.o
	gcc $^ -o $@

clean:
	rm -rf dl_list *.o