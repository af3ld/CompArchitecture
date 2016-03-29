CC=gcc
EXEC=bigadventure
OBJS=driver.o bigint.o
SOURCES=*.c
FLAGS=-g -Wall -std=c99

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(EXEC)

.c.o:
	$(CC) $(FLAGS) -c *.c

clean:
	rm -f *.o $(EXEC) a.out
