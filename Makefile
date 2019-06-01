include config.mk

SRC = repocalc.c ui.c stack.c parse.c corefuncs.c trigfuncs.c customfuncs.c bank.c
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

install: repocalc
	mkdir -p $(INSTALL_DIR)
	cp -f repocalc $(INSTALL_DIR)
	chmod 755 $(INSTALL_DIR)/repocalc
	mkdir -p $(MAN_DIR)/man1
	sed "s/VERSION/$(VERSION)/g" < repocalc.1 > $(MAN_DIR)/man1/repocalc.1
	chmod 644 $(MAN_DIR)/man1/repocalc.1
		

uninstall:
	rm -f $(INSTALL_DIR)/repocalc
	rm -f $(MAN_DIR)/man1/repocalc.1

clean:
	rm -f repocalc $(OBJ)

.PHONY: all options clean install uninstall

