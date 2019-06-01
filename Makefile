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
customfuncs.c:
	cp customfuncs.def.c customfuncs.c
customfuncs.h:
	cp customfuncs.def.h customfuncs.h
structs.h:
	cp structs.def.h structs.h

.c.o:
	$(CC) $(RPCCFLAGS) -c $<

$(OBJ): config.h config.mk customfuncs.c customfuncs.h structs.h

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

defconfig: clean
	rm -f config.h customfuncs.h customfuncs.h structs.h

dist: defconfig
	mkdir repocalc
	cp *.h repocalc
	cp *.c repocalc
	cp Makefile repocalc
	cp config.mk repocalc
	cp *.md repocalc
	cp LICENSE repocalc
	cp repocalc.1 repocalc
	tar cvzf repocalc-$(VERSION).tar.gz repocalc
	rm -rf repocalc


help:
	@echo all: Display build options and build the application
	@echo repocalc: Build the application without displaying build options
	@echo install: Install the application and manpage to $(INSTALL_DIR) and $(MAN_DIR) respectively
	@echo uninstall: Uninstall the application from the system
	@echo clean: Remove generated files
	@echo defconfig: Restore config.h, corefuncs.h, corefuncs.c, and structs.h to default
	@echo dist: Create a tarball of the project
	@echo help: Display this help message

.PHONY: all options install defconfig help

