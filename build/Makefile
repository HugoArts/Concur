VPATH= ../src
CFLAGS= -O0 -Wall -std=c99
SOURCES= main.c stack.c
OBJECTS= $(SOURCES:.c=.o)
ASSEMBLED= $(SOURCES:.c=.s)

all: concur
assemble: $(ASSEMBLED)

concur: $(OBJECTS)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

%.s: %.c
	$(CC) -S $(CFLAGS) $< -o $@

# dependencies
main.o: instr.h
stack.o: stack.h

.PHONY: clean
clean:
	rm -f concur $(OBJECTS) $(ASSEMBLED)
