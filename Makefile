include config.mk

SRC = repocalc.c ui.c stack.c parse.c corefuncs.c
OBJ = $(SRC:.c=.o)

all: options repocalc

options:
	@echo repocalc build options:
	@echo "CFLAGS  = $(RPCCFLAGS)"
	@echo "LDFLAGS = $(RPCLFLAGS)"
	@echo "CC 	   = $(CC)"

config.h:
	cp config.def.h config.h

.c.o:
	$(CC) $(RPCCFLAGS) -c $<

$(OBJ): config.h config.mk

repocalc: $(OBJ)
	$(CC) -o $@ $(OBJ) $(RPCLFLAGS)

clean:
	rm -f repocalc $(OBJ)

.PHONY: all options clean

