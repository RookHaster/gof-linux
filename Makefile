CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LIBS = -lncurses

TARGET = gol
OBJS = main.o functions.o

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(TARGET)

main.o: main.c header.h
	$(CC) $(CFLAGS) -c main.c

functions.o: functions.c header.h
	$(CC) $(CFLAGS) -c functions.c

clean:
	rm -f $(OBJS) $(TARGET)
