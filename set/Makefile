# Makefile for Set

CC := gcc
SRCDIR := src
BINDIR := bin
BUILDDIR := build
TARGET := set

# GCC Debug Flags
DEBUGFLAGS := -g3 -O0 -Wall -pg
RTCHECKS := -fmudflap -fstack-check -gnato
# GCC Production Flags
PRODFLAGS := -Wall -O2
# Active Flags
CFLAGS := -std=gnu99 $(DEBUGFLAGS)
LINK := $(DEBUGFLAGS)
 
SRCEXT := c
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

$(TARGET): $(OBJECTS)
	@echo " Linking..."; $(CC) $(LINK) $^ -o $(BINDIR)/$(TARGET)
 
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " CC $<"; $(CC) $(CFLAGS) -c -o $@ $<
 
clean:
	@echo " Cleaning..."; rm -r $(BUILDDIR) $(BINDIR)/$(TARGET)*
 
.PHONY: clean
