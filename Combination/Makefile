CC=gcc
CFLAGS=-I.
DEPS = IO.h
OBJ = main.o

%.o: %.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)
qsum: $(OBJ)
	gcc -g -o $@ $^ $(CFLAGS)
	rm *.o
.PHONY: clean

clean:
	rm -f *.o qwyit

