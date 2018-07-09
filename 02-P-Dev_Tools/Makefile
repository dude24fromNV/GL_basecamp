TARGET=lee1
DEPS=algo timer
DEPS:=$(addsuffix .o, $(DEPS))

CC=gcc
CFLAGS= -O2

$(TARGET): $(DEPS)
	$(CC) $(CFLAGS) $(addsuffix .c, $(TARGET)) $(DEPS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<

.PHONY: all clean

all: $(TARGET)
clean:
	-rm -f *.o $(TARGET)

