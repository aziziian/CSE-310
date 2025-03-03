CC = g++
CFLAGS = -Wall -Wextra -std=c++11

all: encoder

encoder: main.o hash.o
	$(CC) $(CFLAGS) -o encoder main.o hash.o

%.o: %.cpp hash.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o encoder