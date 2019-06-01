VERSION = 1.0.0

INSTALL_DIR = /usr/local/bin
MAN_DIR = /usr/local/share/man/

PKG_CONFIG = pkg-config

INCS = `$(PKG_CONFIG) --cflags ncurses`
LIBS = -lm \
	   `$(PKG_CONFIG) --libs ncurses`

RPCCFLAGS = $(INCS) -DVERSION=\"$(VERSION)\" -Wall -pedantic -Os
RPCLFLAGS = $(LIBS)

