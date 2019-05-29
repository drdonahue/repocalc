CC = cc
CFLAGS = -Wall `pkg-config --cflags check`
LDFLAGS = -lm `pkg-config --libs check`

TESTS = test.o
SOURCES = ../stack.c
OBJ = stack.o

all: test

OBJ : SOURCES
	$(CC) $(CFLAGS) -c $<

.c.o:
	$(CC) $(CFLAGS) -c $<

test: $(TESTS) $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TESTS) $(OBJ) test


