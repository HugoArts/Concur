VPATH= ../src
CFLAGS= -Wall
SOURCES= hello.c
OBJECTS= $(SOURCES:.c=.o)
ASSEMBLED= $(SOURCES:.c=.s)

all: hello
assemble: $(ASSEMBLED)

hello: $(OBJECTS)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

%.s: %.c
	$(CC) -S $(CFLAGS) $< -o $@

# dependencies
hello.c: instr.h

.PHONY: clean
clean:
	rm -f hello $(OBJECTS) $(ASSEMBLED)
