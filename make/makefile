OBJS=main.o tool1.o tool2.o
CC=gcc
CFLAGS+=-c -Wall -g

my_tool: $(OBJS)
	$(CC) $^ -o $@

%.o:%.c
	$(CC) $^ $(CFLAGS) -o $@

clean:
	rm -rf *.o my_tool 