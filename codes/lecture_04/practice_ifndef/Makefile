VPATH=./
EXEC=main
OBJDIR=./

CC=gcc

CFLAGS=-Wall -Wfatal-errors

OBJ=coordinate.o main.o

OBJS = $(addprefix $(OBJDIR), $(OBJ))
DEPS = $(wildcard ./*.h) Makefile

all: obj results $(EXEC)

$(EXEC): $(OBJS)
    $(CC) $(COMMON) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJDIR)%.o: %.c $(DEPS)
    $(CC) $(COMMON) $(CFLAGS) -c $< -o $@

obj:
    mkdir -p obj
results:
    mkdir -p results

.PHONY: clean

clean:
    rm -rf $(OBJS) $(EXEC)
