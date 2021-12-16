CC = gcc
AR = ar
OBJECTS_MAIN = main.o
OBJECTS_LIB = my_char.o
FLAGS= -Wall -g

all:  stringProg

stringProg: $(OBJECTS_MAIN) $(OBJECTS_LIB)
	$(CC) $(FLAGS) -o stringProg $(OBJECTS_MAIN) $(OBJECTS_LIB)
my_char.o: my_char.c my_char.h
	$(CC) $(FLAGS) -c my_char.c
main.o: main.c my_char.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so stringProg
