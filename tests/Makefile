CC = cc
CFLAGS = -Wall `pkg-config --cflags check`
LDFLAGS = -lm `pkg-config --libs check`

TESTS = test.o
SOURCES = ../stack.c ../corefuncs.c
OBJ = stack.o corefuncs.o

all: test

$(OBJ) : $(SOURCES)
	$(CC) $(CFLAGS) -c $^

$(TESTS) : $(TESTS:.o=.c)
	$(CC) $(CFLAGS) -c $<

test: $(TESTS) $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TESTS) $(OBJ) test


