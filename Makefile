TARGET = KretShell
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra

SRCDIR = src
SRC = $(SRCDIR)/main.cpp

PREFIX = /usr/local
BINDIR = $(PREFIX)/bin

all: build

build:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

install: build
	install -d $(BINDIR)
	install -m 755 $(TARGET) $(BINDIR)

clean:
	rm -f $(TARGET)

uninstall:
	rm -f $(BINDIR)/$(TARGET)
