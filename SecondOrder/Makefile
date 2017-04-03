CC=g++
CFLAGS=-I.
DEPS = secondOrder.h
OBJ = secondOrder.o main.o

%.o: %.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)
qsum: $(OBJ)
	g++ -g -o $@ $^ $(CFLAGS)
	rm *.o
.PHONY: clean

clean:
	rm -f *.o qsum

