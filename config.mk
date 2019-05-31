VERSION = 0.1.1

INSTALL_DIR = /usr/local/bin

PKG_CONFIG = pkg-config

INCS = `$(PKG_CONFIG) --cflags ncurses`
LIBS = -lm \
	   `$(PKG_CONFIG) --libs ncurses`

RPCCFLAGS = $(INCS) -DVERSION=\"$(VERSION)\" -Wall -pedantic -Os
RPCLFLAGS = $(LIBS)

