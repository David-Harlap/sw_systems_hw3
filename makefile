CC=gcc
AR=ar
FLAGS= -Wall
OBJECTS_ISORT=isort.o
OBJECTS_TXTFIND=txtfind.o

all: txtfind isort 

isort: $(OBJECTS_ISORT) isort.a
	$(CC) $(FLAGS) -o isort $(OBJECTS_ISORT) isort.a

txtfind: $(OBJECTS_TXTFIND) txtfind.a
	$(CC) $(FLAGS) -o txtfind $(OBJECTS_TXTFIND) txtfind.a

isort.a: $(OBJECTS_ISORT)
	$(AR) -rcs isort.a $(OBJECTS_ISORT)

txtfind.a: $(OBJECTS_TXTFIND)
	$(AR) -rcs txtfind.a $(OBJECTS_TXTFIND)

txtfind.o: txtfind.c txtfind.h
	$(CC) $(FLAGS) -c txtfind.c

isort.o: isort.c isort.h
	$(CC) $(FLAGS) -c isort.c

clean:
	rm -f *.o *.a  run

.PHONY: clean all