VPATH= ../src
CFLAGS= -Wall -std=c99
SOURCES= main.c
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

.PHONY: clean
clean:
	rm -f concur $(OBJECTS) $(ASSEMBLED)
