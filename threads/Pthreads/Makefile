TARGET=pth
DEPS=timer
DEPS:=$(addsuffix .o, $(DEPS))

CC=gcc
CFLAGS= -O2 -lpthread -lm -Wall -Wextra -Wpedantic 

$(TARGET): $(DEPS)
	$(CC)  $(addsuffix .c, $(TARGET)) $(DEPS) -o $@ $(CFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

.PHONY: all clean

all: $(TARGET)
clean:
	-rm -f *.o $(TARGET)

