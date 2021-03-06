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
	mkdir -p $(DESTDIR)$(INSTALL_DIR)
	cp -f repocalc $(DESTDIR)$(INSTALL_DIR)
	chmod 755 $(DESTDIR)$(INSTALL_DIR)/repocalc
	mkdir -p $(DESTDIR)$(MAN_DIR)/man1
	sed "s/VERSION/$(VERSION)/g" < repocalc.1 > $(DESTDIR)$(MAN_DIR)/man1/repocalc.1
	chmod 644 $(DESTDIR)$(MAN_DIR)/man1/repocalc.1
		

uninstall:
	rm -f $(DESTDIR)$(INSTALL_DIR)/repocalc
	rm -f $(DESTDIR)$(MAN_DIR)/man1/repocalc.1

clean:
	rm -f repocalc $(OBJ)

defconfig: clean
	rm -f config.h customfuncs.h customfuncs.h structs.h

dist: defconfig
	mkdir repocalc-$(VERSION)
	cp *.h repocalc-$(VERSION)
	cp *.c repocalc-$(VERSION)
	cp Makefile repocalc-$(VERSION)
	cp config.mk repocalc-$(VERSION)
	cp *.md repocalc-$(VERSION)
	cp LICENSE repocalc-$(VERSION)
	cp repocalc.1 repocalc-$(VERSION)
	tar cvzf repocalc-$(VERSION).tar.gz repocalc-$(VERSION)
	rm -rf repocalc-$(VERSION)


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

