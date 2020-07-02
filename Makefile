.POSIX:
CC     = c99
CFLAGS = -Og -g
LDLIBS = -lm

main: main.c
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ main.c -lm

clean:
	rm -f main
