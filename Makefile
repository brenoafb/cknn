CC=gcc
CFLAGS=-std=c99 -O2
LIBS=-lm

SRCDIR= ./src
OBJDIR= ./obj
BINDIR= ./bin

SRC=io.c knn.c
MAINSRC=main.c

OBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))
MAINOBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(MAINSRC))

$(OBJDIR)/%.o: $(SRCDIR)/%.c
		$(CC) $(CFLAGS) -c $< -o $@

$(BINDIR)/main.out: $(OBJ) $(MAINOBJ)
		$(CC) $(CFLAGS) -o $@ $(OBJ) $(MAINOBJ) $(LIBS) 

all: $(BINDIR)/main.out

debug: CFLAGS += -DDEBUG -g
debug: all

.PHONY=clean

clean:
		rm $(BINDIR)/* $(OBJDIR)/*.o
