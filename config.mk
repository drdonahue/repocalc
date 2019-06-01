VERSION = 1.0.1

PREFIX = /usr/local
INSTALL_DIR = $(PREFIX)/bin
MAN_DIR = $(PREFIX)/share/man/

PKG_CONFIG = pkg-config

INCS = `$(PKG_CONFIG) --cflags ncurses`
LIBS = -lm \
	   `$(PKG_CONFIG) --libs ncurses`

RPCCFLAGS = $(INCS) -DVERSION=\"$(VERSION)\" -Wall -pedantic -Os
RPCLFLAGS = $(LIBS)

