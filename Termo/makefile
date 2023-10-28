CC = gcc
CFLAGS = -Wall

IDIR = ./include
ODIR = ./src
OBJDIR = objects
BINDIR = bin
FDIR = files

SRC = $(wildcard $(ODIR)/*.c)
OBJ = $(patsubst $(ODIR)/%.c, $(OBJDIR)/%.o, $(SRC))

all: binfolder objfolder bin/main
	@ echo "Type 'make run' to run code"

bin/main: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

binfolder:
	@ echo "Creating bin directory..."
	mkdir -p $(BINDIR)

objfolder:
	@ echo "Creating obj directory..."
	mkdir -p $(OBJDIR)

$(OBJDIR)/main.o: $(ODIR)/main.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(ODIR)/%.c $(IDIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean run

clean:
	rm -f $(BINDIR)/* $(OBJDIR)/*
	rmdir $(BINDIR) $(OBJDIR)

run:
	$(BINDIR)/main $(FDIR)/5.txt
